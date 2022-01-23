#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a[2];
    long long sum[2], tot[2]; sum[0] = sum[1] = 0; tot[0] = tot[1] = 0;
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      sum[k % 2] += k;
      a[k % 2].push_back(k);
    }
    for (int i = 0; i < 2; i++) {
      sort(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; i++) {
      int cur = i % 2;
      if (!a[cur].empty() and (a[cur ^ 1].empty() or a[cur].back() >= a[cur ^ 1].back())) {
        sum[cur] -= a[cur].back();
        tot[cur] += a[cur].back();
        a[cur].pop_back();
      }
      else {
        sum[cur ^ 1] -= a[cur ^ 1].back();
        a[cur ^ 1].pop_back();
      }
    }
    if (tot[0] > tot[1]) {
      cout << "Alice\n";
    }
    else if (tot[0] < tot[1]) {
      cout << "Bob\n";
    }
    else {
      cout << "Tie\n";
    }
  }
  return 0;
}