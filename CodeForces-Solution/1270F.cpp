#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
#include <immintrin.h>
using mi = __m256i;
constexpr int BLOCK = 8;
 
string s;
int n;
int p[200005];
mi _p[8][200005/8+1];
vector<int> v[200005];
 
int32_t used[200005];
long long ans;
 
void prin(mi m) {
    union {
        mi m;
        int32_t d[BLOCK];
    } u;
    u.m = m;
    for (int i = 0; i < BLOCK; ++i) cout << u.d[i] << " ";
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (s[i] - '0');
    }
 
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            v[j].push_back(i);
        }
    }
    for (int i = 0; i+7 <= n; ++i) {
        union {
            mi m;
            int32_t d[8];
        } u;
        for (int j = 0; j < 8; ++j) {
            u.d[j] = p[i+j];
        }
        _p[i%8][i/8] = u.m;
    }
    // cout << used << "\n";
    // cout << (used+1) << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int x : v[i])
            used[x] = 1;
        mi sum = _mm256_set1_epi32(0);
        int jj = 0;
        if (n >= i+7) {
            const int up = (n-i-7)/8;
            for (; jj <= up; ++jj) {
                mi m = _mm256_sub_epi32(_p[i%8][jj+i/8],_p[0][jj]);
                mi vals = _mm256_i32gather_epi32(used, m, 4);
                sum = _mm256_add_epi32(sum,vals);
            }
        }
        int j = jj*8;
        for (;j <= n-i; ++j) ans += used[p[j+i]-p[j]];
        union {
            mi m;
            int32_t d[BLOCK];
        } u;
        u.m = sum;
        for (int k = 0; k < 8; ++k) ans += u.d[k];
        for (int x : v[i])
            used[x] = 0;
    }
    cout << ans << '\n';
    return 0;
}