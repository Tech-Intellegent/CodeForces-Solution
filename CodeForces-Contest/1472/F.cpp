#include<bits/stdc++.h>
using namespace std;

const int N = 3e6 + 9;
int a[N], n;
int yo(int i, int mask) {
  if (i == n) return mask == 3;
  int nxt = a[i];
  for (int k = 0; k < 2; k++) {
    if ((~mask >> k & 1)) {
      if (a[i] >> k & 1) return 0;
      else {
        nxt |= 1 << k;
      }
    }
  }
  if (nxt == 0) nxt = 3;
  return yo(i + 1, nxt);
}
int solve(vector<pair<int, int>> v) {
  int mn = v[0].first;
  n = v.back().first - mn + 1;
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
  for (auto x: v) {
    a[x.first - mn] |= 1 << (x.second - 1);
  }
  return yo(0, 3);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v;
    while (m--) {
      int i, j; cin >> i >> j;
      v.push_back({j, i});
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> cur;
    cur.push_back(v[0]);
    int x = 0;
    for (int i = 1; i < v.size(); i++) {
      int d = v[i].first - v[i - 1].first;
      if (d > 5) {
        x -= d;
        x += 5;
        if (~d & 1) x--;
      }
      cur.push_back({v[i].first + x, v[i].second});
    }
    if (solve(cur)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}