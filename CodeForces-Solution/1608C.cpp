#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i][0];
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i][1];
      a[i][2] = i;
    }
    sort(a.begin() + 1, a.end());
    vector<int> ans(n + 1, 0);
    int mn = a[n][1], l = n;
    ans[a[n][2]] = 1;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i][1] >= mn) {
        l = i;
      }
      mn = min(mn, a[i][1]);
    }
    for (int i = l; i <= n; i++) {
      ans[a[i][2]] = 1;
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}