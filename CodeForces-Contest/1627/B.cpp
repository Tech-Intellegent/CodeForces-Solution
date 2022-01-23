#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int cur = abs(i - 1) + abs(j - 1);
        cur = max(cur, abs(i - 1) + abs(j - m));
        cur = max(cur, abs(i - n) + abs(j - 1));
        cur = max(cur, abs(i - n) + abs(j - m));
        ans.push_back(cur);
      }
    }
    sort(ans.begin(), ans.end());
    for (auto x: ans) cout << x << ' '; cout << '\n';
  }
  return 0;
}