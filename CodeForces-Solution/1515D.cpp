#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, l, r; cin >> n >> l >> r;
    vector<int> cl(n + 1, 0), cr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      if (i <= l) cl[k]++;
      else cr[k]++;
    }
    int tl = 0, tr = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
      int mn = min(cl[i], cr[i]);
      cl[i] -= mn;
      cr[i] -= mn;
      tl += cl[i];
      tr += cr[i];
    }
    for (int i = 1; i <= n; i++) {
      while (tl - 2 >= tr and cl[i] > 1) {
        cl[i] -= 2;
        tl -= 2;
        ++ans;
      }      
      while (tr - 2 >= tl and cr[i] > 1) {
        cr[i] -= 2;
        tr -= 2;
        ++ans;
      }
    }
    cout << ans + max(tl, tr) << '\n';
  }
  return 0;
}