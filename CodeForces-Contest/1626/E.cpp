#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
int black[N], a[N];
bool up[N], down[N];
vector<int> g[N];
void dfs(int u, int p = 0) {
  if (p) g[u].erase(find(g[u].begin(), g[u].end(), p));
  down[u] = a[u] == 1;
  black[u] = a[u];
  for (auto v: g[u]) {
    dfs(v, u);
    black[u] += black[v];
    if (a[v] == 1) {
      down[u] = true;
    }
    else if (black[v] > 1) {
      down[u] |= down[v];
    }
  }
}
void dfs2(int u, int p = 0) {
  int totalOK = 0, bl = a[p];
  if (black[1] - black[u] > 1) totalOK += up[u];
  for (auto v: g[u]) {
    bl += a[v];
    if (black[v] > 1) totalOK += down[v];
  }
  for (auto v: g[u]) {
    if (a[v] == 1 or a[u] == 1 or ((bl - a[v]) > 0 and black[1] - black[v] > 1)) {
      up[v] = true;
    }
    int temp = totalOK;
    if (black[v] > 1) temp -= down[v];
    up[v] |= temp >= 1;
    dfs2(v, u);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  dfs2(1);
  for (int i = 1; i <= n; i++) {
    if (up[i] or down[i]) cout << 1 << ' ';
    else cout << 0 << ' ';
  }
  return 0;
}