#include "extgcd.hpp"

ll inv_mod(ll n, ll m) {
    n %= m;
    if (n < 0) n += m;
    ll x, y;
    assert(extgcd(n, m, x, y) == 1);
    x %= m;
    if(x < 0) x += m;
    return x;
}

ll pow_mod(ll a, ll n, ll m) {
    if(n == 0) return 1LL;
    if(n < 0) return inv_mod(pow_mod(a, -n, m), m);
    a %= m;
    if (a < 0) n += m;
    ll res = 1;
    while(n) {
        if(n & 1) {
            res *= a;
            res %= m;
        }
        n >>= 1;
        a *= a;
        a %= m;
    }
    return res;
}
