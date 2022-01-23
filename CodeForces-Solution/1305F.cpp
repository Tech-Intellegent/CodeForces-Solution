#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define nl '\n'
#define deb(x) cerr << #x" = " << x << nl
#define in() ( { int a ; scanf("%d", &a); a; } )

const int N = 3e5 + 9;
const int mod = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ull gcd(ull u, ull v) {
    if (u == 0 || v == 0)
        return v ^ u;
    int shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) {
            ull t = v;
            v = u;
            u = t;
        }
        v -= u;
    } while (v);
    return u << shift;
}

ull mod_mul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1 / (double)M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull mod_pow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = mod_mul(b, b, mod), e /= 2)
        if (e & 1)
            ans = mod_mul(ans, b, mod);
    return ans;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1)
        return (n | 1) == 3;
    ull A[] = {2, 13, 23, 1662803}, s = __builtin_ctzll(n - 1), d = n >> s;
    for (auto a : A) { // ^ count trailing zeroes
        ull p = mod_pow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = mod_mul(p, p, n);
        if (p != n - 1 && i != s)
            return 0;
    }
    return 1;
}
typedef ull u64;
typedef unsigned int u32;

typedef __uint128_t u128;
// typedef __int128_t i128;
typedef long long i64;
typedef unsigned long long u64;

u64 hi(u128 x) { return (x >> 64); }
u64 lo(u128 x) { return (x << 64) >> 64; }
struct Mont {
    Mont(u64 n) : mod(n) {
        inv = n;
        for(int i = 0; i < 6; i++)  inv *= 2 - n * inv;
        r2 = -n % n;
        for(int i = 0; i < 4; i++)  if ((r2 <<= 1) >= mod) r2 -= mod;
        for(int i = 0; i < 5; i++)  r2 = mul(r2, r2);
    }
    u64 reduce(u128 x) const {
        u64 y = hi(x) - hi(u128(lo(x) * inv) * mod);
        return i64(y) < 0 ? y + mod : y;
    }
    u64 reduce(u64 x) const { return reduce(x); }
    u64 init(u64 n) const { return reduce(u128(n) * r2); }
    u64 mul(u64 a, u64 b) const { return reduce(u128(a) * b); }
    u64 mod, inv, r2;
};

ull pollard(ull n) {
    if (n == 9)
        return 3;
    if (n == 25)
        return 5;
    if (n == 49)
        return 7;
    if (n == 323)
        return 17;
    Mont mont(n);
    auto f = [n, &mont](ull x) { return mont.mul(x, x) + 1; };
    ull x = 0, y = 0, t = 0, prd = 2, i = 1, q;
    while (t++ % 32 || gcd(prd, n) == 1) {
        if (x == y)
            x = ++i, y = f(x);
        if ((q = mont.mul(prd, max(x, y) - min(x, y))))
            prd = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prd, n);
}

unordered_set<ll> primes;
unordered_set<ll> seen;
void factor(ull n) {
    if (n <= 2 || seen.count(n))
        return;
    seen.insert(n);
    if (isPrime(n))
        primes.insert(n);
    else {
        ull x = pollard(n);
        factor(x), factor(n / x);
    }
}


ll a[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans += a[i] & 1;
        factor(a[i]);
    }
    for(auto p: primes){
        ll nw = 0;
        for(int i = 1; i <= n; i++){
            ll x = a[i] % p;
            nw += x < p - x && a[i] >= p ? x : p - x;
            if(nw >= ans) break;
        }
        ans = min(ans, nw);
    }
    cout << ans << nl;
    return 0;
}