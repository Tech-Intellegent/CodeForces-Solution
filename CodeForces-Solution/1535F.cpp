#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int power(long long n, long long k, const int mod) {
    int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }

}
struct Hashing {
    int n; string s; // 0 - indexed
    vector<pair<int, int>> hs; // 1 - indexed
    Hashing() {}
    Hashing(string _s) {
        n = _s.size(); s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    int get_hash(int l, int r) { // 1 - indexed
      // assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return (ans.first * 1LL * MOD1 + ans.second) % MOD2;
    }
    int get_hash() { return get_hash(1, n); }
}H[N];
int n, m;
int pref[N], suf[N];
string s[N];
int ok(int i, int j) {
  int k = 0, last = 0;
  while (k < m) {
    if (k + 1 < m and s[i][k + 1] >= s[i][k]) {
      ++k;
    }
    else {
      if (!last or pref[last - 1]) {
        if (k == m - 1 or suf[k + 1]) {
          auto p = s[i].substr(last, k - last + 1);
          auto q = s[j].substr(last, k - last + 1);
          sort(q.begin(), q.end());
          if (p == q) {
            return 1;
          }
        }
      }
      last = k + 1;
      ++k;
    }
  }
  return 0;
}
int pos(int i, int j) {
  vector<int> a(26, 0), b(26, 0);
  for (auto x: s[i]) {
    a[x - 'a']++;
  }  
  for (auto x: s[j]) {
    b[x - 'a']++;
  }
  return a == b;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    // H[i] = Hashing(s[i]);
  }
  m = s[1].size();
  long long ans = 0;
  // if (n <= 500) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = 0; k < m; k++) {
          pref[k] = s[i][k] == s[j][k];
          if (k) pref[k] &= pref[k - 1];
        }
        for (int k = m - 1; k >= 0; k--) {
          suf[k] = s[i][k] == s[j][k];
          if (k + 1 < m) suf[k] &= suf[k + 1];
        }
        if (pos(i, j)) {
          if (ok(i, j) or ok(j, i)) ++ans;
          else ans += 2;
        }
        else ans += 1337;
      } 
    }
  // }
  cout << ans << '\n';
  return 0;
}