#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
using ll = long long;

ll a[N];
struct Range {
  set<pair<int, int>> se;
  Range() {}
  void insert(int l, int r) {
    se.insert({r, l});
  }
  void erase(int l, int r) {
    auto it = se.lower_bound({l, -1});
    if (it == se.end()) return;
    auto [y, x] = *it;
    vector<pair<int, int>> v;
    if (x <= l - 1) v.push_back({x, l - 1});
    while (it != se.end()) {
      tie(y, x) = *it;
      it = se.erase(it);
      if (y >= r) break;
    }
    if (r + 1 <= y) {
      v.push_back({r + 1, y});
    }
    for (auto x: v) {
      se.insert(x);
    }
  }
  int query(int l, int r) {
    auto it = se.lower_bound({l, -1});
    int ans = 0;
    int lastx = -10, lasty = -10;
    while (it != se.end()) {
      auto [y, x] = *it;
      ans += max(0, min(r, y) - max(l, x) + 1);
      if (lasty + 1 == x) {
        se.erase(it);
        se.erase({lasty, lastx});
        se.insert({y, lastx});
        it = se.upper_bound({y + 1, -1});
        lasty = y;
        continue;
      }
      if (y >= r) break;
      lasty = y;
      lastx = x;
      ++it;
    }
    return ans;
  }
}seg[62][2];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> mx = {0}, mn = {0};
  ll ans = 0;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    while (mx.back() != 0 && a[mx.back()] < a[i]) {
      int r = mx.back();
      mx.pop_back();
      int c = __builtin_popcountll(a[r]), d = __builtin_popcountll(a[i]);
      cur -= seg[c][1].query(mx.back() + 1, r);
      seg[c][0].erase(mx.back() + 1, r);
      seg[d][0].insert(mx.back() + 1, r);
      cur += seg[d][1].query(mx.back() + 1, r);
    }
    int d = __builtin_popcountll(a[i]);
    seg[d][0].insert(i, i);
    mx.push_back(i);

    while (mn.back() != 0 && a[mn.back()] > a[i]) {
      int r = mn.back();
      mn.pop_back();
      int c = __builtin_popcountll(a[r]), d = __builtin_popcountll(a[i]);
      cur -= seg[c][0].query(mn.back() + 1, r);
      seg[c][1].erase(mn.back() + 1, r);
      seg[d][1].insert(mn.back() + 1, r);
      cur += seg[d][0].query(mn.back() + 1, r);
    }
    mn.push_back(i);
    seg[d][1].insert(i, i);
    cur++;
    ans += cur;
  }
  cout << ans << '\n';
  return 0;
}