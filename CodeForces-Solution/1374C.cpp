#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s;
		int ans = 0, cur = 0;
		for (auto c: s) {
			cur += c == '(' ? +1 : -1;
			if (cur < 0) ans = max(ans, -cur);
		}
		cout << ans << '\n';
	}
    return 0;
}