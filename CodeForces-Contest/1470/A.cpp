#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
const long long inf = 2e18;

int a[N], c[N], n, m;
long long s1[N], s2[N];

long long f(int mid) {
  for (int i = mid; i <= n; i++) {
    if (a[i] < i - mid + 1) return 0;
  }
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> c[i];
      s2[i] = s2[i - 1] + c[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      s1[i] = s1[i - 1] + c[a[i]];
    }
    int l = 1, r = n; int z = n + 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (f(mid)) {
        z = mid; r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    long long ans = inf;
    for (int i = z; i <= n + 1; i++) {
      ans = min(ans, s1[i - 1] + s2[n - i + 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}