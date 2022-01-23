#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    sum /= n;
    for (int i = 1; i <= n; i++) {
      ans += a[i] > sum;
    }
    cout << ans << '\n';
  }
  return 0;
}