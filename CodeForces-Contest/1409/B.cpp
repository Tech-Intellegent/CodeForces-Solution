#include<bits/stdc++.h>
using namespace std;

long long yo(int a, int b, int x, int y, int n) {
	int z = min(a - x, n);
	a -= z;
	n -= z;
	b -= min(b - y, n);
	return 1LL *a * b;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, x, y, n; cin >> a >> b >> x >> y >> n;
		cout << min(yo(a, b, x, y, n), yo(b, a, y, x, n)) << '\n';
	}
    return 0;
}