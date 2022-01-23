#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

vector<int> g[N * 2];
struct SuffixAutomaton {
    struct node {
        int len, link, firstpos;
        map<char, int> nxt;
    };
    int sz, last;
    vector<node> t;
    vector<int> terminal;
    vector<long long> dp;
    SuffixAutomaton() {}
    SuffixAutomaton(int n) {
        t.resize(2 * n); terminal.resize(2 * n);
        dp.resize(2 * n, -1); sz = 1; last = 0;
        t[0].len = 0; t[0].link = -1; t[0].firstpos = 0;
    }
    void extend(char c) {
      if (t[last].nxt.count(c) && t[t[last].nxt[c]].len == t[last].len + 1) {
        last = t[last].nxt[c];
        return;
      }
        int cur = sz++;
        t[cur].len = t[last].len + 1;
        t[cur].firstpos = t[cur].len;
        int p = last;
        while (p != -1 && !t[p].nxt.count(c)) {
            t[p].nxt[c] = cur;
            p = t[p].link;
        }
        if (p == -1) t[cur].link = 0;
        else {
            int q = t[p].nxt[c];
            if (t[p].len + 1 == t[q].len) t[cur].link = q;
            else {
                int clone = sz++;
                t[clone] = t[q];
                t[clone].len = t[p].len + 1;
                while (p != -1 && t[p].nxt[c] == q) {
                    t[p].nxt[c] = clone;
                    p = t[p].link;
                }
                t[q].link = t[cur].link = clone;
            }
        }
        last = cur;
    }
};

long long ans;
long long dp[N * 2];
void dfs(int u) {
    long long cur = 0;
    for (auto v: g[u]) {
        dfs(v);
        cur += dp[v];
    }
    if (dp[u]) ans += cur;
    if (cur) dp[u] = cur;
}
string s[N];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    SuffixAutomaton sa(N);
    for (int i = 0; i < n; i++) {
      for (auto c: s[i]) {
        sa.extend(c);
      }
      dp[sa.last]++;
      cout << sa.last << '\n';
      sa.last = 0;
    }
    for (int i = 1; i < sa.sz; i++) g[sa.t[i].link].push_back(i);
        for (int i = 0; i < sa.sz; i++) {
            for (auto v: g[i]) {
                cout << i << ' ' << v << '\n';
            }
        }
    dfs(0);
    cout << ans << '\n';
    return 0;
}