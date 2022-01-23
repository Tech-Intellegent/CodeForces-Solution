#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int w, h; cin >> w >> h;
    vector<vector<int>> v(4);
    for (int i = 0; i < 4; i++) {
      int k; cin >> k;
      for (int j = 0; j < k; j++) {
        int x; cin >> x;
        v[i].push_back(x);
      }
    }
    long long ans = 1LL * (v[0].back() - v[0][0]) * h;
    ans = max(ans, 1LL * (v[1].back() - v[1][0]) * h);    
    ans = max(ans, 1LL * (v[2].back() - v[2][0]) * w);
    ans = max(ans, 1LL * (v[3].back() - v[3][0]) * w);
    cout << ans << '\n';
  }
  return 0;
}