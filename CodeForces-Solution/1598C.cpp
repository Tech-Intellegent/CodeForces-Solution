#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sum *= 2;
    ll ans = 0;
    if (sum % n == 0) {
      sum /= n;
      map<ll, int> mp;
      for (int i = 1; i <= n; i++) {
        ans += mp[sum - a[i]];
        mp[a[i]]++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}