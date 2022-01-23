#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) {
      cin >> x;
    }
    int ans = -1;
    while (k--) {
      bool f = 0;
      for (int i = 0; i + 1 < n; i++) {
        if (a[i] < a[i + 1]) {
          ans = i + 1;
          f = 1;
          ++a[i];
          break;
        }
      }
      if (!f) {
        ans = -1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}