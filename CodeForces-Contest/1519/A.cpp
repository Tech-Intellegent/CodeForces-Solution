#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int r, b, d; cin >> r >> b >> d;
    if (r < b) swap(r, b);
    int k = r - b;
    if ((k + b - 1) / b <= d) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}