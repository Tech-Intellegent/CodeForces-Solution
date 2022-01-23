#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
      cin >> x;
    }
    sort(a.begin(), a.end(), [&](int i, int j) {
      return i % 2 < j % 2;
    });
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans += __gcd(a[i], 2 * a[j]) > 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}