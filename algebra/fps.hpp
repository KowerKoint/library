#pragma once
#include "field.hpp"
#include "../convolution/fft.hpp"
#include "../convolution/ntt.hpp"

template <typename T>
struct SumGroupFPS : SumGroupBase<Vector<T>> {
    static Vector<T>& addassign(Vector<T>& l, const Vector<T>& r) {
        resize(max(l.size(), r.size()));
        for(int i = 0; i < r.size(); i++) {
            l[i] += r[i];
        }
        return l;
    }
    constexpr static bool defzero = true;
    const static Vector<T> zero;
    static Vector<T> minus(const Vector<T>& x) {
        Vector<T> ret;
        for(int i = 0; i < x.size(); i++) {
            ret[i] = -ret[i];
        }
        return ret;
    }
};
template <typename T>
const Vector<T> SumGroupFPS<T>::zero = {};
template <typename T, bool expandable>
struct ProdGroupFPS : ProdGroupBase<Vector<T>> {
    static Vector<T>& mulassign(Vector<T>& l, const Vector<T>& r) {
        Vector<T> ret = sum_convolution(l, r);
        if constexpr(!expandable) {
            ret.resize(max(l.size(), r.size()));
        }
        return l = ret;
    }
    constexpr static bool defone = true;
    const static Vector<T> one;
    static Vector<T> inv(const Vector<T>& f) {
        Vector<T> g = {f[0].inv()};
        while(g.size() < f.size()) {
            Vector<T> f_short(f.begin(), f.begin() + min(f.size(), g.size() << 1));
            Vector<T> fgg = sum_convolution(f_short, sum_convolution(g, g));
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
const Vector<T> ProdGroupFPS<T, expandable>::one = {1};

template <typename T>
using FPS = Field<Vector<T>, SumGroupFPS<T>, ProdGroupFPS<T, false>>;
template <typename T>
using ExpandableFPS = Field<Vector<T>, SumGroupFPS<T>, ProdGroupFPS<T, true>>;
