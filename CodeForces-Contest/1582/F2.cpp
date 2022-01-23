#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, K = 1 << 13;
int dp[K];
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < K; i++) {
    dp[i] = -1;
  }
  dp[0] = K;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < K; j++) {
      if (dp[j] > a[i]) {
        dp[j ^ a[i]] = max(dp[j ^ a[i]], a[i]);
      }
    }
  }
  vector<int> v;
  for (int i = 0; i < K; i++) {
    if (dp[i] != -1) {
      v.push_back(i);
    }
  }
  cout << v.size() << '\n';
  for (auto x: v) {
    cout << x << ' ';
  }
  return 0;
}