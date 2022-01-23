#include<bits/stdc++.h>
using namespace std;

const int N = 2020;
set<int> g[N];
int vis[N];
vector<int> cnt[N];
int32_t main() {
  int n; cin >> n;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    cout << "? " << u << endl;
    for (int i = 0; i <= n; i++) {
      cnt[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      cnt[k].push_back(i);
    }
    int last = u;
    for (int i = 1; i < n; i++) {
      if (cnt[i].empty()) break;
      if (cnt[i].size() > 1) {
        for (auto x: cnt[i]) {
          g[x].insert(last);
          g[last].insert(x);
          vis[x] = 1;
        }
        for (auto x: cnt[i + 1]) {
          q.push(x);
        }
        break;
      }
      else {
        vis[last] = 1;
        int x = cnt[i].front();
        g[x].insert(last);
        g[last].insert(x);
        last = x;
      }
    }
  }
  cout << "!" << endl;
  for (int u = 1; u <= n; u++) {
    for (auto v: g[u]) {
      if (u < v) cout << u << ' ' << v << endl;
    }
  }
  return 0;
}