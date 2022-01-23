#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    bool ok = false;
    for (int k = 0; k <= n; k++) {
      if ((k and s[k - 1] == '1') and s[k] == '0') continue;
      bool cur = true;
      for (int i = 0; i + 1 < k; i++) {
        if (s[i] == '1' and s[i + 1] == '1') cur = false;
      }      
      for (int i = k; i + 1 < n; i++) {
        if (s[i] == '0' and s[i + 1] == '0') cur = false;
      }
      ok |= cur;
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}