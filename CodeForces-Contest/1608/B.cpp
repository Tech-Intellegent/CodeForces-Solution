#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, x, y; cin >> n >> x >> y;
    deque<int> ans;
    for (int i = 1; i <= y; i++) {
      ans.push_back(2 * i);
      ans.push_back(2 * i - 1);
    }
    ans.push_back(2 * y + 1);
    if (2 * y + 1 <= n and x == y - 1) {
      for (int i = 2 * y + 2; i <= n; i++) {
        ans.push_back(i);
      }
    }
    else if (x == y and 2 * y + 2 <= n) {
      ans.back() = 2 * y + 2;
      ans.push_back(2 * y + 1);
      for (int i = 2 * y + 3; i <= n; i++) {
        ans.push_front(i);
      }
    }
    else if (2 * x + 1 <= n and x == y + 1) {
      ans.clear();
      for (int i = 1; i <= x; i++) {
        ans.push_back(2 * i);
        ans.push_back(2 * i - 1);
      }
      ans.push_back(2 * x + 1);
      for (int i = 0; i < 2 * x + 1; i++) {
        ans[i] = n - ans[i] + 1;
      }
      for (int i = n - 2 * x - 1; i >= 1; i--) {
        ans.push_front(i);
      }
    }
    else {
      ans.clear();
    }
    if (!ans.empty()) {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
    }
    else {
      cout << -1 << '\n';
    }
  }
  return 0;
}