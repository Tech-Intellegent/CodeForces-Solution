#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

vector<int> d[N];
int a[N], dp[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      d[j].push_back(i);
    }
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      a[k]++;
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
      dp[i] = a[i];
      for (auto x: d[i]) {
        dp[i] = max(dp[i], dp[x] + a[i]);
      }
      ans = max(ans, dp[i]);
    }
    cout << n - ans << '\n';
    memset(a, 0, sizeof a);
    memset(dp, 0, sizeof dp);
  }
  return 0;
}