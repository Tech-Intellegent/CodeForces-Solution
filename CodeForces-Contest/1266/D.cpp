#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; scanf("%d",&a); a; } )

const int N = 1e5 + 9;
const int mod = 1e9 + 7;

gp_hash_table<int, ll> mp[N];
set<int> g[N];
set<pii> ed;
int32_t main()
{
    int n=in(), m=in();
    for(int i=1; i<=m; i++){
        int u=in(), v=in(), w=in();
        ed.insert(make_pair(u, v));
        g[u].insert(v);
        mp[u][v]+=w;
    }
    //auto it=0;
    while(!ed.empty()){
        //if(it>100) assert(0);
        pii e= *(ed.begin());
        ed.erase(e);
        int u=e.first, v=e.second;
        //deb(u);
        //deb(v);
        ll nw=mp[u][v];
        vector<int> add;
        for(auto w: g[v]){
            ll mn=min(nw, mp[v][w]);
            nw-=mn, mp[v][w]-=mn;
            if(mp[v][w]==0){
                g[v].erase(w);
                ed.erase(make_pair(v, w));
            }
            if(u!=w){
                add.eb(w);
                ed.insert(make_pair(u, w));
                mp[u][w]+=mn;
            }
            if(nw==0) break;
        }
        for(auto x: add) if(mp[u][x]>0) g[u].insert(x);
        if(nw==0){
            g[u].erase(v);
        }
        mp[u][v]=nw;
        //++it;
    }
    assert(0);
    vector<pii> ans;
    vector<ll> wt;
    for(int u=1; u<=n; u++) for(auto v: g[u]){
        ll w=mp[u][v];
        if(w>0) ans.eb(u, v), wt.eb(w);
    }
    //assert((int)ans.size()<=300000);
    int p= ans.size();
    cout<<p<<nl;
    for(int i=0; i<p; i++){
        pii x=ans[i];
        printf("%d %d %lld\n", x.first, x.second, wt[i]);
    }
    return 0;
}