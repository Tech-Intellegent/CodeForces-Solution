#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    int sum = 0;
    for (auto &k: a) {
      cin >> k;
      sum += k;
    }
    if (sum == x) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < n; i++) {
      x -= a[i];
      if (x == 0) {
        swap(a[i], a[i + 1]);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}