#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int x = 1; x <= k; x++) {
      vector<array<int, 3>> pref;
      pref.push_back({0, 0, 0});
      int consec_ones = 0;
      for (int j = x; j <= n; j += k) {
        auto p = pref.back();
        pref.push_back(p);
        if (a[j] == 1) {
          pref.back()[0]++;
          consec_ones++;
        }
        else if (spf[a[j]] == a[j]) {
          pref.back()[1]++;
          consec_ones = 0;
          ans--; // single primes
        }
        else {
          pref.back()[2]++;
          consec_ones = 0;
        }
        ans -= consec_ones;
      }
      int sz = (int)pref.size() - 1;
      for (int i = 1; i <= sz; i++) {
        int l = i, r = sz, cur = i - 1;
        while (l <= r){
          int mid = l + r >> 1;
          if (pref[mid][2] - pref[i - 1][2]) {
            r = mid - 1;
          }
          else if (pref[mid][1] - pref[i - 1][1] > 1) {
            r = mid - 1;
          }
          else {
            cur = mid;
            l = mid + 1;
          }
        }
        ans += cur - i + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}