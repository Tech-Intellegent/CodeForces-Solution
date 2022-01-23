#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
int par[N][20],dep[N],sz[N];
void dfs(int u,int pre) {
    par[u][0]=pre;
    dep[u]=dep[pre]+1;
    sz[u]=1;
    for(int i=1;i<=18;i++) par[u][i]=par[par[u][i-1]][i-1];
    for(auto v:g[u]){
        if(v==pre) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int lca(int u,int v) {
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=18;k>=0;k--) if(dep[par[u][k]]>=dep[v]) u=par[u][k];
    if(u==v) return u;
    for(int k=18;k>=0;k--) if(par[u][k]!=par[v][k]) u=par[u][k],v=par[v][k];
    return par[u][0];
}

int kth(int u,int k) {
    for(int i=0;i<=18;i++) if(k&(1<<i)) u=par[u][i];
    return u;
}

int isanc(int u, int g) {
    int k = dep[u] - dep[g];
    return k>=0 && kth(u, k) == g;
}

// merging two paths
// Given two valid paths in a tree it finds the union of two paths. If the union is not a path it //returns {-1,-1};
pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
    if (x.first == 0)                 return y; //where {0,0} is a null path
    if (y.first == 0)                 return x;
    if (x.first==-1 || y.first==-1)   return {-1, -1};

    vector<int> can = {x.first, x.second, y.first, y.second};
    int a = can[0];

    for (int u: can)
        if (dep[u] > dep[a])
            a = u;

    int b = -1;
    for (int u: can)
        if (!isanc(a, u)) {
            if (b==-1)  b = u;
            if (dep[b] < dep[u])    b = u;
        }

    if (b == -1) {
        b = can[0];
        for (int u: can)
            if (dep[u] < dep[b])
                b = u;
        return {a, b};
    }

    int g = lca(a, b);
    for (int u: can) {
        if (u==a || u==b)   continue;
        if (dep[u] < dep[g] || (!isanc(a, u) && !isanc(b, u)))    return {-1, -1};
    }
    return {a, b};
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      ++u; ++v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 0);
    pair<int, int> cur = {1, 1};
    vector<long long> ans(n + 1, 0);
    ans[0] = 1LL * n * (n - 1) / 2;
    long long sum = 0;
    for (auto x: g[1]) {
      sum += 1LL * sz[x] * (sz[x] - 1) / 2;
    }
    ans[1] = ans[0] - sum;
    for (int i = 2; i <= n; i++) {
      cur = merge(cur, {i, i});
      if (cur.first == -1) break;
      auto [u, v] = cur;
      if (dep[u] > dep[v]) swap(u, v);
      if (isanc(v, u)) {
        ans[i] = 1LL * sz[v] * (n - sz[kth(v, dep[v] - dep[u] - 1)]);
      }
      else {
        ans[i] = 1LL * sz[u] * sz[v];
      }
    }
    for (int i = 0; i < n; i++) ans[i] -= ans[i + 1];
    for (int i = 0; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i <= n; i++) {
      g[i].clear();
      for (int j = 0; j <= 18; j++) {
        par[i][j] = 0;
      }
    }
  }
  return 0;
}