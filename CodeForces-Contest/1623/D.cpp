#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;

template <const int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
  inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd, P; cin >> n >> m >> rb >> cb >> rd >> cd >> P;
    mint p = mint(P) / 100;
    vector<int> a;
    map<array<int, 4>, int> id;
    int loop_start = 0, time = 0, loop_len = 0, dr = 1, dc = 1;
    while (1) {
      if (id.find({rb, cb, dr, dc}) != id.end()) {
        loop_start = id[{rb, cb}];
        loop_len = time - a[loop_start];
        break;
      }
      if (rb == rd or cb == cd) {
        a.push_back(time);
        id[{rb, cb, dr, dc}] = (int)a.size() - 1;
      }
      rb += dr;
      cb += dc;
      if (rb <= 0 or rb > n) dr *= -1, rb += 2 * dr;
      if (cb <= 0 or cb > m) dc *= -1, cb += 2 * dc;
      ++time;
    }
    mint ans = 0, mul = 1;
    for (int i = loop_start; i < a.size(); i++) {
      ans += mul * (a[i] - a[loop_start]) * p;
      mul *= mint(1) - p;
    }
    ans += mul * loop_len;
    ans /= mint(1) - mul;
    ans += a[loop_start];
    for (int i = loop_start - 1; i >= 0; i--) {
      ans = a[i] * p + (mint(1) - p) * ans;
    }
    cout << ans << '\n';
  }
  return 0;
}