#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 9;
int a[N][N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  int k = 1;
  for (int i = 1; i <= 16; i++) {
    k = k * i / __gcd(k, i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x; cin >> x;
      if ((i + j) & 1) {
        cout << k + x * x * x *x << ' ';
      }
      else {
        cout << k << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}