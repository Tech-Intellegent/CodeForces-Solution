#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int cnt[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int k = 0; k < 20; k++) {
			if (x >> k & 1) cnt[k]++;
		}
	}
	long long ans = 0;
	while (1) {
		int cur = 0;
		for (int k = 0; k < 20; k++) {
			if (cnt[k]) cur |= 1 << k, cnt[k]--;
		}
		if (cur == 0) break;
		ans += 1LL * cur * cur;
	}
	cout << ans << '\n';
    return 0;
}