#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n + 1, 0), b(n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		int ok = a == b;
		vector<int> A = a, B = b;
		for (int i = 1, j = n; i <= n / 2; i++, j--) {
			swap(a[i], a[j]);
			if (a == b) {
				ok = 1; break;
			}
			swap(a[i], a[j]);
		}
		for (int len = 1; len <= n / 2; len++) {
			a = A;
			for (int i = 1, j = n - len + 1; i <= len; i++, j++) {
				swap(a[i], a[j]);
			}
			for (int i = 1, j = n; i <= n / 2; i++, j--) {
				swap(a[i], a[j]);
				if (a == b) {
					ok = 1; break;
				}
				swap(a[i], a[j]);
			}
			if (ok) break;
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
    return 0;
}