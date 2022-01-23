#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;
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

int a[N];
long long cnt[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, p; cin >> n >> p;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		if (p == 1) {
			cout << n % 2 << '\n';
			for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
			continue;
		}
		sort(a + 1, a + n + 1);
		int mx = -1;
		for (int i = n; i >= 1; i--) {
			if (cnt[a[i]] & 1) {
				mx = a[i];
				cnt[a[i]] = 1;
				break;
			}
			else cnt[a[i]] = 0;
		}
		if (mx == -1) {
			cout << 0 << '\n';
			continue;
		}
		mint s = 0;
		int cur = 1;
		for (int i = 0; i < mx; ) {
			if (cnt[i] < p) {
				s += mint(p).pow(i) * cnt[i];
				cnt[i] = 0;
				while (cur <= n && a[cur] <= i) cur++;
				i = a[cur];
			}
			else {
				cnt[i + 1] += cnt[i] / p;
				cnt[i] %= p;
				s += mint(p).pow(i) * cnt[i];
				cnt[i] = 0;
				i++;
			}
		}
		//cout << mx << ": " << s << ' ' << cnt[mx] << '\n';
		s += mint(p).pow(mx) * (cnt[mx] >> 1);
		mint ans = mint(p).pow(mx) * ((cnt[mx] + 1) >> 1);
		if (cnt[mx] & 1) ans -= s;
		else ans = s - ans;
		cout << ans << '\n';
		cnt[mx] = 0;
	}
    return 0;
}