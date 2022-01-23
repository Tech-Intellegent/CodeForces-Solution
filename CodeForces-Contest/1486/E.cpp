#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<array<int, 2>> g[N];
int vis[N][55][2], d[N][55][2];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({w, v});
    g[v].push_back({w, u});
  }
  priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 50; j++) {
      d[i][j][0] = d[i][j][1] = 2e9;
    }
  }
  d[1][0][1] = 0;
  q.push({0, 1, 0, 1});
  while (!q.empty()) {
    auto x = q.top();
    q.pop();
    int u = x[1], last = x[2], f = x[3];
    if (vis[u][last][f]) continue;
    vis[u][last][f] = 1;
    for (auto x: g[u]) {
      int v = x[1], w = x[0];
      int nx = d[u][last][f] + (!f ? (w + last) * (w + last) : 0);
      if (nx < d[v][w][f ^ 1]) {
        d[v][w][f ^ 1] = nx;
        q.push({d[v][w][f ^ 1], v, w, f ^ 1});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int ans = 2e9;
    for (int j = 0; j <= 50; j++) {
      ans = min(ans, d[i][j][1]);
    }
    cout << (ans == 2e9 ? -1 : ans) << ' ';
  }
  return 0;
}