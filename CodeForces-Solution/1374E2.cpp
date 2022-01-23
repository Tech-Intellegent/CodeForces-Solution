#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
const long long inf = 5e18;
int a[N], b[N], c[N], n, m, k;
vector<pair<long long, int>> z[2][2];
pair<long long, vector<int>> yo(long long cost) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			z[i][j].clear();
		}
	}
	for (int i = 1; i <= n; i++) {
			z[a[i]][b[i]].push_back({cost + c[i], i});
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			sort(z[i][j].rbegin(), z[i][j].rend());
		}
	}
	long long ans = 0;
	vector<int> res;
	int c1 = 0, c2 = 0;
	while (c1 < k || c2 < k) {
		if (c1 < k && c2 < k) {
			if (z[1][1].size() && z[1][0].size() && z[0][1].size()) {
				long long cc = z[1][0].back().first + z[0][1].back().first;
				if (z[1][1].back().first < cc) {
					ans += z[1][1].back().first;
					res.push_back(z[1][1].back().second);
					z[1][1].pop_back();
				}
				else {
					ans += cc;
					res.push_back(z[1][0].back().second);
					res.push_back(z[0][1].back().second);
					z[1][0].pop_back();
					z[0][1].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back().first;
				res.push_back(z[1][1].back().second);
				z[1][1].pop_back();
			}
			else if (z[1][0].size() && z[0][1].size()) {
				ans += z[1][0].back().first + z[0][1].back().first;
				res.push_back(z[1][0].back().second);
				res.push_back(z[0][1].back().second);
				z[1][0].pop_back();
				z[0][1].pop_back();
			}
			else break;
			c1++; c2++;
		}
		else if (c1 < k) {
			if (z[1][1].size() && z[1][0].size()) {
				if (z[1][1].back().first < z[1][0].back().first) {
					ans += z[1][1].back().first;
					res.push_back(z[1][1].back().second);
					z[1][1].pop_back();
				}
				else {
					ans += z[1][0].back().first;
					res.push_back(z[1][0].back().second);
					z[1][0].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back().first;
				res.push_back(z[1][1].back().second);
				z[1][1].pop_back();
			}
			else if (z[1][0].size()) {
				ans += z[1][0].back().first;
				res.push_back(z[1][0].back().second);
				z[1][0].pop_back();
			}
			else break;
			c1++;
		}		
		else {
			if (z[1][1].size() && z[0][1].size()) {
				if (z[1][1].back().first < z[0][1].back().first) {
					ans += z[1][1].back().first;
					res.push_back(z[1][1].back().second);
					z[1][1].pop_back();
				}
				else {
					ans += z[0][1].back().first;
					res.push_back(z[0][1].back().second);
					z[0][1].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back().first;
				res.push_back(z[1][1].back().second);
				z[1][1].pop_back();
			}
			else if (z[0][1].size()) {
				ans += z[0][1].back().first;
				res.push_back(z[0][1].back().second);
				z[0][1].pop_back();
			}
			else break;
			c2++;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (auto x: z[i][j]) {
				if (x.first < 0) {
					res.push_back(x.second);
					ans += x.first;
				}
			}
		}
	}
	if (c1 < k || c2 < k) res.clear(), ans = inf;
	return {ans, res};
}
vector<int> solve(long long cost) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			z[i][j].clear();
		}
	}
	for (int i = 1; i <= n; i++) {
			z[a[i]][b[i]].push_back({cost + c[i], i});
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			sort(z[i][j].rbegin(), z[i][j].rend());
		}
	}
	long long ans = 0;
	vector<int> res;
	int c1 = 0, c2 = 0;
	while (c1 < k || c2 < k) {
		if (c1 < k && c2 < k) {
			if (z[1][1].size() && z[1][0].size() && z[0][1].size()) {
				int cc = z[1][0].back().first + z[0][1].back().first;
				if (z[1][1].back().first < cc || res.size() + 2 > m) {
					ans += z[1][1].back().first;
					res.push_back(z[1][1].back().second);
					z[1][1].pop_back();
				}
				else {
					ans += cc;
					res.push_back(z[1][0].back().second);
					res.push_back(z[0][1].back().second);
					z[1][0].pop_back();
					z[0][1].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back().first;
				res.push_back(z[1][1].back().second);
				z[1][1].pop_back();
			}
			else if (z[1][0].size() && z[0][1].size()) {
				ans += z[1][0].back().first + z[0][1].back().first;
				res.push_back(z[1][0].back().second);
				res.push_back(z[0][1].back().second);
				z[1][0].pop_back();
				z[0][1].pop_back();
			}
			else break;
			c1++; c2++;
		}
		else if (c1 < k) {
			if (z[1][1].size() && z[1][0].size()) {
				if (z[1][1].back().first < z[1][0].back().first) {
					ans += z[1][1].back().first;
					res.push_back(z[1][1].back().second);
					z[1][1].pop_back();
				}
				else {
					ans += z[1][0].back().first;
					res.push_back(z[1][0].back().second);
					z[1][0].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back().first;
				res.push_back(z[1][1].back().second);
				z[1][1].pop_back();
			}
			else if (z[1][0].size()) {
				ans += z[1][0].back().first;
				res.push_back(z[1][0].back().second);
				z[1][0].pop_back();
			}
			else break;
			c1++;
		}		
		else {
			if (z[1][1].size() && z[0][1].size()) {
				if (z[1][1].back().first < z[0][1].back().first) {
					ans += z[1][1].back().first;
					res.push_back(z[1][1].back().second);
					z[1][1].pop_back();
				}
				else {
					ans += z[0][1].back().first;
					res.push_back(z[0][1].back().second);
					z[0][1].pop_back();
				}
			}
			else if (z[1][1].size()) {
				ans += z[1][1].back().first;
				res.push_back(z[1][1].back().second);
				z[1][1].pop_back();
			}
			else if (z[0][1].size()) {
				ans += z[0][1].back().first;
				res.push_back(z[0][1].back().second);
				z[0][1].pop_back();
			}
			else break;
			c2++;
		}
	}
	vector<pair<long long, int>> v;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (auto x: z[i][j]) v.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	int need = m - (int)res.size();
	for (int i = 0; i < need; i++) {
		ans += v[i].first;
		res.push_back(v[i].second);
	}
	return res;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> a[i] >> b[i];
	}
	long long l = -2e9, r = 2e9, ans = 0;
	if (yo(0).first == inf) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> res; long long last = -1e18;
	while (l <= r) {
		long long mid = (l + r) / 2;
		auto nw = yo(mid);
		if (nw.second.size() <= m) {
			ans = nw.first - mid * m;
			res = nw.second;
			last = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	if (last == -1e18) {
		cout << -1 << '\n';
		return 0;
	}
	res = solve(last);
	cout << ans << '\n';
	for (auto x: res) cout << x << ' '; cout << '\n';
    return 0;
}