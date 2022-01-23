#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<string> a(n), b(n), c(n);
    int okb = 1, okc = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = c[i] = a[i];
      for (int j = 0; j < m; j++) {
        b[i][j] = (i + j) & 1 ? 'R' : 'W';
        c[i][j] = (i + j) & 1 ? 'W' : 'R';
        if (a[i][j] != '.') {
          if (a[i][j] != b[i][j]) {
            okb = 0;
          }          
          if (a[i][j] != c[i][j]) {
            okc = 0;
          }
        }
      }
    }
    if (okb) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << b[i] << '\n';
      }
    }    
    else if (okc) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << c[i] << '\n';
      }
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}