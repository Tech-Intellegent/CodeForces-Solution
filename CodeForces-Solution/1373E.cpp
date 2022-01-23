#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
const long long inf = 1e17;

int f(long long n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int n, k;
long long ans;
inline void yo(long long x) {
	if (x < 0) return;
	int sum = 0;
	for (long long i = x; i <= x + k; i++) sum += f(i);
	if (sum == n) {
		if (ans == -1) ans = x;
		else ans = min(ans, x);
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		ans = -1;
		for (int i = 0; i <= 100; i++) yo(i);
		for (long long cur = 9; cur < inf; cur = cur * 10 + 9) {
			for (int add = 0; add < 9; add++) {
				long long nw = (cur + 1) * add + cur;
				for (long long i = nw - 20; i <= nw + 20; i++) yo(i);
			}
		}
		cout << ans << '\n';
	}
    return 0;
}