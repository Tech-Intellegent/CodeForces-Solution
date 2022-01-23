#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
const long long inf = 1e18 + 1;

string s[N];
long long dp[N][N][4]; int  n, m;
long long yo(int i, int j, int d) {
	long long &ret = dp[i][j][d];
	if (ret != -1) return ret;
	ret = 1;
	int ni = i, nj = j;
	if (d == 0) ni--;
	else if (d == 1) ni++;
	else if (d == 2) nj--;
	else nj++;
	if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
		if (s[ni][nj] != s[i][j]) ret = 1 + yo(ni, nj, d);
	}
	else ret = inf;
	return ret;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> n >> m >> q;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) cin >> s[i];
	while (q--) {
		int x, y; long long p; cin >> x >> y >> p;
		x--; y--;
		long long k = inf;
		for (int i = 0; i < 4; i++) k = min(k, yo(x, y, i));
		if (p < k) cout << s[x][y] << '\n';
		else if ((p - k) % 2 == 1) cout << s[x][y] << '\n';
		else cout << (s[x][y] == '0' ? '1' : '0') << '\n';
	}
    return 0;
}