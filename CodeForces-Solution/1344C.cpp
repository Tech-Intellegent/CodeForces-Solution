#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<int> g[N];
int vis[N], indeg[N];
void dfs(int u) {
	vis[u] = 1;
	for (auto v: g[u]) {
		if (vis[v] == 1) {
			cout << -1 << '\n'; exit(0);
		}
		if (vis[v] == 0) dfs(v);
	}
	vis[u] = 2;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		indeg[v]++;
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += indeg[i] == 0;
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) cout << 'A';
		else cout << 'E';
	}
	cout << '\n';
    return 0;
}