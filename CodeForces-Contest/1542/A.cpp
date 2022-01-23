#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
      int x; cin >> x;
      cnt += x & 1;
    }
    if (cnt == n) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
  return 0;
}