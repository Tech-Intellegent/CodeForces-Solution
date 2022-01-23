#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    int bal = 0;
    for (int i = 1; i < n; i++) {
      bal += s[i - 1] != s[i];
    }
    if (bal & 1) s[n - 1] = s[n - 1] == 'a' ? 'b' : 'a';
    cout << s << '\n';
  }
  return 0;
}