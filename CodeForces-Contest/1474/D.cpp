#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int n, a[N];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  if (!a.second || !b.second) return {-1, 0};
  if (b.first < a.first) return {-1, 0};
  return {b.first - a.first, 1};
}
pair<int, int> suf[N], pref[N];
int yo() {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    sum %= 2;
  }
  if (sum) return 0;
  suf[n + 1] = {0, 1};
  for (int i = n; i >= 1; i--) {
    suf[i] = merge(suf[i + 1], {a[i], 1});
  }
  if (suf[1].second && suf[1].first == 0) return 1;
  pref[0] = {0, 1};
  for (int i = 1; i <= n; i++) {
    pref[i] = merge(pref[i - 1], {a[i], 1});
    if (i > 1) {
      swap(a[i], a[i - 1]);
      pair<int, int> cur = pref[i - 2];
      cur = merge(cur, {a[i - 1], 1});
      cur = merge(cur, {a[i], 1});
      cur = merge(cur, suf[i + 1]);
      if (cur.second && cur.first == 0) return 1;
      swap(a[i], a[i - 1]);
    }
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (yo()) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}