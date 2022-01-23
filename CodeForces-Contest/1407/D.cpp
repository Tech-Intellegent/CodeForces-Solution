#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;

int t1[N][19], t2[N][19], a[N];

void build1(int n) {
    for(int i = 1; i <= n; ++i) t1[i][0] = a[i];
    for(int k = 1; k < 19; ++k) {
            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
                    t1[i][k] = min(t1[i][k - 1], t1[i + (1 << (k - 1))][k - 1]);
            }
    }
}
void build2(int n) {
    for(int i = 1; i <= n; ++i) t2[i][0] = a[i];
    for(int k = 1; k < 19; ++k) {
            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
                    t2[i][k] = max(t2[i][k - 1], t2[i + (1 << (k - 1))][k - 1]);
            }
    }
}

int query1(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(t1[l][k], t1[r - (1 << k) + 1][k]);
}
int query2(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(t2[l][k], t2[r - (1 << k) + 1][k]);
}

int dp[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build1(n);
	build2(n);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (a[i] == a[i - 1]) continue;
		int cur = i - 1;
		if (a[i - 1] > a[i]) {
			while (cur > 1) {
				int l = 1, r = cur - 1, nxt = 1;
				while (l <= r) {
					int mid = l + r >> 1;
					if (query1(mid, cur) < a[cur]) {
						nxt = mid; l = mid + 1;
					}
					else r = mid - 1;
				}
				if (query1(nxt + 1, i - 1) > max(a[i], a[nxt])) {
					dp[i] = min(dp[i], dp[nxt] + 1);
				}
				else break;
				cur = nxt;
			}
		}		
		else {
			while (cur > 1) {
				int l = 1, r = cur - 1, nxt = 1;
				while (l <= r) {
					int mid = l + r >> 1;
					if (query2(mid, cur) > a[cur]) {
						nxt = mid; l = mid + 1;
					}
					else r = mid - 1;
				}
				if (query2(nxt + 1, i - 1) < min(a[i], a[nxt])) {
					dp[i] = min(dp[i], dp[nxt] + 1);
				}
				else break;
				cur = nxt;
			}
		}
	}
	cout << dp[n] << '\n';
    return 0;
}