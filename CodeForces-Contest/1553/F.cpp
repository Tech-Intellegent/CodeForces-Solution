#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, B = 500, C = N / B + 5;

template <class T>
struct SQRT {
  int n; vector<T> a, b;
  SQRT() {}
  SQRT(int _n) {
    n = _n; a.assign(n + 1, 0);
    b.assign(C, 0);
  }
  T query(int k) {
    return a[k] + b[k / B];
  }
  void upd(int i, T val) {
    int r = (i + B - 1) / B * B;
    while (i < r) {
      a[i] += val;
      ++i;
    }
    for (int j = i / B; j < C; j++) {
      b[j] += val;
    }
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  SQRT<long long> s(N);
  SQRT<int> cnt(N);
  int n; cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    for (int j = 0; j < N; j += k) {
      int l = max(1, j), r = min(N - 1, j + k - 1);
      ans += s.query(l, r) - 1LL * cnt.query(l, r) * j;
    }
    for (int j = 1, last; j <= k; j = last + 1) {
      last = k / (k / j);
      int c = cnt.query(j, last);
      ans += 1LL * k * c - (k / j) * s.query(j, last);
      // k / x yields the same value for j <= x <= last.
    }
    ans += 1LL * k * cnt.query(k + 1, N - 1);
    s.upd(k, k);
    cnt.upd(k, 1);
    cout << ans << ' ';
  }
  return 0;
}