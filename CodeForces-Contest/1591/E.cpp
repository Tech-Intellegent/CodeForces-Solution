#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
template <class T>
struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
BIT<int> t;
set<int> se[N];
int cnt[N];
void add(int x, int w) {
  if (cnt[x]) {
    se[cnt[x]].erase(x);
    t.upd(cnt[x], -1);
  }
  cnt[x] += w;
  if (cnt[x]) {
    se[cnt[x]].insert(x);
    t.upd(cnt[x], 1);
  }
}
int n, a[N], ans[N];
vector<int> g[N];
vector<array<int, 3>> Q[N];
void dfs(int u, int p = 0) {
  add(a[u], 1);
  for (auto w: Q[u]) {
    int l = w[0], k = w[1], i = w[2];
    int r = n, id = -1;
    if (t.query(l, r) < k) {
      ans[i] = -1;
      continue;
    }
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (t.query(w[0], mid) >= k) {
        id = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    assert(id != -1);
    assert(!se[id].empty());
    ans[i] = *se[id].begin();
  }
  for (auto v: g[u]) {
    if (v ^ p) {
      dfs(v, u);
    }
  }
  add(a[u], -1);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    int q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    t = BIT<int>(n + 1);
    for (int i = 2; i <= n; i++) {
      int p; cin >> p;
      g[p].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
      int u, l, k; cin >> u >> l >> k;
      Q[u].push_back({l, k, i});
    }
    dfs(1);
    for (int i = 1; i <= q; i++) {
      cout << ans[i] << ' ';
    } cout << '\n';
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0;
      se[i].clear();
      g[i].clear();
      Q[i].clear();
    }
  }
  return 0;
}