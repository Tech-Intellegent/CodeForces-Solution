#include<bits/stdc++.h>
using namespace std;

long long a, b, c;
long long yo1(long long x) {
	if (x > 0 && x <= 1000000000 && x * a < (x + b - 1) / b * c) return x;
	return -1;
}
long long yo2(long long x) {
	if (x > 0 && x <= 1000000000 && x * a > (x + b - 1) / b * c) return x;
	return -1;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		long long p = max({yo1(1), yo1(b), yo1(b + 1), yo1(a), yo1(b - 1), yo1(1000000000)});
		long long q = max({yo2(1), yo2(b), yo2(b + 1), yo2(a), yo2(b - 1), yo2(1000000000)});
		cout << p << ' ' << q << '\n';
	}
    return 0;
}