#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
string s[N];
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (i and j and s[i - 1][j] == 'X' and s[i][j - 1] == 'X') {
        a[j] = 1;
      }
    }
  }
  for (int i = 1; i < m; i++) {
    a[i] += a[i - 1];
  }
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    if (a[r - 1] - a[l - 1]) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
  return 0;
}