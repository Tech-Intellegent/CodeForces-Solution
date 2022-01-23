#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<long long> dp(n + 2, 0);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
      dp[i] = a[i] + dp[min(i + a[i], n + 1)];
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}