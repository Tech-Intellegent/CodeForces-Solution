#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int a[3][N], sz[3];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
    	cin >> sz[0] >> sz[1] >> sz[2];
    	for (int k = 0; k < 3; k++) {
    		for (int i = 0; i < sz[k]; i++) cin >> a[k][i];
    		sort(a[k], a[k] + sz[k]);
    		sz[k] = unique(a[k], a[k] + sz[k]) - a[k];
    	}
    	vector<int> p;
    	long long ans = 5e18;
    	for (int i = 0; i < 3; i++) p.push_back(i);
    	do {
    		for (int i = 0; i < sz[p[0]]; i++) {
    			int x = lower_bound(a[p[1]], a[p[1]] + sz[p[1]], a[p[0]][i]) - a[p[1]];
    			for (int j = max(0, x - 3); j < min(sz[p[1]], x + 3); j++) {
    				int y = lower_bound(a[p[2]], a[p[2]] + sz[p[2]], (a[p[0]][i] + a[p[1]][j]) / 2) - a[p[2]];
    				for (int k = max(0, y - 3); k < min(sz[p[2]], y + 3); k++) {
    					long long c = a[p[0]][i], d = a[p[1]][j], e = a[p[2]][k];
    					ans = min(ans, (c - d) * (c - d) + (d - e) * (d - e) + (c - e) * (c - e));
    				}

    			}
    		}
    	}while(next_permutation(p.begin(), p.end()));
    	cout << ans << '\n';
    }
    return 0;
}