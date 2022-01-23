#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n & 1) {
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          if (i + n / 2 >= j) {
            cout << 1 << ' ';
          }
          else {
            cout << -1 << ' ';
          }
        }
      }
      cout << '\n';
    }
    else {
      vector<vector<int>> ans(n, vector<int> (n, 0));
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < i + n / 2; j++) {
          int k = j % n;
          ans[i][k] = 1;
          ans[k][i] = -1;
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          cout << ans[i][j] << ' ';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}