#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = 1, last = -1;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      if (ans == -1) continue;
      if (x and last == 1) ans += 5;
      else if (x) ans++;
      else if (last == 0) ans = -1;
      last = x;
    }
    cout << ans << '\n';
  }
  return 0;
}