#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
map<pair<int, int>, vector<int>> mp;
map<pair<int, int>, int> z;
int a[N];
set<int> g[N];
set<pair<int, int>> cur;
pair<int, int> ed[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		pair<int, int> p = {u, v};
		if (mp.find(p) != mp.end()) {
			mp[p].push_back(i);
		}
		else {
			z[p] = i;
			mp[p].push_back(i);
			g[u].insert(v);
			g[v].insert(u);
			cur.insert({min(a[u], a[v]), i});
		}
		ed[i] = p;
	}
	auto tmp = cur;
	for (auto x: tmp) {
		cur.erase(x);
		int id = x.second;
		cur.insert({x.first - (int)mp[ed[id]].size(), id});
	}
	vector<int> ans;
	while (!cur.empty()) {
		auto x = *cur.begin();
		cur.erase(cur.begin());
		int id = x.second;
		pair<int, int> p = ed[id];
		int cnt = mp[p].size();
		for (auto x: mp[p]) ans.push_back(x);
		int u = p.first, v = p.second;
		mp[p].clear();
		g[u].erase(v);
		g[v].erase(u);
		for (auto v: g[u]) {
			pair<int, int> p = {min(u, v), max(u, v)};
			int id = z[p];
			cur.erase(make_pair(min(a[u], a[v]) - (int)mp[p].size(), id));
		}		
		for (auto u: g[v]) {
			pair<int, int> p = {min(u, v), max(u, v)};
			int id = z[p];
			cur.erase(make_pair(min(a[u], a[v]) - (int)mp[p].size(), id));
		}
		while (cnt) {
			if (max(a[u], a[v]) == 0) {
				cout << "DEAD\n";
				return 0;
			}
			if (a[u]) a[u]--;
			if (a[v]) a[v]--;
			cnt--;
		}
		for (auto v: g[u]) {
			pair<int, int> p = {min(u, v), max(u, v)};
			int id = z[p];
			cur.insert(make_pair(min(a[u], a[v]) - (int)mp[p].size(), id));
		}		
		for (auto u: g[v]) {
			pair<int, int> p = {min(u, v), max(u, v)};
			int id = z[p];
			cur.insert(make_pair(min(a[u], a[v]) - (int)mp[p].size(), id));
		}
	}
	cout << "ALIVE\n";
	for (auto x: ans) cout << x << ' '; cout << '\n';
    return 0;
}