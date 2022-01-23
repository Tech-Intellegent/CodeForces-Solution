#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];
int solve(int x) {
  if (x < 0) return N * 10;
  if (x == 0) return 1;
  int l = __lg(x);
  if ((1 << l) == x) return 0;
  return (1 << l + 1) - x;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      a[k]++;
    }
    for (int i = 1; i <= n; i++) {
      a[i] += a[i - 1];
    }
    int ans = N * 10;
    set<int> se;
    se.insert(0);
    for (int i = 1; i <= n; i++) {
      for (int k = 0; (1 << k) <= 2 * a[i]; k++) {
        auto it = se.upper_bound((1 << k));
        --it;
        int cur = solve(*it) + solve(a[i] - (*it)) + solve(a[n] - a[i]);
        ans = min(ans, cur);
        it = se.lower_bound(a[i] - (1 << k));
        if (it == se.end()) continue;
        cur = solve(*it) + solve(a[i] - (*it)) + solve(a[n] - a[i]);
        ans = min(ans, cur);
      }
      se.insert(a[i]);
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      a[i] = 0;
    }
  }
  return 0;
}