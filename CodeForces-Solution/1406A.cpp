#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> cnt(200, 0);
		while (n--) {
			int k; cin >> k;
			cnt[k]++;
		}
		int ans = 0, z = 2;
		for (int i = 0; i < 200; i++) {
			if (cnt[i] >= 2) ans += z;
			else if (cnt[i] == 1) ans++, z = 1;
			else break;
		}
		cout << ans << '\n';
	}
    return 0;
}