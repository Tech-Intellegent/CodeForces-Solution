#include<bits/stdc++.h>
using namespace std;

const int N = 505;

long long d[N][N], res[N];
bool vis[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> d[i][j];
    vector<int> ord;
    for(int i = 1; i <= n; i++){
        int k; cin >> k; ord.push_back(k);
    }
    for(int id = n - 1; id >= 0; id--){
        int k = ord[id];
        vis[k] = 1;
        long long ans = 0;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            if(vis[i] && vis[j]) ans += d[i][j];
        }
        res[id] = ans;
    }
    for(int i = 0; i < n; i++) cout << res[i] << ' ';
    return 0;
}