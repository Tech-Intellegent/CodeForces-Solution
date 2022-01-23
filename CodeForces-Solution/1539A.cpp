#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll n, x, t; cin >> n >> x >> t;
    ll k = t / x;
    if (k >= n) cout << n * (n - 1) / 2 << '\n';
    else cout << n * k - k * (k + 1) / 2 << '\n';
  }
  return 0;
}