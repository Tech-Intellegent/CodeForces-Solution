#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = i; j < n and cur < m; j++) {
        if (a[j] != b[cur]) break;
        int x = ++cur;
        for (int k = j - 1; k >= 0 and x < m; k--) {
          if (a[k] != b[x]) break;
          ++x;
        }
        if (x == m) {
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}