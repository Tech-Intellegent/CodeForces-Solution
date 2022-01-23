#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll a, b, n; cin >> n >> a >> b;
    if (n == 1) {
      cout << "Yes\n";
      continue;
    }
    if (a == 1) {
      if ((n - 1) % b == 0) {
        cout << "Yes\n";
      }
      else {
        cout << "No\n";
      }
      continue;
    }
    bool ok = false;
    for (ll x = 1; x <= n; x *= a) {
      if ((n - x) % b == 0) {
        ok = true; break;
      }
    }
    if (ok) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
  return 0;
}