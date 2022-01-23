#include<bits/stdc++.h>
using namespace std;
#define T unsigned int
const int N = 2010;

T d[N], mob[N], f[N * N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  T a, b, c; cin >> a >> b >> c;
  mob[1] = 1;
  for (T i = 1; i < N; i++) {
    for (T j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
  for (T i = 1; i <= c; i++) {
    for (T j = i; j <= c; j += i) {
      d[i] += c / j;
    }
  }
  for (T i = 1; i < N; i++) {
    if (mob[i] == 0) continue;
    for (T j = i; j < N * N; j += i) {
      f[j] += mob[i] * d[i];
    }
  }
  T ans = 0;
  for (T i = 1; i <= a; i++) {
    for (T j = 1; j <= b; j++) {
      if (__gcd(i, j) == 1) {
        ans += (a / i) * (b / j) * f[i * j];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}