#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      if (x > 0) {
        a.push_back(x);
      }
      else if (x < 0) {
        b.push_back(-x);
      }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    long long ans = 0;
    for (int i = 0; i < a.size(); i += k) {
      ans += 2 * a[i];
    }
    for (int i = 0; i < b.size(); i += k) {
      ans += 2 * b[i];
    }
    ans -= max((!a.empty() ? a[0] : 0), (!b.empty() ? b[0] : 0));
    cout << ans << '\n';
  }
  return 0;
}