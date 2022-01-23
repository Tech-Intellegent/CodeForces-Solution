#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n), nxt(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      nxt[i] = i;
    }
    nxt[n] = n;
    int cur = 0;
    while (1) {
      while (cur < n && a[cur] <= 1) ++cur;
      if (cur >= n) break;
      if (a[cur] > n) {
        ans += a[cur] - n;
        a[cur] = n;
        continue;
      }
      ++ans;
      int i = nxt[cur];
      vector<int> v;
      while (i < n) {
        int add = a[i];
        a[i] = a[i] == 1 ? 1 : a[i] - 1;
        if (a[i] == 1) {
          v.push_back(i);
        }
        i = i + add < n ? nxt[i + add] : n;
      }
      while (!v.empty()) {
        nxt[v.back()] = nxt[nxt[v.back()]];
        v.pop_back();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}