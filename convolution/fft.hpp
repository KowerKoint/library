#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fft(vector<complex<double>>& v) {
    int n = v.size();
    assert((n & (n - 1)) == 0);
    int m = __builtin_ctz(n);
    vector<complex<double>> zeta(n);
    zeta[0] = 1;
    complex<double> gn = polar(1.0, 2 * M_PI / n);
    for(int i = 0; i < n-1; i++) zeta[i+1] = zeta[i] * gn;
    int array_idx_mask = 0;
    int array_id_mask = n-1;
    for(int i = 0; i < m; i++) {
        array_idx_mask ^= 1 << (m-i-1);
        array_id_mask ^= 1 << (m-i-1);
        vector<complex<double>> nv(n);
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
    vector<complex<double>> izeta(n);
    izeta[0] = 1;
    complex<double> ign = polar(1.0, -2 * M_PI / n);
    for(int i = 0; i < n-1; i++) izeta[i+1] = izeta[i] * ign;
    int array_idx_mask = 0;
    int array_id_mask = n-1;
    for(int i = 0; i < m; i++) {
        array_idx_mask ^= 1 << (m-i-1);
        array_id_mask ^= 1 << (m-i-1);
        vector<complex<double>> nv(n);
        for(int j = 0; j < n; j++) {
            int k = (((j & array_idx_mask) << 1) & array_idx_mask) | (j & array_id_mask);
            nv[j] = v[k] + izeta[j & array_idx_mask] * v[k | (1 << (m-i-1))];
        }
        v.swap(nv);
    }
    for(int i = 0; i < n; i++) v[i] /= n;
}
vector<complex<double>> sum_convolution(const vector<complex<double>>& v1, const vector<complex<double>>& v2) {
    int n = 1;
    while(n < (int)v1.size() + (int)v2.size() - 1) n <<= 1;
    vector<complex<double>> f1(v1), f2(v2);
    f1.resize(n); f2.resize(n);
    fft(f1); fft(f2);
    for(int i = 0; i < n; i++) {
        f1[i] *= f2[i];
    }
    ifft(f1);
    return f1;
}
vector<double> sum_convolution(const vector<double>& v1, const vector<double>& v2) {
    vector<complex<double>> res = sum_convolution(vector<complex<double>>(v1.begin(), v1.end()), vector<complex<double>>(v2.begin(), v2.end()));
    return vector<double>(res.begin(), res.end());
}
vector<ll> sum_convolution(const vector<ll>& v1, const vector<ll>& v2) {
    vector<complex<double>> res = sum_convolution(vector<complex<double>>(v1.begin(), v1.end()), vector<complex<double>>(v2.begin(), v2.end()));
    vector<ll> ret(res.size());
    for(int i = 0; i < (int)res.size(); i++) {
        ret[i] = round(res[i].real());
    }
    return ret;
}
