#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int lsm[N], rsm[N], a[N], lbg[N], rbg[N], dpl[N], dpr[N]; 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i == 1 || a[i] > a[i - 1]) {
      lsm[i] = lsm[i - 1];
    }
    lsm[i]++;
    if (i == 1 || a[i] < a[i - 1]) {
      lbg[i] = lbg[i - 1];
    }
    lbg[i]++;
    dpl[i] = max(dpl[i - 1], lbg[i]);
    dpl[i] = max(dpl[i - 1], lsm[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (i == n || a[i] > a[i + 1]) {
      rsm[i] = rsm[i + 1];
    }
    rsm[i]++;
    if (i == n || a[i] < a[i + 1]) {
      rbg[i] = rbg[i + 1];
    }
    rbg[i]++;
    dpr[i] = max(dpr[i + 1], rbg[i]);
    dpr[i] = max(dpr[i + 1], rsm[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int L = lsm[i] - 1, R = rsm[i] - 1;
    if (max(L, R) <= 0) continue;
    bool win = true;
    if (max(L, R) <= max(dpl[i - max(1, L)], dpr[i + max(1, R)]) - 1) {
      win = false;
    }
    else {
      if (L < 1 || R < 1) {
        win = false;
      }
      else {
        int cur;
        if (L & 1) cur = i - L;
        else cur = i - L + 1;
        if (i - cur >= R) win = false;
        int dummy;
        if (R & 1) cur = i + R;
        else cur = i + R - 1;
        if (cur - i >= L) win = false;
      }
    }
    ans += win;
  }
  cout << ans << '\n';
  return 0;
}