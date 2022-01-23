#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
const long long inf = 1e18;

struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    long long t[4 * N], lazy[4 * N];
    ST() {}
    inline void push(int n, int b, int e) {
        if (lazy[n] == 0) return;
        t[n] = t[n] + lazy[n];
        if (b != e) {
            lazy[lc] = lazy[lc] + lazy[n];
            lazy[rc] = lazy[rc] + lazy[n];
        }
        lazy[n] = 0;
    }
    inline long long combine(long long a,long long b) {
        return max(a, b);
    }
    inline void pull(int n) {
        t[n] = max(t[lc], t[rc]);
    }
    void build(int n, int b, int e) {
        lazy[n] = 0;
        if (b == e) {
            t[n] = 0;
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if (j < b || e < i) return;
        if (i <= b && e <= j) {
            lazy[n] = v;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    long long query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (i > e || b > j) return -inf;
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
}t;

int a[N], p[N];
long long dp[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  t.build(1, 1, n);
  vector<int> mn = {0};
  for (int i = 1; i <= n; i++) {
    while (mn.back() != 0 && p[mn.back()] > p[i]){ 
      int r = mn.back();
      mn.pop_back();
      t.upd(1, 1, n, mn.back() + 1, r, a[i] - a[r]);
    }
    mn.push_back(i);
    t.upd(1, 1, n, i, i, dp[i - 1] + a[i]);
    dp[i] = t.query(1, 1, n, 1, i);
  }
  cout << dp[n] << '\n';
  return 0;
}