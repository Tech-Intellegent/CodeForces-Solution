#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      sum += k;
    }
    if (sum < n) cout << 1 << '\n';
    else cout << sum - n << '\n';
  }
  return 0;
}