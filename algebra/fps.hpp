#pragma once
#include "field.hpp"
#include "../convolution/ntt.hpp"

template <typename T, bool expandable = false>
struct FPSBase {
    Vector<T> val;
};
template <typename T, bool expandable>
struct SumGroup<FPSBase<T, expandable>> {
    static FPSBase<T, expandable>& addassign(FPSBase<T, expandable>& l, const FPSBase<T, expandable>& r) {
        resize(max(l.val.size(), r.val.size()));
        for(int i = 0; i < r.size(); i++) {
            l.val[i] += r.val[i];
        }
        return l;
    }
    constexpr static bool defzero = true;
    const static FPSBase<T, expandable> zero;
    static FPSBase<T, expandable>& minus(FPSBase<T, expandable> x) {
        for(int i = 0; i < x.val.size(); i++) {
            x.val[i] = -x.val[i];
        }
        return x;
    }
};
template <typename T, bool expandable>
const FPSBase<T, expandable> SumGroup<FPSBase<T, expandable>>::zero = {{}};
template <typename T, bool expandable>
struct ProdGroup<FPSBase<T, expandable>> {
    static FPSBase<T, expandable>& mulassign(FPSBase<T, expandable>& l, const FPSBase<T, expandable>& r) {
        Vector<T> ret = sum_convolution(l.val, r.val);
        if constexpr(!expandable) {
            ret.resize(max(l.val.size(), r.val.size()));
        }
        l.val = ret;
        return l;
    }
    constexpr static bool defone = true;
    const static FPSBase<T, expandable> one;
    static FPSBase<T, expandable> inv(const FPSBase<T, expandable>& f) {
        Vector<T> g = {f[0].inv()};
        while(g.size() < f.size()) {
            Vector<T> fgg = sum_convolution(f, sum_convolution(g, g));
            g.resize(g.size() << 1);
            for(int i = 0; i < g.size(); i++) {
                g[i] <<= 1;
                if(i < (int)fgg.size()) g[i] -= fgg[i];
            }
        }
        return {g};
    }
};
template <typename T, bool expandable>
const FPSBase<T, expandable> ProdGroup<FPSBase<T, expandable>>::one = {{1}};

template <typename T>
using FPS = Field<FPSBase<T>>;
template <typename T>
using ExpandableFPS = Field<FPSBase<T, true>>;
