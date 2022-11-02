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
private:
    T _val;
public:
    Monoid() : _val(one()) {}
    Monoid(const T& t) : _val(t) {}
    Monoid(const R& r) : _val(rtot(r)) {}
    R val() const { return ttor(_val); }
    Monoid& operator*=(const Monoid& other) {
        _val = mult(_val, other._val);
        return *this;
    }
    Monoid operator*(const Monoid& other) const {
        return Monoid(*this) *= other;
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
    bool operator==(const Monoid& other) const {
        return val() == other.val();
    }
    bool operator!=(const Monoid& other) const {
        return !(*this == other);
    }
    bool operator<(const Monoid& other) const {
        return val() < other.val();
    }
    bool operator>(const Monoid& other) const {
        return other < *this;
    }
    bool operator<=(const Monoid& other) const {
        return !(other < *this);
    }
    bool operator>=(const Monoid& other) const {
        return !(*this < other);
    }
    friend istream& operator>>(istream& is, Monoid& f) {
        R r; is >> r;
        f = Monoid(r);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Monoid& f) {
        return os << f.val();
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
            return hash<R>()(f.val());
        }
    };
}
