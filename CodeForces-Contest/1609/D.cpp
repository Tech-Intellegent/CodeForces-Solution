#include<bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  DSU d(n);
  int extra = 0;
  while (q--) {
    int u, v; cin >> u >> v;
    if (d.same(u, v)) {
      extra++;
    }
    else {
      d.merge(u, v);
    }
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      if (d.find(i) == i) {
        a.push_back(d.get_size(i));
      }
    }
    sort(a.rbegin(), a.rend());
    int ans = a[0];
    for (int i = 1; i <= extra; i++) {
      if (i >= (int)a.size()) break;
      ans += a[i];
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}