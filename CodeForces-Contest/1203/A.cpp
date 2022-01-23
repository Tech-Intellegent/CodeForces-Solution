//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MP make_pair
#define fs first
#define sc second
#define F first
#define S second
#define nl "\n"
#define asche cerr<<"Ekhane asche\n";
#define pf printf
#define sf scanf
#define mem(a,x) memset(a,x,sizeof(a))
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define one(x) __builtin_popcount(x)
#define fout(x) fixed<<setprecision(x)
#define BeatMeScanf ios_base::sync_with_stdio(false)
//int dx[]={1,0,-1,0,1,-1,-1,1};
//int dy[]={0,1,0,-1,1,1,-1,-1};
random_device RD;
mt19937 rnd(RD());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
namespace IO
{
    #define in() ( { int a ; scanf("%d",&a); a; } )
    #define LL() ( { ll a ; scanf("%lld",&a); a; } )
    #define ULL() ( { ull a ; scanf("%llu",&a); a; } )
    #define DD() ({ double a; scanf("%lf", &a); a;})
    #define CC() ( { char a ; scanf("%c",&a); a; } )
    #define pf1(a) printf("%d\n",a);
    #define pf1ll(a) printf("%lld\n",a);
}
using namespace IO;

const int mod=1e9+7;
const int N=3e5+9;
const double eps=1e-9;
const double PI=acos(-1.0);
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

int a[55][55];
bool pal(int x1,int y1,int x2,int y2)
{
    if(x1>x2||y1>y2) return 0;
    if(a[x1][y1]!=a[x2][y2]) return 0;
    return pal(x1+1,y1,x2-1,y2)|pal(x1+1,y1,x2,y2-1)|pal(x1,y1+1,x2-1,y2)|pal(x1,y1+1,x2,y2-1);
}
int32_t main()
{
    BeatMeScanf;
    int i,j,k,n,m;
    cin>>n;
    a[1][1]=1;
    k=yo(1,1,1,3);
    a[1][3]=k?a[1][1]:!a[1][1];
    k=yo(1,1,3,1);
    a[3][1]=k?a[1][1]:!a[1][1];
    k=yo(1,1,2,2);
    a[2][2]=k?a[1][1]:!a[1][1];
    k=yo(2,2,3,3);
    a[3][3]=k?a[2][2]:!a[2][2];
    v.eb(1,1,2,3);
    v.eb(1,1,3,2);
    v.eb(2,1,3,3);
    v.eb(1,2,3,3);
    v.eb(1,2,3,2);
    v.eb(2,1,2,3);
    vi ans;
    for(auto x:v) ans.eb(yo(x.x1,x.y1,x.x2,x.y2));
    vi nw;
    for(i=0;i<(1<<4);i++){
        nw.clear();
        for(j=0;j<4;j++){
            if((i>>j)&1){
                nw.eb(1);
            }
            else nw.eb(0);
        }
        a[1][2]=nw[0];
        a[2][1]=nw[1];
        a[2][3]=nw[2];
        a[3][2]=nw[3];
        bool ok=1;
        k=0;
        for(auto x:v){
            ok&=ans[k++]==pal(x.x1,x.y1,x.x2,y.y2);
        }
        if(ok) break;
    }
    for(i=4;i<=n;i++){
        for(j=1;j<=3;j++){
            k=yo(i-2,j,i,j);
            a[i][j]=k?a[i-2][j]:!a[i-2][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=4;j<=n;j++){
            k=yo(i,j-2,i,j);
            a[i][j]=k?a[i][j-2]:!a[i][j-2];
        }
    }
    cout<<"!\n";
    cout.flush();
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1