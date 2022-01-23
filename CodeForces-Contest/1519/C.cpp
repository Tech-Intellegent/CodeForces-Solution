#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> b(n + 1);
    vector<long long> ans(n + 1, 0);
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      a[k].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      vector<long long> v;
      for (auto x: a[i]) {
        v.push_back(b[x]);
      }
      sort(v.begin(), v.end());
      int sz = v.size();
      for (int i = 1; i < sz; i++) {
        v[i] += v[i - 1];
      }
      for (int k = 1; k <= sz; k++) {
        ans[k] += v.back() - (sz % k == 0 ? 0 : v[sz % k - 1]);
      }
    }
    for (int k = 1; k <= n; k++) {
      cout << ans[k] << ' ';
    }
    cout << '\n';
  }
  return 0;
}