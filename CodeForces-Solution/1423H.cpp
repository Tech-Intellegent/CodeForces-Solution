#include<bits/stdc++.h>
using namespace std;

const int N = 8e5 + 9;
struct PDSU
{
  int c, dep[N], par[N];
  stack<array<int, 4>> st;
  PDSU() {}
  void init(int n) {
    c = n;
    for(int i = 0; i <= n; i++) par[i] = i, dep[i] = 1;
        st = stack<array<int, 4>>();
  }
  int root(int x) { return x == par[x] ? x : root(par[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return dep[root(x)]; }
  int count() { return c; }
  void unite(int x, int y) {
    if((x = root(x)) == (y = root(y))) return;
    st.push({x, dep[x], y, dep[y]});
    if(dep[x] <= dep[y]) par[x] = y, dep[y] += dep[x];
    else par[y] = x, dep[x] += dep[y];
    c--;
  }
  void snapshot() { st.push({-1, -1, -1, -1}); }
  void rollback() {
    while(!st.empty()){
      if(st.top()[0] == -1) return;
      ++c;
      for(int i = 0; i < 3; i += 2) par[st.top()[i]] = st.top()[i], dep[st.top()[i]] = st.top()[i + 1];
      st.pop();
    }
  }
}d;
vector<pair<int, int>> alive[3*N];
#define stree l=(n<<1),r=l+1,mid=b+(e-b)/2
void upd(int n,int b,int e,int i,int j,pair<int, int> &p)
{
    if(b>j||e<i) return;
    if(b>=i&&e<=j){
        alive[n].emplace_back(p);///this edge was alive in this time range
        return;
    }
    int stree;
    upd(l,b,mid,i,j,p);
    upd(r,mid+1,e,i,j,p);
}
int ans[N];
int P[N];
bool isquery[N];
void query(int n,int b,int e)
{
    if(b>e) return;
    d.snapshot();
    ///add edges which were alive in this range
    for(auto p:alive[n]) d.unite(p.first,p.second);
    if(b==e){
        if(isquery[b]) {
          ans[b]=d.size(P[b]);
        }
        d.rollback();
        d.st.pop();
        return;
    }
    int stree;
    query(l,b,mid);
    query(r,mid+1,e);
    d.rollback();
    d.st.pop();
}
map<pair<int, int>, int> id;
deque<int> st[N];
int u[N], v[N], ty[N];
vector<pair<int, int>> all[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, k; cin >> n >> q >> k;
    int m = 0, at = 1, day = 1;
    while (q--) {
      int t; cin >> t;
      if (t == 1) {
        int x, y; cin >> x >> y;
        ++m;
        u[m] = x; v[m] = y;
        all[day].push_back({x, y});
        ty[m] = 0;
      }
      else if (t == 2) {
        ++m;
        ty[m] = 2;
        cin >> u[m];
      }
      else {
        ++day;
        if (day - at >= k) {
          for (auto x: all[at]) {
            ++m;
            ty[m] = 1;
            u[m] = x.first;
            v[m] = x.second;
          }
          all[at].shrink_to_fit();
          ++at;
        }
      }
    }
    d.init(n);
    for(int i=1;i<=m;i++){
        if(ty[i]==2){
            isquery[i]=1;
            P[i]= u[i];
        }
        else if(ty[i]==0){
            if(u[i]>v[i]) swap(u[i],v[i]);
            pair<int, int> p={u[i],v[i]};
            if (id.find(p) == id.end()) {
              id[p];
              id[p] = id.size();
            }
            st[id[p]].push_back(i);
        }
        else{
            if(u[i]>v[i]) swap(u[i],v[i]);
            pair<int, int> p={u[i],v[i]};
            if (id.find(p) == id.end()) {
              id[p];
              id[p] = id.size();
            }
            upd(1,1,m,st[id[p]].front(),i-1,p);///in this time range this edge was in the DSU
            st[id[p]].pop_front();
        }
    }
    for(auto p: id) {
      auto z = p.first;
      for (auto x: st[p.second]) {
        upd(1,1,m,x,m,z);///update rest of the edges
      }
    }
    query(1,1,m);
    for (int i = 1; i <= m; i++) {
      if (isquery[i]) {
        cout << ans[i] << '\n';
      }
    }
    return 0;
}