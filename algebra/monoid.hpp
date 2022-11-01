#pragma once

#include "../base.hpp"

template <
    typename T,
    T (*mult)(const T, const T),
    T (*one)()
>
struct Monoid {
    T val;

    Monoid(T val=one()) : val(val) {
    }
    operator T() const {
        return val;
    }
    Monoid& operator*=(const Monoid& r) {
        val = mult(val, r.val);
        return *this;
    }
    Monoid operator*(const Monoid& r) const {
        return Monoid(*this) *= r;
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
    friend istream& operator>>(istream& is, Monoid& r) {
        return is >> r.val;
    }
    friend ostream& operator<<(ostream& os, const Monoid& r) {
        return os << r.val;
    }
};
namespace std {
    template <typename T, T (*mult)(const T, const T), T (*one)()>
    struct hash<Monoid<T, mult, one>> {
        size_t operator()(const Monoid<T, mult, one>& r) const {
            return hash<T>()(r.val);
        }
    };
}
