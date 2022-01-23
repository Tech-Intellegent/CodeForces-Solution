#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], b[N], c[N];
vector<int> z[2][2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> a[i] >> b[i];
		v.push_back(i);
		z[a[i]][b[i]].push_back(c[i]);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			sort(z[i][j].rbegin(), z[i][j].rend());
		}
	}
	long long ans = 0;
	int c1 = 0, c2 = 0;
	while (c1 < k || c2 < k) {
		if (c1 < k && c2 < k) {
			if (z[1][1].size() && z[1][0].size() && z[0][1].size()) {
				int cc = z[1][0].back() + z[0][1].back();
				if (z[1][1].back() < cc) {
					ans += z[1][1].back();
					z[1][1].pop_back();
				}
				else {
					ans += cc;
					z[1][0].pop_back();
					z[0][1].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back();
				z[1][1].pop_back();
			}
			else if (z[1][0].size() && z[0][1].size()) {
				ans += z[1][0].back() + z[0][1].back();
				z[1][0].pop_back();
				z[0][1].pop_back();
			}
			else break;
			c1++; c2++;
		}
		else if (c1 < k) {
			if (z[1][1].size() && z[1][0].size()) {
				if (z[1][1].back() < z[1][0].back()) {
					ans += z[1][1].back();
					z[1][1].pop_back();
				}
				else {
					ans += z[1][0].back();
					z[1][0].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back();
				z[1][1].pop_back();
			}
			else if (z[1][0].size()) {
				ans += z[1][0].back();
				z[1][0].pop_back();
			}
			else break;
			c1++;
		}		
		else {
			if (z[1][1].size() && z[0][1].size()) {
				if (z[1][1].back() < z[0][1].back()) {
					ans += z[1][1].back();
					z[1][1].pop_back();
				}
				else {
					ans += z[0][1].back();
					z[0][1].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back();
				z[1][1].pop_back();
			}
			else if (z[0][1].size()) {
				ans += z[0][1].back();
				z[0][1].pop_back();
			}
			else break;
			c2++;
		}
	}
	if (c1 < k || c2 < k) ans = -1;
	cout << ans << '\n';
    return 0;
}