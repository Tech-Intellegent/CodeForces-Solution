#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    bitset<202> bs;
    bs[0] = 1; int sum = 0;
    while (n--) {
      int k; cin >> k;
      sum += k;
      bs |= bs << k;
    }
    if (sum % 2 == 0 && bs[sum / 2]) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}