#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      cout << "? " << 1 << ' ' << n - 1 << '\n';
      cout << i << '\n';
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          cout << j << ' ';
        }
      }
      cout << '\n';
      cout.flush();
      int k; cin >> k;
      if (!k) {
        ans.push_back(i);
      }
    }
    cout << "! " << ans.size();
    for (auto x: ans) {
      cout << ' ' << x;
    }
    cout << '\n';
    cout.flush();
  }
  return 0;
}