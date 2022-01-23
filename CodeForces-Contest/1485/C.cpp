#include<bits/stdc++.h>
using namespace std;

long long yo(long long n, long long m) {
  long long ans = 0;
  for (long long i = 1, last; i <= min(n, m); i = last + 1) {
      last = n / (n / i);
      ans += (n / i) * (min(last, m) - i + 1);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    long long ans = 0;
    int i;
    for (i = 1; i <= b && i * i <= a; i++) {
      ans += i * i / (i + 1);
    }
    if (i <= b) {
      ans += yo(a, b + 1) - yo(a, i);
    }
    cout << ans << '\n';
  }
  return 0;
}