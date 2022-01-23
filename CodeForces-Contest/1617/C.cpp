#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    multiset<int> se;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      se.insert(x);
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      if (se.find(i) != se.end()) {
        se.erase(se.find(i));
      }
      else {
        auto it = se.lower_bound(i * 2 + 1);
        if (it == se.end()) {
          ans = -1;
          break;
        }
        ++ans;
        se.erase(it);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}