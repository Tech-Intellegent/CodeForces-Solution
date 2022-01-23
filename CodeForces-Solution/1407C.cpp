#include<bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
	assert(i != j);
	cout << "? " << i << ' ' << j << '\n';
	cout.flush();
	int k; cin >> k;
	return k;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	if (n == 1) {
		cout << "! " << 1 << '\n';
		cout.flush();
		return 0;
	}
	vector<int> ans(n + 1);
	int cur = 1;
	for (int i = 2; i <= n; i++) {
		int x = ask(cur, i);
		int y = ask(i, cur);
		if (x > y) ans[cur] = x, cur = i;
		else ans[i] = y;
	}
	for (int i = 0; i <= n; i++) if (ans[i] == 0) ans[i] = n;
	cout << "!";
	for (int i = 1; i <= n; i++) cout << " " << ans[i];
	cout << '\n';
	cout.flush();
    return 0;
}