#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

vector<int> g[N];
int bad[N], vis[N], dep[N], a[N], last[N];
set<pair<int, int>> bp;
void dfs(int u, int p = 0) {
  dep[u] = dep[p] + 1;
  if (a[u] == a[p]) {
    last[u] = last[p];
  }
  else {
    last[u] = p;
  }
  vis[u] = 1;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v, u);
    }
    else {
      set<int> se;
      int cur = u;
      if ((dep[u] - dep[v] + 1) & 1) {
        while (se.size() <= 1 && dep[cur] >= dep[v]) {
          se.insert(a[cur]);
          cur = last[cur];
        }
        if (se.size() == 1) {
          bad[*se.begin()] = 1;
        }
        else if (se.size() == 2) {
           int x = *se.begin(), y = *se.rbegin();
           if (bp.find({x, y}) == bp.end()) {
            set<int> se;
            int cur = u;
            while (se.size() <= 2 && dep[cur] >= dep[v]) {
              se.insert(a[cur]);
              cur = last[cur];
            }
            if (se.size() == 2) {
              bp.insert({x, y});
            }
          }
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  long long ans = 1LL * k * (k - 1) / 2;
  for (auto x: bp) {
    int u = x.first, v = x.second;
    if (!bad[u] && !bad[v]) {
      ans--;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (bad[i]) {
      ans -= k - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}