#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N], ans[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        ans[1] = 0;
        int last = -1;
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i - 1]){
                last = i;
                ans[i] = ans[i - 1];
            }
            else ans[i] = !ans[i - 1];
        }
        if(a[1] != a[n] && ans[1] == ans[n]){
            if(last != -1){
                for(int i = last; i <= n; i++) ans[i] = !ans[i];
            }
            else ans[n] = 2;
        }
        int res = 0; for(int i = 1; i <= n; i++) res = max(res, ans[i]);
        cout << res + 1 << '\n';
        for(int i = 1; i <= n; i++) cout << ans[i] + 1<< ' ';
        cout << '\n';
    }
    return 0;
}