#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  set<pair<int, int>> same, diff;
  map<pair<int, int>, char> mp;
  while (m--) {
    char ty; cin >> ty;
    if (ty == '+') {
      int u, v; char c; cin >> u >> v >> c;
      pair<int, int> p = pair<int, int>(min(u, v), max(u, v));
      if (mp.find({v, u}) != mp.end()) {
        if (c == mp[{v, u}]) {
          same.insert(p);
        }
        else {
          diff.insert(p);
        }
      }
      mp[{u, v}] = c;
    }
    else if (ty == '-') {
      int u, v; cin >> u >> v;
      pair<int, int> p = pair<int, int>(min(u, v), max(u, v));
      if (same.find(p) != same.end()) {
        same.erase(p);
      }
      if (diff.find(p) != diff.end()) {
        diff.erase(p);
      }
      mp.erase({u, v});
    }
    else {
      int k; cin >> k;
      if (k & 1) {
        if (!same.empty() || !diff.empty()) {
          cout << "YES\n";
        }
        else {
          cout << "NO\n";
        }
      }        
      else {
        if (!same.empty()) {
          cout << "YES\n";
        }
        else {
          cout << "NO\n";
        }
      }
    }
  }
  return 0;
}