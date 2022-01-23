#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ok = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      sum += k;
      if (sum >= i) {
        sum -= i;
      }
      else {
        ok = 0;
      }
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}