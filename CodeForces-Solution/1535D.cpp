#include<bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
int dp[N], a[N];
inline int merge(int &x, int &y, char c) {
  if (c == '?') return x + y;
  else if (c == '0') return x;
  else return y;
}
int get_id(int k) {
  return a[k];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k; cin >> k;
  int n = 1 << k;
  for (int i = 0, l = 1, r = n - 1; i < k; i++) {
    for (int p = 1; p <= (1 << i); p++) {
      a[r - (1 << i) + p] = l;
      l++;
    }
    r -= 1 << i;
  }
  string p; cin >> p;
  p = "0" + p;
  string s = p;
  for (int i = 1; i < n; i++) {
    s[get_id(i)] = p[i];
  }
  for (int i = n; i <= 2 * n; i++) dp[i] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = merge(dp[i << 1], dp[i << 1 | 1], s[i]);
  }
  int q; cin >> q;
  while (q--) {
    int k; char c; cin >> k >> c;
    k = get_id(k);
    s[k] = c;
    for (int i = k; i; i >>= 1) {
      dp[i] = merge(dp[i << 1], dp[i << 1 | 1], s[i]);
    }
    cout << dp[1] << '\n';
  }
  return 0;
}