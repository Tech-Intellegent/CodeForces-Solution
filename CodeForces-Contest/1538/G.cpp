#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int x, y, a, b; cin >> x >> y >> a >> b;
    int ans = 0;
    for (int i = 0; i < 16000; i++) {
      int cx = a * i, cy = b * i;
      if (cx > x or cy > y) break;
      ans = max(ans, i + min((x - cx) / b, (y - cy) / a));
    }   
    int z = max(16000, x / a - 16000);
    for (int i = x / a; i >= z; i--) {
      int cx = a * i;
      if (cx > x or b > y / i + 1) continue;
      int cy = b * i;
      ans = max(ans, i + min((x - cx) / b, (y - cy) / a));
    }
    cout << ans << '\n';
  }
  return 0;
}