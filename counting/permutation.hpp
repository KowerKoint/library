#include "../base.hpp"

template<typename T>
T permutation(T n, T k) {
    assert(n >= k);
    assert(k >= 0);
    T res(1);
    REP(i, k) {
        res *= n - i;
    }
    return res;
}
