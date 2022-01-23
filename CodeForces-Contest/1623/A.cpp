#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, a, b, x, y; cin >> n >> m >> a >> b >> x >> y;
    int p = x >= a ? x - a : n - x + n - a;
    int q = y >= b ? y - b : m - y + m - b;
    cout << min(p, q) << '\n';
  }
  return 0;
}