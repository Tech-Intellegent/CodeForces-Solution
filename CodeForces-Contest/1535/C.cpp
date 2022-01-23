#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int dp[N][2];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    s = "#" + s;
    dp[0][0] = dp[0][1] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '?') {
        dp[i][0] = max(0, dp[i - 1][1]) + 1;
        dp[i][1] = max(0, dp[i - 1][0]) + 1;
      }
      else {
        int k = s[i] - '0';
        dp[i][k] = max(0, dp[i - 1][!k]) + 1;
        dp[i][!k] = -2 * n;
      }
      ans += max(dp[i][0], dp[i][1]);
    }
    cout << ans << '\n';
  }
  return 0;
}