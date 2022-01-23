#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], f[N];
vector<int> g[N];
int cnt, x;
void dfs(int u, int p = 0) {
  f[u] = a[u];
  for (auto v: g[u]) {
    if (v ^ p) {
      dfs(v, u);
      f[u] ^= f[v];
    }
  }
  if (f[u] == x) {
    ++cnt;
    f[u] = 0;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    x = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      x ^= a[i];
    }
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cnt = 0;
    dfs(1);
    bool ok = false;
    if (x == 0) {
      ok = true;
    }
    else if (k > 2 and cnt >= 3) {
      ok = true;
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
  }
  return 0;
}