#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

vector<array<int, 2>> a, b[24];
inline void ckmin(int &x, int z) {
  x = x < z ? x : z;
}
const int inf = 2e9 + 2;
int z;
int yo(array<int, 2> p[4]) {
  int ans = inf;
  for (int i = 0; i < z; i++) {
    long long cur = 0;
    cur += abs(b[i][0][0] - p[0][0]);
    cur += abs(b[i][0][1] - p[0][1]);
    cur += abs(b[i][1][0] - p[1][0]);
    cur += abs(b[i][1][1] - p[1][1]);
    cur += abs(b[i][2][0] - p[2][0]);
    cur += abs(b[i][2][1] - p[2][1]);
    cur += abs(b[i][3][0] - p[3][0]);
    cur += abs(b[i][3][1] - p[3][1]);
    ans = cur < ans ? cur : ans;
  }
  return ans;
}
int g(array<int, 2> p, int len) {
  int ans = inf;
  array<int, 2> cur[4];
  auto q = p;
  q[0] += len;
  q[1] += len;
  cur[0] = p;
  cur[1] = {p[0], q[1]};
  cur[2] = {q[0], p[1]};
  cur[3] = {q[0], q[1]};
  ckmin(ans, yo(cur));  
  q = p;
  q[0] += len;
  q[1] -= len;
  cur[0] = p;
  cur[1] = {p[0], q[1]};
  cur[2] = {q[0], p[1]};
  cur[3] = {q[0], q[1]};
  ckmin(ans, yo(cur));  
  q = p;
  q[0] -= len;
  q[1] += len;
  cur[0] = p;
  cur[1] = {p[0], q[1]};
  cur[2] = {q[0], p[1]};
  cur[3] = {q[0], q[1]};
  ckmin(ans, yo(cur));  
  q = p;
  q[0] -= len;
  q[1] -= len;
  cur[0] = p;
  cur[1] = {p[0], q[1]};
  cur[2] = {q[0], p[1]};
  cur[3] = {q[0], q[1]};
  ckmin(ans, yo(cur));
  return ans;
} 
int f(int len) {
  int ans = inf;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ckmin(ans, g({a[i][0], a[j][1]}, len));
      ckmin(ans, g({a[i][1], a[j][0]}, len));
      ckmin(ans, g({a[i][0], a[j][0]}, len));
      ckmin(ans, g({a[i][1], a[j][1]}, len));
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    a.resize(4);
    for (int i = 0; i < 4; i++) {
      cin >> a[i][0] >> a[i][1];
    }
    auto c = a;
    sort(c.begin(), c.end());
    z = 0;
    do {
      b[z++] = c;
    } while(next_permutation(c.begin(), c.end()));

    int l = -1, r = 1e9;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (f(mid) < f(mid + 1)) {
        r = mid;
      }
      else {
        l = mid;
      }
    }
    int ans = f(l + 1);
    cout << ans << '\n';
  }
  return 0;
}