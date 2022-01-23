#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    int ans = 1e9;
    for (int k = 0; k < 40000; k++) {
      int c = b + k, cur = k, d = a;
      if (c == 1) continue;
      while (d) {
        ++cur;
        d /= c;
      }
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}