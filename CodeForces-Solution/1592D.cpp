#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> e;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    e.push_back({u, v});
  }
  cout << "? " << n;
  for (int i = 1; i <= n; i++) {
    cout << ' ' << i;
  }
  cout << '\n';
  cout.flush();
  int mx; cin >> mx;
  while (e.size() != 1) {
    int mid = (e.size() + 1) / 2;
    set<int> se;
    for (int i = 0; i < mid; i++) {
      se.insert(e[i].first);
      se.insert(e[i].second);
    }
    cout << "? " << se.size();
    for (auto x: se) {
      cout << ' ' << x;
    }
    cout << '\n';
    cout.flush();
    int x; cin >> x;
    if (x == mx) {
      e.resize(mid);
    }
    else {
      e.erase(e.begin(), e.begin() + mid);
    }
  }
  cout << "! " << e[0].first << ' ' << e[0].second << endl;
  return 0;
}