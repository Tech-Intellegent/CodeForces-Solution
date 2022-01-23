#include<bits/stdc++.h>
using namespace std;

const int N = 606;
long long d[N][N];
vector<pair<int, int>> g[N];
int ok[N * N];
long long f[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = 1e18;
    }
    d[i][i] = 0;
  }
  vector<array<int, 4>> e;
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    e.push_back({u, v, w, i});
    d[u][v] = min(d[u][v], 1LL * w);
    d[v][u] = min(d[v][u], 1LL * w);
  }
  int q; cin >> q;
  while (q--) {
    int u, v, l; cin >> u >> v >> l;
    g[u].push_back({v, l});
    g[v].push_back({u, l});
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      f[v] = 0;
      for (auto [x, w]: g[u]) {
        f[v] = max(f[v], w - d[v][x]);
      }
    }
    for (auto [x, y, w, i]: e) {
      if (d[u][x] + w <= f[y]) {
        ok[i] = 1;
      }
      if (d[u][y] + w <= f[x]) {
        ok[i] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans += ok[i];
  }
  cout << ans << '\n';
  return 0;
}