#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N];
long long p[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q, k; cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i < n; i++) {
    p[i] = a[i + 1] - a[i - 1] - 2;
    p[i] += p[i - 1];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    long long ans = l + 1 < r ? p[r - 1] - p[l] : 0;
    if (l == r) {
      ans += k - 1;
    }
    else {
      ans += k - a[r - 1] - 1;
      ans += a[l + 1] - 1 - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}