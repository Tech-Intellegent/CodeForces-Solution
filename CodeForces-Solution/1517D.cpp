#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int dp[12][N][N], r[N][N], d[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, K; cin >> n >> m >> K;
  if (K & 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << -1 << ' ';
      }
      cout << '\n';
    }
    return 0;
  }
  K >>= 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      cin >> r[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> d[i][j];
    }
  }
  for (int k = 1; k <= K; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[k][i][j] = 1e9;
        for (int x = 0; x < 4; x++) {
          int ni = i + dx[x];
          int nj = j + dy[x];
          if (ni >= 1 and ni <= n and nj >= 1 and nj <= m) {
            int cost = 0;
            if (x == 0) cost = r[i][j];
            else if (x == 1) cost = r[ni][nj];
            else if (x == 2) cost = d[ni][nj];
            else cost = d[i][j];
            dp[k][i][j] = min(dp[k][i][j], dp[k - 1][ni][nj] + cost);
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << dp[K][i][j] * 2 << ' ';
    }
    cout << '\n';
  }
  return 0;
}