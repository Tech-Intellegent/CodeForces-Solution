#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int par[N][20], dep[N], a[N], c[N];
int kth(int u, int k) {
  for (int i = 0; i < 20; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q; cin >> q >> a[1] >> c[1];
  dep[1] = 1;
  for (int u = 2; u <= q + 1; u++) {
    int ty; cin >> ty;
    if (ty == 1) {
      int p; cin >> p; p++;
      cin >> a[u] >> c[u];
      par[u][0] = p;
      dep[u] = dep[p] + 1;
      for (int i = 1; i < 20; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    }
    else {
      int v, w; cin >> v >> w;
      v++;
      int cur = v;
      for (int i = 19; i >= 0; i--) {
        if (a[par[cur][i]]) {
          cur = par[cur][i];
        }
      }
      long long tot = 0, cost = 0;
      while (w) {
        int x = min(w, a[cur]);
        w -= x;
        tot += x; cost += 1LL * x * c[cur];
        a[cur] -= x;
        if (cur == v) break;
        cur = kth(v, dep[v] - dep[cur] - 1);
      }
      cout << tot << ' ' << cost << '\n';
    }
  }
  return 0;
}