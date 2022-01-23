#include <bits/stdc++.h>
using namespace std;

#define ll long long

int sign(ll n) {return (n > 0) - (n < 0);}
#define point pair<ll,ll>
#define polygon vector<point>
#define x first
#define y second
point operator - (point a, point b) {return {a.x - b.x, a.y - b.y};}
ll operator * (point a, point b) {return {a.x*b.y - a.y * b.x};}
ll operator | (point a, point b) {return {a.x*b.x + a.y * b.y};}
int orientation(point a, point b, point c) {return sign((b - a) * (c - a));}
ll dist2(point a, point b) {return (a - b) | (a - b);}
double dist(point a, point b) {return sqrt(dist2(a, b));}

int rnd(vector<int> a, int md) {
	while (1) {
		int p = rand() % md, ok = 1;
		for (auto x : a) {
			if (x == p) {
				ok = 0;
				break;
			}
		}
		if (ok)return p;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
	int n, k; cin >> n >> k; k--;
	vector<point> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}
	if (n == 3) {
		int r1 = 0, r2 = 1;
		if (k == 0)r1++, r2++;
		else if (k == 1)r2++;
		cout << dist(v[r1], v[r2]) + min(dist(v[k], v[r1]), dist(v[k], v[r2])) << '\n';
		return 0;
	}
	int a, b, c;
	while (1) {
		a = rnd({}, n);
		b = rnd({a}, n);
		c = rnd({a, b}, n);
		if (orientation(v[a], v[b], v[c]) == 0) {
			break;
		}
	}
	vector<point> nw;
	point ex;
	for (int i = 0; i < n; i++) {
		if (orientation(v[a], v[b], v[i]) == 0) {
			nw.push_back(v[i]);
		} else {
			ex = v[i];
		}
	}
	sort(nw.begin(), nw.end());
	assert(nw.size() + 1 == v.size());
	double tot = dist(nw[0], nw.back());
	double ans = 1e16, curr;
	if (ex == v[k]) {
		ans = min(dist(ex, nw[0]), dist(ex, nw.back())) + tot;
	} else {
		curr = dist(v[k], nw[0]) + tot;
		ans = min(ans, curr + dist(nw.back(), ex));
		for (int i = 0; i < nw.size(); i++) {
			ans = min(ans, curr + dist(ex, nw[i]) * 2);
			if (i + 1 < nw.size()) {
				// ans = min(ans, curr + dist(ex, nw[i]) + min(dist(nw[i + 1], ex), dist(ex, nw.back())) - dist(nw[i], nw[i + 1]));
				ans = min(ans, curr + dist(ex, nw[i]) + dist(ex, nw[i + 1]) - dist(nw[i], nw[i + 1]));
			}
		}
		curr = dist(v[k], nw.back()) + tot;
		ans = min(ans, curr + dist(nw[0], ex));
		for (int i = 0; i < nw.size(); i++) {
			ans = min(ans, curr + dist(ex, nw[i]) * 2);
			if (i + 1 < nw.size()) {
				// ans = min(ans, curr + dist(ex, nw[i]) + min(dist(nw[i + 1], ex), dist(ex, nw[0])) - dist(nw[i], nw[i + 1]));
				ans = min(ans, curr + dist(ex, nw[i]) + dist(ex, nw[i + 1]) - dist(nw[i], nw[i + 1]));
			}
		}
		for (int i = 0; i < nw.size(); i++) {
			ans = min(ans, dist(nw[i], v[k]) + dist(nw[i], ex) + dist(ex, nw[0]) + tot);
			ans = min(ans, dist(nw[i], v[k]) + dist(nw[i], ex) + dist(ex, nw.back()) + tot);
		}
		for (int i = 0; i < nw.size(); i++) {
			if (nw[i] == v[k]) {
				if (i + 1 < nw.size()) {
					ans = min(ans, dist(nw[0], nw[i]) + dist(nw[0], ex) + dist(ex, nw[i + 1]) + dist(nw.back(), nw[i + 1]));
				} else if (i - 1 >= 0) {
					ans = min(ans, dist(nw.back(), nw[i]) + dist(nw.back(), ex) + dist(ex, nw[i - 1]) + dist(nw[0], nw[i - 1]));
				}
			}
		}
	}
	if (v[k] == nw[0] || v[k] == nw.back()) {
		for (int i = 0; i < nw.size(); i++) {
			ll mul = (((i == 0 && v[k] == nw.back()) || (i + 1 == nw.size() && v[k] == nw[0])) ? 1 : 2);
			ans = min(ans, tot + dist(nw[i], ex) * mul);
			// if (i + 1 < nw.size())ans = min(ans, tot - dist(nw[i], nw[i + 1]) + dist(nw[i], ex) + min(dist(nw[i + 1], ex), dist(ex, (v[k] == nw[0] ? nw.back() : nw[0]))));
			if (i + 1 < nw.size())ans = min(ans, tot - dist(nw[i], nw[i + 1]) + dist(nw[i], ex) + dist(nw[i + 1], ex));

		}
	}
	cout << setprecision(10) << fixed << ans << '\n';
}