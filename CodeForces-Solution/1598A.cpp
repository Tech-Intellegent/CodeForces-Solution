#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok &= a[i] == '0' or b[i] == '0';
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}