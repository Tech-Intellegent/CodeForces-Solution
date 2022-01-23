#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<int> g[N];
int dep[N], s[N];
void dfs(int u, int p = 0) {
	dep[u] = dep[p] + 1;
	s[u] = 1;
	for (auto v: g[u]) if(v != p) {
		dfs(v, u);
		s[u] += s[v];
	}
}
long long ans = 0;
int nw = 0;
bool f[N];
void yo(int u, int p = 0) {
	nw += !f[u];
	if(f[u]) ans += nw;
	for (auto v: g[u]) if(v != p) yo(v, u);
	nw -= !f[u];
}
int a[N];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) a[i] = i;
    sort(a + 1, a + n + 1, [&](int x, int y) { return dep[x] - s[x] - 1 > dep[y] - s[y] - 1; });
	for (int i = 1; i <= k; i++) f[a[i]] = 1;
	yo(1);
	cout << ans << '\n';
    return 0;
}