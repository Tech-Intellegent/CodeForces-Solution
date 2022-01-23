#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N][20];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < N; i++) {
    for (int k = 0; k < 20; k++) {
      a[i][k] = a[i - 1][k] + (i >> k & 1);
    }
  }
  int t; cin >> t;
  while (t--) {
    int l, r; cin >> l >> r;
    int ans = r - l + 1;
    for (int k = 0; k < 20; k++) {
      ans = min(ans, (r - l + 1) - a[r][k] + a[l - 1][k]);
    }
    cout << ans << '\n';
  }
  return 0;
}