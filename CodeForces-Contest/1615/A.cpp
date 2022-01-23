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
      int x; cin >> x;
      sum += x;
    }
    cout << (sum % n == 0 ? 0 : 1) << '\n';
  }
  return 0;
}