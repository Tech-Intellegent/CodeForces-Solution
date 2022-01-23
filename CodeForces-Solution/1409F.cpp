#include<bits/stdc++.h>
using namespace std;

string a, b;
int n, k, dp[202][202][202];
int yo(int i, int change, int cnt) {
	if (change > k) return -1000000;
	if (i == n) return 0;
	int &ret = dp[i][change][cnt];
	if (ret != -1) return ret;
	ret = yo(i + 1, change, cnt + (a[i] == b[0])) + cnt * (a[i] == b[1]);
	ret = max(ret, yo(i + 1, change + 1, cnt + 1) + cnt * (b[0] == b[1]));
	ret = max(ret, yo(i + 1, change + 1, cnt + (b[0] == b[1])) + cnt);
	return ret;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cin >> a >> b;
	memset(dp, -1, sizeof dp);
	cout << yo(0, 0, 0) << '\n';
    return 0;
}