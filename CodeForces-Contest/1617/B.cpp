#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) { // will run O(log n) times at max
      if (__gcd(i, n - 1 - i) == 1) {
        cout << i << ' ' << n - 1 - i << ' ' << 1 << '\n';
        break;
      }
    }
  }
  return 0;
}