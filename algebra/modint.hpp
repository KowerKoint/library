#pragma once
#include "../integer/pow-mod.hpp"
#include "field.hpp"

template <ll mod>
struct ModintBase {
    ll val;
};
template <ll mod>
struct SumGroup<ModintBase<mod>> {
    static ModintBase<mod>& addassign(ModintBase<mod>& l, const ModintBase<mod>& r) {
        ll ret;
        if(__builtin_add_overflow(l.val, r.val, &ret)) {
            l.val = l.val % mod + r.val % mod;
        } else {
            l.val = ret;
        }
        return l;
    }
    constexpr static bool defzero = true;
    constexpr static ModintBase<mod> zero = {0};
    constexpr static ModintBase<mod> minus(const ModintBase<mod>& x) {
        return {-x.val};
    }
};
template <ll mod>
struct ProdGroup<ModintBase<mod>> {
    constexpr static bool defmul = true;
    static ModintBase<mod>& mulassign(ModintBase<mod>& l, const ModintBase<mod>& r) {
        ll ret;
        if(__builtin_mul_overflow(l.val, r.val, &ret)) {
            l.val = (l.val % mod) * (r.val % mod);
        } else {
            l.val = ret;
        }
        return l;
    }
    constexpr static bool defone = true;
    constexpr static ModintBase<mod> one = {1};
    constexpr static bool definv = true;
    static ModintBase<mod> inv(const ModintBase<mod>& x) {
        return {inv_mod(x.val, mod)};
    }
};
template <ll mod>
struct Representation<ModintBase<mod>> {
    using R = ll;
    constexpr static ModintBase<mod> construct(const R& x) { return {x % mod}; }
    static R represent(const ModintBase<mod>& x) {
        ll ret = x.val % mod;
        if(ret < 0) ret += mod;
        return ret;
    }
};
template <ll mod>
struct FiniteProperty<ModintBase<mod>> {
    constexpr static bool is_finite = true;
    constexpr static ModintBase<mod> premitive_root() {
        static_assert(mod == 998244353);
        return 3;
    }
    constexpr static size_t order() {
        return mod - 1;
    }
};

template <ll mod>
using Modint = Field<ModintBase<mod>>;

using MI3 = Modint<998244353>;
using V3 = Vector<MI3>;
using VV3 = Vector<V3>;
using VVV3 = Vector<VV3>;
using MI7 = Modint<1000000007>;
using V7 = Vector<MI7>;
using VV7 = Vector<V7>;
using VVV7 = Vector<VV7>;
