#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, K = 512;
bitset<K> dp[K];
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < K; i++) {
    dp[i][0] = true;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < K; j++) {
      if (dp[a[i] + 1][j]) dp[a[i]][j ^ a[i]] = true;
    }
    for (int j = a[i] - 1; j >= 0; j--) {
      dp[j] |= dp[a[i]];
    }
  }
  cout << dp[0].count() << '\n';
  for (int i = 0; i < K; i++) {
    if (dp[0][i]) {
      cout << i << ' ';
    }
  }
  return 0;
}