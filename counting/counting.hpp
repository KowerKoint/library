#pragma once
#include "base.hpp"

template <typename T>
struct Counting {
    vector<T> fact, ifact;

    Counting() {}
    Counting(ll n) {
        expand(n);
    }

    void expand(ll n) {
        ll sz = (ll)fact.size();
        if(sz > n) return;
        fact.resize(n+1);
        ifact.resize(n+1);
        fact[0] = 1;
        FOR(i, max(1LL, sz), n+1) fact[i] = fact[i-1] * i;
        ifact[n] = 1 / fact[n];
        for(ll i = n-1; i >= sz; i--) ifact[i] = ifact[i+1] * (i+1);
    }

    T p(ll n, ll r) {
        assert(n >= r);
        assert(r >= 0);
        expand(n);
        return fact[n] * ifact[n-r];
    }

    T c(ll n, ll r) {
        assert(n >= r);
        assert(r >= 0);
        expand(n);
        return fact[n] * ifact[r] * ifact[n-r];
    }

    T h(ll n, ll r) {
        assert(n >= 0);
        assert(r >= 0);
        return c(n+r-1, r);
    }

    T stirling(ll n, ll k) {
        assert(n >= k);
        assert(k >= 0);
        if(n == 0) return 1;
        T res = 0;
        int sign = k%2? -1 : 1;
        expand(k);
        REP(i, k+1) {
            res += sign * ifact[i] * ifact[k-i] * T(i).pow(n);
            sign *= -1;
        }
        return res;
    }

    vector<vector<T>> stirling_table(ll n, ll k) {
        assert(n >= 0 && k >= 0);
        vector<vector<T>> res(n+1, vector<T>(k+1));
        res[0][0] = 1;
        FOR(i, 1, n+1) FOR(j, 1, k+1) {
            res[i][j] = res[i-1][j-1] + j * res[i-1][j];
        }
        return res;
    }

    T bell(ll n, ll k) {
        assert(n >= 0 && k >= 0);
        expand(k);
        vector<T> tmp(k+1);
        int sign = 1;
        tmp[0] = 1;
        FOR(i, 1, k+1) {
            sign *= -1;
            tmp[i] = tmp[i-1] + sign * ifact[i];
        }
        T res = 0;
        REP(i, k+1) {
            res += T(i).pow(n) * ifact[i] * tmp[k-i];
        }
        return res;
    }

    vector<vector<T>> partition_table(ll n, ll k) {
        assert(n >= 0);
        vector<vector<T>> res(n+1, vector<T>(k+1));
        REP(i, k+1) res[0][i] = 1;
        FOR(i, 1, n+1) FOR(j, 1, k+1) {
            res[i][j] = res[i][j-1] + (i<j? 0 : res[i-j][j]);
        }
        return res;
    }
};
