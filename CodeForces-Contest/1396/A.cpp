#include<bits/stdc++.h>
using namespace std;

long long a[101000];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		for (int k = 1; k <= 3; k++) {
			cout << 1 << ' ' << 1 << '\n';
			if (k == 1) cout << -a[1] << '\n';
			else cout << 0 << '\n';
		}
		return 0;
	}
	cout << 1 << ' ' << n << '\n';
	for (int i = 1; i <= n; i++) cout << -(a[i] % (n - 1)) * n << ' ';
	cout << '\n';
	cout << 1 << ' ' << n - 1 << '\n';
	for (int i = 1; i <= n - 1; i++) cout << -(a[i] - (a[i] % (n - 1)) * n) << ' '; cout << '\n';
	cout << n << ' ' << n << '\n';
	cout << -(a[n] - (a[n] % (n - 1)) * n) << '\n';
    return 0;
}