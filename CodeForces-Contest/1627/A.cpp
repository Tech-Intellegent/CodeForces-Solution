#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, r, c; cin >> n >> m >> r >> c;
    bool ok = false, already = false;
    int black = 0;
    for (int i = 1; i <= n; i++) {
      string s; cin >> s;
      for (int j = 1; j <= m; j++) {
        if (s[j - 1] == 'B') {
          ++black;
          ok |= i == r or j == c;
          already |= i == r and j == c;
        }
      }
    }
    if (already) {
      cout << 0 << '\n';
    }
    else if (black == 0) {
      cout << -1 << '\n';
    }
    else if (ok) {
      cout << 1 << '\n';
    }
    else {
      cout << 2 << '\n';
    }
  }
  return 0;
}