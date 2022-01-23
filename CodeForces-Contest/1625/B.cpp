#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> last;
    int ans = n + 1;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      if (last.find(x) != last.end()) {
        ans = min(ans, i - last[x]);
      }
      last[x] = i;
    }
    cout << n - ans << '\n';
  }
  return 0;
}