#pragma once
#include "../integer/pow-mod.hpp"
#include "ordinal_operator.hpp"
#include "field.hpp"

template <ll (*mod)()>
ll mod_plus(const ll& a, const ll& b) {
    ll res;
    if(__builtin_add_overflow(a, b, &res)) {
        return a % mod() + b % mod();
    }
    return res;
}
template <ll (*mod)()>
ll mod_mult(const ll& a, const ll& b) {
    ll res;
    if(__builtin_mul_overflow(a, b, &res)) {
        return (a % mod()) * (b % mod());
    }
    return res;
}
template <ll (*mod)()>
ll mod_inv(const ll& a) {
    return inv_mod(a, mod());
}
ll mod998244353() { return 998244353; }
ll mod1000000007() { return 1000000007; }
template <ll (*mod)()>
ll make_representative(const ll& a) {
    ll b = a % mod();
    if(b < 0) b += mod();
    return b;
}

template <ll (*mod)()>
using Modint = Field<ll, mod_mult<mod>, ordinal_one<ll>, mod_inv<mod>, mod_plus<mod>, ordinal_zero<ll>, ordinal_plusinv<ll>, ll, ordinal_identity<ll>, make_representative<mod>>;

using MI3 = Modint<mod998244353>;
using V3 = Vector<MI3>;
using VV3 = Vector<V3>;
using VVV3 = Vector<VV3>;
using MI7 = Modint<mod1000000007>;
using V7 = Vector<MI7>;
using VV7 = Vector<V7>;
using VVV7 = Vector<VV7>;
