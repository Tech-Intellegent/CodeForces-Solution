#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;

int u[N], v[N];
vector<int> in[N], out[N];
set<int> g[N], nw[N];
vector<int> edge[N];
set<int> yo(int n, vector<int> order) {
	for (int i = 1; i <= n; i++) nw[i] = g[i];
	set <int> ans;
	for (int i = 0; i < n; i++) {
		int p = order[i];
		if (nw[p].size() == 0) continue;
		for (auto id: nw[p]) {
			int a = edge[id][0], b = edge[id][1], c = edge[id][2];
			if (a != p) {
				nw[a].erase(id);
			}			
			if (b != p) {
				nw[b].erase(id);
			}			
			if (c != p) {
				nw[c].erase(id);
			}				
		}
		nw[p].clear();
		ans.insert(p);
	}
	return ans;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
set<int> check(set<int> a, set<int> b) {
	if (a.size() < b.size()) return a;
	else return b;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (m >= N) while (1);
		for (int i = 1; i <= m; i++) {
			cin >> u[i] >> v[i];
			assert(u[i] < v[i]);
			in[v[i]].push_back(i);
			out[u[i]].push_back(i);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (auto x: in[i]) {
				for (int y: out[i]) {
					int a = u[x], b = i, c = v[y];
					cnt++;
					edge[cnt] = {a, b, c};
					g[a].insert(cnt);
					g[b].insert(cnt);
					g[c].insert(cnt);
				}
			}
		}
		if (cnt >= N) while (1);
		set<pair<int, int>> se;
		for (int i = 1; i <= n; i++) nw[i] = g[i];
		for (int i = 1; i <= n; i++) {
			se.insert({nw[i].size(), i});
		}
		set <int> ans;
		while (!se.empty()) {
			auto x = *(--se.end());
			int p = x.second;
			se.erase(x);
			assert(nw[p].size() == x.first);
			if (x.first == 0) continue;
			for (auto id: nw[p]) {
				int a = edge[id][0], b = edge[id][1], c = edge[id][2];
				if (a != p) {
					se.erase({nw[a].size(), a});
					nw[a].erase(id);
					se.insert({nw[a].size(), a});
				}			
				if (b != p) {
					se.erase({nw[b].size(), b});
					nw[b].erase(id);
					se.insert({nw[b].size(), b});
				}			
				if (c != p) {
					se.erase({nw[c].size(), c});
					nw[c].erase(id);
					se.insert({nw[c].size(), c});
				}				
			}
			nw[p].clear();
			ans.insert(p);
		}
		vector<int> perm;
		for (int i = 1; i <= n; i++) perm.push_back(i);
		ans = check(ans, yo(n, perm));
		reverse(perm.begin(), perm.end());
		ans = check(ans, yo(n, perm));
		while (ans.size() * 7 > 4 * n) {
			shuffle(perm.begin(), perm.end(), rnd);
			ans = check(ans, yo(n, perm));
		}
		cout << ans.size() << '\n';
		for (auto x: ans) cout << x << ' '; cout << '\n';
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			in[i].clear();
			out[i].clear();
		}
	}
    return 0;
}