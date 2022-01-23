#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

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
int nxt(int p) {
  while (spf[p] != p) {
    ++p;
  }
  return p;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  linear_sieve();
  int t; cin >> t;
  while (t--) {
    int d; cin >> d;
    int k = nxt(d + 1);
    cout << min(1LL * k * k * k, 1LL * k * nxt(k + d)) << '\n';
  }
  return 0;
}