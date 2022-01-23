#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
using ll = long long;
vector<int> g[N];
int l[N], r[N];
ll dp[N][2];
void dfs(int u, int p = 0) {
  dp[u][0] = dp[u][1] = 0;
  for (auto v: g[u]) {
    if (v ^ p) {
      dfs(v, u);
      dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
      dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
  }
  return 0;
}