#pragma once
#include "../base.hpp"
#include "ordinal_operator.hpp"

template <
    typename T,
    T (*mult)(const T&, const T&),
    T (*one)(),
    T (*plus)(const T&, const T&),
    T (*zero)(),
    T (*plusinv)(const T&),
    typename R = T,
    T (*rtot)(const R&) = ordinal_identity<R>,
    R (*ttor)(const T&) = ordinal_identity<T>
>
struct Ring {
    T val;
    Ring() : val(zero()) {}
    Ring(const R& r) : val(rtot(r)) {}
    operator R() const { return ttor(val); }
    Ring& operator*=(const Ring& other) {
        val = mult(val, other.val);
        return *this;
    }
    Ring operator*(const Ring& other) const {
        return Ring(*this) *= other;
    }
    Ring& operator+=(const Ring& other) {
        val = plus(val, other.val);
        return *this;
    }
    Ring operator+(const Ring& other) const {
        return Ring(*this) += other;
    }
    Ring operator-() const {
        return Ring(plusinv(val));
    }
    Ring& operator-=(const Ring& other) {
        return *this += -other;
    }
    Ring operator-(const Ring& other) const {
        return Ring(*this) -= other;
    }
    Ring pow(ll n) const {
        assert(n >= 0);
        Ring res = one();
        Ring a = *this;
        while(n > 0) {
            if(n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    friend istream& operator>>(istream& is, Ring& f) {
        R r; is >> r;
        f = Ring(r);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Ring& f) {
        return os << (R)f.val;
    }
};
namespace std {
    template <
        typename T,
        T (*mult)(const T, const T),
        T (*one)(),
        T (*plus)(const T, const T),
        T (*zero)(),
        T (*plusinv)(const T),
        typename R,
        T (*rtot)(const R),
        R (*ttor)(const T)
    >
    struct hash<Ring<T, mult, one, plus, zero, plusinv, R, rtot, ttor>> {
        size_t operator()(const Ring<T, mult, one, plus, zero, plusinv, R, rtot, ttor>& f) const {
            return hash<T>()((R)f.val);
        }
    };
}
