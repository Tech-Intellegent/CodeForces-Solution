#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  double p; cin >> p;
  for (int i = 0; i <= n; i++) {
    double ans = 0;
    int l = i, r = n - i, all = n * (n - 1) * (n - 2) / 6;
    ans += l * (l - 1) * (l - 2) / 6 * 1.0 / all;
    ans += l * (l - 1) / 2 * r * 1.0 / all;
    ans += l * r * (r - 1) / 4 * 1.0 / all;
    // cout << ans << '\n';
    if (ans >= p or abs(ans - p) < 1e-9) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}