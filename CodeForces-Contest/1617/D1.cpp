#include<bits/stdc++.h>
using namespace std;

int op = 0;
int query(int i, int j, int k) {
  ++op;
  cout << "? " << i << ' ' << j << ' ' << k << ' ' << endl;
  int p; cin >> p;
  if (p == -1) assert(0);
  return p;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    op = 0;
    int last = -1, x = 1, y = 2;
    for (int i = 3; i <= n; i++) {
      int cur = query(i - 2, i - 1, i);
      if (last == -1) {
        last = cur;
        continue;
      }
      if (last != cur) {
        x = i - 2, y = i - 1;
        break;
      }
    }
    vector<int> f(n + 1, -1);
    for (int i = 1; i <= n; i++) {
      if (i == x or i == y) {
        continue;
      }
      f[i] = query(x, y, i);
    }
    // (x, y) == (0, 1) or (1, 0)
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (f[i] == 0) {
        v.push_back(i);
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (f[i] == 1) {
        v.push_back(i);
        break;
      }
    }
    assert((int)v.size() == 2);
    f[x] = query(v[0], v[1], x);
    f[y] = query(v[0], v[1], y);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += !f[i];
    }
    cout << "! ";
    cout << ans;
    for (int i = 1; i <= n; i++) {
      if (!f[i]) {
        cout << ' ' << i;
      }
    }
    cout << endl;
  }
  return 0;
}