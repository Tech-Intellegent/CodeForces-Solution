#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    long long odd = 2e9, ev = 2e9, ans = 1e18, sum = 0;
    for (int i = 1; i <= n; i++) {
      long long k; cin >> k;
      sum += k;
      if (i & 1) odd = min(odd, k);
      else ev = min(ev, k);
      if (i > 1) {
        long long cur = sum;
        cur += odd * (n - (i + 1) / 2);
        cur += ev * (n - i / 2);
        ans = min(ans, cur);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}