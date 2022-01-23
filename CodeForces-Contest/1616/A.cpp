#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> mp;
    while (n--) {
      int x; cin >> x;
      mp[abs(x)]++;
    }
    int ans = mp[0] ? 1 : 0;
    for (int i = 1; i <= 100; i++) {
      ans += min(mp[i], 2);
    }
    cout << ans << '\n';
  }
  return 0;
}