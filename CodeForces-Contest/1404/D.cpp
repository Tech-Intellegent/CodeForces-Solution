#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

long long sum[3];
int ans[N], a[N];
vector<int> g[N];
void dfs(int u, int c = 1) {
	sum[c] += u;
	ans[u] = c;
	for (auto v: g[u]) {
		if (!ans[v]) {
			dfs(v, 3 - c);
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	if (n % 2 == 0) {
		cout << "First\n";
		for (int i = 1; i <= 2 * n; i++) {
			cout << i % n + 1 << ' ';
		}
		cout << '\n';
		return 0;
	}
	cout << "Second\n";
	cout.flush();
	for (int i = 1; i <= 2 * n; i++) {
		int k; cin >> k;
		if (a[k] != 0) {
			g[a[k]].push_back(i);
			g[i].push_back(a[k]);
		}
		else a[k] = i;
		if (i <= n) {
			g[i].push_back(i + n);
			g[i + n].push_back(i);
		}
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!ans[i]) dfs(i);
	}
	sum[1] %= 2 * n;
	if (sum[1] == 0) {
		for (int i = 1; i <= 2 * n; i++) {
			if (ans[i] == 1) cout << i << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= 2 * n; i++) {
			if (ans[i] == 2) cout << i << ' ';
		}
		cout << '\n';
	}
    return 0;
}