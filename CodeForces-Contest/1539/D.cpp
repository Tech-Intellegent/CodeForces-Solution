#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;

array<ll, 2> a[N], b[N];
int n;
bool yo(ll x) {
  ll cur = x;
  for (int i = n; i >= 1; i--) {
    if (a[i][1] <= x) {
      x -= a[i][1];
      b[i] = a[i];
      b[i][1] = 0;
    }
    else {
      b[i] = a[i];
      b[i][1] -= x;
      x = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (b[i][0] <= cur) {
      cur += b[i][1];
      b[i][1] = 0;
    }
    else {
      break;
    }
  }
  ll left = 0;
  for (int i = 1; i <= n; i++) {
    left += b[i][1];
  }
  return left == 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ll tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][0];
    tot += a[i][1];
  }
  sort(a + 1, a + n + 1);
  ll l = 0, r = tot, ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (yo(mid)) {
      ans = mid * 2 + tot - mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}