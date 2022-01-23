#include<bits/stdc++.h>
using namespace std;

const int N = 305;
struct Mat {
  int n, m;
  vector<vector<int>> a;
  Mat() { }
  Mat(int _n, int _m) {n = _n; m = _m; a.assign(n, vector<int>(m, 0)); }
  Mat(vector< vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(int i = 1; i < n; i++) {
      for(int j = i; j < b.m; j++) {
        for(int k = i; k <= j; k++) {
          ans.a[i][j] = max(ans.a[i][j], a[i][k] + b.a[k][j]);
        }
      }
    }
    return ans;
  }
  inline Mat pow(int k) {
    assert(n == m);
    Mat ans(n, n), t = a; ans = a; k--;
    while (k) {
      if (k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
};
int a[N], g[N][N], dp[N][N];
int yo(int i, int j) { // a[i] <= a[j]
  if (i == j) return 1;
  if (i + 1 == j) return 2;
  int &ret = dp[i][j];
  if (ret != -1) return ret;
  ret = 0;
  for (int k = i + 1; k <= j; k++) {
    if (a[i] <= a[k] and a[k] <= a[j]) {
      ret = max(ret, 1 + yo(k, j));
    }
  }
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        g[a[i]][a[j]] = max(g[a[i]][a[j]], yo(i, j));
      if (a[i] <= a[j]) {
      }
    }
  }
  for (int i = N - 3; i >= 1; i--) {
    for (int j = i + 1; j < N; j++) {
      g[i][j] = max(g[i][j], g[i + 1][j]);
    }
  }
  Mat a(N, N);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j++) {
      a.a[i][j] = g[i][j];
    }
  }
  a = a.pow(k);
  int ans = 0;
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j++) {
      ans = max(ans, a.a[i][j]);
    }
  }
  cout << ans << '\n';
  return 0;
}