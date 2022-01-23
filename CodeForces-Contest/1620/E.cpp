#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

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
  void merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return;
    if (i > j) swap(i, j);
    par[i] = j;
  }
}d(N);
int a[N], last[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q; cin >> q;
  int n = 0;
  for (int i = 1; i <= q; i++) {
    int ty; cin >> ty;
    if (ty == 1) {
      int x; cin >> x;
      ++n;
      a[n] = x;
      if (last[x]) {
        d.merge(last[x], n);
      }
      last[x] = n;
    }
    else {
      int x, y; cin >> x >> y;
      if (!last[x]) continue;
      if (!last[y]) {
        a[last[x]] = y;
        last[y] = last[x];
        last[x] = 0;
        continue;
      }
      if (x == y) continue;
      d.merge(last[x], last[y]);
      last[y] = d.find(last[y]);
      a[last[y]] = y;
      last[x] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[d.find(i)] << ' ';
  }
  return 0;
}