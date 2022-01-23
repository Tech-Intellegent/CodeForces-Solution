#include<bits/stdc++.h>
using namespace std;

int cur = -1;
string yo() {
  cur++;
  if (cur < 26) return string(1, char(cur + 'A'));
  return "A" + string(1, char(cur - 26 + 'A'));
}
string ans[55];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 1; i < k; i++) {
    ans[i] = yo();
  }
  for (int i = k; i <= n; i++) {
    string s; cin >> s;
    if (s[0] == 'Y') {
      ans[i] = yo();
    }
    else {
      ans[i] = ans[i - k + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}