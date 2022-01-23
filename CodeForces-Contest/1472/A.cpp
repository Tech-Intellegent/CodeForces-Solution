#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, w, h; cin >> w >> h >> n;
    int a = 1, b = 1;
    while (w % 2 == 0) {
      w /= 2; a *= 2;
    }
    while (h % 2 == 0) {
      h /= 2; b *= 2;
    }
    if (1LL * a * b >= n) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}