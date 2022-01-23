#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> se;
void solve(int l, int r) {
  for (int i = l; i <= r; i++) {
    bool ok = true;
    if (l <= i - 1 and se.find({l, i - 1}) == se.end()) ok = false;
    if (i + 1 <= r and se.find({i + 1, r}) == se.end()) ok = false;
    if (ok) {
      cout << l << ' ' << r << ' ' << i << '\n';
      if (l <= i - 1) {
        solve(l, i - 1);
      }
      if (i + 1 <= r) {
        solve(i + 1, r);
      }
      break;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    se.clear();
    for (int i = 1; i <= n; i++) {
      int l, r; cin >> l >> r;
      se.insert({l, r});
    }
    solve(1, n);
  }
  return 0;
}