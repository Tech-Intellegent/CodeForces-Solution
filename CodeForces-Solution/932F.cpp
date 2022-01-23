#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

struct Line {
    ll k, d;
    ll eval(int x) {
        return k * x + d;
    }
};

struct LiChaoNode {
    Line line;
    LiChaoNode* left = nullptr;
    LiChaoNode* right = nullptr;

    LiChaoNode(Line line) : line(line) {}

    void add_line(Line nw, int l, int r) {
        int m = (l + r) / 2;
        bool lef = nw.eval(l) < line.eval(l);
        bool mid = nw.eval(m) < line.eval(m);
        if(mid) swap(line, nw);
        if(l == r) return;
        if(lef != mid) {
            if(left == nullptr) left = new LiChaoNode(nw);
            else left -> add_line(nw, l, m);
        }
        else{
            if(right == nullptr) right = new LiChaoNode(nw);
            else right -> add_line(nw, m + 1, r);
        }
    }

    ll query(int x, int l, int r) {
        ll val = line.eval(x);
        int m = (l + r) / 2;
        if(l < r) {
            if(x <= m && left != nullptr) val = min(val, left -> query(x, l, m));
            if(x > m && right != nullptr) val = min(val, right -> query(x, m + 1, r));
        }
        return val;
    }
    void clear()
    {
        if(left){
            left -> clear();
            delete left;
        }
        if(right){
            right -> clear();
            delete right;
        }
    }
};

struct LiChaoTree
{
    int L, R;
    LiChaoNode* root;

    LiChaoTree() : L(numeric_limits<int>::min() / 2), R(numeric_limits<int>::max() / 2), root(nullptr) {}
    LiChaoTree(int L, int R) : L(L), R(R) {
        root = new LiChaoNode({0, numeric_limits<ll>::max() / 2});
    }

    void add_line(Line line) {
        root -> add_line(line, L, R);
    }
    ll query(int x) {
        return root -> query(x, L, R);
    }
    void clear()
    {
        root -> clear();
        delete root;
    }
    ~LiChaoTree() {
    }
};

LiChaoTree a[N];
ll ans[N], x[N], y[N];
vector<Line> p[N];
vector<int> g[N];
void dfs(int u, int pre = 0)
{
    bool child = 0;
    a[u] = LiChaoTree(-100010, 100010);
    for(auto v: g[u]){
        if(v == pre) continue;
        child = 1;
        dfs(v, u);
        if(p[u].size() < p[v].size()) swap(p[u], p[v]), swap(a[u], a[v]);
        for(auto x: p[v]) a[u].add_line(x), p[u].push_back(x);
        //a[v].clear();
        p[v].clear();

    }
    if(!child) ans[u] = 0;
    else ans[u] = a[u].query(x[u]);
    a[u].add_line({y[u], ans[u]});
    p[u].push_back({y[u], ans[u]});
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) cin >> y[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}