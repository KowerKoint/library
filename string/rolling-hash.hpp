#pragma once

#include "../base.hpp"

struct RollingHash {
    constexpr static ull MASK30 = (1ULL << 30) - 1;
    constexpr static ull MASK31 = (1ULL << 31) - 1;
    constexpr static ull MOD = (1ULL << 61) - 1;
    constexpr static ull MASK61 = MOD;

    constexpr static inline ull add(ull a, ull b) {
        if((a += b) >= MOD) a -= MOD;
        return a;
    }

    constexpr static inline ull mul(ull a, ull b) {
        __uint128_t c = (__uint128_t)a * b;
        return add(c >> 61, c & MASK61);
    }

    uint base;
    vector<ull> power;

    RollingHash(ull base = 0) : base(base) {
        if(base == 0) {
            mt19937 mt((random_device())());
            base = uniform_int_distribution<uint>(129, ~0U)(mt);
        }
        power = {1};
    }

    void expand(int n) {
        int m = power.size();
        if(m > n) return;
        power.resize(n+1);
        FOR(i, m, n+1) power[i] = power[i-1] * base;
    }

    template<typename It>
    vector<ull> build(It begin, It end) {
        int n = end - begin;
        vector<ull> res(n+1);
        REP(i, n) {
            res[i+1] = add(mul(res[i], base), *(begin+i));
        }
        return res;
    }

    vector<ull> build(const string& s) {
        return build(ALL(s));
    }

    ull query(const vector<ull>& hs, int l, int r) {
        expand(r - l);
        return add(hs[r], MOD - mul(hs[l], power[r-l]));
    }
};
