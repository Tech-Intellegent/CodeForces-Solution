#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
      ans += abs(a[i] - a[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
        ans -= a[i] - max(a[i - 1], a[i + 1]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}