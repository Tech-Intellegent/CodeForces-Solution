#include<bits/stdc++.h>
using namespace std;

vector<int> yo(int n, int k, int cnt) {
  int sum = k * cnt;
  vector<int> ans(n + 1, 0);
  sum -= n; 
  if (sum & 1) return {-1};
  sum /= 2;
  int lim = (cnt - 1) / 2;
  for (int i = 1; i <= n; i++) {
    if (sum >= lim) {
      ans[i] = lim;
      sum -= lim;
    }
    else {
      ans[i] = sum;
      sum = 0;
    }
  }
  if (sum != 0) return {-1};
  for (int i = 1; i <= n; i++) {
    ans[i] = ans[i] * 2 + 1;
  }
  return ans;
}
int32_t main() {
  int n, k; cin >> n >> k;
  for (int cnt = 1; cnt <= 500; cnt++) {
    if (n % 2 != (k * cnt) % 2) continue;
    if (k * cnt < n) continue;
    auto v = yo(n, k, cnt);
    if (v.front() == -1) continue;
    vector<int> cur;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= v[i]; j++) {
        cur.push_back(i);
      }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      cout << "?";
      for (int j = i; j < k * cnt; j += cnt) {
        cout << " " << cur[j];
      }
      cout << endl;
      int p; cin >> p;
      ans ^= p;
    }
    cout << "! " << ans << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}