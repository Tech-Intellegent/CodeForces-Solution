#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll l, r; cin >> l >> r;
  int ans = 0;
  for (int i = 2; i < 61; i++) {
    for (int j = 0; j < i - 1; j++) {
      ll cur = ((1LL << i) - 1) ^ (1LL << j);
      ans += cur >= l and cur <= r;
    }
  }
  cout << ans << '\n';
  return 0;
}