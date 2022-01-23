#include<bits/stdc++.h>
using namespace std;

int n, a[200];
void solve(int cur, vector<int> done) {
  if (cur == 0) return;
  int last = n;
  while (done[last]) {
    --last;
  }
  vector<int> v;
  v.push_back(last);
  for (int add = 2; add <= cur; add++) {
    cout << "?";
    for (int i = 1; i <= n; i++) {
      if (done[i]) {
        cout << ' ' << n;
      }
      else if (i != last) {
        cout << ' ' << 1;
      }
      else {
        cout << ' ' << add;
      }
    }
    cout << endl;
    int x; cin >> x;
    if (x == 0 or done[x]) break;
    v.push_back(x);
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < (int)v.size(); i++) {
    a[v[i]] = cur--;
    done[v[i]] = 1;
  }
  solve(cur, done);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> done(n + 1, 0);
  solve(n, done);
  cout << "!";
  for (int i = 1; i <= n; i++) {
    cout << ' ' << a[i];
  }
  cout << endl;
  return 0;
}