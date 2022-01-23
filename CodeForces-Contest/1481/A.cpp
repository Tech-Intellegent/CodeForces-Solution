#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    map<char, int> mp;
    string s; cin >> s;
    for (auto x: s) {
      mp[x]++;
    }
    if (((x >= 0 && mp['R'] >= x) || (x < 0 && mp['L'] >= -x)) && ((y >= 0 && mp['U'] >= y) 
      || (y < 0 && mp['D'] >= -y))) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}