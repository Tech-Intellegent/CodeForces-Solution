#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int spf[N];
vector<int> primes;
void linear_sieve() {
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
  linear_sieve();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> a, b;
    for (int i = 1; i <= n; i++) {
      int k, cur = 1; cin >> k;
      while (k > 1) {
        int p = spf[k], z = 0;
        while (k % p == 0) {
          k /= p;
          z ^= 1;
        }
        if (z) {
          cur *= p;
        }
      }
      a[cur]++;
    }
    int ans = 0;
    for (auto x: a) {
      ans = max(ans, x.second);
      if (x.second % 2 == 0) {
        b[1] += x.second;
      }
      else {
        b[x.first] += x.second;
      }
    }
    int res = 0;
    for (auto x: b) {
      res = max(res, x.second);
    }
    int q; cin >> q;
    while (q--) {
      long long p; cin >> p;
      if (p == 0) cout << ans << '\n';
      else cout << res << '\n';
    }
  }
  return 0;
}