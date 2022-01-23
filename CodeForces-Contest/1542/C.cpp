#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    ll lc = 1;
    ll ans = 0;
    vector<ll> a(60, 0);
    for (ll i = 1; ; i++) {
      lc = lc / __gcd(lc, i) * i;
      if (lc > n) break;
      a[i] =  n / lc;
    }
    for (int i = 55; i >= 1; i--) {
      ans += (a[i] - a[i + 1])% mod * (i + 1) % mod;
      ans %= mod;
      ans = (ans + mod) % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}