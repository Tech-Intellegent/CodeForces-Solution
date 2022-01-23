#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
using ll = long long;
struct ST {
  int t[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = min(t[l], t[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = min(t[l], t[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
}t;

bool cmp(array<ll, 3> x, array<ll, 3> y) {
  return x[0] * y[1] < y[0] * x[1];
}
vector<int> b[N];
int a[N], n, m;
int bigger(ll sum, int sz) {
  int l = 1, r = n, ans = n + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (1LL * a[mid] * sz >= sum) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return n - ans + 1;
}
vector<array<ll, 3>> v;
int lowerbound(ll sum, int sz) {
  int l = 1, r = m, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (1LL * v[mid - 1][0] * sz <= sum * v[mid - 1][1]) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return ans;
}
bool good(int l, int r, int sub) {
  if (l > r) return true;
  return t.query(1, 1, m, l, r) - sub >= 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    v.clear();
    for (int i = 1; i <= m; i++) {
      int k; cin >> k;
      ll sum = 0;
      for (int j = 0; j < k; j++) {
        int x; cin >> x;
        b[i].push_back(x);
        sum += x;
      }
      v.push_back({sum, k, i});
    }
    t.build(1, 1, m);
    sort(v.rbegin(), v.rend(), cmp);
    int id = 0;
    for (auto [sum, sz, i]: v) {
      ++id;
      t.upd(1, 1, m, id, bigger(sum, sz) - id);
    }
    string ans = "";
    for (int i = 1; i <= m; i++) {
      ll sum = 0;
      for (auto x: b[i]) {
        sum += x;
      }
      int sz = b[i].size();
      int cur_id = lowerbound(sum, sz);
      for (auto x: b[i]) {
        int new_id = lowerbound(sum - x, sz - 1);
        if (new_id == 0) {
          if (good(1, cur_id - 1, 0) and good(cur_id + 1, m, -1)) {
            ans += '1';
          }
          else {
            ans += '0';
          }
          continue;
        }
        // cout << cur_id << ' ' << new_id << '\n';
        bool ok = true; 
        if (new_id <= cur_id) {
          ok &= bigger(sum - x, sz - 1) >= new_id;
          ok &= good(1, new_id - 1, 0) and good(new_id, cur_id - 1, 1) and good(cur_id + 1, m, 0);
        }
        else {
          ok &= bigger(sum - x, sz - 1) >= new_id - 1;
          ok &= good(1, cur_id - 1, 0) and good(cur_id + 1, new_id - 1, -1) and good(new_id, m, 0);
        }
        ans += char('0' + (int)ok);
      }
      b[i].clear();
    }
    cout << ans << '\n';
  }
  return 0;
}