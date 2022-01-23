#include<bits/stdc++.h>
using namespace std;

int query(int l, int r) {
  if (l == r) return l;
  cout << "? " << l << ' ' << r << '\n';
  cout.flush();
  int k; cin >> k;
  return k;
}
void print(int k) {
  cout << "! " << k << '\n';
  cout.flush();
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int k = query(1, n);
  if (k == 1 || (k != n && query(k, n) == k)) {
    int l = k + 1, r = n, ans = n;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(k, mid) == k) {
        ans = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    print(ans);
  }
  else {
    int l = 1, r = k - 1, ans = 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(mid, k) == k) {
        ans = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    print(ans);
  }
  return 0;
}