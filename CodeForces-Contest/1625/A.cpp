#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int j = 0; j < k; j++) {
      int x = 0;
      for (int i = 0; i < n; i++) {
        x += a[i] >> j & 1;
      }
      if (x * 2 >= n) ans += 1 << j;
    }
    cout << ans << '\n';
  }
  return 0;
}