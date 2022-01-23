#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
using ll = long long;
ll s[N]; int a[N];
bool dp[N][700];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
      dp[i][1] = true;
    }
    for (int k = 2; k * (k + 1) / 2 <= n; k++) {
      vector<ll> mx(n + 2, 0);
      for (int i = n; i >= 1; i--) {
        if (i + k - 1 > n) {
          dp[i][k] = false;
          if (dp[i][k - 1]) {
            mx[i] = max(mx[i + 1], s[i + k - 2] - s[i - 1]);
          }
          continue;
        }
        if (mx[i + k] > s[i + k - 1] - s[i - 1]) {
          dp[i][k] = true;
        }
        else {
          dp[i][k] = false;
        }
        if (dp[i][k - 1]) {
          mx[i] = max(mx[i + 1], s[i + k - 2] - s[i - 1]);
        }
        else {
          mx[i] = mx[i + 1];
        }
        if (dp[i][k]) {
          ans = k;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}