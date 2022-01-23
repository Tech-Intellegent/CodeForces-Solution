#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int dp[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    if (i >= 2020) {
      dp[i] |= dp[i - 2020];
    }    
    if (i >= 2021) {
      dp[i] |= dp[i - 2021];
    }
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (dp[n]) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}