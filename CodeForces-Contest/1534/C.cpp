#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> p(n + 1), a(n + 1), vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      a[p[i]] = k;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      if (vis[p[i]]) continue;
      vis[p[i]] = 1;
      int k = a[p[i]];
      while (k != p[i]) {
        vis[k] = 1;
        k = a[k];
      }
      ans = (ans + ans) % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}