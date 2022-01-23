#include<bits/stdc++.h>
using namespace std;

int query(int i) {
  cout << "? " << i << '\n';
  cout.flush();
  int x; cin >> x;
  return x;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    set<int> se;
    for (int i = 1; i <= n; i++) {
      se.insert(i);
    }
    vector<int> p(n + 1);
    while (!se.empty()) {
      int k = *se.begin();
      se.erase(k);
      int last = k;
      while (query(k) != k);
      while (1) {
        int x = query(k);
        p[last] = x;
        if (x == k) break;
        se.erase(x);
        last = x;
      }
    }
    cout << "!";
    for (int i = 1; i <= n; i++) {
      cout << " " << p[i];
    }
    cout << endl;
  }
  return 0;
}