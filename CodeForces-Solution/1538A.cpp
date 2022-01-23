#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      a[k] = i;
    }
    if (a[1] > a[n]) swap(a[1], a[n]);
    cout << min({a[n], n - a[1] + 1, a[1] + n - a[n] + 1}) << '\n';
  }
  return 0;
}