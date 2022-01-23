#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, x; cin >> n >> m >> x;
    vector<array<int, 2>> a;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      a.push_back({k, i});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      ans[a[i][1]] = i % m;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}