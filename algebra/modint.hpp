#pragma once
#include "../integer/pow-mod.hpp"
#include "field.hpp"

template <ll mod>
struct SumGroupModint : SumGroupBase<ll> {
    static ll& addassign(ll& l, const ll& r) {
        ll ret;
        if(__builtin_add_overflow(l, r, &ret)) {
            l = l % mod + r % mod;
        } else {
            l = ret;
        }
        return l;
    }
    constexpr static bool defzero = true;
    constexpr static ll zero = 0;
    constexpr static ll minus(const ll& x) {
        return -x;
    }
};
template <ll mod>
struct ProdGroupModint : ProdGroupBase<ll> {
    constexpr static bool defmul = true;
    static ll& mulassign(ll& l, const ll& r) {
        ll ret;
        if(__builtin_mul_overflow(l, r, &ret)) {
            l = (l % mod) * (r % mod);
        } else {
            l = ret;
        }
        return l;
    }
    constexpr static bool defone = true;
    constexpr static ll one = 1;
    constexpr static bool definv = true;
    constexpr static ll inv(const ll& x) {
        return inv_mod(x, mod);
    }
};
template <ll mod>
struct RepresentationModint : RepresentationBase<ll> {
    using R = ll;
    constexpr static ll construct(const R& x) { return x % mod; }
    constexpr static R represent(const ll& x) {
        ll ret = x % mod;
        if(ret < 0) ret += mod;
        return ret;
    }
};
template <ll mod>
struct CompareModint : CompareBase<ll> {
    constexpr static bool lt(const ll& l, const ll& r) {
        return RepresentationModint<mod>::represent(l) < RepresentationModint<mod>::represent(r);
    }
    constexpr static bool eq(const ll& l, const ll& r) {
        return RepresentationModint<mod>::represent(l) == RepresentationModint<mod>::represent(r);
    }
};
template <ll mod>
struct FinitePropertyModint : FinitePropertyBase<ll> {
    constexpr static bool is_finite = true;
    constexpr static ll premitive_root() {
        static_assert(mod == 998244353);
        return 3;
    }
    constexpr static size_t order() {
        return mod - 1;
    }
};

template <ll mod>
using Modint = Field<ll, SumGroupModint<mod>, ProdGroupModint<mod>, RepresentationModint<mod>, CompareModint<mod>, FinitePropertyModint<mod>>;

using MI3 = Modint<998244353>;
using V3 = vector<MI3>;
using VV3 = vector<V3>;
using VVV3 = vector<VV3>;
using MI7 = Modint<1000000007>;
using V7 = vector<MI7>;
using VV7 = vector<V7>;
using VVV7 = vector<VV7>;
