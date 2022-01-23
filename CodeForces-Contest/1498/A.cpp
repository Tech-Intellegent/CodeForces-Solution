#include<bits/stdc++.h>
using namespace std;

long long f(long long n) {
  long long k = n, sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return __gcd(k, sum);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    while (f(n) == 1) ++n;
    cout << n << '\n';
  }
  return 0;
}