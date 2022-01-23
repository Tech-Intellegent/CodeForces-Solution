#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int u, v; cin >> u >> v;
    if (u <= v && __builtin_popcount(u) >= __builtin_popcount(v) && __builtin_ctz(u) <= __builtin_ctz(v)) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}