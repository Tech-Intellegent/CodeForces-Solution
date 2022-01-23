#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll pw[20], pref[20], cost[20];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < 20; i++) {
    pw[i] = pw[i - 1] * 10;
  }
  int t; cin >> t;
  while (t--) {
    int n, w; cin >> n >> w;
    vector<int> f(20, 0);
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      f[x] = 1;
    }
    int last = 0;
    for (int i = 0; i < 20; i++) {
      if (f[i]) last = i;
      cost[i] = pw[i - last];
    }
    pref[0] = 9;
    for (int i = 1; i < 20; i++) {
      pref[i] = pref[i - 1] + cost[i] * 9;
    }
    ll ans = 0, cur = 0;
    for (int i = 18; i >= 0; i--) {
      for (int k = 0; k <= 9; k++) {
        ll z = cur + cost[i] * k + (i ? pref[i - 1] : 0);
        if (z > w) {
          ans += k * pw[i];
          cur += cost[i] * k;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}