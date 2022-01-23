#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;

const int kinds = 128;///maximum ASCII value of any character of the string
char str[N];
int K, buc[N], r[N], sa[N], X[N], Y[N], high[N];
bool cmp(int *r, int a, int b, int x) {
    return (r[a] == r[b] && r[a+x] == r[b+x]);
}
void suffix_array_DA(int n, int m) {
    int *x = X, *y = Y, i, j, k = 0, l;
    memset(buc, 0, sizeof(buc));
    for(i = 0; i < n; i++) buc[ x[i]=str[i] ]++;
    for(i = 1; i < m; i++) buc[i] += buc[i-1];
    for(i = n-1; i >= 0; i--) sa[--buc[x[i]]] = i;
    for(l = 1, j = 1; j < n; m = j, l <<= 1) {
        j = 0;
        for(i = n-l; i < n; i++) y[j++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= l) y[j++] = sa[i]-l;
        for(i = 0; i < m; i++) buc[i] = 0;
        for(i = 0; i < n; i++) buc[ x[y[i]] ]++;
        for(i = 1; i < m; i++) buc[i] += buc[i-1];
        for(i = n-1; i >= 0; i--) sa[ --buc[ x[y[i]] ]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, j = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], l) ? j-1 : j++;
    }
    for(i = 1; i < n; i++) r[sa[i]] = i;
    for(i = 0; i < n-1; high[r[i++]] = k)
        for(k ? k--: 0, j = sa[r[i]-1]; str[i+k] == str[j+k]; k++);
}
vector<int> suffix_array_construction(string s) {
    int n=s.size();
    for(int i=0; i<n; i++) str[i]=s[i];
    str[n]='\0';
    suffix_array_DA(n+1,kinds);
    vector<int>saa;
    for(int i=1; i<=n; i++) saa.push_back(sa[i]);
    return saa;
}
///lower bound of string t
int lb(string &ss, string &t, vector<int> &sa) {
    int sz = ss.size();
    int l=0,r=sz-1;
    int k=t.size();
    int ans=sz;
    while(l<=r) {
        int mid = (l+r)/2;
        if(ss.substr(sa[mid],min(sz-sa[mid],k)) >= t) ans=mid,r=mid-1;
        else l = mid+1;
    }
    return ans;
}
///upper bound of string t
int ub(string &ss, string &t, vector<int> &sa) {
    int sz = ss.size();
    int l=0,r=sz-1;
    int k=t.size();
    int ans=sz;
    while(l<=r) {
        int mid = (l+r)/2;
        if(ss.substr(sa[mid],min(sz-sa[mid],k)) > t) ans=mid,r=mid-1;
        else l = mid+1;
    }
    return ans;
}
template <int32_t MOD>
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
    modint<MOD> pow(uint64_t k) const {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1) {
            if (k & 1) y *= x;
            x *= x;
        }
        return y;
    }
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

vector<mint> BerlekampMassey(vector<mint> S) {
	int n = (int)S.size(), L = 0, m = 0;
	vector<mint> C(n), B(n), T;
	C[0] = B[0] = 1;
	mint b = 1;
	for(int i = 0; i < n; i++) {
        ++m; mint d = S[i];
		for(int j = 1; j <= L; j++) d += C[j] * S[i - j];
		if (d == 0) continue;
		T = C; mint coef = d * b.inv();
		for(int j = m; j < n; j++) C[j] -= coef * B[j - m];
		if (2 * L > i) continue;
		L = i + 1 - L; B = T; b = d; m = 0;
	}
	C.resize(L + 1); C.erase(C.begin());
	for(auto &x: C)  x *= -1;
	return C;
}
vector<mint> combine (int n, vector<mint> &a, vector<mint> &b, vector<mint> &tr) {
	vector<mint> res(n * 2 + 1, 0);
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) res[i + j] += a[i] * b[j];
	}
	for (int i = 2 * n; i > n; --i) {
		for (int j = 0; j < n; j++) res[i - 1 - j] += res[i] * tr[j];
	}
	res.resize(n + 1);
	return res;
};
// transition -> for(i = 0; i < x; i++) f[n] += tr[i] * f[n-i-1]
// S contains initial values, k is 0 indexed
mint LinearRecurrence(vector<mint> &S, vector<mint> &tr, long long k) {
	int n = S.size(); assert(n == (int)tr.size());
	if (n == 0) return 0;
	if (k < n) return S[k];
	vector<mint> pol(n + 1), e(pol);
	pol[0] = e[1] = 1;
	for (++k; k; k /= 2) {
		if (k % 2) pol = combine(n, pol, e, tr);
		e = combine(n, e, e, tr);
	}
	mint res = 0;
	for (int i = 0; i < n; i++) res += pol[i + 1] * S[i];
	return res;
}
string f[100];
vector<int> SA[100];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[1] = "a", f[2] = "b";
    int k;
    for (int i = 3; ; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i].size() >= 1e6) break;
        k = i;
    }
    for (int i = 1; i <= k; i++) SA[i] = suffix_array_construction(f[i]);
    long long n; int q; cin >> n >> q;
    while (q--) {
        string s; cin >> s;
        int z = 1;
        while (f[z].size() < s.size()) z++;
        if (z > n) {
        	cout << 0 << '\n';
        	continue;
        }
        assert(z + 4 <= k);
        vector<mint> v;
        for (int i = z; i <= z + 5; i++) {
        	v.push_back(ub(f[i], s, SA[i]) - lb(f[i], s, SA[i]));
        }
        auto tr = BerlekampMassey(v);
        v.resize(tr.size());
        cout << LinearRecurrence(v, tr, n - z) << '\n';
    }
    return 0;
}