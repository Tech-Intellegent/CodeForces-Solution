#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int N = 3e6 + 9;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int a[N], n;
long long yo(int k) {
	int pref = 0;
	o_set<pair<int, int>> se;
	se.insert({0, 0});
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = (a[i] < k) ? -1 : 1;
		pref += x;
		ans += se.order_of_key(make_pair(pref - 1, n + 10));
		se.insert(make_pair(pref, i));
	}
	return ans;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int k; cin >> n >> k;
		int cnt = 0;
		for (int i = 1; i <= n; i++) cin >> a[i], cnt += a[i] == k;
		long long ans = yo(k) - cnt;
		if (cnt && (cnt == n || ans)) cout << "yes\n";
		else cout << "no\n";
	}
    return 0;
}