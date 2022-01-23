#include<bits/stdc++.h>
using namespace std;

int a[200020];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, l, r; cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += upper_bound(a + i + 1, a + n + 1, r - a[i]) - lower_bound(a + i + 1, a + n + 1, l - a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}