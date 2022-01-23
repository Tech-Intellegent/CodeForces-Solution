#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		int cur = 0;
		for (int i = 0; i < n; i++) cin >> a[i], cur = max(cur, a[i]);
		vector<int> ans({cur});
		a.erase(find(a.begin(), a.end(), cur));
		while (a.size() >= 1) {
			pair<int, int> mx = {0, 0};
			for (auto i: a) {
				mx = max(mx, {__gcd(i, cur), i});
			}
			cur = mx.first;
			ans.push_back(mx.second);
			a.erase(find(a.begin(), a.end(), mx.second));
		}
		for (auto i: ans) cout << i << ' '; cout << '\n';
	}
    return 0;
}