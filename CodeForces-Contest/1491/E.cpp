#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int f[30], fib[N * 10];

set<int> g[N];
int vis[N], sz[N];
int cnt;
void dfs(int u, int p = 0) {
  vis[u] = 1;
  ++cnt;
  sz[u] = 1;
  for (auto v: g[u]) {
    if (v ^ p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}
int found;
void dfs2(int u, int p = 0) {
  if (found) return;
  for (auto v: g[u]) {
    if (found) return;
    if (v ^ p) {
      if (fib[sz[v]] && fib[cnt - sz[v]]) {
        found = 1;
        g[u].erase(v);
        g[v].erase(u);
        return;
      }
      dfs2(v, u);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  f[0] = 1; f[1] = 1;
  fib[1] = 1;
  for (int i = 2; i < 30; i++) {
    f[i] = f[i - 1] + f[i - 2];
    fib[f[i]] = 1;
  }
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  if (!fib[n]) {
    cout << "NO\n";
    return 0;
  }
  while (1) {
    int x = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        cnt = 0;
        dfs(i);
        if (cnt == 1) {
          continue;
        }
        x = 1;
        found = 0;
        dfs2(i);
        if (!found) {
          cout << "NO\n";
          return 0;
        }
      }
    }
    if (!x) break;
    for (int i = 1; i <= n; i++) {
      vis[i] = sz[i] = 0;
    }
  }
  cout << "YES\n";
  return 0;
}