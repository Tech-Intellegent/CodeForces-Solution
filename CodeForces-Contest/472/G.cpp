#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = (1 << 16) - 1;
const unsigned int M = ~0u;
int cnt[mod + 1];
inline int popcount(unsigned int x){
    return cnt[x >> 16] + cnt[x & mod];
}
unsigned int a[N], b[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 1; i < 1 << 16; ++i) cnt[i] = cnt[i >> 1] + (i & 1);
	string A, B; cin >> A >> B;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		if (i + 31 < n) {
			unsigned int mask = 0;
			for (int j = i; j <= i + 31; j++) {
				mask = (mask << 1) + (A[j] - '0');
			}
			a[i] = mask;
		}
	}
	int m = B.size();
	for (int i = 0; i < m; i++) {
		if (i + 31 < m) {
			unsigned int mask = 0;
			for (int j = i; j <= i + 31; j++) {
				mask = (mask << 1) + (B[j] - '0');
			}
			b[i] = mask;
		}
	}
	int q; cin >> q;
	while (q--) {
		int l1, l2, x; cin >> l1 >> l2 >> x;
		int ans = 0;
		while (x >= 32) {
			ans += popcount(a[l1] ^ b[l2]);
			l1 += 32; l2 += 32; x -= 32;
		}
		for (int i = 0; i < x; i++) ans += A[l1 + i] != B[l2 + i];
		cout << ans << '\n';
	}
    return 0;
}