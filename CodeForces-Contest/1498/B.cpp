#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      mp[-x]++;
    }
    int ans = 0;
    while (n) {
      int z = k;
      for (auto [x, c]: mp) {
        while (z >= -x and c) {
          --n;
          z -= -x;
          c--;
        }
        mp[x] = c;
      }
      ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}