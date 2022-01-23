#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int ans = 10;
    for (int mask = 0; mask < (1 << 10); mask++) {
      vector<int> a(10);
      for (int i = 0; i < 10; i++) {
        a[i] = s[i] == '?' ? (mask >> i & 1) : s[i] - '0';
      }
      int x = 0, y = 0, cur = 10;
      for (int i = 0; i < 10; i++) {
        if (i & 1) y += a[i];
        else x += a[i];
        int p = 0, q = 0;
        for (int j = i + 1; j < 10; j++) {
          if (j & 1) q += 1;
          else p += 1;
        }
        if (x + p < y or y + q < x) {
          cur = i + 1;
          break;
        }
      }
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}