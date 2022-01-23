#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, l, r, k; cin >> n >> l >> r >> k;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      if (x >= l and x <= r) {
        a.push_back(x);
      }
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (auto x: a) {
      if (k >= x) {
        ++ans;
        k -= x;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}