#include<bits/stdc++.h>
using namespace std;

long long l[105], r[105];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> r[i];
    }
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      l[i] = r[i] - x + 1;
    }
    long long ans = 0, mn = 1e9 + 1, mx = mn - 1;
    for (int i = n; i >= 1; i--) {
      if (r[i] >= mn) {
        mn = min(mn, l[i]);
      }
      else {
        ans += (mx - mn + 1) * (mx - mn + 2) / 2;
        mx = r[i];
        mn = l[i];
      }
    }
    ans += (mx - mn + 1) * (mx - mn + 2) / 2;
    cout << ans << '\n';
  }
  return 0;
}