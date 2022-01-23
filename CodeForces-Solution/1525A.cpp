#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int k; cin >> k;
    int ans = 200;
    for (int i = 1; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        if (i * 100 == k * (i + j)) {
          ans = min(ans, i + j);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}