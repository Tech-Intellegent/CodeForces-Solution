#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> p(n), w(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      w[i] = i + 1;
    }
    int ans;
    if (p == w) ans = 0;
    else if (p[0] == 1 or p[n - 1] == n) {
      ans = 1;
    }
    else if (p[0] == n and p[n - 1] == 1) {
      ans = 3;
    }
    else {
      ans = 2;
    }
    cout << ans << '\n';
  }
  return 0;
}