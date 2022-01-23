#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

vector<int> g[N];
int vis[N], d[N];

void dfs(int u) {
  vis[u] = 1;
  int f = 0;
  for (auto v: g[u]) {
    if (vis[v] && d[v]) f = 1;
  }
  d[u] = f ^ 1;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1);
    vector<int> ans;
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        ok = 0;
      }
    }
    if (!ok) {
      cout << "NO\n";
    }
    else {
      for (int i = 1; i <= n; i++) {
        if (d[i]) {
          ans.push_back(i);
        }
      }
      cout << "YES\n";
      cout << ans.size() << '\n';
      for (auto x: ans) cout << x << ' '; cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = 0;
    }
  }
  return 0;
}