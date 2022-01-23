#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int ans, n, k;
vector<pair<int, int>> g[N];
int cnt[10][10], f[10][10], tot[10];
vector<int> all[10][10];
bitset<N> bs[10][10], cur;
void yo(int d, int sum = 0, int mul = 1) {
	if (d == k + 1) {
		if (sum == n) ans += mul;
		return;
	}
	if (tot[d] + sum < n) return;
	int t = 0;
	for (int i = 0; i < d; i++) {
		if (f[d][i]) continue;
		else if (cnt[d][i] == 0) t++;
		else {
			if (all[d][i].size() <= 50) {
				int ok = 1;
				for (auto x: all[d][i]) {
					if (cur[x]) {
						ok = 0; break;
					}
				}
				if (ok) {
					for (auto x: all[d][i]) {
						cur[x] = 1;
					}
					yo(d + 1, sum + cnt[d][i], mul);
					for (auto x: all[d][i]) {
						cur[x] = 0;
					}
				}
			}
			else {
				if ((cur & bs[d][i]).count()) continue;
				cur ^= bs[d][i];
				yo(d + 1, sum + cnt[d][i], mul);
				cur ^=  bs[d][i];
			}
		}
	}
	if (t) yo(d + 1, sum, mul * t);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m; cin >> n >> m >> k;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({w, v});
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
		int d = g[i].size();
		for (int j = 0; j < d; j++) {
			bs[d][j][g[i][j].second] = 1;
			all[d][j].push_back(g[i][j].second);
			cnt[d][j]++;
		}
	}
	for (int d = 1; d <= k; d++) {
		for (int i = 0; i < d; i++) {
			if (bs[d][i].count() != cnt[d][i]) {
				f[d][i] = 1;
			}
			else {
				tot[d] = max(tot[d], cnt[d][i]);
			}
		}
	}
	for (int i = k - 1; i >= 1; i--) tot[i] += tot[i + 1];
	yo(1);
	cout << ans << '\n';
    return 0;
}