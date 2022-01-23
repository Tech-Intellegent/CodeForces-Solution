#include<bits/stdc++.h>
using namespace std;
const long long inf = 5e18;
long long dp[101000][6][2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		dp[0][0][0] = dp[0][0][1] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][0][0] = dp[i][0][1] = 1;
			for (int k = 1; k <= 5; k++) {
				if (i >= k) {
					dp[i][k][1] = max({i - 1 >= k ? dp[i - 1][k][1] : -inf, dp[i - 1][k - 1][1] * a[i], dp[i - 1][k - 1][0] * a[i]});
					dp[i][k][0] = min({i - 1 >= k ? dp[i - 1][k][0] : inf, dp[i - 1][k - 1][1] * a[i], dp[i - 1][k - 1][0] * a[i]});
				}
			}
		}
		cout << dp[n][5][1] << '\n';
	}
    return 0;
}