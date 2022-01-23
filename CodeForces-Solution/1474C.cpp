#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(2 * n);
    n *= 2;
    map<int, int> mp;
    for (auto &x: a) {
      cin >> x;
      mp[x]++;
    }
    sort(a.begin(), a.end());
    int found = 0;
    for (int i = 0; i < n - 1; i++) {
      auto cur = mp;
      cur[a[i]]--;
      cur[a[n - 1]]--;
      vector<pair<int, int>> op({{a[i], a[n - 1]}});
      int last = a[n - 1], ok = 1;
      for (int i = n - 2; i >= 0; i--) {
        if (cur[a[i]] == 0) continue;
        if (cur[last - a[i]] == 0) {
          ok = 0; break;
        }
        cur[a[i]]--;
        cur[last - a[i]]--;
        op.push_back({last - a[i], a[i]});
        last = a[i];
      }
      if (ok) {
        cout << "YES\n";
        cout << op[0].first + op[0].second << '\n';
        for (auto x: op) {
          cout << x.first << ' ' << x.second << '\n';
        }
        found = 1;
        break;
      }
    }
    if (!found) {
      cout << "NO\n";
    }
  }
  return 0;
}