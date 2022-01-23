#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, x, y; cin >> n >> x >> y;
    int w, b; cin >> w >> b;
    if (w <= min(x, y) + abs(x - y) / 2 and b <= min(n - x, n - y) + abs(x - y) / 2) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}