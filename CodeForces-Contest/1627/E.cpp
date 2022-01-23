#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
using ll = long long;

//add lines with -m and -b and return -ans to
//make this code work for minimums.(not -x)
const ll inf = 1e18;
const __int128 INF = -1e36;
struct line {
  __int128 m, b;
  mutable function<const line*() > succ;
  bool operator < (const line& rhs) const {
    if (rhs.b != INF) return m < rhs.m;
    const line* s = succ();
    if (!s) return 0;
    __int128 x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct CHT : public multiset<line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y -> m == z -> m && y -> b <= z -> b;
    }
    auto x = prev(y);
    if (z == end()) return y -> m == x -> m && y -> b <= x -> b;
    return 1.0 * (x -> b - y -> b) * (z -> m - y -> m) >= 1.0 * (y -> b - z -> b) * (y -> m - x -> m);
  }
  void add(__int128 m, __int128 b) {
    auto y = insert({ m, b });
    y->succ = [ = ] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  __int128 query(__int128 x) {
    assert(!empty());
    auto it = lower_bound((line) {
      x, INF
    });
    auto l = *it;
    return l.m * x + l.b;
  }
};
CHT* cht;

vector<pair<int, int>> g[N];
vector<int> e[N];
map<pair<int, int>, int> mp;
int x[N];
int id(int i, int j) {
  pair<int, int> p = {i, j};
  if (mp.find(p) != mp.end()) return mp[p];
  mp[p]; mp[p] = mp.size();
  return mp[p];
}
ll dp[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      cin >> x[i];
    }
    for (int i = 1; i <= k; i++) {
      int a, b, c, d, h; cin >> a >> b >> c >> d >> h;
      g[id(c, d)].push_back({id(a, b), h});
      e[a].push_back(b);
      e[c].push_back(d);
    }
    for (int i = 1; i <= 3 * k; i++) {
      dp[i] = inf;
    }
    e[1].push_back(1);
    e[n].push_back(m);
    dp[id(1, 1)] = 0;
    for (int i = 1; i <= n; i++) {
      sort(e[i].begin(), e[i].end());
      e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
      int sz = e[i].size();
      vector<ll> temp(sz, inf), cur_dp(sz, inf);
      if (i == 1) temp[0] = 0;
      for (int j = 0; j < sz; j++) {
        for (auto [x, h]: g[id(i, e[i][j])]) {
          temp[j] = min(temp[j], dp[x] - h);
        }
        cur_dp[j] = min(cur_dp[j], temp[j]);
      }
      cht = new CHT();
      for (int j = 0; j < sz; j++) {
        if (j) cur_dp[j] = min(cur_dp[j], (ll)-(cht -> query(x[i])) + 1LL * e[i][j] * x[i]);
        cht -> add(e[i][j], -temp[j]);
      }
      cht = new CHT();
      for (int j = sz - 1; j >= 0; j--) {
        if (j < sz - 1) cur_dp[j] = min(cur_dp[j], (ll)-cht -> query(x[i]) - 1LL * e[i][j] * x[i]);
        cht -> add(-e[i][j], -temp[j]);
      }
      for (int j = 0; j < sz; j++) {
        dp[id(i, e[i][j])] = min(dp[id(i, e[i][j])], cur_dp[j]);
      }
    }
    int des = id(n, m);
    if (dp[des] > inf / 2) cout << "NO ESCAPE\n";
    else cout << dp[des] << '\n';
    int cnt = 0;
    for (int i = 1; i <= (int)mp.size(); i++) {
      g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      e[i].clear();
    }
    mp.clear();
  }
  return 0;
}