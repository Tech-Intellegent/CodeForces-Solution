#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, a, b; cin >> n >> a >> b;
    vector<int> p(n + 1), vis(n + 1, 0);
    p[1] = a;
    vis[a] = 1;
    p[n] = b;
    vis[b] = 1;
    for (int i = 2, mx = n; i <= n / 2; i++) {
      while (vis[mx]) mx--;
      p[i] = mx;
      vis[mx] = 1;
    }
    for (int i = n / 2 + 1, mn = 1; i < n; i++) {
      while (vis[mn]) mn++;
      p[i] = mn;
      vis[mn] = 1;
    }
    int mn = n;
    for (int i = 1; i <= n / 2; i++) {
      mn = min(mn, p[i]);
    }
    if (mn != a) {
      cout << -1 << '\n';
      continue;
    }    
    int mx = 1;
    for (int i = n / 2 + 1; i <= n; i++) {
      mx = max(mx, p[i]);
    }
    if (mx != b) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      cout << p[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}