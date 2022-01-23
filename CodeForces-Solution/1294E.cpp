#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> mp2;
vector<pii> q[2*N];
int yo(vector<int> a)
{
    int n=a.size();
    auto tmp=a;
    for(auto x: tmp) a.eb(x);
    a.insert(a.begin(), 0);
    for(int i=1; i<=2*n; i++) a[i]-=i;
    for(int i=1; i<=n; i++){
        q[i-1].eb(-(i-1), -i);
        q[i+n-1].eb(-(i-1), i);
    }
    mp2.clear();
    vector<int> ans(2*n+2, 0);
    for(int i=1; i<=2*n; i++){
        mp2[a[i]]++;
        for(auto x: q[i]){
            auto id=x.second;
            if(id<0) ans[-id]-=mp2[x.first];
            else ans[id]+=mp2[x.first];
        }
    }
    int res=2e9;
    for(int i=1; i<=n; i++){
        res=min(res, i-1+n-ans[i]);
    }
    for(int i=0; i<=2*n; i++) q[i].clear();
    return res;
}
vector<int> a[N];
gp_hash_table<int, int, chash> mp;
int32_t main()
{
    int n=in(), m=in();
    for(int i=1; i<=n; i++){
        a[i].resize(m+1);
        for(int j=1; j<=m; j++) a[i][j]=in();
    }
    ll ans=0;
    for(int j=1; j<=m; j++){
        vector<int> v;
        for(int i=1; i<=n; i++) v.eb(a[i][j]);
        mp.clear();
        for(int i=1; i<=n; i++) mp[(i-1)*m+j]=i;
        for(auto &x: v){
            if(mp[x]) x=mp[x];
            else x=n*m+1;
        }
        ans+=yo(v);
    }
    cout<<ans<<nl;
    return 0;
}