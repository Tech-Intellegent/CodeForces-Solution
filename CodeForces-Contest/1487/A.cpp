#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n), cnt(200, 0);
    int mn = 200;
    for (auto &x: a) {
      cin >> x;
      mn = min(mn, x);
      cnt[x]++;
    }
    cout << n - cnt[mn] << '\n';
  }
  return 0;
}