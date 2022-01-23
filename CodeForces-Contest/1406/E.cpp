#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int spf[N];
vector<int> primes;
void linear_sieve() {
    for(int i = 2; i < N; i++) {
        if (spf[i] == 0) spf[i] = i, primes.push_back(i);
        int sz = primes.size();
        for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
        	spf[i * primes[j]] = primes[j];
        }
    }
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	linear_sieve();
	int n; cin >> n;
	while (!primes.empty() && primes.back() > n) primes.pop_back();
	int cnt = 0;
	for (auto x: primes) {
		if (1LL * x * x > n) break;
		cout << "B " << x << '\n';
		cout.flush();
		int k; cin >> k;
	}
	int ans = 1;
	for (auto x: primes) {
		if (1LL * x * x > n) break;
		cout << "B " << x << '\n';
		cout.flush();
		int k; cin >> k;
		if (k) {
			ans *= x;
			for (int c = x, x = c * c; ; x *= c) {
				cout << "B " << x << '\n';
				cnt++;
				cout.flush();
				int k; cin >> k;
				if (!k) break;
				ans *= c;
			}
		}
	}
	reverse(primes.begin(), primes.end());
	while (!primes.empty() && 1LL * primes.back() * primes.back() <= n) {
		primes.pop_back();
	}
	reverse(primes.begin(), primes.end());
	int cur = primes.size();
	for (int i = 0; i < primes.size(); i += 100) {
		int j = min(i + 100, (int)primes.size());
		int f = 0;
		for (int x = i; x < j; x++) {
			cout << "B " << primes[x] << '\n';
			cout.flush();
			int k; cin >> k;
			if (k > 1) {
				ans *= primes[x];
				f = 1;
				break;
			}
			cur--;
		}
		if (f) break;
		cout << "A " << 1 << '\n';
		cout.flush();
		int k; cin >> k;
		if (k == cur + 1) continue;
		for (int x = i; x < j; x++) {
			cout << "B " << primes[x] << '\n';
			cout.flush();
			int k; cin >> k;
			if (k) {
				ans *= primes[x];
			}
		}
	}
	cout << "C " << ans << '\n';
	cout.flush();
    return 0;
}