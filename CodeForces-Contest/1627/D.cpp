#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
bool a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    a[k] = 1;
  }
  int ans = 0;
  for (int i = 1; i < N; i++) {
    int g = 0;
    for (int j = i; j < N; j += i) {
      if (a[j]) {
        g = __gcd(g, j / i);
        if (g == 1) break;
      }
    }
    ans += g == 1;
  }
  cout << ans - n << '\n';
  return 0;
}