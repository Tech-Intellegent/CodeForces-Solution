#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 1e9 + 7;

int pw[N];
struct PersistentSegTree
{
    struct node
    {
        int l, r, val = 0;
    }t[100 * N];
    int T = 0;

    int upd(int pre, int &cur, int b, int e, int i)
    {
        cur = ++T; t[cur] = t[pre];
        assert(T < 100 * N);
        if(b == e){
            t[cur].val = !t[pre].val;
            return t[pre].val;
        }
        int mid = b + e >> 1;
        int f = 0;
        if(i <= mid){
            f = upd(t[pre].l, t[cur].l, b, mid, i);
            if(f) f = upd(t[pre].r, t[cur].r, mid + 1, e, mid + 1);
        }
        else f = upd(t[pre].r, t[cur].r, mid + 1, e, i);
        t[cur].val = (t[t[cur].l].val + 1LL * t[t[cur].r].val * pw[mid - b + 1] % mod) % mod;
        return f;
    }

    int cmp(int x, int y, int b, int e)
    {
        if(b == e) return t[x].val < t[y].val;
        int mid = b + e >> 1;
        if(t[t[x].r].val == t[t[y].r].val) return cmp(t[x].l, t[y].l, b, mid);
        return cmp(t[x].r, t[y].r, mid + 1, e);
    }
}seg;
struct st
{
    int u, rt;
};
bool operator < (const st &a, const st& b)
{
    return seg.cmp(b.rt, a.rt, 0, N - 1);
}
priority_queue<st> q;

int d[N], par[N];
bool vis[N];
vector<pair<int, int>> g[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1; for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * 2 % mod;
    int n, m; cin >> n >> m;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int s, t; cin >> s >> t;
    memset(d, -1, sizeof d);
    q.push({s, 0});
    d[s] = 0;
    while(!q.empty()){
        auto x = q.top(); q.pop();
        int u = x.u;
        if(vis[u]) continue;
        if(u == t) break;
        vis[u] = 1;
        for(auto y: g[u]){
            int v = y.first, w = y.second;
            int nx; seg.upd(d[u], nx, 0, N - 1, w);
            if(d[v] == -1 || seg.cmp(nx, d[v], 0, N - 1)){
                d[v] = nx;
                q.push({v, d[v]});
                par[v] = u;
            }
        }
    }
    if(d[t] == -1) return cout << -1 << '\n', 0;
    vector<int> path;
    for(int u = t; u != s; u = par[u]) path.push_back(u);
    path.push_back(s);
    reverse(path.begin(), path.end());
    cout << seg.t[d[t]].val << '\n' << path.size() << '\n';
    for(auto x: path) cout << x << ' ';
    cout << '\n';
    return 0;
}