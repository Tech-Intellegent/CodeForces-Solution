#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    sort(a.begin(), a.end());
    if (b == "abc") {
      vector<int> cnt(26, 0);
      for (auto x: a) {
        cnt[x - 'a']++;
      }
      if (cnt[0] and cnt[1] and cnt[2]) {
        a = string (cnt[0], 'a');
        a += string(cnt[2], 'c');
        a += string(cnt[1], 'b');
        for (int i = 3; i < 26; i++) {
          a += string(cnt[i], char(i + 'a'));
        }
      }
    }
    cout << a << '\n';
  }
  return 0;
}