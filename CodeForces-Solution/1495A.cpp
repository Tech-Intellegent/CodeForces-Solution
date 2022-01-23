#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a, b;
    for (int i = 0; i < 2 * n; i++) {
      int x, y; cin >> x >> y;
      if (x == 0) {
        b.push_back(abs(y));
      }
      else {
        a.push_back(abs(x));
      }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += sqrt((1LL * a[i] * a[i] + 1LL * b[i] * b[i]) * 1.0L);
    }
    cout << fixed << setprecision(12) << ans << '\n';
  }
  return 0;
}