#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    int z = x + y;
    if (z % 2 == 0) {
      z /= 2;
      if (x >= y) cout << z - y << ' ' << y << '\n';
      else cout << x << ' ' << z - x << '\n';
    }
    else {
      cout << -1 << ' ' << -1 << '\n';
    }
  }
  return 0;
}