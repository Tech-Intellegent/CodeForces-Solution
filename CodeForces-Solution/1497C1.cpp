#include<bits/stdc++.h>
using namespace std;

array<int, 3> f(int n) {
  if (n & 1) return {n / 2, n / 2, 1};
  if (n % 4 == 0) return {n / 4, n / 4, n / 2};
  return {2, (n - 2) / 2, (n - 2) / 2};
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    for (int i = 0; i < k - 3; i++) {
      cout << 1 << ' ';
    }
    n -= k - 3;
    auto x = f(n);
    cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
  }
  return 0;
}