#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
using ll = long long;
ll dp[N][N], a[N], b[N];
ll yo(int l, int r) {
  if (l > r) return 0;
  if (l == r) return a[l] * b[l];
  ll &ret = dp[l][r];
  if (ret != -1) return ret;
  return ret = yo(l + 1, r - 1) + a[l] * b[r] + a[r] * b[l];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n; cin >> n;
  ll tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }  
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    tot += a[i] * b[i];
  }
  ll ans = tot;
  for (int i = 1; i <= n; i++) {
    ll cur = 0;
    for (int j = i; j <= n; j++) {
      cur += a[j] * b[j];
      ans = max(ans, tot - cur + yo(i, j));
    }
  }
  cout << ans << '\n';
  return 0;
}