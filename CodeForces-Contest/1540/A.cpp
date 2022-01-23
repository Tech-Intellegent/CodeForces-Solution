#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      if (i) ans += a[i] - a[i - 1];
      ans -= 1LL * i * a[i] - sum;
      sum += a[i];
    }
    cout << ans << '\n';
  }
  return 0;
}