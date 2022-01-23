#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
int a[N], vis[N], ok;
long long sum[3];
void dfs(int u, int p = 0, int c = 1) {
  vis[u] = c;
  sum[c] += a[u];
  for (auto v: g[u]) {
    if (v ^ p) {
      if (!vis[v]) dfs(v, u, 3 - c);
      else {
        if (vis[u] == vis[v]) {
          ok = 0;
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }    
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      a[i] = x - a[i];
    }
    for (int i = 1; i <= m; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ok = 1;
    dfs(1);
    if ((sum[1] + sum[2]) % 2 == 0 and (!ok or sum[1] == sum[2])) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = 0;
    }
    sum[1] = sum[2] = 0;
  }
  return 0;
}