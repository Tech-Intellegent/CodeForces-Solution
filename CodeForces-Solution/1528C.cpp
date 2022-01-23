#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, LG = 19;

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
vector<int> g[N], h[N];
int st[N], en[N], T;
int par[N][LG + 1], dep[N];
void dfs2(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  st[u] = ++T;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: h[u]) if (v != p) {
    dfs2(v, u);
  }
  en[u] = T;
}
int kth(int u, int k) {
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}
int ans, cur, add[N];
vector<array<int, 5>> vec;
void dfs(int u) {
  if (t.query(st[u], en[u]) == 0) {
    int l = 1, r = dep[u] - 1, z = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      int v = kth(u, mid);
      if (t.query(st[v], en[v])) {
        z = v; r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    vec.push_back({z, add[z], u, add[u], cur});
    if (z and add[z]) {
      add[z] = 0; add[u] = 1;
    }
    else {
      cur++; add[u] = 1;
    }
  }
  else vec.push_back({0, 0, 0, 0, cur});
  t.upd(st[u], 1);
  ans = max(ans, cur);
  for (auto v: g[u]) {
    dfs(v);
  }
  auto [w, x, q, y, z] = vec.back();
  vec.pop_back();
  if (w) add[w] = x;
  if (q) add[q] = y;
  cur = z;
  t.upd(st[u], -1);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
      int k; cin >> k;
      g[k].push_back(i);
    }    
    for (int i = 2; i <= n; i++) {
      int k; cin >> k;
      h[k].push_back(i);
    }
    T = 0;
    dfs2(1);
    t = BIT<int> (n + 1);
    ans = 0; cur = 0;
    dfs(1);
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      h[i].clear();
      add[i] = 0;
      for (int j = 0; j <= LG; j++) {
        par[i][j] = 0;
      }
    }
  }
  return 0;
}