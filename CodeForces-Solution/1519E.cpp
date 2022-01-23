#include<bits/stdc++.h>
using namespace std;

#define double long double
const int N = 2e5 + 9;
bool vis[N];
bool same(array<int, 4> x, array<int, 4> y) {
  double p = atan2(1.0L * x[2] / x[3], 1.0L * x[0] / x[1]);
  double q = atan2(1.0L * y[2] / y[3], 1.0L * y[0] / y[1]);
  return abs(p - q) < 1e-9;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<pair<array<int, 4>, int>> lines;
  for (int i = 1; i <= n; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    lines.push_back({{a + b, b, c, d}, i});
    lines.push_back({{a, b, c + d, d}, i});
  }
  sort(lines.begin(), lines.end(), [&](pair<array<int, 4>, int> a, pair<array<int, 4>, int> b) {
    auto [x, i] = a;
    auto [y, j] = b;
    double x1 = 1.0L * x[0] / x[1], y1 = 1.0L * x[2] / x[3];
    double p = atan2(y1, x1);    
    double x2 = 1.0L * y[0] / y[1], y2 = 1.0L * y[2] / y[3];
    double q = atan2(y2, x2);
    if (abs(p - q) < 1e-9) {
      return (x1 * x1 + y1 * y1) < (x2 * x2 + y2 * y2);
    }
    return p < q;
  });
  vector<array<int, 2>> ans;
  for (int i = 0; i < lines.size();) {
    int j = i;
    while (j < lines.size() and same(lines[i].first, lines[j].first)) j++;
    sort(lines.begin() + i, lines.begin() + j, [&](pair<array<int, 4>, int> a, pair<array<int, 4>, int> b) {
      return a.second < b.second;
    });
    int last = -1;
    for (int k = i; k < j; k++) {
      int cur = lines[k].second;
      if (!vis[cur]) {
        if (last == -1) last = cur;
        else if (cur != last) {
          ans.push_back({last, cur});
          vis[last] = vis[cur] = 1;
          last = -1;
        }
      }
    }
    i = j;
  }
  cout << ans.size() << '\n';
  for (auto [x, y]: ans) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}