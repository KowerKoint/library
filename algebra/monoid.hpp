#pragma once

#include "../base.hpp"
#include "ordinal_operator.hpp"

template <
    typename T,
    T (*mult)(const T&, const T&),
    T (*one)(),
    typename R = T,
    T (*rtot)(const R&) = ordinal_identity<R>,
    R (*ttor)(const T&) = ordinal_identity<T>
>
struct Monoid {
    T val;
    Monoid() : val(one()) {}
    Monoid(const R& r) : val(rtot(r)) {}
    operator R() const { return ttor(val); }
    Monoid& operator*=(const Monoid& other) {
        val = mult(val, other.val);
        return *this;
    }
    Monoid operator*(const Monoid& other) const {
        return Monoid(*this) *= other;
    }
    Monoid operator*(const R& r) const {
        return Monoid(*this) *= Monoid(r);
    }
    friend Monoid operator*(const R& r, const Monoid& m) {
        return Monoid(r) *= m;
    }
    Monoid pow(ll n) const {
        assert(n >= 0);
        Monoid res = one();
        Monoid a = *this;
        while(n > 0) {
            if(n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    friend istream& operator>>(istream& is, Monoid& f) {
        R r; is >> r;
        f = Monoid(r);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Monoid& f) {
        return os << (R)f.val;
    }
};
namespace std {
    template <
        typename T,
        T (*mult)(const T, const T),
        T (*one)(),
        typename R,
        T (*rtot)(const R),
        R (*ttor)(const T)
    >
    struct hash<Monoid<T, mult, one, R, rtot, ttor>> {
        size_t operator()(const Monoid<T, mult, one, R, rtot, ttor>& f) const {
            return hash<T>()((R)f.val);
        }
    };
}
