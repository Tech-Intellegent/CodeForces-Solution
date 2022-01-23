#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cur += a[i] == i;
  }
  int ans = cur;
  for (int i = 0; i < n; i++) {
    if (i != a[i]) {
      if (a[a[i]] == i) {
        ans = max(ans, cur + 2);
      }
      else ans = max(ans, cur + 1);
    }
  }
  cout << ans << '\n';
  return 0;
}