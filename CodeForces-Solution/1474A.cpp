#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int last = -1;
    for (int i = 0; i < n; i++) {
      int k = s[i] - '0';
      if (k + 1 != last) {
        cout << 1;
        last = k + 1;
      }
      else {
        cout << 0;
        last = k;
      }
    } 
    cout << '\n';
  }
  return 0;
}