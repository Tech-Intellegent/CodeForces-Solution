#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  string p = "abba";
  for (int i = 0; i < n; i++) {
    cout << p[i % 4];
  }
  return 0;
}