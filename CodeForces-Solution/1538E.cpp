#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using P = array<string, 2>;
using T = pair<P, ll>;

P yo(string s) {
  int n = s.size();
  P ans = {s, s};
  if (s.size() > 3) {
    ans[0] = s.substr(0, 3);
    ans[1] = s.substr(s.size() - 3);
  }
  return ans;
}
T merge(T a, T b) {
  T ans;
  ll cnt = a.second + b.second;
  for (int i = 1; i <= a.first[1].size(); i++) {
    string p = a.first[1].substr(a.first[1].size() - i);
    if (4 - i > b.first[0].size()) continue;
    p += b.first[0].substr(0, 4 - i);
    cnt += p == "haha";
  }
  ans.second = cnt;
  ans.first[0] = a.first[0];
  if (ans.first[0].size() < 3) {
    ans.first[0] += b.first[0];
    if (ans.first[0].size() > 3) {
      ans.first[0].resize(3);
    }
  }
  ans.first[1] = b.first[1];
  if (ans.first[1].size() < 3) {
    ans.first[1] = a.first[1] + ans.first[1];
    if (ans.first[1].size() > 3) {
      ans.first[1] = ans.first[1].substr(ans.first[1].size() - 3);
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<string, T> mp;
    ll ans = 0;
    while (n--) {
      string x; cin >> x;
      string e; cin >> e;
      string a, b;
      if (e == "=") {
        cin >> a >> e >> b;
        mp[x] = merge(mp[a], mp[b]);
        ans = mp[x].second;
      }
      else {
        cin >> a;
        mp[x].first = yo(a);
        mp[x].second = 0;
        for (int i = 0; i + 3 < a.size(); i++) {
          mp[x].second += a.substr(i, 4) == "haha";
        }
        ans = mp[x].second;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}