#pragma once
#include "../algebra/field.hpp"

void fft(vector<complex<double>>& v) {
    int n = v.size();
    assert((n & (n - 1)) == 0);
    int m = __builtin_ctz(n);
    Vector<complex<double>> zeta(n);
    zeta[0] = 1;
    complex<double> gn = polar(1.0, 2 * M_PI / n);
    for(int i = 0; i < n-1; i++) zeta[i+1] = zeta[i] * gn;
    int array_idx_mask = 0;
    int array_id_mask = n-1;
    for(int i = 0; i < m; i++) {
        array_idx_mask ^= 1 << (m-i-1);
        array_id_mask ^= 1 << (m-i-1);
        Vector<complex<double>> nv(n);
        for(int j = 0; j < n; j++) {
            int k = (((j & array_idx_mask) << 1) & array_idx_mask) | (j & array_id_mask);
            nv[j] = v[k] + zeta[j & array_idx_mask] * v[k | (1 << (m-i-1))];
        }
        v.swap(nv);
    }
}
void ifft(vector<complex<double>>& v) {
    int n = v.size();
    assert((n & (n - 1)) == 0);
    int m = __builtin_ctz(n);
    Vector<complex<double>> izeta(n);
    izeta[0] = 1;
    complex<double> ign = polar(1.0, -2 * M_PI / n);
    for(int i = 0; i < n-1; i++) izeta[i+1] = izeta[i] * ign;
    int array_idx_mask = 0;
    int array_id_mask = n-1;
    for(int i = 0; i < m; i++) {
        array_idx_mask ^= 1 << (m-i-1);
        array_id_mask ^= 1 << (m-i-1);
        Vector<complex<double>> nv(n);
        for(int j = 0; j < n; j++) {
            int k = (((j & array_idx_mask) << 1) & array_idx_mask) | (j & array_id_mask);
            nv[j] = v[k] + izeta[j & array_idx_mask] * v[k | (1 << (m-i-1))];
        }
        v.swap(nv);
    }
    for(int i = 0; i < n; i++) v[i] /= n;
}
template <typename T, enable_if_t<!FiniteProperty<T>::is_finite, nullptr_t> = nullptr>
Vector<T> sum_convolution(const vector<T>& v1, const vector<T>& v2) {
    int n = 1;
    while(n < (int)v1.size() + (int)v2.size() - 1) n <<= 1;
    Vector<complex<double>> f1(ALL(v1)), f2(ALL(v2));
    f1.resize(n); f2.resize(n);
    fft(f1); fft(f2);
    for(int i = 0; i < n; i++) {
        f1[i] *= f2[i];
    }
    ifft(f1);
    return Vector<T>(f1.begin(), f1.begin() + v1.size() + v2.size() - 1);
}
template <>
Vector<ll> sum_convolution<ll>(const vector<ll>& v1, const vector<ll>& v2) {
    Vector<complex<double>> res = sum_convolution(Vector<complex<double>>(v1.begin(), v1.end()), Vector<complex<double>>(v2.begin(), v2.end()));
    Vector<ll> ret(res.size());
    for(int i = 0; i < (int)res.size(); i++) {
        ret[i] = round(res[i].real());
    }
    return ret;
}
