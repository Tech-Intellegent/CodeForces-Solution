#include<bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int dp[2][N][N], n;
int yo(int i, int k, int dir) {
  if (i == 0 or i == n + 1) return 1;
  if (k == 1) return 1;
  int &ret = dp[dir][i][k];
  if (ret != -1) return ret;
  if (dir) {
    ret = yo(i + 1, k, dir) + yo(i - 1, k - 1, dir ^ 1);
  }
  else {
    ret = yo(i - 1, k, dir) + yo(i + 1, k - 1, dir ^ 1);
  }
  if (ret >= mod) ret -= mod;
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int k; cin >> n >> k;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        memset(dp[j][i], -1, sizeof dp[j][i]);
      }
    }
    cout << yo(1, k, 1) << '\n';
  }
  return 0;
}