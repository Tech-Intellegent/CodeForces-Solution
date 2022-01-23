#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<vector<int>> ans;
  vector<int> cnt(k + 1, 0);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  vector<int> l(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> l[i];
  }
  for (int i = k; i >= 1; i--) {
    int L = 0, R = (int)ans.size() - 1, f = ans.size();
    while (L <= R) {
      int mid = L + R >> 1;
      if (ans[mid].size() < l[i]) {
        f = mid;
        R = mid - 1;
      }
      else {
        L = mid + 1;
      }
    }
    for (int j = f; j < ans.size(); j++) {
      if (!cnt[i]) break;
      while (ans[j].size() < l[i] and cnt[i]) {
        ans[j].push_back(i);
        cnt[i]--;
      }
    }
    while (cnt[i] > 0) {
      ans.emplace_back();
      while (ans.back().size() < l[i] and cnt[i]) {
        ans.back().push_back(i);
        cnt[i]--;
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto x: ans) {
    cout << x.size() << ' ';
    for (auto y: x) {
      cout << y << ' ';
    }
    cout << '\n';
  }
  return 0;
}