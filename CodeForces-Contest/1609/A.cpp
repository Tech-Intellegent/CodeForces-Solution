#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long cur = 1;
    for (int i = 0; i < n; i++) {
      while (a[i] % 2 == 0) {
        a[i] /= 2;
        cur *= 2;
      }
    }
    sort(a.begin(), a.end());
    a[n - 1] *= cur;
    long long ans = 0;
    for (auto x: a) {
      ans += x;
    }
    cout << ans << '\n';
  }
  return 0;
}