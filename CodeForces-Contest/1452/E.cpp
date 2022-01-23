#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 9;
#define int long long
int s[N];
vector<int> a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int l, r; cin >> l >> r;
    a[r].push_back(l);
  }
  int ans = 0;
  for (int i = k; i <= n; i++) {
    int cur = 0;
    for (int r = 1; r <= i; r++) {
      for (auto l: a[r]) {
        int L = max(i - k + 1, l);
        int R = min(r, i);
        cur += max(0LL, R - L + 1);
      }
    }
    memset(s, 0, sizeof s);
    for (int r = i + 1; r <= n; r++) {
      for (auto l: a[r]) {
        s[l]++;
        s[r + 1]--;
      }
    }
    for (int j = 1; j <= n + 1; j++) {
      s[j] += s[j - 1];
    }    
    for (int j = 1; j <= n + 1; j++) {
      s[j] += s[j - 1];
    }
    for (int j = i; j <= n; j++) {
      ans = max(ans, cur + s[j] - s[j - k]);
    }
  }
  cout << ans << '\n';
  return 0;
}