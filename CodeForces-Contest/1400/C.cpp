#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int k; cin >> k;
		int n = s.size();
		string p = string(n, '1');
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i - k >= 0) p[i - k] = '0';
				if (i + k < n) p[i + k] = '0';
			}
		}
		int ok = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				int f = 0;
				if (i - k >= 0 && p[i - k] == '1') f = 1;
				if (i + k < n && p[i + k] == '1') f = 1; 
				ok &= f;
			}
		}
		if (ok) cout << p << '\n';
		else cout << -1 << '\n';
	}
    return 0;
}