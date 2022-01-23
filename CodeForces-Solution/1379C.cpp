#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<array<int, 2>> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    vector<ll> sum(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) {
      sum[i] = sum[i + 1] + a[i][0];
    }
    ll ans = sum[max(0, m - n)];
    if (n >= 2) {
      for (int i = 0; i < m; i++) {
        ll cur = a[i][1] + a[i][0];
        int j = upper_bound(a.begin(), a.end(), array<int, 2>({a[i][1], -1})) - a.begin();
        int cnt = m - j - (j <= i);
        if (cnt >= n - 2) {
          cur += sum[m - (n - 2)];
          if (m - (n - 2) <= i) {
            cur -= a[i][0];
            cur += a[m - (n - 2) - 1][0];
          }
        }
        else {
          cur += sum[j];
          ll left = n - 2 - cnt;
          if (j <= i) cur -= a[i][0];
          cur += left * a[i][1];
        }
        // cout << i << ' ' << j << ' ' << cur << '\n';
        ans = max(ans, cur);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}