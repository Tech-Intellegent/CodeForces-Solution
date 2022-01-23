#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<pair<int, int>> g[N];
int ans[N];
void dfs(int u, int p, int cur) {
  for (auto [v, i]: g[u]) {
    if (v ^ p) {
      ans[i] = cur;
      dfs(v, u, 5 - cur);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back({v, i});
      g[v].push_back({u, i});
    }
    int l = 1;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= g[i].size() <= 2;
      if (g[i].size() == 1) l = i;
    }
    if (!ok) { // not a line tree
      cout << -1 << '\n';
    }
    else {
      dfs(l, 0, 2);
      for (int i = 1; i < n; i++) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
  }
  return 0;
}