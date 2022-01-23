#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string a, b;
        int f = 0;
        if(s[0] == '0') a = "2", b = "1", f = 1;
        else if(s[0] == '1')  a= "2", b = "2";
        else a = "1", b = "1";

        for(int i = 1; i < n; i++){
            if(f) a.push_back('0'), b.push_back(s[i]);
            else{
                if(s[i] == '2') a.push_back('1'), b.push_back('1');
                else if(s[i] == '0') a.push_back('0'), b.push_back('0');
                else b.push_back('0'), a.push_back('1'), f = 1;
            }
        }
        cout << a << '\n' << b << '\n';
    }
    return 0;
}