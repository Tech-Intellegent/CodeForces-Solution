#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9;
int n, m;
string s[N];
vector<int> vis[N];
int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};
void go(int i, int j) {
  if (vis[i][j]) return;
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int ni = i + di[k];
    int nj = j + dj[k];
    if (ni >= 0 and ni < n and nj >= 0 and nj < m) {
      if (k == 3 or s[ni][nj] == '#') go(ni, nj);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    vis[i].resize(m + 1, 0);
  }
  vector<array<int, 3>> v;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '#') {
        int cnt = 0, x = i;
        while (i < n and s[i][j] == '#') ++i, ++cnt;
        v.push_back({-cnt, -x, j});
        break;
      }
    }
  }
  sort(v.begin(), v.end());
  int ans = 0;
  while (!v.empty()) {
    auto [x, i, j] = v.back();
    v.pop_back();
    i = -i;
    if (vis[i][j]) continue;
    ++ans;
    go(i, j);
  }
  cout << ans << '\n';
  return 0;
}