#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int nw = 1;
        string s = string(n, 'a');
        while(k){
            if(k <= nw){
                int i = n - nw, j = n - k + 1;
                s[i - 1] = s[j - 1] = 'b';
                break;
            }
            k -= nw;
            nw++;
        }
        cout << s << '\n';
    }
    return 0;
}