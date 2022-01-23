#include<bits/stdc++.h>
using namespace std;

const int N = 35005;
const int inf = 2e9;

struct PST
{
  #define lc t[cur].l
  #define rc t[cur].r
  struct node
  {
      int l = 0, r = 0, val = 0;
  }t[50 * N];
  int T = 0;
  int build(int b, int e)
  {
      int cur = ++T;
      if(b == e) return cur;
      int mid = b + e >> 1;
      lc = build(b, mid);
      rc = build(mid + 1, e);
      t[cur].val = t[lc].val + t[rc].val;
      return cur;
  }
  int upd(int pre, int b, int e, int i, int v)
  {
      int cur = ++T; t[cur] = t[pre];
      if(b == e){
          t[cur].val += v;
          return cur;
      }
      int mid = b + e >> 1;
      if(i <= mid){
          rc = t[pre].r;
          lc = upd(t[pre].l, b, mid, i, v);
      }
      else{
          lc = t[pre].l;
          rc = upd(t[pre].r, mid + 1, e, i, v);
      }
      t[cur].val = t[lc].val + t[rc].val;
      return cur;
  }
  int query(int cur, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[cur].val;
    int mid = (b + e) >> 1;
    int L = query(t[cur].l, b, mid, i, j);
    int R = query(t[cur].r, mid + 1, e, i, j);
    return L + R;
  }
}t1, t2;

int a[N]; int dp[110][N]; //dp[i][j]=minimum cost for dividing [1...j] into i parts
int r1[N], r2[N], n, nxt[N];
inline int cost(int l, int r) {
  if (l > r) return 0;
  return t1.query(r1[r], 1, n, l, r) - t2.query(r2[l], 1, n, l, r);
}
void yo(int i, int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid=(l+r)/2;
  dp[i][mid]=inf; int cur = cost(optl + 1, mid);
  int opt=-1;
  for(int k=optl;k<=min(mid, optr);k++){
    int c=dp[i-1][k]+cur;
    if (c<dp[i][mid]){
      dp[i][mid]=c;
      opt=k;
    }
    if (k + 1 <= n and nxt[k + 1] <= mid) {
      cur -= nxt[k + 1] - k - 1;
    }
  }
  yo(i, l, mid-1, optl, opt);
  yo(i, mid+1, r, opt, optr);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  r1[0] = t1.build(1, n);
  vector<int> last(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (last[a[i]]) {
      r1[i] = t1.upd(r1[i - 1], 1, n, last[a[i]], -last[a[i]]);
      r1[i] = t1.upd(r1[i], 1, n, i, i);
    }
    else {
      r1[i] = t1.upd(r1[i - 1], 1, n, i, i);
    }
    last[a[i]] = i;
  }
  r2[n + 1] = t2.build(1, n);
  last = vector<int> (n + 1, 0);
  for (int i = n; i >= 1; i--) {
    if (last[a[i]]) {
      r2[i] = t2.upd(r2[i + 1], 1, n, last[a[i]], -last[a[i]]);
      r2[i] = t2.upd(r2[i], 1, n, i, i);
      nxt[i] = last[a[i]];
    }
    else {
      r2[i] = t2.upd(r2[i + 1], 1, n, i, i);
      nxt[i] = n + 1;
    }
    last[a[i]] = i;
  }
  for(int i = 1; i <= n; i++) dp[1][i] = cost(1, i);
  for(int i = 2; i <= k; i++) yo(i, 1, n, 1, n);
  cout << dp[k][n] <<'\n';
  return 0;
}