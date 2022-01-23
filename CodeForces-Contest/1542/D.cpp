#include<bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;

int x[N], cur, curid, dp[2][N][N], n;
char ty[N];
int yo(int i, int c, int took) {
  if (i == n + 1) return 1;
  int &ret = dp[took][i][c];
  if (ret != -1) return ret;
  if (i == curid) {
    ret = yo(i + 1, c, 1);
    return ret;
  }
  ret = yo(i + 1, c, took);
  if (ty[i] == '+') {
    if (x[i] < cur or (x[i] == cur and i < curid)) {
      ret += yo(i + 1, c + 1, took);
    }
    else {
      ret += yo(i + 1, c, took);
    }
  }
  else {
    if (!(took and !c)) {
      ret += yo(i + 1, max(0, c - 1), took);
    }
  }
  if (ret >= mod) ret -= mod;
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ty[i];
    if (ty[i] == '+') cin >> x[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (ty[i] == '-') continue;
    memset(dp, -1, sizeof dp);
    cur = x[i]; curid = i;
    ans += 1LL * yo(1, 0, 0) * x[i] % mod;
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}