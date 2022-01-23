#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e7 + 9;
int cnt[N], d[N];
long long dp[N];
int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  for (int i = N - 1; i >= 1; i--) {
    for (int j = i; j < N; j += i) {
      d[i] += cnt[j];
    }
  }
  long long ans = 0;
  for (int i = N - 1; i >= 1; i--) {
    if (!d[i]) continue;
    dp[i] = max(dp[i], 1LL * i * d[i]);
    int n = i;
    while (n > 1) {
      int k = spf[n];
      int cur = 1;
      while (n % k == 0) {
        cur *= k;
        dp[i / cur] = max(dp[i / cur], dp[i] + 1LL * (d[i / cur] - d[i]) * (i / cur));
        n /= k;
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}