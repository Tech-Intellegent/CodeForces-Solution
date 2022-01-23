#include<bits/stdc++.h>
using namespace std;

string s;
int n, ans;
int f(int i) {
  return s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'c';
}
void yo(int i, int add) {
  if (i - 2 >= 0 and f(i - 2)) ans += add;
  if (i - 1 >= 0 and i + 1 < n and f(i - 1)) ans += add;
  if (i + 2 < n and f(i)) ans += add;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q; cin >> n >> q;
  ans = 0;
  cin >> s;
  for (int i = 1; i < n - 1; i++) {
    ans += s[i - 1] == 'a' and s[i] == 'b' and s[i + 1] == 'c';
  }
  while (q--) {
    int i; char c; cin >> i >> c;
    --i;
    yo(i, -1);
    s[i] = c;
    yo(i, +1);
    cout << ans << '\n';
  }
  return 0;
}