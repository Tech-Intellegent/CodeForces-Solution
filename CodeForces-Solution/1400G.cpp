#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, mod = 998244353 ;

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

struct Combi{
	int n; vector<mint> facts, finvs, invs;
	Combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n){
		facts[0] = finvs[0] = 1;
		invs[1] = 1;
	    for (int i = 2; i < n; i++) invs[i] =  invs[mod % i] * (-mod / i);
		for(int i = 1; i < n; i++){
			facts[i] = facts[i - 1] * i;
			finvs[i] = finvs[i - 1] * invs[i];
		}
	}
	inline mint fact(int n) { return facts[n]; }
	inline mint finv(int n) { return finvs[n]; }
	inline mint inv(int n) { return invs[n]; }
	inline mint ncr(int n, int k) { return n < k ? 0 : k < 0 ? 0 : facts[n] * finvs[k] * finvs[n-k]; }
};
Combi C(N);

int f[N], l[N], r[N], a[N], b[N];
mint sum[44][N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		f[l[i]]++;
		f[r[i] + 1]--;
	}
	for (int i = 1; i <= n; i++) f[i] += f[i - 1];
	for (int k = 0; k <= 40; k++) {
		for (int i = 1; i <= n; i++) {
			sum[k][i] = sum[k][i - 1] + C.ncr(f[i] - k, i - k);
		}
	}
	mint ans = sum[0][n];
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
	for (int mask = 1; mask < (1 << m); mask++) {
		int L = 1, R = n;
		set<int> se;
		for (int i = 0; i < m; i++) {
			if (mask >> i & 1) {
				L = max(L, l[a[i]]);
				L = max(L, l[b[i]]);
				R = min(R, r[a[i]]);
				R = min(R, r[b[i]]);
				se.insert(a[i]);
				se.insert(b[i]);
			}
		}
		mint cur = 0;
		int k = se.size();
		if (L <= R) cur = sum[k][R] - sum[k][L - 1];
		if (__builtin_popcount(mask) % 2 == 1) ans -= cur;
		else ans += cur;
	}
	cout << ans << '\n';
    return 0;
}