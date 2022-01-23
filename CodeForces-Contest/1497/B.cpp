#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> a(m, 0);
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      a[k % m]++;
    }
    int ans = a[0] > 0;
    for (int i = 1; i * 2 <= m; i++) {
      if (i == m - i) {
        if (a[i]) ++ans;
      }
      else {
        if (a[i] or a[m - i]) {
          int cur = max(0, a[i] + a[m - i] - min(a[i], a[m - i]) * 2 - 1);
          ans += 1 + cur;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}