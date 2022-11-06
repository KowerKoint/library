#pragma once
#include "../algebra/modint.hpp"
#include "fft.hpp"

template <ll mod>
void ntt(vector<Modint<mod>>& v) {
    assert(mod == 998244353);
    constexpr ll g = 3;
    int n = v.size();
    assert((n & (n - 1)) == 0);
    int m = __builtin_ctz(n);
    assert(m <= 23);
    Vector<Modint<mod>> zeta(n);
    zeta[0] = 1;
    Modint<mod> gn = Modint<mod>(g).pow((mod - 1) >> m);
    for(int i = 0; i < n-1; i++) zeta[i+1] = zeta[i] * gn;
    int array_idx_mask = 0;
    int array_id_mask = n-1;
    for(int i = 0; i < m; i++) {
        array_idx_mask ^= 1 << (m-i-1);
        array_id_mask ^= 1 << (m-i-1);
        Vector<Modint<mod>> nv(n);
        for(int j = 0; j < n; j++) {
            int k = (((j & array_idx_mask) << 1) & array_idx_mask) | (j & array_id_mask);
            nv[j] = v[k] + zeta[j & array_idx_mask] * v[k | (1 << (m-i-1))];
        }
        v.swap(nv);
    }
}
template <ll mod>
void intt(vector<Modint<mod>>& v) {
    assert(mod == 998244353);
    constexpr ll ig = 332748118;
    int n = v.size();
    assert((n & (n - 1)) == 0);
    int m = __builtin_ctz(n);
    assert(m <= 23);
    Vector<Modint<mod>> izeta(n);
    izeta[0] = 1;
    Modint<mod> ign = Modint<mod>(ig).pow((mod - 1) >> m);
    for(int i = 0; i < n-1; i++) izeta[i+1] = izeta[i] * ign;
    int array_idx_mask = 0;
    int array_id_mask = n-1;
    for(int i = 0; i < m; i++) {
        array_idx_mask ^= 1 << (m-i-1);
        array_id_mask ^= 1 << (m-i-1);
        Vector<Modint<mod>> nv(n);
        for(int j = 0; j < n; j++) {
            int k = (((j & array_idx_mask) << 1) & array_idx_mask) | (j & array_id_mask);
            nv[j] = v[k] + izeta[j & array_idx_mask] * v[k | (1 << (m-i-1))];
        }
        v.swap(nv);
    }
    for(int i = 0; i < n; i++) v[i] /= n;
}
template <typename T, enable_if_t<FiniteProperty<T>::is_finite, nullptr_t> = nullptr>
Vector<T> sum_convolution(const vector<T>& v1, const vector<T>& v2) {
    static_assert(is_same_v<T, Modint<998244353>>);
    int n = 1;
    while(n < (int)v1.size() + (int)v2.size() - 1) n <<= 1;
    Vector<T> f1(v1), f2(v2);
    f1.resize(n); f2.resize(n);
    ntt(f1); ntt(f2);
    for(int i = 0; i < n; i++) {
        f1[i] *= f2[i];
    }
    intt(f1);
    f1.resize(v1.size() + v2.size() - 1);
    return f1;
}
