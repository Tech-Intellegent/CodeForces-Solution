#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

vector<int> a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int m, k; cin >> m >> k;
    a[m].push_back(k);
  }
  double expected = -1.0;
  vector<int> ans;
  for (int x = 1; x <= 40; x++) {
    vector<pair<double, int>> v;
    for (int i = 1; i < N; i++) {
      if (a[i].empty()) continue;
      double sum = 0;
      for (auto k: a[i]) {
        sum += x <= k ? 1.0 : 1.0 * k / x;
      }
      v.push_back({sum, i});
    }
    if ((int)v.size() < x) break;
    sort(v.rbegin(), v.rend());
    double cur = 0;
    for (int i = 0; i < x; i++) {
      cur += v[i].first;
    }
    if (cur >= expected) {
      expected = cur;
      ans.clear();
      for (int i = 0; i < x; i++) {
        ans.push_back(v[i].second);
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto x: ans) cout << x << ' ';
  return 0;
}