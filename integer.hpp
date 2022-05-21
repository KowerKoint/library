#pragma once
#include "base.hpp"

ll kth_root(ll x, ll k) {
    if(k == 1) return x;
    ll res = 0;
    for(int i = 31; i >= 0; i--) {
        bool over = false;
        ll tmp = 1;
        ll nxt = res | 1LL << i;
        REP(i, k) {
            if(tmp > x / nxt) {
                over = true;
                break;
            }
            tmp *= nxt;
        }
        if(!over) res = nxt;
    }
    return res;
}

ll sqrt(ll x) {
    return kth_root(x, 2);
}

struct Prime {
    VI sieved;
    VL primes;

    Prime() {}
    Prime(ll n) {
        expand(n);
    }

    void expand(ll n) {
        ll sz = (ll)sieved.size() - 1;
        if(n <= sz) return;
        sieved.resize(n+1);
        sieved[0] = sieved[1] = 1;
        primes.clear();
        primes.push_back(2);
        for(ll d = 4; d <= n; d += 2) sieved[d] = 1;
        FOR(d, 2, n+1) {
            if(!sieved[d]) {
                primes.push_back(d);
                for(ll i = d*d; i <= n; i += d*2) sieved[i] = 1;
            }
        }
    }

    bool is_prime(ll n) {
        assert(n > 0);
        if(n <= (ll)sieved.size() - 1) return !sieved[n];
        for(ll d = 2; d*d <= n; d++) {
            if(n % d == 0) return false;
        }
        return true;
    }

    VL least_prime_factors(ll n) {
        assert(n > 0);
        VL lpfs(n+1, -1), primes;
        FOR(d, 2, n+1) {
            if(lpfs[d] == -1) {
                lpfs[d] = d;
                primes.push_back(d);
            }
            for(ll p : primes) {
                if(p * d > n || p > lpfs[d]) break;
                lpfs[p*d] = p;
            }
        }
        return lpfs;
    }

    VL prime_list(ll n) {
        assert(n > 0);
        expand(n);
        return VL(primes.begin(), upper_bound(ALL(primes), n));
    }

    vector<pair<ll, int>> prime_factor(ll n) {
        assert(n > 0);
        vector<pair<ll, int>> factor;
        expand(sqrt(n));
        for(ll prime : primes) {
            if(prime * prime > n) break;
            int cnt = 0;
            while(n % prime == 0) {
                n /= prime;
                cnt++;
            }
            if(cnt) factor.emplace_back(prime, cnt);
        }
        if(n > 1) factor.emplace_back(n, 1);
        return factor;
    }


    VL divisor(ll n) {
        assert(n > 0);
        auto factor = prime_factor(n);
        VL res = {1};
        for(auto [prime, cnt] : factor) {
            int sz = res.size();
            res.resize(sz * (cnt+1));
            REP(i, sz*cnt) res[sz+i] = res[i] * prime;
            REP(i, cnt) inplace_merge(res.begin(), res.begin() + sz*(i+1), res.begin() + sz*(i+2));
        }
        return res;
    }
};

ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll nx = 0, ny = 1;
    while(b) {
        ll q = a / b;
        tie(a, b) = LP(b, a % b);
        tie(x, nx) = LP(nx, x - nx*q);
        tie(y, ny) = LP(ny, y - ny*q);
    }
    return a;
}

ll inv_mod(ll n, ll m) {
    ll x, y;
    assert(extgcd(n, m, x, y) == 1);
    x %= m;
    if(x < 0) x += m;
    return x;
}

ll pow_mod(ll a, ll n, ll m) {
    if(n == 0) return 1LL;
    if(n < 0) return inv_mod(pow_mod(a, -n, m), m);
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

