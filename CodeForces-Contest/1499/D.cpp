#include<bits/stdc++.h>
using namespace std;

const int N = 2e7 + 9;

int cnt[N];
bool p[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < N; i++) p[i] = true;
  p[1] = false;
  for (int i = 2; i < N; i++) {
    if (p[i]) {
      cnt[i]++;
      for (int j = i + i; j < N; j += i) {
        p[j] = false;
        cnt[j]++;
      }
    }
  }
  int t; cin >> t;
  while (t--) {
    int c, d, x; cin >> c >> d >> x;
    vector<int> divs;
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        divs.push_back(i);
        if (i != x / i) {
          divs.push_back(x / i);
        }
      }
    }
    long long ans = 0;
    for (auto g: divs) {
      long long l = (x + 1LL * g * d);
      if (l % c != 0) continue;
      l /= c;
      if (l < g || l % g != 0) continue;
      l /= g;
      assert(l < N);
      ans += 1LL << cnt[l];
    }
    cout << ans << '\n';
  }
  return 0;
}