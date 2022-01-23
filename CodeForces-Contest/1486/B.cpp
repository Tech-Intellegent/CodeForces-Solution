#include<bits/stdc++.h>
using namespace std;

int yo(vector<int> a) {
  sort(a.begin(), a.end());
  int n = a.size();
  if (n & 1) return 1;
  return a[n >> 1] - a[(n >> 1) - 1] + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> x, y;
    while (n--) {
      int a, b; cin >> a >> b;
      x.push_back(a);
      y.push_back(b);
    }
    cout << 1LL * yo(x) * yo(y) << '\n';
  }
  return 0;
}