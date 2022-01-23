#include<bits/stdc++.h>
using namespace std;

const int N = 405, mod = 998244353;
int d[N][N];
vector<int> g[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = (i != j) * mod;
    }
  }
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    d[u][v] = 1;
    d[v][u] = 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      int cnt = 0;
      for (int k = 1; k <= n; k++) {
        cnt += d[x][k] + d[y][k] == d[x][y];
      }
      int ans = cnt - 1 == d[x][y];
      for (int k = 1; k <= n; k++) {
        if (d[x][k] + d[k][y] == d[x][y]) continue;
        int cnt = 0;
        for (auto z: g[k]) {
          cnt += (d[x][z] + 1 == d[x][k]) && (d[y][z] + 1 == d[y][k]);
        }
        ans = 1LL * ans * cnt % mod;
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
  return 0;
}