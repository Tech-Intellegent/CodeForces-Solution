#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
string s[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    if (m & 1) {
      cout << "YES\n";
      for (int i = 0; i <= m; i++) {
        cout << i % 2 + 1 << ' ';
      }
      cout << '\n';
      continue;
    }
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (s[i][j] == s[j][i]) {
          cout << "YES\n";
          for (int k = 0; k <= m; k++) {
            cout << (k & 1 ? i + 1 : j + 1) << ' ';
          }
          cout << '\n';
          ok = 1;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    if (ok) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      map<char, int> id;
      for (int j = 0; j < n; j++) {
        if (i != j) {
          id[s[j][i]] = j;
        }
      }
      for (int k = 0; k < n; k++) {
        if (i != k) {
          if (id.find(s[i][k]) != id.end()) {
            int j = id[s[i][k]];
            ok = 1;
            cout << "YES\n";
            map<int, int> a, b;
            b[0] = i + 1; b[1] = k + 1;
            if ((m / 2) & 1) {
              a[0] = j + 1; a[1] = i + 1;
            }
            else {
              a[0] = i + 1; a[1] = j + 1;
            }
            for (int i = 0; i < (m / 2); i++) {
              cout << a[i & 1] << ' ';
            }
            for (int i = 0; i <= (m / 2); i++) {
              cout << b[i & 1] << ' ';
            }
            cout << '\n';
            break;
          }
        }
      }
      if (ok) {
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
    }
  }
  return 0;
}