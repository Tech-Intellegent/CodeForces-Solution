#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], cnt[2];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  while (q--) {
    int ty, k; cin >> ty >> k;
    if (ty == 1) {
      cnt[a[k]]--;
      a[k] ^= 1;
      cnt[a[k]]++;
    }
    else {
      if (k <= cnt[1]) {
        cout << 1 << '\n';
      }
      else {
        cout << 0 << '\n';
      }
    }
  }
  return 0;
}