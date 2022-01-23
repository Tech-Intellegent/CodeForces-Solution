#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll n, k; cin >> n >> k;
    if (k == 1) {
      cout << n - 1 << '\n';
      continue;
    }
    ll ans = 0, x = 1;
    while (x < k) {
      ++ans;
      x += x;
    }
    if (x < n) {
      ans += (n - x + k - 1) / k;
    }
    cout << ans << '\n';
  }
  return 0;
}