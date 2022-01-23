#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> L, R;
    map<pair<int, int>, int> mp;
    int mn = 1e9, mx = 0;
    for (int i = 1; i <= n; i++) {
      int l, r, c; cin >> l >> r >> c;
      if (L.find(l) != L.end()) {
        L[l] = min(L[l], c);
      }
      else {
        L[l] = c;
      }
      if (R.find(r) != R.end()) {
        R[r] = min(R[r], c);
      }
      else {
        R[r] = c;
      }
      mn = min(mn, l);
      mx = max(mx, r);
      if (mp.find({l, r}) != mp.end()) {
        mp[{l, r}] = min(mp[{l, r}], c);
      }
      else {
        mp[{l, r}] = c;
      }
      int ans = L[mn] + R[mx];
      if (mp.find({mn, mx}) != mp.end()) {
        ans = min(ans, mp[{mn, mx}]);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}