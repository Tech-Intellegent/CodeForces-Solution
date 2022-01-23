#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    set<int> se, alive;
    for (int i = 0; i < n; i++) {
      int k = __gcd(a[i], a[(i - 1 + n) % n]);
      if (k == 1) {
        se.insert(i);
      }
      alive.insert(i);
    }
    vector<int> ans;
    int last = 0;
    while (1) {
      if (se.empty()) break;
      if (alive.size() == 1) {
        ans.push_back((*alive.begin()));
        break;
      }
      auto it = se.upper_bound(last);
      if (it == se.end()) {
        it = se.begin();
      }
      int k = *it;
      ans.push_back(k);
      se.erase(it);
      auto ii = alive.lower_bound(k);
      int l = ii == alive.begin() ? *prev(alive.end()) : *prev(ii);
      int r = ii == prev(alive.end()) ? *(alive.begin()) : *next(ii);
      alive.erase(k);
      if (__gcd(a[k], a[r]) == 1) {
        se.erase(r);
      }
      if (__gcd(a[l], a[r]) == 1) {
        se.insert(r);
      }
      last = r;
    }
    cout << ans.size() << ' ';
    for (auto x: ans) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}