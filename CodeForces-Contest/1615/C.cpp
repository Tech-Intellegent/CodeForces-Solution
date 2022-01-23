#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    if (a == b) {
      cout << 0 << '\n';
      continue;
    }
    int cnt = 0;
    vector<int> c(2, 0), d(2, 0);
    for (int i = 0; i < n; i++) {
      cnt += a[i] != b[i];
      c[a[i] - '0']++;
      d[b[i] - '0']++;
    }
    int ans = n + 1;
    if (cnt % 2 == 0 and c[0] == d[0] and c[1] == d[1]) {
      ans = cnt;
    }
    if ((n - cnt) % 2 == 1 and d[1] == c[0] + 1 and d[0] == c[1] - 1) {
      ans = min(ans, n - cnt);
    }
    if (ans == n + 1) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}