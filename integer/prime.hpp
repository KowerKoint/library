#pragma once
#include "./kth-root-integer.hpp"

struct Prime {
    vector<bool> sieved;
    VI primes;

    Prime() {}
    Prime(int n) {
        expand(n);
    }

    void expand(int n) {
        int sz = (int)sieved.size() - 1;
        if(n <= sz) return;
        sieved.resize(n+1);
        sieved[0] = sieved[1] = 1;
        primes.clear();
        if(n >= 2) primes.push_back(2);
        for(int i = 3; i <= n; i += 2) {
            if(!sieved[d]) {
                primes.push_back(d);
                for(ll i = (ll)d*d; i <= n; i += d*2) sieved[i] = 1;
            }
        }
    }

    bool is_prime(ull n) {
        assert(n > 0);
        if(n == 2) return true;
        if(!(n & 1)) return false;
        if(n <= (ll)sieved.size() - 1) return !sieved[n];
        for(ull d = 2; d*d <= n; d++) {
            if(n % d == 0) return false;
        }
        return true;
    }

    VI prime_list(int n) {
        assert(n > 0);
        expand(n);
        return VI(primes.begin(), upper_bound(ALL(primes), n));
    }

    vector<pair<ull, int>> prime_factor(ull n) {
        assert(n > 0);
        vector<pair<ull, int>> factor;
        expand(kth_root_integer(n, 2));
        for(ull prime : primes) {
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


    VUL divisor(ull n) {
        assert(n > 0);
        auto factor = prime_factor(n);
        VUL res = {1};
        for(auto [prime, cnt] : factor) {
            int sz = res.size();
            res.resize(sz * (cnt+1));
            REP(i, sz*cnt) res[sz+i] = res[i] * prime;
            REP(i, cnt) inplace_merge(res.begin(), res.begin() + sz*(i+1), res.begin() + sz*(i+2));
        }
        return res;
    }
};
