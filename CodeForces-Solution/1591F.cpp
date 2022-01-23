#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 2, mod = 998244353;
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

struct node {
	node *l, *r;
	mint lazy;
	mint sum;
	bool zero, mul;
	node() {
		l = NULL;
		r = NULL;
		lazy = sum = 0;
		zero = false; mul = false;
	}
};
void propagate(node* t, int b, int e) {
	if (t->lazy == 0 and t -> zero == false and t -> mul == false) return;
	if (t -> mul) {
		t -> sum *= mod - 1;
	}
	t->sum += t->lazy * ((e - b + 1) % mod);
	if (t -> zero) {
		t -> sum = 0;
	}
	if(!t->l) t->l = new node();
	if(!t->r) t->r = new node();
	t->l->lazy += t->lazy;
	t->r->lazy += t->lazy;
	t->lazy = 0;
	t -> l -> zero = t -> r -> zero = t -> zero;
	t -> zero = false;	
	t -> l -> mul = t -> r -> mul = t -> mul;
	t -> mul = false;
}
void upd(node* t, int b, int e, int i, int j, mint v) {
	propagate(t, b, e);
	if(!t || b > j || e < i) return;
	if(b >= i && e <= j) {
		t->lazy += v;
		propagate(t, b, e);
		return;
	}
	int mid = (b + e) / 2;
	if(!t->l) t->l = new node();
	if(!t->r) t->r = new node();
	upd(t->l, b, mid, i, j, v);
	upd(t->r, mid + 1, e, i, j, v);
	t->sum = t->l->sum + t->r->sum;
}
void mul_upd(node* t, int b, int e, int i, int j) {
	propagate(t, b, e);
	if(!t || b > j || e < i) return;
	if(b >= i && e <= j) {
		t->mul = true;
		propagate(t, b, e);
		return;
	}
	int mid = (b + e) / 2;
	if(!t->l) t->l = new node();
	if(!t->r) t->r = new node();
	mul_upd(t->l, b, mid, i, j);
	mul_upd(t->r, mid + 1, e, i, j);
	t->sum = t->l->sum + t->r->sum;
}
void zero_upd(node* t, int b, int e, int i, int j) {
	propagate(t, b, e);
	if(!t || b > j || e < i) return;
	if(b >= i && e <= j) {
		t->zero = true;
		propagate(t, b, e);
		return;
	}
	int mid = (b + e) / 2;
	if(!t->l) t->l = new node();
	if(!t->r) t->r = new node();
	zero_upd(t->l, b, mid, i, j);
	zero_upd(t->r, mid + 1, e, i, j);
	t->sum = t->l->sum + t->r->sum;
}
mint query(node* t, int b, int e, int i, int j) {
	propagate(t, b, e);
	if(!t || b > j || e < i) return 0;
	if(b >= i && e <= j) return t->sum;
	int mid = (b + e) / 2;
	if(!t->l) t->l = new node();
	if(!t->r) t->r = new node();
	return query(t->l, b, mid, i, j) + query(t->r, mid + 1, e, i, j);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int x; cin >> x;
	auto root = new node();
	upd(root, 1, N, 1, x, 1);
	--n;
	for (int i = 1; i <= n; i++) {
		mint sum = query(root, 1, N, 1, N);
		int x; cin >> x;
		mul_upd(root, 1, N, 1, N);
		upd(root, 1, N, 1, x, sum);
		zero_upd(root, 1, N, x + 1, N);
	}
	cout << query(root, 1, N, 1, N) << '\n';
	return 0;
}