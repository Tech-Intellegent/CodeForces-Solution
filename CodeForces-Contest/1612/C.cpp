#include<bits/stdc++.h>
using namespace std;

#define int long long

int sum(int l, int r) {
  if (l > r) return 0;
  return r * (r + 1) / 2 - l * (l - 1) / 2;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;
    int l = 1, r = 2 * n - 1, ans = 2 * n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int cur = 0;
      if (mid <= n) {
        cur = sum(1, mid);
      }
      else {
        cur = sum(1, n) + sum(n - mid + n, n - 1);
      }
      if (cur >= x) {
        ans = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}