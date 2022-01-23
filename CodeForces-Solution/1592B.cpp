#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    b = a;
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (i - k < 0 and i + k >= n) {
        ok &= a[i] == b[i];
      }
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