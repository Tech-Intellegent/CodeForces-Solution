#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
//add lines with -m and -b and return -ans to
//make this code work for minimums.(not -x)
const long long inf = -(1LL<<62);
struct line {
    long long m, b; int z;
    mutable function<const line*() > succ;
    bool operator < (const line& rhs) const {
        if (rhs.b != inf) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        long long x = rhs.m;
        long long q =  b - s->b, r = (s->m - m) * x;
        if (q == r) return z < rhs.z;
        return q < r;
    }
};
struct CHT : public multiset<line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y -> m == z -> m && y -> b <= z -> b;
        }
        auto x = prev(y);
        if (z == end()) return y -> m == x -> m && y -> b <= x -> b;
        return ((__int128) (x -> b - y -> b))*(z -> m - y -> m) >= ((__int128) (y -> b - z -> b))*(y -> m - x -> m);
    }
    void add(long long m, long long b, int c) {
        auto y = insert({ m, b, c });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    pair<long long, int> query(long long x) {
        auto l = *lower_bound((line) { x, inf, -1 });
        return {l.m * x + l.b, l.z};
    }
};

int n;
long long a[N], p[N], s[N], dp[N];
int cnt[N];
pair<long long, int> yo(long long c) {
  CHT *t;
  t = new CHT();
  for (int i = 1; i <= n; i++) {
    t -> add(-s[i], dp[i - 1] + p[i], cnt[i - 1]);
    auto x = t -> query(n - i + 1);
    dp[i] = x.first - p[i] + s[i] * (n - i + 1) + c;
    cnt[i] = x.second + 1;
  }
  return {dp[n], cnt[n]};
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k; cin >> n >> k;
  ++k;
  k = min(k, n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<long long>());
  for (int i = n; i >= 1; i--) {
    s[i] = s[i + 1] + a[i];
    p[i] = p[i + 1] + a[i] * (n - i + 1);
  }
  int z = yo(0).second;
  k = min(k, z);
  long long l = -1e12-1, r = 1e12+1;
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    auto nw = yo(mid);
    //cout << mid << ' ' << nw.first << ' ' << nw.second << '\n';
    if (nw.second <= k) ans = nw.first - 1LL * k * mid, l = mid + 1;
    else r = mid - 1;
  }
  cout << ans << '\n';
  return 0;
}