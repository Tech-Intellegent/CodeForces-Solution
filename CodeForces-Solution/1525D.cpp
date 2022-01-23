#include<bits/stdc++.h>
using namespace std;

const int N = 5005, inf = 1e9;
int dp[N][N];
vector<int> a, b;
int yo(int i, int j) {
  if (i == a.size()) return 0;
  if (j == b.size()) return inf;
  int &ret = dp[i][j];
  if (ret != -1) return ret;
  ret = yo(i, j + 1);
  if (i < a.size()) ret = min(ret, abs(a[i] - b[j]) + yo(i + 1, j + 1));
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    if (k == 1) {
      a.push_back(i);
    }
    else {
      b.push_back(i);
    }
  }
  memset(dp, -1, sizeof dp);
  cout << yo(0, 0) << '\n';
  return 0;
}