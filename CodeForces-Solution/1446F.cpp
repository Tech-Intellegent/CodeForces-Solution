#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
using str = string; // yay python!
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
 
// pairs
#define mp make_pair
#define f first
#define s second
 
// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 998244353;
const int MX = 3e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
// helper funcs
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
 
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set
 
// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);
 
tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
 
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int& n, vector<T>& x) { re(n); x.rsz(n); trav(a,x) re(a); }
 
// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
 
	#endif
}
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}
 
// OUTPUT
tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif
 
// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
 
int N, ans;
int deg[520][520];
bool infect[520][520], ori[520][520];
vi adj[300000];
bool present[MX], ORI[MX];
 
vpi nei(pi p) {
	vpi res;
	res.pb({p.f-1,p.s});
	res.pb({p.f+1,p.s});
	if (p.f%2 == 0) {
		res.pb({p.f+1,p.s-1});
	} else {
		res.pb({p.f-1,p.s+1});
	}
	return res;
}
 
int hsh(pi p) { return 520*p.f+p.s; }
 
bool vis[MX];
int sum_ori, sum_num;
 
AR<AR<AR<int,2>,2>,2> dfs(int a, int b) {
	AR<AR<AR<int,2>,2>,2> ans; F0R(i,2) F0R(j,2) F0R(k,2) ans[i][j][k] = MOD;
	// will be on, on, parent can't initially be on
	vis[a] = 1;
	sum_ori += ORI[a];
	sum_num += 1;
	AR<AR<AR<int,2>,3>,3> stor;
	F0R(i,3) F0R(j,3) F0R(k,2) stor[i][j][k] = MOD;
	stor[0][0][0] = 0;
	trav(t,adj[a]) if (t != b) {
		if (vis[t]) {
			ps("SICK");
			exit(0);
		}
		auto res = dfs(t,a);
		AR<AR<AR<int,2>,3>,3> STOR;
		F0R(i,3) F0R(j,3) F0R(k,2) STOR[i][j][k] = MOD;
		F0R(i,3) F0R(j,3) F0R(k,2) if (stor[i][j][k] != MOD) {
			F0R(I,2) F0R(J,2) F0R(K,2) {
				ckmin(STOR[i+I][j+J][k|K],stor[i][j][k]+res[I][J][K]);
			}
		}
		swap(stor,STOR);
		// # of eventually neighbors
		// # of on neighbors
		// can't be on
	}
	if (ORI[a]) {
		// leave on
		F0R(eventual_nei,3) F0R(on_nei,3) F0R(ok_on,1) {
			ckmin(ans[1][1][0],stor[eventual_nei][on_nei][ok_on]+1);
		}
		// turn off
		FOR(eventual_nei,1,3) F0R(on_nei,2) F0R(ok_on,2) {
			ckmin(ans[eventual_nei-1][0][on_nei],stor[eventual_nei][on_nei][ok_on]);
		}
	} else {
		FOR(eventual_nei,1,3) F0R(on_nei,3) F0R(ok_on,2)
			ckmin(ans[eventual_nei-1][0][0],stor[eventual_nei][on_nei][ok_on]);
		// # of eventually neighbors = 1 -> need parent
		// # of eventually neighbors = 2 ->
	}
	// dbg("DOING",a,b);
	// if (a == 1012 || a == 2021) {
	// 	dbg("REC",a);
	// 	F0R(i,2) F0R(j,2) F0R(k,2) dbg(i,j,k,ans[i][j][k]);
	// }
	return ans;
}
 
void solve(int x) {
	sum_ori = sum_num = 0;
	auto res = dfs(x,-1);
	int huh = MOD;
	F0R(i,2) F0R(j,2) ckmin(huh,res[1][i][j]);
	dbg(huh);
	// dbg("HA",sum_ori,sum_num,huh);
	ans += sum_ori-huh+sum_num-huh+sum_num;
	// # on - ( need ) + (size-need)+size
 
}
 
int main() {
	setIO(); re(N);
	queue<pi> todo;
	F0R(i,N) {
		int x,y; re(x,y);
		x += 2, ++y;
		infect[x][y] = 1;
		ori[x][y] = 1;
		trav(t,nei({x,y})) {
			deg[t.f][t.s] ++;
			if (deg[t.f][t.s] == 2) todo.push(t);
		}
	}
	while (sz(todo)) {
		pi p = todo.ft; todo.pop();
		if (infect[p.f][p.s]) continue;
		infect[p.f][p.s] = 1;
		trav(t,nei(p)) {
			deg[t.f][t.s] ++;
			if (deg[t.f][t.s] == 2) todo.push(t);
		}
	}
	// F0R(i,7) present[i] = 1;
	// // ORI[0] = ORI[1] = ORI[4] = ORI[5] = ORI[6] = 1;
	// ORI[0] = ORI[5] = ORI[4] = ORI[6] = 1;
	// ORI[2] = 1;
	// auto ae = [&](int a, int b) {
	// 	adj[a].pb(b), adj[b].pb(a);
	// };
	// ae(0,1), ae(1,5), ae(1,2), ae(2,3), ae(3,4), ae(3,6);
	F0R(i,520) F0R(j,520) if (infect[i][j]) {
		present[hsh({i,j})] = 1;
		ORI[hsh({i,j})] = ori[i][j];
		trav(t,nei({i,j})) if (infect[t.f][t.s]) 
			adj[hsh({i,j})].pb(hsh(t)); 
		// todo.push({});
	}
	F0R(i,300000) if (present[i] && !vis[i]) solve(i);
	ps("RECOVERED");
	ps(ans);
 
	// dbg("HA");
 
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/