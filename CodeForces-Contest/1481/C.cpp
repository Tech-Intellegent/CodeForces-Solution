#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], b[N], c[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    map<int, vector<int>> mp;
    map<int, int> d;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      if (a[i] != b[i]) {
        mp[b[i]].push_back(i);
      }
      d[b[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
      cin >> c[i];
    }
    if (d.find(c[m]) == d.end()) {
      cout << "NO\n";
      continue;
    }
    vector<int> ans;
    int id = mp.find(c[m]) != mp.end() ? mp[c[m]].front() : d[c[m]];
    for (int i = 1; i <= m; i++) {
      if (!mp[c[i]].empty()) {
        ans.push_back(mp[c[i]].back());
        mp[c[i]].pop_back();
      }
      else {
        ans.push_back(id);
      }
    }
    int f = 1;
    for (auto x: mp) {
      if (!x.second.empty()) {
        f = 0;
        break;
      }
    }
    if (!f) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      for (auto x: ans) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}