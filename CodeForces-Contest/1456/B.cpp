#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = n + 1;
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int k = i; k >= max(1, i - 400); k--) {
      cur ^= a[k];
      if ((i + 1 <= n && cur > a[i + 1]) || (k > 1 && a[k - 1] > cur)) {
        ans = min(ans, i - k);
      }
    }
  }
  if (ans == (n + 1)) ans = -1;
  cout << ans << '\n';
  return 0;
}