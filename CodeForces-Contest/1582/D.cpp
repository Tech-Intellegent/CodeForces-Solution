#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (sum - a[i] != 0) {
        long long x = 1LL * abs(a[i]) * abs(sum - a[i]) / __gcd(abs(a[i]), abs(sum - a[i]));
        for (int j = 1; j <= n; j++) {
          if (i != j) {
            cout << x / (sum - a[i]) << ' ';
          }
          else {
            cout << -x / a[i] << ' ';
          }
        }
        cout << '\n';
        break;
      }
    }
  }
  return 0;
}