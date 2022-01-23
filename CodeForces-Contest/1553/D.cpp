#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<int> f(2, 0);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[0]) {
        if (f[i & 1]) continue;
        f[i & 1] = 1;
        int cur = 0, last = i - 1;
        for (int j = i; j < n and cur < m; j++) {
          if (a[j] == b[cur] and (j - last - 1) % 2 == 0) {
            ++cur;
            last = j;
          }
        }
        if (cur == m and (n - last - 1) % 2 == 0) {
          ok = true;
          break;
        }
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}