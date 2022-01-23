#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int res = 1e9;
    for (int c = 'a'; c <= 'z'; c++) {
      int l = 0, r = n - 1;
      int ans = 0;
      while (l < r) {
        if (s[l] == s[r]) {
          ++l, --r;
        }
        else if (s[l] == c) ++l, ++ans;
        else if (s[r] == c) --r, ++ans;
        else {
          ans = 1e9;
          break;
        }
      }
      res = min(res, ans);
    }
    if (res == 1e9) res = -1;
    cout << res << '\n';
  }
  return 0;
}