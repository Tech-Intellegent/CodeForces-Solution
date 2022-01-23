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
    set<pair<int, int>> vis;
    while (1) {
      int x, y; 
      // finding a random pair
      while (1) {
        x = rnd() % n + 1;
        y = rnd() % n + 1;
        while (y == x) {
          y = rnd() % n + 1;
        }
        if (x > y) swap(x, y);
        if (vis.find({x, y}) == vis.end()) {
          vis.insert({x, y});
          break;
        }
      }
      vector<int> f(n + 1, -1), cnt(2, 0);
      int done = 0;
      for (int i = 1; i <= n; i++) {
        if (i == x or i == y) {
          continue;
        }
        ++done;
        f[i] = query(x, y, i);
        cnt[f[i]]++;
        if (cnt[0] == 0 or cnt[1] == 0) {
          if (done >= 2 * n / 3) {
            break;
          }
        }
      }
      if (cnt[0] == 0 or cnt[1] == 0) { // if (x, y) == (0, 0) or (x, y) == (1, 1)
        continue;
      }
      // (x, y) == (0, 1) or (1, 0)
      vector<int> v;
      for (int i = 1; i <= n; i++) {
        if (f[i] != -1) {
          v.push_back(i);
          if ((int)v.size() == 2) break;
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
      break;
    }
  }
  return 0;
}