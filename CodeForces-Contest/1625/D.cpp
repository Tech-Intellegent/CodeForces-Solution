#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int t[N * 30][2], cnt = 1;
pair<int, int> dp[N * 30];
int par[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; int k; cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = {x, i};
  }
  for (int i = 0; i < N * 30; i++) {
    dp[i] = {0, -1};
  }
  sort(a.begin(), a.end());
  pair<int, int> res = {0, -1}; int z = 0;
  for (auto [x, id]: a) {
    pair<int, int> ans = {0, -1};
    int cur = 1;
    for (int i = 30; i >= 0; i--) {
      int bx = x >> i & 1, bk = k >> i & 1;
      if (!bk) {
        ans = max(ans, dp[t[cur][bx ^ 1]]);
      }
      cur = t[cur][bx ^ bk];
      if (cur == 0) break;
    }
    ans = max(ans, dp[cur]);
    par[z] = ans.second;
    ans.first++;
    ans.second = z;
    cur = 1;
    for (int i = 30; i >= 0; i--) {
      int bx = x >> i & 1;
      if (!t[cur][bx]) {
        t[cur][bx] = ++cnt;
      }
      dp[cur] = max(dp[cur], ans);
      cur = t[cur][bx];
    }
    dp[cur] = max(dp[cur], ans);
    res = max(res, ans);
    z++;
  }
  if (res.first < 2) {
    cout << -1 << '\n';
    return 0;
  }
  cout << res.first << '\n';
  int cur = res.second;
  while (cur != -1) {
    cout << a[cur].second + 1 << ' ';
    cur = par[cur];
  }
  return 0;
}