#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  string s; cin >> s;
  string ans = string(k, 'z');
  for (int i = 1; i <= n; i++) {
    string cur = s.substr(0, i);
    string res = string(k, 'z');
    int x = 0;
    for (int j = 0; j < k; j++) {
      res[j] = cur[x];
      ++x;
      if (x == i) x = 0;
    }
    if (res < ans) ans = res;
  }
  cout << ans << '\n';
  return 0;
}