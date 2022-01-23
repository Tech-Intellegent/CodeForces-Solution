#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int a[N], ans[N][N];
int n; int cur, cnt;
void dfs(int i, int j) {
  if (!cnt) return;
  if (i < n and !ans[i + 1][j]) {
    ans[i + 1][j] = cur;
    cnt--;
    dfs(i + 1, j);
    return;
  }
  ans[i][j - 1] = cur;
  cnt--;
  dfs(i, j - 1);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    cur = a[i];
    cnt = a[i] - 1;
    ans[i][i] = a[i];
    dfs(i, i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}