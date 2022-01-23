#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 9;

int l[N], r[N], a[200005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int k = a[i] + a[j];
      if (l[k]) {
        if (l[k] != i and l[k] != j and r[k] != i and r[k] != j) {
          cout << "YES\n";
          cout << l[k] << ' ' << r[k] << ' ' << i << ' ' << j << '\n';
          return 0;
        }
      }
      else {
        l[k] = i, r[k] = j;
      }
    }
  }
  cout << "NO\n";
  return 0;
}