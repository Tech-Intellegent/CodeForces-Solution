#include<bits/stdc++.h>
using namespace std;

int query(int i) {
  cout << "? " << i << '\n';
  cout.flush();
  int k; cin >> k;
  return k;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  int l = 2, r = n, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (query(1) < query(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  if (ans == 1) ans = n;
  else ans--;
  int last1 = query(1), last2 = query(n), f1 = 1, f2 = 1;
  for (int i = 0; i < 400; i++) {
    if (query(1) != last1) {
      f1 = 0;
    }    
    if (query(n) != last2) {
      f2 = 0;
    }
  }
  if (ans == -1) {
    if (f1 && query(1) == k / 2) ans = 1;
    else if (f2 && query(n) == k / 2) ans = n;
  }
  cout << "! " << ans << '\n';
  cout.flush();
  return 0;
}