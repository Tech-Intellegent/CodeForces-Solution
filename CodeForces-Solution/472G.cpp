#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

bitset<N> a[2], b[2];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B; cin >> A >> B;
	for (int i = 0; i < A.size(); i++) a[A[i] - '0'][i] = 1;
	for (int i = 0; i < B.size(); i++) b[B[i] - '0'][i] = 1;
	int q; cin >> q;
	while (q--) {
		int l, r, x; cin >> l >> r >> x;
		int ans = (((a[0] >> l) << (N - x)) & ((b[0] >> r) << (N - x))).count();
		ans += (((a[1] >> l) << (N - x)) & ((b[1] >> r) << (N - x))).count();
		cout << x - ans << '\n';
	}
    return 0;
}