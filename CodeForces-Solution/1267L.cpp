#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+6;

vector<int> divi[N];
int cnt[N],divcnt[N],val[N];

int main()
{
    for (int i = 1;i<N;i++){
        for (int j = i;j<N;j+=i)
            divi[j].push_back(i);
    }

    int tc;scanf("%d",&tc);
    while (tc--)
    {
        int n; scanf("%d",&n);

        for (int i = 0;i<=n;i++){
            cnt[i] = 0;
            val[i] = 0;
            divcnt[i] = 0;
        }
        int un = 0;
        for (int i = 0;i<n;i++){
            int c; scanf("%d",&c);
            cnt[c]++;
            if (cnt[c]==1) un++;
        }
        for (int i = 0;i<=n;i++) if (cnt[i]){
            for (int d: divi[cnt[i]]){
                divcnt[d]++;
                val[d]+=cnt[i]/d;
            }
            cnt[i]++;
            for (int d: divi[cnt[i]])if ( (cnt[i]-1)%d!=0){
                divcnt[d]++;
                val[d]+=cnt[i]/d;
            }
        }
        int ans = n;
        for (int i = 0;i<=n;i++)if (divcnt[i]==un){
            ans = min(ans,val[i]);
        }
        printf("%d\n",ans );
    }
    return 0;

}