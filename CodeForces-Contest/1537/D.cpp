#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n & 1) cout << "Bob\n";
    else {
      if (n & (n - 1)) cout << "Alice\n";
      else {
        int i = 0;
        while ((1LL << i) < n) ++i;
        if (i & 1) cout << "Bob\n";
        else cout << "Alice\n";
      }
    }
  }
  return 0;
}