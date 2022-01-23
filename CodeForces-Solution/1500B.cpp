#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
#define ll long long

using T = __int128;

// ax + by = __gcd(a, b)
// returns __gcd(a, b)
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = y = 0;
  T yy = x = 1;
  while (b) {
    T q = a / b;
    T t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}

// find z such that z % x = a, z % y = b. 
// here, z is unique modulo M = lcm(x,y).
// returns (z, M). on failure, M = -1.
pair<T, T> CRT(T x, T a, T y, T b) {
  T s, t;
  T d = extended_euclid(x, y, s, t);
  if (a % d != b % d) return make_pair(0, -1);
  T m = x * y;
  s %= m; s = (s + m) % m;
  t %= m; t = (t + m) % m;
  return make_pair((s * b % m * x % m + t * a % m * y % m) %  m / d, m / d);
}

int n, m, a[N], b[N];
ll lc;
ll f(ll x, ll y, ll k) {
  auto p = CRT(n, x, m, y);
  if (p.second == -1) return 0;
  ll cur = p.first;
  if (cur > k) return 0;
  return 1 + (k - cur) / lc;
}
ll yo(ll k) {
  ll ans = k;
  for (int i = 1; i < N; i++) {
    if (b[i] == 0) continue;
    ans -= f(b[i] - 1, i - 1, k - 1);
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  lc = 1LL * n * m / __gcd(n, m);
  ll k; cin >> k;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[x] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    if (a[x]) {
      b[i] = a[x];
    }
  }
  ll l = 1, r = 1e18, ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (yo(mid) >= k) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}