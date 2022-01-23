#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      mp[x].push_back(i);
    }
    vector<pair<int, int>> c;
    for (int i = 1; i <= n; i++) {
      c.push_back({(int)mp[i].size(), i});
    }
    sort(c.rbegin(), c.rend());
    int l = 0, r = n;
    vector<int> ans(n + 1, 0);
    while (l <= r) {
      int mid = l + r >> 1;
      auto cnt = c;
      auto v = mp;
      bool ok = true;
      vector<int> id(n + 1, 0);
      for (int j = 1; j <= k; j++) {
        int cur = mid;
        for (int i = 0; i < n and cur; i++) {
          if (cnt[i].first) {
            cur--; cnt[i].first--;
            int z = cnt[i].second;
            id[v[z].back()] = j;
            v[z].pop_back();
          }
        }
        if (cur != 0) {
          ok = false; break;
        }
      }
      if (ok) {
        ans = id;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}