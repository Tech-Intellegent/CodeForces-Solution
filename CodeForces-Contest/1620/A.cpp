#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    if (count(s.begin(), s.end(), 'N') == 1) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
  return 0;
}