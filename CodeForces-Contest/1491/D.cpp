#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int u, v; cin >> u >> v;
    if (u <= v && __builtin_popcount(u) >= __builtin_popcount(v)) {
      int ok = 1, cnt = 0;
      for (int i = 0; i < 30; i++) {
        cnt += u >> i & 1;
        cnt -= v >> i & 1;
        if (cnt < 0) {
          ok = 0;
        }
      }
      if (ok) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}