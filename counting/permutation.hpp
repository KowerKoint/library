#include "../base.hpp"

template<typename T>
T permutation(ll n, ll k) {
    assert(n >= k);
    assert(k >= 0);
    T res(1);
    REP(i, k) {
        res *= n - i;
    }
    return res;
}
