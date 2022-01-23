#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int one = 0;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			one += k;
		}
		int k;
		int cnt = n / 2;
		if (one <= cnt) k = 0;
		else {
			if (cnt & 1) cnt++;
			k = 1;
		}
		cout << cnt << '\n';
		for (int i = 0; i < cnt; i++) cout << k << ' '; cout << '\n';
	}
    return 0;
}