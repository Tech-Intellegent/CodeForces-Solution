#include<bits/stdc++.h>
using namespace std;

const int N = 120;

int a[N][N], done[N], ans[N][N], vis[N][N];
array<int, 2> f[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> v;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        v.push_back({a[i][j], i, j});
        vis[i][j] = 0;
      }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
      f[i + 1] = {v[i][1], v[i][2]};
      vis[v[i][1]][v[i][2]] = 1;
    }
    for (int i = 1; i <= m; i++) {
      memset(done, 0, sizeof done);
      ans[i][f[i][0]] = a[f[i][0]][f[i][1]];
      done[f[i][0]] = 1;
      for (int j = 1; j <= n; j++) {
        if (!done[j]) {
          for (int k = 1; k <= m; k++) {
            if (!vis[j][k]) {
              vis[j][k] = 1;
              ans[i][j] = a[j][k];
              break;
            }
          }
          done[j] = 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << ans[j][i] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}