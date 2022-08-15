#pragma once
#include "../base.hpp"

VI least_prime_factors(int n) {
    assert(n > 0);
    VI lpfs(n+1, -1), primes;
    FOR(d, 2, n+1) {
        if(lpfs[d] == -1) {
            lpfs[d] = d;
            primes.push_back(d);
        }
        for(int p : primes) {
            if(p * d > n || p > lpfs[d]) break;
            lpfs[p*d] = p;
        }
    }
    return lpfs;
}
