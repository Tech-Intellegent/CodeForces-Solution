#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    long long a, b; cin >> a >> b;
    if (b == 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (b == 2) {
      cout << a << ' ' << 3 * a << ' ' << 4 * a << '\n';
      continue;
    }
    cout << a << ' ' << a * (b - 1) << ' ' << a * b << '\n';
  }
  return 0;
}