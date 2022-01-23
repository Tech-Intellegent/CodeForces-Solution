#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
long long a[N], b[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      for (int i = 1; i <= n; i++) {
        b[i] = 0;
      }
      for (int i = n; i >= 3; i--) {
        if (b[i] + a[i] < mid) continue;
        long long left = min(a[i], b[i] + a[i] - mid);
        left /= 3;
        b[i - 1] += left;
        b[i - 2] += 2 * left;
        b[i] -= 3 * left;
      }
      bool ok = true;
      for (int i = 1; i <= n; i++) {
        if (b[i] + a[i] < mid) {
          ok = false;
        }
      }
      if (ok) {
        ans = mid; l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}