#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<string> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = string(n, '.');
      for (int j = 0; j < n; j++) {
        if (i == j and i % 2 == 0 and k) {
          ans[i][j] = 'R';
          --k;
        }
      }
    }
    if (k) {
      cout << -1 << '\n';
    }
    else {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
      }
    }
  }
  return 0;
}