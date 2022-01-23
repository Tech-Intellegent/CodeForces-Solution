#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9;

template <class T>
struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, n + 1);
  }
  T query(int i) {
    i += n / 2;
    T ans = n + 1;
    for (; i >= 1; i -= (i & -i)) ans = min(ans, t[i]);
    return ans;
  }
  void upd(int i, T val) {
    i += n / 2;
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] = min(t[i], val);
  }
};

int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    BIT<int> t(2 * n + 10);
    t.upd(0, 0);
    int cur = 0, ok = 0;
    for (int i = 1; i <= n; i++) {
      cur += a[i] < mid ? -1 : 1;
      if (t.query(cur - 1) <= i - k) {
        ok = 1;
        break;
      }
      t.upd(cur, i);
    }
    if (ok) {
      ans = mid; l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}