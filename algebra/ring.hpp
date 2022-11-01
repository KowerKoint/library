#pragma once
#include "../base.hpp"

template<
    typename T,
    T (*mult)(const T, const T),
    T (*one)(),
    T (*plus)(const T, const T),
    T (*zero)(),
    T (*plusinv)(const T)
>
struct Ring {
    T val;

    Ring(T val=zero()) : val(val) {
    }
    operator T() const {
        return val;
    }
    Ring& operator*= (const Ring& other) {
        this->val = mult(this->val, other.val);
        return *this;
    }
    Ring operator*(const Ring& other) const {
        return Ring(mult(this->val, other.val));
    }
    Ring& operator+=(const Ring& r) {
        this->val = plus(this->val, r.val);
        return *this;
    }
    Ring operator+(const Ring& r) const {
        return Ring(*this) += r;
    }
    Ring operator-() const {
        return Ring(plusinv(this->val));
    }
    Ring& operator-=(const Ring& r) {
        return *this += -r;
    }
    Ring operator-(const Ring& r) const {
        return Ring(*this) -= r;
    }
    Ring pow(ll n) {
        assert(n >= 0);
        Ring res = one();
        Ring a = *this;
        while (n > 0) {
            if (n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    friend istream& operator>>(istream& is, Ring& r) {
        return is >> r.val;
    }
    friend ostream& operator<<(ostream& os, const Ring& r) {
        return os << r.val;
    }
};
namespace std {
    template<typename T, T (*mult)(const T, const T), T (*one)(), T (*plus)(const T, const T), T (*zero)(), T (*plusinv)(const T)>
    struct hash<Ring<T, mult, one, plus, zero, plusinv>> {
        size_t operator()(const Ring<T, mult, one, plus, zero, plusinv>& r) const {
            return hash<T>()(r.val);
        }
    };
}
