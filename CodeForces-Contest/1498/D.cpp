#include<bits/stdc++.h>
using namespace std;

long long mul(long long k, long long x) {
  k = (k * x + 100000 - 1) / 100000;
  return k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  const int inf = 10000;
  vector<int> dp(m + 1, inf);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    long long x; int ty, y; cin >> ty >> x >> y;
    vector<int> nxt = dp;
    if (ty == 1) {
      int p = (x + 100000 - 1) / 100000;
      for (int k = 0; k < p; k++) {
        int cnt = 0, sum = 0;
        for (int l = k; l <= m; l += p) {
          if (nxt[l] == inf and sum) nxt[l] = i;
          sum += dp[l] != inf;
          cnt++;
          if (cnt == y + 1) {
            sum -= dp[l - y * p] != inf;
            cnt--;
          }
        }
      }
    }
    else {
      for (int k = 0; k <= m; k++) {
        if (dp[k] != inf) {
          long long cur = k, cnt = 0;
          while (mul(cur, x) != cur and cnt + 1 <= y) {
            cur = mul(cur, x);
            if (cur > m) break;
            cnt++;
            if (nxt[cur] == inf) {
              nxt[cur] = i;
            }
            else break;
          }
        }
      }
    }
    dp = nxt;
  }
  for (int i = 1; i <= m; i++) {
    cout << (dp[i] == inf ? -1 : dp[i]) << ' ';
  }
  return 0;
}