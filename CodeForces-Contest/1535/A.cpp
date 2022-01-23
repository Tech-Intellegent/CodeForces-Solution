#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
      cin >> a[i];
    }
    int x = max(a[0], a[1]), y = max(a[2], a[3]);
    sort(a.begin(), a.end());
    if (a[2] == x or a[2] == y) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}