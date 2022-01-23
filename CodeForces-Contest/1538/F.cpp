#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll pw[20];
ll yo(ll n, ll k) {
  if (n == 0) return 0;
  ll l = 0, r = 1e9, ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    ll cur = mid * pw[k] + pw[k] - 1;
    if (cur <= n) {
      ans = mid + 1;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < 20; i++) {
    pw[i] = pw[i - 1] * 10;
  }
  int t; cin >> t;
  while (t--) {
    ll l, r; cin >> l >> r;
    r--;
    ll ans = r - l + 1;
    for (int i = 1; i <= 10; i++) {
      ans += yo(r, i) - yo(l - 1, i);
    }
    cout << ans << '\n';
  }
  return 0;
}