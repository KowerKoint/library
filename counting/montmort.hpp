#pragma once
#include "../base.hpp"

template <typename T>
vector<T> montmort(int n) {
    assert(n >= 0);
    vector<T> res(n+1);
    FOR(i, 2, n+1) {
        res[i] = res[i-1] * i + (i % 2? -1 : 1);
    }
    return res;
}
