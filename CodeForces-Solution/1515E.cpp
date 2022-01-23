#include<bits/stdc++.h>
using namespace std;

const int N = 405;
int n, mod, dp[N][N], c[N][N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> mod;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  dp[0][0] = 1;
  dp[1][1] = 1;
  dp[2][2] = 2; int x = n;
  for (int n = 3; n <= x; n++) {
    for (int k = 1; k <= n; k++) {
      int ans = 2 * dp[n - 1][k - 1] % mod;
      ans += 2 * dp[n - 2][k - 1] % mod; ans %= mod;
      for (int i = 2; i <= n - 2; i++) {
        for (int j = 1; j <= min(k - 1, i - 1); j++) {
          ans += 2LL * dp[i - 1][j] * dp[n - i - 1][k - j - 1] % mod * c[k - 1][j] % mod;
          ans %= mod;
        }
        ans %= mod;
      }      
      for (int i = 3; i <= n - 2; i++) {
        for (int j = 1; j <= min(k - 1, i - 2); j++) {
          ans += 1LL * dp[i - 2][j] * dp[n - i - 1][k - j - 1] % mod * c[k - 1][j] % mod;
          ans %= mod;
        }
        ans %= mod;
      }
      dp[n][k] = ans;
    } 
  }
  int ans = 0;
  for (int k = 1; k <= n; k++) {
    ans += dp[n][k];
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}