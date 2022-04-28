#pragma once
#include "base.hpp"

VL divisor(ll n) {
    assert(n > 0);
    VL fow, bck;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            fow.push_back(i);
            if(i * i != n) bck.push_back(n / i);
        }
    }
    reverse(ALL(bck));
    fow.insert(fow.end(), ALL(bck));
    return fow;
}

bool is_prime(ll n) {
    assert(n > 0);
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
    VL primes;
    vector<bool> sieved(n+1);
    FOR(d, 2, n+1) {
        if(!sieved[d]) {
            primes.push_back(d);
            for(ll i = d*d; i <= n; i += d) sieved[i] = 1;
        }
    }
    return primes;
}

map<ll, int> prime_factor(ll n) {
    assert(n > 0);
    map<ll, int> factor;
    for(ll d = 2; d*d <= n; d++) {
        while(n%d == 0) {
            n /= d;
            factor[d]++;
        }
    }
    if(n > 1) factor[n]++;
    return factor;
}

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
