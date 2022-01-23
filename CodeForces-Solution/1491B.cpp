#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, u, v; cin >> n >> u >> v;
    long long ans = 1e18;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int d = -5; d <= 5; d++) {
        int k = a[i] + d, ok = 0;
        if (i > 1 && abs(a[i - 1] - k) > 1) ok = 1;
        if (i < n && abs(a[i + 1] - k) > 1) ok = 1;
        if (ok) {
          ans = min(ans, 1LL * abs(d) * v);
        }
      }
      if (i > 1 && a[i] != a[i - 1]) {
        ans = min(ans, 1LL * u);
      }
      if (i > 1 && a[i] == a[i - 1]) {
        ans = min(ans, 1LL * u + v);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}