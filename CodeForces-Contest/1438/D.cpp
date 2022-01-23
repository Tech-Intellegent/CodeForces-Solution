#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int cnt[30], a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int k = 0; k < 30; k++) {
      cnt[k] += a[i] >> k & 1;
    }
  }
  for (int k = 0; k < 30; k++) {
    if (cnt[k] % 2 == 1 && (n - cnt[k]) % 2 == 1) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  vector<array<int, 3>> ans;
  for (int i = 1; i + 2 <= n; i += 2) {
    ans.push_back({i, i + 1, i + 2});
    int z = a[i] ^ a[i + 1] ^ a[i + 2];
    a[i] = a[i + 1] = a[i + 2] = z;
  }
  for (int k = 0; k < 30; k++) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
      c += a[i] >> k & 1;
    }
    if (c == 0 || c == n);
    else {
      int z = c % 2 == 0 ? 1 : 0;
      int id = -1;
      for (int i = 1; i <= n; i++) {
        if ((a[i] >> k & 1) == !z) id = i;
      }
      assert(id != -1);
      vector<int> v;
      for (int i = 1; i <= n; i++) {
        if ((a[i] >> k & 1) == z) {
          v.push_back(i);
        }
      }
      assert(v.size() % 2 == 0);
      for (int i = 0; i < v.size(); i += 2) {
        ans.push_back({id, v[i], v[i + 1]});
        int z = a[id] ^ a[v[i]] ^ a[v[i + 1]];
        a[id] = a[v[i]] = a[v[i + 1]] = z;
      }
    }
  }
  assert(ans.size() <= n);
  cout << ans.size() << '\n';
  for (auto x: ans) {
    cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
  }
  return 0;
}