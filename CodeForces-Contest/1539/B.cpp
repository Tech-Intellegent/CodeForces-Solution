#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (s[i - 1] - 'a' + 1);
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << a[r] - a[l - 1] << '\n';
  }
  return 0;
}