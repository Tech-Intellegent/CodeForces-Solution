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

template <class T>
struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int dp[22][M], pre[M];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int tc; cin >> tc;
  while (tc--) {
    int n, k; cin >> n >> k;
    BIT<int> t(n + 1);
    map<int, int> last;
    for (int j = 0; j <= k; j++) {
      dp[j][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int d; cin >> d;
      int cur = 1;
      while (d > 1) {
        int x = spf[d], cnt = 0;
        while (d % x == 0) {
          d /= x;
          ++cnt;
        }
        if (cnt & 1) cur *= x;
      }
      pre[i] = last[cur];
      if (pre[i]) t.upd(1, pre[i], +1);
      for (int j = 0; j <= k; j++) {
        dp[j][i] = n;
      }
      int w = i;
      for (int j = 0; j <= k; j++) {
        int l = 1, r = w, x = 0;
        while (l <= r) {
          int mid = l + r >> 1;
          if (t.query(mid) >= j + 1) {
            x = mid; 
            l = mid + 1;
          }
          else {
            r = mid - 1;
          }
        }
        for (int l = j; l <= k; l++) {
          dp[l][i] = min(dp[l][i], dp[l - j][x] + 1);
        }
        w = x;
      }
      for (int j = 1; j <= k; j++) {
        dp[j][i] = min(dp[j][i], dp[j - 1][i]);
      }
      last[cur] = i;
    }
    cout << dp[k][n] << '\n';
  }
  return 0;
}