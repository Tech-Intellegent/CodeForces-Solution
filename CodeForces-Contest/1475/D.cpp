#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int b[N];
vector<long long> a[3], p[3];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      a[x].push_back(b[i]);
    }
    for (int i = 1; i <= 2; i++) {
      sort(a[i].rbegin(), a[i].rend());
      long long sum = 0;
      p[i].push_back(0);
      for (int j = 0; j < a[i].size(); j++) {
        sum += a[i][j];
        p[i].push_back(sum);
      }
    }
    int ans = 3 * n;
    for (int i = 0; i < p[1].size(); i++) {
      int j = lower_bound(p[2].begin(), p[2].end(), m - p[1][i]) - p[2].begin();
      if (j < p[2].size()) {
        ans = min(ans, i + 2 * j);
      }
    }
    if (ans == 3 * n) ans = -1;
    cout << ans << '\n';
    for (int i = 1; i <= 2; i++) {
      p[i].clear(); a[i].clear();
    }
  }
  return 0;
}