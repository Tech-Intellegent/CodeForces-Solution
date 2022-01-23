#include<bits/stdc++.h>
using namespace std;

const int N = 420;

/*
all the edges should be in the same connected component
#undirected graph: euler path: all degrees are even or exactly two of them are odd.
#undirected graph: euler circuit: all degrees are even
*/


//euler path in an undirected graph
//it also finds circuit if it exists
vector<pair<int, int>> g[N];
vector<pair<int, int>> ans;
int done[N];
int vis[N * N]; //number of edges
void dfs(int u)
{
    while(done[u] < g[u].size()){
        auto e = g[u][done[u]++];
        if(vis[e.second]) continue;
        vis[e.second] = 1;
        ans.push_back({u, e.first});
        dfs(e.first);
    }
}

int solve(int n)
{
    ans.clear();
    memset(done, 0, sizeof done);
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) if(done[i] < g[i].size()) dfs(i);
    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> deg(n + 1, 0);
        for(int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            g[u].push_back({v, i});
            g[v].push_back({u, i});
            deg[u]++, deg[v]++;
        }
        int sz = m;
        for(int i = 1; i <= n; i++){
            if(deg[i] & 1){
                ++sz;
                g[n + 1].push_back({i, sz});
                g[i].push_back({n + 1, sz});
            }
        }
        int ok = solve(n + 1);
        assert(ok);
        vector<int> in(n + 2, 0), out(n + 2, 0);
        for(auto e: ans){
            if(e.first != n + 1 && e.second != n + 1){
                in[e.second]++; out[e.first]++;
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++) res += in[i] == out[i];
        cout << res <<'\n';
        for(auto e: ans) if(e.first != n + 1 &&  e.second != n + 1) cout << e.first << ' ' << e.second << '\n';
        for(int i = 0; i <= n + 1; i++) g[i].clear();
    }
    return 0;
}
/*
1
6 4
1 6
4 5
2 1
2 6
*/