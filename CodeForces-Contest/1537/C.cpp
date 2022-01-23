#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cur = 1e9;
    for (int i = 1; i < n; i++) {
      cur = min(cur, a[i + 1] - a[i]);
    }
    for (int i = 1; i < n; i++) {
      if (cur == a[i + 1] - a[i]) {
        cout << a[i] << ' ';
        for (int j = i + 2; j <= n; j++) {
          cout << a[j] << ' ';
        }        
        for (int j = 1; j < i; j++) {
          cout << a[j] << ' ';
        }
        cout << a[i + 1] << '\n';
        break;
      }
    }
  }
  return 0;
}