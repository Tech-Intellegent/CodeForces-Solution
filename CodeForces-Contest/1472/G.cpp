#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
int d[N], dp[N];

int yo(int u) {
  if (dp[u] != -1) return dp[u];
  int ans = d[u];
  for (auto v: g[u]) {
    if (d[u] < d[v]) {
      ans = min(ans, yo(v));
    }
    else {
      ans = min(ans, d[v]);
    }
  }
  return dp[u] = ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    while (m--) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      d[i] = 1e9;
    }
    d[1] = 0;
    q.push(1);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto v: g[u]) {
        if (d[u] + 1 < d[v]) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      dp[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      cout << yo(i) << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
  }
  return 0;
}