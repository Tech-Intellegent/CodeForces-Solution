#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> get_frac(ll p, ll q) {
  vector<ll> a;
  while (q) {
    a.push_back(p / q);
    p %= q; swap(p, q);
  }
  return a;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll p, q; cin >> p >> q;
  int n; cin >> n;
  vector<ll> b(n);
  for (int i = 0; i < n; i++) cin >> b[i];
  if (b[n - 1] == 1 and n > 1) {
    b.pop_back();
    b.back()++;
  }
  if (get_frac(p, q) == b) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
  return 0;
}