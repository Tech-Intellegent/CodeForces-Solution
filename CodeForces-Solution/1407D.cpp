#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;

int a[N], dp[N], l[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l[i] = i - 1;
		if (a[i] == a[i - 1]) l[i] = l[i - 1];
	}
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		int mx = a[i - 1], mn = a[i - 1];
		for (int j = l[i - 1]; j >= 1; j = l[j]) {
			if (mx < min(a[i], a[j])) dp[i] = min(dp[i], dp[j] + 1);
			else if (max(a[i], a[j]) < mn) dp[i] = min(dp[i], dp[j] + 1);
			else break;
			mx = max(mx, a[j]);
			mn = min(mn, a[j]);
		}
	}
	cout << dp[n] << '\n';
    return 0;
}