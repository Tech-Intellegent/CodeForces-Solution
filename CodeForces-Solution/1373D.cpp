#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
long long dp[N][2];
int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		dp[0][0] = 0;
		dp[0][1] = -1e18;
		for (int i = 1; i <= n; i++) {
			long long k = i & 1 ? -a[i] : a[i];
			dp[i][0] = max(0LL, dp[i - 1][1] + k);
			dp[i][1] = max(k, dp[i - 1][0] + k);
		}
		long long cur = 0, ans = 0;
		for (int i = 1; i <= n; i += 2) cur += a[i];
		for (int i = 0; i <= n; i++) {
			ans = max(ans, cur + dp[i][0]);
		}
		cout << ans << '\n';
	}
    return 0;
}