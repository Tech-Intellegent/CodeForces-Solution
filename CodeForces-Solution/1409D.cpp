#include<bits/stdc++.h>
using namespace std;

long long dp[2][20][200][200];
vector<int> v;
long long yo(int i, int cur, int f, int s) {
    if(i == -1) return s == cur;
    long long &ret = dp[f][i][cur][s];
    if(ret != -1 && !f) return ret;
    int m = f ? v[i] : 9;
    long long ans = 0;
    for(int k = 0; k <= m; k++){
        ans += yo(i - 1, cur + k, k == m? f : 0, s);
    }
    if(!f) ret = ans;
    return ans;
}
int solve(long long n, int s) {
    if(n == 0) return 0;
    v.clear();
    while(n) {
        v.push_back(n % 10); n /= 10;
    }
    return yo(v.size() - 1, 0, 1, s);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	int t; cin >> t;
	while (t--) {
		long long n, s; cin >> n >> s;
		long long ans = 1e18;
		for (int i = 1; i <= s; i++) {
			long long l = n, r = n < 1e17 ? min(n * 10, (long long)1e18) : 1e18;
			r = min(r, l + ans);
			long long p = solve(n - 1, i);
			while (l <= r) {
				long long mid = (l + r) / 2;
				if (solve(mid, i) - p) {
					ans = min(ans, mid - n);
					r = mid - 1;
				}
				else l = mid + 1;
			}
		}
		cout << ans << '\n';
	}
    return 0;
}