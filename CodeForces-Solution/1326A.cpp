#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    cout << "2" + string(n - 1, '9') << '\n';
  }
  return 0;
}