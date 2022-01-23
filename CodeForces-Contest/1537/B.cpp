#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<array<int, 2>> p({{1, 1}, {1, m}, {n, 1}, {n, m}});
    long long ans = -1;
    array<int, 2> u, v;
    for (auto [a, b]: p) {
      for (auto[c, d]: p) {
        long long cur = abs(x - a) + abs(b - y);
        cur += abs(a - c) + abs(b - d);
        cur += abs(x - c) + abs(y - d);
        if (cur > ans) {
          ans = cur;
          u = {a, b};
          v = {c, d};
        }
      }
    }
    cout << u[0] << ' ' << u[1] << ' ' << v[0] << ' ' << v[1] << '\n';
  }
  return 0;
}