#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    string w = s; reverse(w.begin(), w.end());
    string ans = s + w;
    ans = min(ans, string(2, s[0]));
    for (int i = 0; i + 1 < n; i++) {
      if (s[i] < s[i + 1]) {
        string a = s.substr(0, i + 1);
        string b = a; reverse(b.begin(), b.end());
        a += b;
        ans = min(ans, a);
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}