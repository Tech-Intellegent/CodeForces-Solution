#include<bits/stdc++.h>
using namespace std;

using ll = long long;
bool yo(ll a, ll b, ll x) {
  if (a > b) swap(a, b);
  if (a == 0 or b == 0) return false;
  if (x <= b and (b - x) % a == 0) return true;
  return yo(b % a, a, x);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll a, b, x; cin >> a >> b >> x;
    ll g = __gcd(a, b);
    if (x % g != 0) {
      cout << "NO\n";
      continue;
    }
    a /= g; b /= g; x /= g;
    if (yo(a, b, x)) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}