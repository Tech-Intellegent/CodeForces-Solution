#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    long long n, k; cin >> n >> k;
    if (n % 2 == 0) {
      cout << (k - 1) % n + 1 << '\n';
    }
    else {
      long long l = 1, r = k * 5, ans = 1;
      while (l <= r) {
        long long mid = (l + r) / 2;
        long long x = mid - 1, cur = (x / ((n + 1) / 2 * n)) * n;
        x %= (n + 1) / 2 * n;
        if (x < n) {
          cur += x >= (n / 2);
        }
        else {
          x -= n;
          cur++;
          long long z = x / n;
          cur += z * 2;
          x %= n;
          cur += x >= z;
          cur += x >= (z + (n + 1) / 2);
        }
        if (mid - cur >= k) {
          ans = (mid - 1) % n + 1;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}