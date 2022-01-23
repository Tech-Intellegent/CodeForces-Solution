#include<bits/stdc++.h>
using namespace std;

bool yo(string a) {
  int bal = 0;
  for (auto x: a) {
    bal += x == '(' ? +1 : -1;
    if (bal < 0) return false;
  }
  return bal == 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    bool ans = false;
    for (int mask = 0; mask < (1 << 3); mask++) {
      string a = "";
      for (auto c: s) {
        if (mask >> (c - 'A') & 1) {
          a += '(';
        }
        else {
          a += ')';
        }
      }
      ans |= yo(a);
    }
    if (ans) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}