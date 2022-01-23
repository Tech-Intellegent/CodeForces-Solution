#include<bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par, sz, w;
  DSU() {}
  DSU(int n) {
    par.resize(n + 1);
    sz.resize(n + 1);
    w.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i; 
      sz[i] = 1; w[i] = 0;
    }
  }
  pair<int, int> find(int u) {
    int ans = 0;
    while (par[u] != u)  {
      ans ^= w[u];
      u = par[u];
    }
    return make_pair(u, ans);
  }
  bool merge(int u, int v, int x) {
    auto pu = find(u), pv = find(v);
    u = pu.first;
    v = pv.first;
    int z = pu.second ^ pv.second ^ x;
    if (u == v) {
      return false;
    }
    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    par[u] = v;
    w[u] = z;
    sz[v] += sz[u];
    return true;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> e;
    DSU d(n);
    for (int i = 1; i < n; i++) {
      int u, v, w; cin >> u >> v >> w;
      if (w != -1) {
        d.merge(u, v, w);
      }
      e.push_back({u, v, w});
    }
    bool ok = true;
    while (m--) {
      int u, v, p; cin >> u >> v >> p;
      auto x = d.find(u);
      int u1 = x.first, w1 = x.second;
      auto y = d.find(v);
      int v1 = y.first, w2 = y.second;
      if (u1 == v1) {
        if (__builtin_popcount(w1 ^ w2) % 2 != p) {
          ok = false;
        }
      }
      else {
        d.merge(u1, v1, w1 ^ w2 ^ p);
      }
    }
    if (!ok) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      for (auto z: e) {
        int u = z[0], v = z[1];
        auto x = d.find(u);
        int u1 = x.first, w1 = x.second;
        auto y = d.find(v);
        int v1 = y.first, w2 = y.second;
        cout << z[0] << ' ' << z[1] << ' ' << (w1 ^ w2) << '\n';
      }
    }
  }
  return 0;
}