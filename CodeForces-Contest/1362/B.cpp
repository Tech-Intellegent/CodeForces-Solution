#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 1e9;
    for (int i = 1; i < n; i++) {
      int x = a[i] ^ a[0];
      vector<int> v(n);
      for (int i = 0; i < n; i++) {
        v[i] = a[i] ^ x;
      }
      sort(v.begin(), v.end());
      if (v == a) {
        ans = min(ans, x);
      }
    }
    if (ans == (int)1e9) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}