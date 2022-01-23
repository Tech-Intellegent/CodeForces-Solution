#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int m; cin >> m;
		string ans; ans.resize(m);
		vector<int> cur;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			cur.push_back(i);
		}
		sort(s.begin(), s.end());
		while (cur.size()) {
			vector<int> done;
			vector<int> del;
			for (auto i: cur) {
				if (a[i] == 0) del.push_back(i);
			}
			assert(del.size() > 0);
			for (auto i: del) {
				done.push_back(i);
				cur.erase(find(cur.begin(), cur.end(), i));
			}
			for (auto i: cur) {
				for (auto j: done) a[i] -= abs(i - j);
			}
			char c;
			for (auto i: del) {
				ans[i] = s.back();
				s.pop_back(); c = ans[i];
			}
			while (s.size() && s.back() == c) s.pop_back();
		}
		cout << ans << '\n';
	}
    return 0;
}