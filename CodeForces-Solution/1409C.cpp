#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x, y; cin >> n >> x >> y;
		if (x < y) swap(x, y);
		for (int len = n; len > 1; len--) {
			if ((x - y) % (len - 1) == 0) {
				int d = (x - y) / (len - 1);
				for (int i = n - len + 1; i >= 1; i--) {
					if (y - (i - 1) * d > 0) {
						for (int k = 1; k <= n; k++) {
							cout << y + (k - i) * d << ' ';
						}
						cout << '\n';
						goto hell;
					}
				}
			}
		}
		hell:
		int dum;
	}
    return 0;
}