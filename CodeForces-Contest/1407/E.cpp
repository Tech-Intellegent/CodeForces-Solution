#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
vector<pair<int, int>> g[N];
int d[N], col[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		g[v].push_back({u, w});
	}
	queue<int> q;
	q.push(n);
	memset(col, -1, sizeof col);
	memset(d, -1, sizeof d);
	d[n] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto x: g[u]) {
			int v = x.first, w = x.second;
			if (col[v] == -1) col[v] = !w;
			else if (col[v] == w && d[v] == -1) d[v] = d[u] + 1, q.push(v);
		}
	}
	cout << d[1] << '\n';
	for (int i = 1; i <= n; i++) cout << (col[i] == -1 ? 0 : col[i]);
    return 0;
}