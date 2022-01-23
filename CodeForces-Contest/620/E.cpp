#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9;
int a[N];
int st[N], en[N], T, f[N];

struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    long long t[4 * N], lazy[4 * N];
    ST() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int n, int b, int e) {
        if (lazy[n] == 0) return;
        t[n] = 1LL << lazy[n];
        if (b != e) {
            lazy[lc] = lazy[n];
            lazy[rc] = lazy[n];
        }
        lazy[n] = 0;
    }
    inline long long combine(long long a,long long b) {
        return a | b;
    }
    inline void pull(int n) {
        t[n] = t[lc] | t[rc];
    }
    void build(int n, int b, int e) {
        lazy[n] = 0;
        if (b == e) {
            t[n] = 1LL << a[f[b]];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if (j < b || e < i) return;
        if (i <= b && e <= j) {
            lazy[n] = v; //set lazy
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    long long query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (i > e || b > j) return 0; //return null
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
}t;

vector<int> g[N];
void dfs(int u, int p = 0) {
	st[u] = ++T;
	f[T] = u;
	for (auto v: g[u]) {
		if (v ^ p) {
			dfs(v, u);
		}
	}
	en[u] = T;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
	    int u, v; cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	dfs(1);
	t.build(1, 1, T);
	while (m--) {
		int ty, u; cin >> ty >> u;
		if (ty == 1) {
			int k; cin >> k;
			t.upd(1, 1, T, st[u], en[u], k);
		}
		else {
			auto x = t.query(1, 1, T, st[u], en[u]);
			cout << __builtin_popcountll(x) << '\n';
		}
	}
    return 0;
}