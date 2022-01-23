#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int a[4][2], c[4], n;
bool ok;
void dfs(int k) {
  if (k == 4) {
    ok = true;
    return;
  }
  for (int mask = 0; mask < 4; mask++) {
    if (__builtin_popcount(mask) <= c[k] && c[k] - __builtin_popcount(mask) <= n - 2) {
      bool ok = true;
      for (int i = 0; i < 2; i++) {
        int d = i == 0 ? -1 : +1, p = mask >> i & 1;
        if (a[(k + d + 4) % 4][!i] != -1 && a[(k + d + 4) % 4][!i] != p) {
          ok = false;
        }
        else a[k][i] = p;
      }
      if (ok) {
        dfs(k + 1);
        a[k][0] = a[k][1] = -1;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < 4; i++) {
      cin >> c[i];
    }
    memset(a, -1, sizeof a);
    ok = false;
    dfs(0);
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}