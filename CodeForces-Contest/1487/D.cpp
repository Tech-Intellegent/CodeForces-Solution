#include<bits/stdc++.h>
using namespace std;

int f(int n) {
  return 2 * n * (n + 1) + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  for (int i = 1; f(i) < 1e9 + 10; i++) {
    v.push_back(f(i));
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << upper_bound(v.begin(), v.end(), n) - v.begin() << '\n';
  }
  return 0;
}