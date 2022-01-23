#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 998244353;
using ll = long long;

int n;
ll pref[N], alt[2][N], a[N];
int yo(int l, int r, int f1, int f2) {
  if (l >= r) return 0;
  if ((r - l + 1) & 1) return 0;
  if (l <= 2 and f1) return 0;
  if (r >= n - 2 and f2) return 0;
  ll cur = -pref[l - 1];
  if (f1) cur += 2 * a[1];
  cur += pref[n] - pref[r];
  if (f2) cur -= 2 * a[n];
  ll z = pref[r] - pref[l - 1];
  z -= 2 * (alt[1][r] - alt[0][l]);
  cur += z;
  return cur > 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
      alt[1][i] = alt[0][i - 1] + a[i];
      alt[0][i] = alt[1][i - 1];
    }
    if (n <= 3) {
      int ans = 0;
      for (int mask = 0; mask < (1 << n); mask++) {
        ll cur = 0;
        for (int i = 0; i < n; i++) {
          if (mask >> i & 1) cur += a[i + 1];
          else cur -= a[i + 1];
        }
        ans += cur > 0;
      }
      cout << ans << '\n';
      continue;
    }
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
      // C C* PC (PC)* P* (C|0)
      for (int j = 0; j < 2; j++) {
        int l = 1, r = (n - i + 1) / 2, cur = 0;
        while (l <= r) {
          int mid = l + r >> 1;
          if (yo(i, i + mid * 2 - 1, 0, j)) {
            cur = mid; l = mid + 1;
          }
          else {
            r = mid - 1;
          }
        }
        ans += cur;
      }
    }
    for (int i = 3; i <= n; i++) {
      // PC C* PC (PC)* P* (C|0)
      for (int j = 0; j < 2; j++) {
        int l = 1, r = (n - i + 1) / 2, cur = 0;
        while (l <= r) {
          int mid = l + r >> 1;
          if (yo(i, i + mid * 2 - 1, 1, j)) {
            cur = mid; l = mid + 1;
          }
          else {
            r = mid - 1;
          }
        }
        ans += cur;
      }
    }
    ans++; // P*
    for (int i = 1; i + 1 <= n; i++) {
      // P P* C* C
      if (pref[i] > pref[n] - pref[i]) ++ans;
    }
    for (int i = 1; i + 1 <= n; i++) {
      // C C* P* P
      if (pref[i] < pref[n] - pref[i]) ++ans;
    }
    for (int i = 3; i <= n; i++) {
      // PC C* P* P
      if (pref[n] - pref[i - 1] + a[1] > pref[i - 1] - a[1]) ++ans;
    }
    for (int i = 2; i + 2 <= n; i++) {
      // C C* PPC
      if (pref[i - 1] + a[n] < pref[n - 1] - pref[i - 1]) {
        ++ans;
      }
    }    
    for (int i = 3; i + 2 <= n; i++) {
      // PC C* PPC
      if (pref[i - 1] + a[n] - a[1] < pref[n - 1] - pref[i - 1] + a[1]) {
        ++ans;
      }
    }
    cout << ans % mod << '\n';
  }
  return 0;
}