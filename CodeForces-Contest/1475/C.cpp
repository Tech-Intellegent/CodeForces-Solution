#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    long long ans = 1LL * k * (k - 1) / 2;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < k; i++) {
      int x; cin >> x;
      cnt[x]++;
    }
    for (int i = 1; i <= n; i++) {
      ans -= 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }    
    cnt = vector<int> (m + 1, 0);
    for (int i = 0; i < k; i++) {
      int x; cin >> x;
      cnt[x]++;
    }
    for (int i = 1; i <= m; i++) {
      ans -= 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}