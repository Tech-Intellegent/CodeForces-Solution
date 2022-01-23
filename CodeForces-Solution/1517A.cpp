#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long cur = 2050;
  vector<long long> v;
  while (cur <= 1e18) {
    v.push_back(cur);
    cur *= 10;
  }
  reverse(v.begin(), v.end());
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    long long ans = 0;
    for (auto x: v) {
      ans += n / x;
      n %= x;
    }
    if (n != 0) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}