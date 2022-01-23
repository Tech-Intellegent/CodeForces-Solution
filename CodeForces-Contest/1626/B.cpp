#include<bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  for (int i = n - 2; i >= 0; i--) {
    int sum = s[i] - '0' + s[i + 1] - '0';
    if (sum >= 10) {
      cout << s.substr(0, i) << sum << s.substr(i + 2) << '\n';
      return;
    }
  }
  cout << (s[0] - '0' + s[1] - '0') << s.substr(2) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}