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

struct dsu {
	vector<int> par, rnk, size; int c;
	dsu(int n) : par(n+1), rnk(n+1,0), size(n+1,1), c(n) {
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }///connected components
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1; else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j; size[j] += size[i];
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};
ll yo(int n, dsu A, int a, int b, int ty)
{
    //cout<<"asche\n";
    ll sum=0, sqsum=0;
    vector<int> vis(n+1, 0);
    if(ty==0){
        vis[a]=1;
        assert(A.get_size(a)==1);
    }
    if(ty==1){
        vis[b]=1;
        assert(A.get_size(b)==1);
    }
    if(ty==2){
        vis[a]=1, vis[b]=1;
        assert(A.get_size(a)==1);
        assert(A.get_size(b)==1);
    }
    for(int i=1; i<=n; i++){
        int k=A.find(i);
        if(vis[k]==0){
            vis[k]=1;
            int s=A.get_size(k);
            if(ty==0){
                if(A.find(b)==k) s--;
            }
            if(ty==1){
                if(A.find(a)==k) s--;
            }
            //deb(s);
            sum+=s;
            sqsum+=1LL*s*s;
        }
    }
    return sum*sum-sqsum;
}
int32_t main()
{
    int t=in();
    while(t--){
        int n=in(), m=in(), a=in(), b=in();
        dsu A(n), B(n), AB(n);
        for(int i=1; i<=m; i++){
            int u=in(), v=in();
            int dum;
            if(u==a||v==a){
            }
            else A.merge(u, v);

            int dd;
            if(u==b||v==b){
            }
            else B.merge(u, v);
            int dm;
            if((u==a||v==b)||(u==b||v==a)){

            }
            else AB.merge(u, v);
        }
        ll ans=yo(n, A, a, b, 0)+yo(n, B, a, b, 1)-yo(n, AB, a, b, 2);
        assert(ans%2==0);
        assert(ans>=0);
        ans/=2;
        printf("%lld\n", ans);
    }
    return 0;
}