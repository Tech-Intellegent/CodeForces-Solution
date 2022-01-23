#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  multiset<int> se;
  for (int i = 1; i <= n * n; i++) {
    int k; cin >> k;
    se.insert(k);
  }
  vector<int> ans;
  ans.push_back(*se.rbegin());
  se.erase(prev(se.end()));
  while (se.size()) {
    int cur = *se.rbegin();
    se.erase(prev(se.end()));
    for (auto x: ans) {
      se.erase(se.find(__gcd(x, cur)));
      se.erase(se.find(__gcd(x, cur)));
    }
    ans.push_back(cur);
  }
  for (auto x: ans) cout << x << ' ';
  return 0;
}