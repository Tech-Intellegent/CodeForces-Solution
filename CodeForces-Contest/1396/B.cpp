#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		int mx = 0;
		for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
		int sum = 0;
		for (int i = 0; i < n; i++) sum += a[i];
		int win = 0;
		if (n == 1) win = 1;
		else if (n == 2) win = a[0] != a[1];
		else if (mx > sum - mx) win = 1;
		else win = sum % 2;
		if (win) cout << "T\n";
		else cout << "HL\n";
	}
    return 0;
}