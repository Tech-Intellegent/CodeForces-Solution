#include<bits/stdc++.h>
using namespace std;

int f(int n) {
  int k = sqrt(n);
  while (k * k < n) ++k;
  while (k * k > n) --k;
  return k * k == n;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ok = 0;
    for (int i = 2; i <= n; i *= 2) {
      if (n % i == 0 and f(n / i)) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}