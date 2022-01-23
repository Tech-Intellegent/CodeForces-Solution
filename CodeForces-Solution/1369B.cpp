#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int l = 0, r = s.size() - 1;
		while (l <= r && s[l] == '0') l++;
		while (r >= l && s[r] == '1') r--;
		cout << string(l, '0') + (l <= r ? "0" : "") + string(n - r - 1, '1') << '\n';
	}
    return 0;
}