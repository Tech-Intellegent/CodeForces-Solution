#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; ll k, x; cin >> n >> k >> x;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  vector<ll> v;
  ll ans = 1;
  for (int i = 2; i <= n; i++) {
    ll d = a[i] - a[i - 1];
    if (d > x) {
      ++ans;
      v.push_back((d - 1) / x);
    }
  }
  sort(v.begin(), v.end());
  for (auto p: v) {
    if (p <= k) {
      k -= p;
      --ans;
    }
  }
  cout << ans << '\n';
  return 0;
}