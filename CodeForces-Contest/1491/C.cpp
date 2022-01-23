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
        if (a[i] == 2) {
          a[i]--;
          for (int j = n - 1; j >= 0; j--) {
            if (a[j] == 1) {
              nxt[j] = nxt[j + 1];
            }
            else {
              nxt[j] = j;
            }
          }
        }
        else a[i] = max(a[i] - 1, 1);
        i = i + add < n ? nxt[i + add] : n;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}