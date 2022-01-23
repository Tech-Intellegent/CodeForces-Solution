#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    vector<int> c(26, 0);
    for (auto x: s) c[x - 'a']++;
    sort(c.rbegin(), c.rend());
    int ans = 0;
    for (int k = 1; ; k++) {
      int cur = k;
      auto cnt = c;
      for (int i = 0; i < 26 and cur; i++) {
        if (cnt[i]) {
          cur--; cnt[i]--;
        }
      }
      if (cur != 0) break;
      cur = k;
      for (int i = 0; i < 26 and cur; i++) {
        if (cnt[i]) {
          cur--; cnt[i]--;
        }
      }
      if (cur != 0) break;
      ans = k;
    }
    cout << ans << '\n';
  }
  return 0;
}