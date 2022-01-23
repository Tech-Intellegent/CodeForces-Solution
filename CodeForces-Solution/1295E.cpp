#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

template <class T>
struct BIT
{
    ///1-indexed
	int sz;
	vector<T> t;

	void init(int n) ///max size of array
	{
		sz = n;
		t.assign(sz,0);
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx)) ans += t[idx];
		return ans;
	}

	void upd(int idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <sz; idx += (idx & -idx)) t[idx] += val;
	}

	void upd(int l, int r, T val)
	{
	    upd(l,val);
	    upd(r+1,-val);
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};
ll pc[N], sc[N], pre[N], suf[N];
int a[N], b[N], c[N];
int32_t main()
{
    int n = in();
    for(int i = 1; i <= n; i++) a[i] = in();
    for(int i = 1; i <= n; i++) b[i] = in();
    for(int i = 1; i <= n; i++) c[a[i]] = b[i];
    ll ans = min(b[1], b[n]);
    BIT<ll> t;
    t.init(N);
    int k = a[1];
    for(int i = 1; i< n; i++){
        t.upd(a[i], 1);
        if(t.query(1, i) == i) ans = 0;
    }
    t.init(N);
    vector<int> v;
    for(int i = 1; i<= 50; i++) v.eb(i);
    v.eb(k);
    for(auto k: v){
        if(k >= n) continue;
        ll ksum = 0;
        for(int i = 1; i <= k; i++) ksum += c[i];
        ll sum = 0;
        t.init(N);
        for(int i = 1; i < n; i++){
            sum += c[a[i]];
            t.upd(a[i], c[a[i]]);
            ll p = t.query(1, k);
            ans = min(ans, sum + ksum - 2LL * p);
        }
    }
    cout << ans << nl;
    return 0;
}