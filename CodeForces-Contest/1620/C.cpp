#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e18 + 9;
ll mul(ll a, ll b) {
  if (a <= inf / b) return a * b; 
  return inf;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; ll x; cin >> n >> k >> x;
    string s; cin >> s;
    vector<pair<char, int>> v;
    for (int i = 0, j; i < n; i = j) {
      j = i + 1;
      while (j < n and s[i] == s[j]) ++j;
      v.push_back({s[i], j - i});
    }
    int sz = v.size();
    string ans = "";
    for (int i = 0; i < sz; i++) {
      auto [ch, cnt] = v[i];
      if (ch == '*') {
        for (int oc = 0; oc <= k * cnt; oc++) {
          ll cur = 1;
          for (int j = i + 1; j < sz; j++) {
            if (v[j].first == '*') {
              cur = mul(cur, v[j].second * k + 1);
              if (cur >= inf) break;
            }
          }
          if (cur >= x) {
            break;
          }
          else {
            ans += 'b';
            x -= cur;
          }
        }
      }
      else {
        ans += string(cnt, 'a');
      }
    }
    cout << ans << '\n';
  }
  return 0;
}