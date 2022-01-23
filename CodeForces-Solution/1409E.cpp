#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int a[N], suf[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> a[n + 1];
		sort(a + 1, a + n + 1);
		int ans = 0;
		suf[n + 1] = 0;
		for (int i = n; i >= 1; i--) {
			int id = upper_bound(a + i, a + n + 1, a[i] + k) - a - 1;
			ans = max(ans, id - i + 1 + suf[id + 1]);
			suf[i] = max(suf[i + 1], id - i + 1);
		}
		cout << ans << '\n';
	}
    return 0;
}