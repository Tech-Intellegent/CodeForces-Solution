#include<bits/stdc++.h>
using namespace std;

const int N = 505;

long long a[N];
int cnt[64];
inline void add(long long x) {
	for (int k = 0; k < 61; k++) {
		if ((x >> k) & 1LL) cnt[k]++;
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(a[i]);
	}
	vector<int> v;
	for (int i = 60; i >= 0; i--) {
		if (cnt[i]) v.push_back(i);
	}
	long long ans = 0;
	for (int len = 1; len <= v.size(); len++) {
		int ok = 1; long long sum = 0;
		for (int i = 0; i < len; i++) {
			ok &= cnt[v[i]] >= max(1, len - 2);
			sum += 1LL << v[i];
		}
		if (ok) ans = max(ans, sum);
	}
	cout << ans << '\n';
    return 0;
}