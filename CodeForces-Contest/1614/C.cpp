#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      int l, r, x; cin >> l >> r >> x;
      ans |= x;
    }
    ans %= mod;
    for (int i = 1; i < n; i++) {
      ans = 1LL * ans * 2 % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}