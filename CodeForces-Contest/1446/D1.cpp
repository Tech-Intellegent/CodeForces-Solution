#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int cnt[N][101], a[N];
vector<int> id[N];
int res;
unordered_map<int, bool> mp[N];
int yo(int l, int r, int op = 0) {
  if (l > r) return 0;
  if (l == r) return 0;
  if (l + 1 == r) return a[l] == a[r] ? 0 : 2;
  if (r - l + 1 < res) return res;
  if (mp[l].find(r) != mp[l].end()) return res;
  mp[l][r] = true;
  int mx = -1, f = -1, z = 0;
  for (int i = 1; i <= 100; i++) {
    int x = cnt[r][i] - cnt[l - 1][i];
    if (x > mx) {
      mx = x;
      z = 1;
      f = i;
    }
    else if (x == mx) {
      z++;
    }
  }
  if (z > 1) return r - l + 1;
  if (mx == (r - l + 1)) return 0;
  int p = lower_bound(id[f].begin(), id[f].end(), l) - id[f].begin();
  int q = upper_bound(id[f].begin(), id[f].end(), r) - id[f].begin() - 1;
  int ans = 0;
  if (op == 0 || op == 2) {
    for (int k = q; k >= p; k--) {
      int len = id[f][k] - l;
      if (mx - (q - k + 1) <= len / 2) {
        ans = max(ans, yo(l, id[f][k] - 1));
        res = max(res, ans);
        break;
      }
      else {
        ans = max(ans, yo(l, id[f][k] - 1, 1));
        res = max(res, ans);
      }
    }
  }
  if (op == 0 || op == 1) {
    for (int k = p; k <= q; k++) {
      int len = r - id[f][k];
      if (mx - (k - p + 1) <= len / 2) {
        ans = max(ans, yo(id[f][k] + 1, r));
        res = max(res, ans);
        break;
      }
      else {
        ans = max(ans, yo(id[f][k] + 1, 2));
        res = max(res, ans);
      }
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    id[a[i]].push_back(i);
    for (int k = 1; k <= 100; k++) {
      cnt[i][k] += cnt[i - 1][k];
    }
    cnt[i][a[i]]++;
  }
  cout << yo(1, n) << '\n';
  return 0;
}