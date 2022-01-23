#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (n <= 2) {
      cout << 0 << '\n';
      continue;
    }
    int ans = n - 1;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        double d = 1.0 * (a[j] - a[i]) / (j - i);
        double cur = a[i];
        int cost = 0;
        for (int k = i + 1; k <= n; k++) {
          cur += d;
          if (abs(cur - a[k]) < eps);
          else ++cost;
        }
        cur = a[i];
        for (int k = i - 1; k >= 1; k--) {
          cur -= d;
          if (abs(cur - a[k]) < eps);
          else ++cost;
        }
        ans = min(ans, cost);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}