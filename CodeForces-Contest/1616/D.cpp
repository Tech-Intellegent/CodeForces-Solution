#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int x; cin >> x;
    long long sum = 0; bool f = false;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      a[i] -= x;
      sum = min((f ? sum : (long long)1e18) + a[i], 1LL * a[i] + a[i - 1]);
      // cout << sum <<' ' << '\n';
      if (!f or sum >= 0) {
        if (!f) sum = a[i];
        ++ans, f = true;
      }
      else sum = 0, f = false;
      // cout << i << ' ' << sum << ' ' << f << '\n';
    }
    cout << ans << '\n';
  }
  return 0;
}