#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int dp[N][N], d[N], a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l, K; cin >> n >> l >> K;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  d[n + 1] = l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n + 1; i++) {
    dp[i][0] = dp[i - 1][0] + a[i - 1] * (d[i] - d[i - 1]);
    for (int k = 1; k <= K; k++) {
      dp[i][k] = dp[i][k - 1];
      int w = k;
      for (int j = i - 1; j >= 1; j--) {
        dp[i][k] = min(dp[i][k], dp[j][w] + a[j] * (d[i] - d[j]));
        w--;
        if (w < 0) break;
      }
    }
  }
  cout << dp[n + 1][K] << '\n';
  return 0;
}