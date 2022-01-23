#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ll long long
#define nl '\n'
#define deb(x) cerr<<#x" = "<<x<<nl
#define in() ( { int a ; read(a); a; } )
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
    x*=sgn; return ~c;
}

const int N = 5e5 + 9;
const int mod = 1e9 + 7;

struct st{
    vector<int> basis;
    int add(int x)
    {
        for(auto &it: basis) if((x^it)<x) x^=it;
        for(auto &it: basis) if((it^x)<it) it^=x;
        if(x) basis.eb(x);
    }
    int get_max()
    {
        int ans=0;
        for(auto x: basis) ans^=x;
        return ans;
    }
    void merge(st& x)
    {
        for(auto val: x.basis) if(val) add(val);
    }
};

struct segtree
{
    int n;
    st t[2 * N];
    void upd(int p, int value) {
        for (t[p += n].add(value); p > 1; p >>= 1) t[p>>1].add(value);
    }

    int query(int l, int r) {
      st res;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res.merge(t[l++]);
        if (r&1) res.merge(t[--r]);
      }
      return res.get_max();
    }
}t;
int main()
{
    int n=in();
    t.n=n;
    for(int i=0; i<n; i++){
        int k=in();
        t.upd(i, k);
    }
    int q=in();
    while(q--){
        int l=in(), r=in();
        printf("%d\n", t.query(l-1, r));
    }
    return 0;
}