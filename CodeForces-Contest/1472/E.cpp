#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<array<int, 3>> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1];
      a[i][2] = i + 1;
      b[i] = a[i];
    }
    vector<int> ans(n + 1, -1);
    sort(a.begin(), a.end());
    function<void(vector<array<int, 3>>)> f = [&](vector<array<int, 3>> b) {
      sort(b.begin(), b.end());
      int k = 0, mn = 2e9, id = -1;
      for (int i = 0; i < n; i++) {
        while (k < n && a[k][0] < b[i][0]) {
          if (a[k][1] < mn) {
            mn = a[k][1]; id = a[k][2];
          }
          ++k;
        }
        if (mn < b[i][1]) {
          ans[b[i][2]] = id;
        }
      }
    };
    f(b);
    for (int i = 0; i < n; i++) {
      swap(b[i][0], b[i][1]);
    }
    f(b);
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}