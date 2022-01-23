#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> cnt(n + 1, 0);
    vector<vector<int>> g(m + 1);
    int ok = 1;
    for (int i = 1; i <= m; i++) {
      int k; cin >> k;
      while (k--) {
        int x; cin >> x;
        g[i].push_back(x);
      }
      if (g[i].size() == 1) {
        int x = g[i][0];
        cnt[x]++;
        if (cnt[x] > (m + 1) / 2) ok = 0;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    vector<int> ans(m + 1);
    for (int i = 1; i <= m; i++) {
      if (g[i].size() > 1) {
        sort(g[i].begin(), g[i].end(), [&](int x, int y) {
          return cnt[x] < cnt[y];
        });
        int x = g[i][0];
        cnt[x]++;
        if (cnt[x] > (m + 1) / 2) {
          ok = 0;
        }
      }
      ans[i] = g[i][0];
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}