#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9, M = 2e5 + 9;

int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
struct ST {
  int t[4 * M];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = min(t[l], t[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = min(t[l], t[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
}t;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int tc; cin >> tc;
  while (tc--) {
    int n, k; cin >> n >> k;
    t.build(1, 0, n);
    t.upd(1, 0, n, 0, 0);
    map<int, int> last;
    vector<int> l(n + 1), dp(n + 1);
    l[0] = 0; dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      int k; cin >> k;
      int cur = 1;
      while (k > 1) {
        int x = spf[k], cnt = 0;
        while (k % x == 0) {
          k /= x;
          ++cnt;
        }
        if (cnt & 1) cur *= x;
      }
      l[i] = max(l[i - 1], last[cur] + 1);
      dp[i] = 1 + t.query(1, 0, n, l[i] - 1, i - 1);
      t.upd(1, 0, n, i, dp[i]);
      last[cur] = i;
    }
    cout << dp[n] << '\n';
  }
  return 0;
}