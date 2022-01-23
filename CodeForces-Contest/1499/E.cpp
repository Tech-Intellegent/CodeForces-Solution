#include<bits/stdc++.h>
using namespace std;

const int N = 1002, mod = 998244353;
string a, b;
int n, m, dp[27][N][N];
int yo(int i, int j, int k, int x, int y) {
  int &ret = dp[k][i][j];
  if (x >= 1 and y >= 1 and ret != -1) return ret;
  int ans = x >= 1 and y >= 1;
  if (i < n and a[i] - 'a' != k) ans += yo(i + 1, j, a[i] - 'a', 1, y);
  if (j < m and b[j] - 'a' != k) ans += yo(i, j + 1, b[j] - 'a', x, 1);
  if (ans >= mod) ans -= mod;
  if (x >= 1 and y >= 1) ret = ans;
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  n = a.size(); m = b.size();
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += yo(i, j, 26, 0, 0);
      ans %= mod;
    }
  }
  cout << ans << '\n';
  return 0;
}