#include<bits/stdc++.h>
using namespace std;

int f(vector<int> a, int len) {
  int ans = 0, n = a.size();
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && a[j] - a[i] + 1 <= len) {
      ++j;
    }
    ans = max(ans, j - i);
  }
  return ans;
}
int yo(vector<int> a, vector<int> b) {
  int n = a.size(), m = b.size();
  if (!n || !m) return 0;
  vector<int> dp(n + 1, 0);
  int cur = 0;
  for (int i = n - 1, j = m - 1; i >= 0; i--) {
    while (j >= 0 && b[j] > a[i]) {
      --j;
    }
    if (j >= 0 && b[j] == a[i]) {
      ++cur;
    }
    dp[i] = cur;
  }
  int ans = dp[0];
  deque<int> d(b.begin(), b.end());
  a.push_back(1e9 + 10);
  for (int i = 1; i <= n; i++) {
    vector<int> cur;
    while (!d.empty() and d.front() < a[i - 1] - (i - 1)) {
      d.pop_front();
    }
    for (int j = 0; j < d.size(); j++) {
      if (d[j] <= a[i] - 1) {
        cur.push_back(d[j]);
      }
      else {
        break;
      }
    }
    ans = max(ans, dp[i] + f(cur, i));
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> pa, na, pb, nb;
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      if (k > 0) {
        pa.push_back(k);
      }
      else {
        na.push_back(-k);
      }
    }    
    for (int i = 0; i < m; i++) {
      int k; cin >> k;
      if (k > 0) {
        pb.push_back(k);
      }
      else {
        nb.push_back(-k);
      }
    }
    sort(na.begin(), na.end());
    sort(nb.begin(), nb.end());
    cout << yo(pa, pb) + yo(na, nb) << '\n';
  }
  return 0;
}