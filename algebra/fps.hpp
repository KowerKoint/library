#pragma once
#include "field.hpp"
#include "../convolution/fft.hpp"
#include "../convolution/ntt.hpp"

template <typename T>
struct SumGroupFPS : SumGroupBase<vector<T>> {
    static vector<T>& addassign(vector<T>& l, const vector<T>& r) {
        l.resize(max(l.size(), r.size()));
        for(int i = 0; i < r.size(); i++) {
            l[i] += r[i];
        }
        return l;
    }
    constexpr static bool defzero = true;
    const static vector<T> zero;
    static vector<T> minus(const vector<T>& x) {
        vector<T> ret;
        for(int i = 0; i < x.size(); i++) {
            ret[i] = -ret[i];
        }
        return ret;
    }
    using Coef = T;
    static vector<T>& coefassign(vector<T>& l, const T& k) {
        for(int i = 0; i < l.size(); i++) {
            l[i] *= k;
        }
        return l;
    }
    using Scalar = T;
    static Scalar dot(const vector<T>& l, const vector<T>& r) {
        Scalar ret = 0;
        for(int i = 0; i < min(l.size(), r.size()); i++) {
            ret += l[i] * r[i];
        }
        return ret;
    }
};
template <typename T>
const vector<T> SumGroupFPS<T>::zero = {};
template <typename T, bool expandable>
struct ProdGroupFPS : ProdGroupBase<vector<T>> {
    static vector<T>& mulassign(vector<T>& l, const vector<T>& r) {
        vector<T> ret = sum_convolution(l, r);
        if constexpr(!expandable) {
            ret.resize(max(l.size(), r.size()));
        }
        return l = ret;
    }
    constexpr static bool defone = true;
    const static vector<T> one;
    static vector<T> inv(const vector<T>& f) {
        vector<T> g = {f[0].inv()};
        while(g.size() < f.size()) {
            vector<T> f_short(f.begin(), f.begin() + min(f.size(), g.size() << 1));
            vector<T> fgg = sum_convolution(f_short, sum_convolution(g, g));
            g.resize(g.size() << 1);
            for(int i = 0; i < g.size(); i++) {
                g[i] += g[i];
                if(i < (int)fgg.size()) g[i] -= fgg[i];
            }
        }
        return g;
    }
};
template <typename T, bool expandable>
const vector<T> ProdGroupFPS<T, expandable>::one = {1};

template <typename T>
using FPS = Field<vector<T>, SumGroupFPS<T>, ProdGroupFPS<T, false>>;
template <typename T>
using ExpandableFPS = Field<vector<T>, SumGroupFPS<T>, ProdGroupFPS<T, true>>;
