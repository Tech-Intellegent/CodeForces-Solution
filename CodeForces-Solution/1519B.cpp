#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    if (k == n * m - 1) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}