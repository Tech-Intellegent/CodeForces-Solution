#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int mn = 2e9, id = 1;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      if (k < mn) {
        mn = k; id = i;
      }
    }
    vector<array<int, 4>> v;
    if (id != 1) {
      v.push_back({1, id, mn, mn});
    }
    for (int i = 2; i <= n; i++) {
      int x = mn, y = mn + 1;
      if (i & 1) y = mn;
      v.push_back({1, i, x, y});
    }
    cout << v.size() << '\n';
    for (auto [i, j, x, y]: v) {
      cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
    }
  }
  return 0;
}