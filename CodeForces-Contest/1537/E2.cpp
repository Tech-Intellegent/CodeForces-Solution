#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
 
// credit: solaimanope
const pll M = make_pair(2147483647, 1088888881);
const ll base = 1135019;   
 
pll operator+ (pll a, ll x)     {return make_pair(a.first + x, a.second + x);}
pll operator- (pll a, ll x)     {return make_pair(a.first - x, a.second - x);}
pll operator* (pll a, ll x)     {return make_pair(a.first * x, a.second * x);}
pll operator+ (pll a, pll x)    {return make_pair(a.first + x.first, a.second + x.second);}
pll operator- (pll a, pll x)    {return make_pair(a.first - x.first, a.second - x.second);}
pll operator* (pll a, pll x)    {return make_pair(a.first * x.first, a.second * x.second);}
pll operator% (pll a, pll m)    {return make_pair(a.first % m.first, a.second % m.second);}
 
pll power (pll a, ll p) {
  if (p==0)   return make_pair(1,1);
  pll ans = power(a, p/2);
  ans = (ans * ans)%M;
  if (p%2)    ans = (ans*a)%M;
  return ans;
}
 
///Magic!!!!!!!
pll inverse(pll a)  {
  return power(a, (M.first-1)*(M.second-1)-1);
}
 
pll pb[N]; // powers of base mod M
pll invb;
pll inv[N];
void prec() {
  pb[0] = make_pair(1,1);
  for (int i=1; i<N; i++)
      pb[i] = (pb[i-1] * base)%M;
  invb = inverse(pb[1]);
  for (int i = 1; i < N; i++) {
    inv[i] = inverse(pb[i] - 1);
  }
}
 
// Calculates Hash of a string
pll Hash (string s) {
  pll ans = make_pair(0,0);
  for (int i=0; i<s.size(); i++)
      ans=(ans*base + s[i])%M;
  return ans;
}
 
// concatenates two strings where length of the right is k
pll concat(pll left, pll right, int k) {
  return (left*pb[k] + right)%M;
}
 
//Calculates hash of string with size len repeated cnt times
//This is O(log n). For O(1), pre-calculate inverses
pll repeat(pll hash, int len, ll cnt) {
  pll mul = (pb[len*cnt] - 1) * inv[len];
  mul = (mul%M+M)%M;
  pll ans = (hash*mul)%M;

  if (pb[len].first == 1)    ans.first = hash.first*cnt;
  if (pb[len].second == 1)    ans.second = hash.second*cnt;
  return ans;
}
 
//Calculates hashes of all prefixes of s including empty prefix
vector<pll> hashList(string s) {
  int n = s.size();
  vector<pll> ans(n+1);
  ans[0] = make_pair(0,0);

  for (int i=1; i<=n; i++)
      ans[i] = (ans[i-1] * base + s[i-1])%M;
  return ans;
}

//Calculates hash of substring s[l..r] (1 indexed)
pll get_hash(const vector<pll> &hashlist, int l, int r) {
  int len = (r-l+1);
  return ((hashlist[r] - hashlist[l-1]*pb[len])%M+M)%M;
}
string s;
vector<pll> a;

pll yo(int i, int len) {
  pll ans = {0, 0};
  if (len >= i) ans = repeat(get_hash(a, 1, i), i, len / i);
  len %= i;
  if (len) {
    ans = concat(ans, get_hash(a, 1, len), len);
  }
  return ans;
}
char get(int i, int len) {
  --len;
  len %= i;
  return s[len];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  int n, k; cin >> n >> k;
  cin >> s;
  a = hashList(s);
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    int l = 1, r = k, x = 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (yo(ans, mid) == yo(i, mid)) {
        x = mid + 1;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    // cout << ans << ' ' << i << ' ' << x << ' ';
    if (x <= k) {
      char l = get(ans, x), r = get(i, x);
      // cout << l << ' ' << r << '\n';
      if (l > r) ans = i;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << s[i % ans];
  }
  return 0;
}