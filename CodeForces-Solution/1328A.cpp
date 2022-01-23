#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << ( b - a % b) % b << '\n';
    }
    return 0;
}