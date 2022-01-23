#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = count(s.begin(), s.end(), '0');
    if (cnt % 2 == 1 and cnt > 1) {
      cout << "ALICE\n";
    }
    else {
      cout << "BOB\n";
    }
  }
  return 0;
}