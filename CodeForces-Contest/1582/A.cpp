#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    long long a, b, c; cin >> a >> b >> c;
    cout << (a + b * 2 + c * 3) % 2 << '\n';
  }
  return 0;
}