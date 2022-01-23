#include<bits/stdc++.h>
using namespace std;

const int N = 20, T = 4e5 + 9;

int dp[1 << N], n;
string s[N];
int len[N], p[N][T], mn[N][T];
vector<int> v[N][T + T];
int yo(int mask, int sum) {
  if (mask == (1 << n) - 1) return 0;
  int &ret = dp[mask];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (int i = 0; i < n; i++) {
    if (~mask >> i & 1) {
      if (mn[i][len[i]] >= -sum) {
        ret = max(ret, (int)v[i][-sum + T].size() + yo(mask | (1 << i), sum + p[i][len[i]]));
      }
      else {
        int l = 1, r = len[i], cur = 0;
        while (l <= r) {
          int mid = l + r >> 1;
          if (mn[i][mid] >= -sum) {
            cur = mid;
            l = mid + 1;
          }
          else {
            r = mid - 1;
          }
        }
        auto &w = v[i][-sum + T];
        int cnt = upper_bound(w.begin(), w.end(), cur) - w.begin();
        ret = max(ret, cnt);
      }
    }
  }
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    len[i] = s[i].size();
    s[i] = "0" + s[i];
    mn[i][0] = T;
    for (int j = 1; j <= len[i]; j++) {
      p[i][j] = p[i][j - 1] + (s[i][j] == '(' ? 1 : -1);
      mn[i][j] = min(mn[i][j - 1], p[i][j]);
      v[i][p[i][j] + T].push_back(j);
    }
  }
  memset(dp, -1, sizeof dp);
  cout << yo(0, 0) << '\n';
  return 0;
}