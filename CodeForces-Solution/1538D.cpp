#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

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
int yo(int n) {
  int cnt = 0;
  for (auto p: primes) {
    if (1LL * p * p > n) break;
    while (n % p == 0) {
      n /= p;
      ++cnt;
    }
  }
  if (n > 1) ++cnt;
  return cnt;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int t; cin >> t;
  while (t--) {
    int a, b, k; cin >> a >> b >> k;
    int n = __gcd(a, b);
    bool ok = false;
    int cnt = yo(n), x = yo(a / n), y = yo(b / n);
    int mn = (a > n) + (b > n);
    if (k >= mn and k <= x + y + cnt * 2) ok = true;
    if (k == 1 and a == b) ok = false;
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}