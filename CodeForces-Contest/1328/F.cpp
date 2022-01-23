#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    long long tsum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], tsum += a[i];
    sort(a + 1, a + n + 1);
    long long sum = 0, ans = 4e18;
    for(int i = 1, j; i <= n; i = j){
        long long lsum = sum;
        sum += a[i];
        for(j = i + 1; j <= n && a[i] == a[j]; j++) sum += a[j];
        long long lmov = 0, rmov = 0;
        if(i > 1){
            lmov = 1LL * (i - 1) * (a[i] - 1) - lsum ;
        }
        if(j <= n){
            rmov = (tsum - sum) - 1LL * (n - j + 1) * (a[i] + 1);
        }
        assert(lmov >= 0 && rmov >= 0);
        long long nw = 0; int need = k - (j - i);
        if(need <= 0){
            ans = 0; continue;
        }
        long long cur = lmov + rmov + need;
        if(need <= i - 1) cur = min(cur, lmov + need);
        if(need <= n - j + 1) cur = min(cur, rmov + need);
        nw = cur;
        ans = min(ans, nw);
    }
    cout << ans << '\n';
    return 0;
}