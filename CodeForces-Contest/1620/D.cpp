#include<bits/stdc++.h>
using namespace std;

int cnt[4], n, a[105];
int ans;
void dfs(int x) {
  if (x == 4) {
    if (cnt[1] < 0 or cnt[2] < 0 or cnt[3] < 0) return;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      int cur = a[i];
      bool f = false;
      for (int one = 0; one <= cnt[1] and !f; one++) {
        for (int two = 0; two <= cnt[2] and !f; two++) {
          int w = one + two * 2;
          if (cur >= w and (cur - w) % 3 == 0 and (cur - w) / 3 <= cnt[3]) {
            f = true;
          }
        }
      }
      if (!f) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = min(ans, cnt[1] + cnt[2] + cnt[3]);
    }
    return;
  }
  int l = 0, r = 3;
  if (x == 3) l = -1, r = 0;
  for (int k = l; k <= r; k++) {
    cnt[x] += k;
    dfs(x + 1);
    cnt[x] -= k;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    cnt[1] = cnt[2] = 0;
    cnt[3] = mx / 3;
    ans = 2e9;
    dfs(1);
    cout << ans << '\n';
  }
  return 0;
}