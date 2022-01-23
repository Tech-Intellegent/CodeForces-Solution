#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(200, 0);
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      a[k]++;
    }
    for (int i = 0; i <= 100; i++) {
      if (a[i]) {
        cout << i << ' ';
        a[i]--;
      }
    }
    for (int i = 0; i <= 100; i++) {
      while (a[i]) {
        cout << i << ' ';
        a[i]--;
      }
    }
    cout << '\n';
  }
  return 0;
}