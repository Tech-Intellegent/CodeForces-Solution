#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
const long long inf = 1e18;

long long x[5], a[5][N];
vector<int> g[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 4; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= x[i]; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= 3; i++) {
    int m; cin >> m;
    while (m--) {
      int u, v; cin >> u >> v;
      g[v].push_back(u);
    }
    multiset<long long> se;
    for (int j = 1; j <= x[i]; j++) {
      se.insert(a[i][j]);
    }
    for (int u = 1; u <= x[i + 1]; u++) {
      for (auto v: g[u]) {
        se.erase(se.find(a[i][v]));
      }
      if (!se.empty()) {
        a[i + 1][u] += *se.begin();
      }
      else {
        a[i + 1][u] = inf;
      }
      for (auto v: g[u]) {
        se.insert(a[i][v]);
      }
      g[u].clear();
    }
  }
  long long ans = inf;
  for (int j = 1; j <= x[4]; j++) {
    ans = min(ans, a[4][j]);
  }
  if (ans == inf) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}