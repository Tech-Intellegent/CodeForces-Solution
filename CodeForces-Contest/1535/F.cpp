#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, m;
int pref[N], suf[N];
string s[N];
int ok(int i, int j) {
  int k = 0, last = 0;
  while (k < m) {
    if (k + 1 < m and s[i][k + 1] >= s[i][k]) {
      ++k;
    }
    else {
      if (!last or pref[last - 1]) {
        if (k == m - 1 or suf[k + 1]) {
          auto p = s[i].substr(last, k - last + 1);
          auto q = s[j].substr(last, k - last + 1);
          sort(q.begin(), q.end());
          if (p == q) {
            return 1;
          }
        }
      }
      last = k + 1;
      ++k;
    }
  }
  return 0;
}
int pos(int i, int j) {
  vector<int> a(26, 0), b(26, 0);
  for (auto x: s[i]) {
    a[x - 'a']++;
  }  
  for (auto x: s[j]) {
    b[x - 'a']++;
  }
  return a == b;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  m = s[1].size();
  long long ans = 0;
  // if (n <= 500) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = 0; k < m; k++) {
          pref[k] = s[i][k] == s[j][k];
          if (k) pref[k] &= pref[k - 1];
        }
        for (int k = m - 1; k >= 0; k--) {
          suf[k] = s[i][k] == s[j][k];
          if (k + 1 < m) suf[k] &= suf[k + 1];
        }
        if (pos(i, j)) {
          if (ok(i, j) or ok(j, i)) ++ans;
          else ans += 2;
        }
        else ans += 1337;
      } 
    }
  // }
  cout << ans << '\n';
  return 0;
}