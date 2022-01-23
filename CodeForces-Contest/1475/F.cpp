#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
struct twosat {
  int n;  // total size combining +, -. must be even.
  vector< vector<int> > g, gt;
  vector<bool> vis, res;
  vector<int> comp;
  stack<int> ts;
  twosat(int vars = 0) {
    n = vars << 1;
    g.resize(n);
    gt.resize(n);
  }
  //add this type of condition->
  //add(a,af,b,bf) means if a is af then b must need to be bf
  void add(int a,bool af,int b,bool bf)
  {
    a += a + (af ^ 1);
    b += b + (bf ^ 1);
    g[a].push_back(b);
    gt[b].push_back(a);
  }
  void dfs1(int u) {
    vis[u] = true;
    for(int v : g[u]) if(!vis[v]) dfs1(v);
    ts.push(u);
  }
  void dfs2(int u, int c) {
    comp[u] = c;
    for(int v : gt[u]) if(comp[v] == -1) dfs2(v, c);
  }
  bool ok() {
    vis.resize(n, false);
    for(int i = 0; i < n; ++i) if(!vis[i]) dfs1(i);
    int scc = 0;
    comp.resize(n, -1);
    while(!ts.empty()) {
      int u = ts.top();
      ts.pop();
      if(comp[u] == -1) dfs2(u, scc++);
    }
    res.resize(n / 2);
    for(int i = 0; i < n; i += 2) {
      if(comp[i] == comp[i + 1]) return false;
      res[i / 2] = (comp[i] > comp[i + 1]);
    }
    return true;
  }
};

string a[N], b[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    twosat ts(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      for (int j = 0; j < n; j++) {
        int k = (a[i][j] - '0') ^ (b[i][j] - '0');
        if (k) {
          ts.add(i, 0, j + n, 1);
          ts.add(i, 1, j + n, 0);
          ts.add(j + n, 0, i, 1);
          ts.add(j + n, 1, i, 0);        
        }
        else {
          ts.add(i, 0, j + n, 0);
          ts.add(i, 1, j + n, 1);
          ts.add(j + n, 0, i, 0);
          ts.add(j + n, 1, i, 1); 
        }
      }
    }
    if (ts.ok()) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}