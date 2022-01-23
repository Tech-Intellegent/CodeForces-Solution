#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1000000000;
map<pair<int, int>, int> mp;
int cnt = 0;
int get(int x, int y) {
	if (mp.count({x, y}))return mp[ {x, y}];
	cnt++;
	assert(cnt <= 40);
	cout << "? " << x << ' ' << y << endl;
	int a; cin >> a;
	return mp[ {x, y}] = a;
}

int32_t main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);

	int lx, ly, rx, ry;
	int p = get(1, 1);
	if (p == 2)lx = 2, ly = 2;
	else {
		int l = 1, r = inf - 1, an = 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (get(mid, 1) + mid == get(an, 1) + an) {
				// if (get(mid, 1) - get(an, 1) ==  -mid + an) {
				an = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		lx = an;
		ly = get(an, 1) + 1;
	}
	p = get(inf, 1);
	rx = inf - 1 - p + ly;
	p = get(inf, inf);
	ry = inf - rx + inf - p;
	cout << "! " << lx << ' ' << ly << ' ' << rx << ' ' << ry << endl;
}