#pragma once
#include "../base.hpp"

template <
    typename T,
    T (*mult)(const T, const T),
    T (*one)(),
    T (*multinv)(const T),
    T (*plus)(const T, const T),
    T (*zero)(),
    T (*plusinv)(const T)
>
struct Field {
    T val;

    Field(T val=zero()) : val(val) {}
    operator T() const { return val; }
    Field& operator*=(const Field& other) {
        val = mult(val, other.val);
        return *this;
    }
    Field operator*(const Field& other) const {
        return Field(*this) *= other;
    }
    Field inv() const {
        return Field(multinv(val));
    }
    Field& operator/= (const Field& other) {
        return *this *= other.inv();
    }
    Field operator/ (const Field& other) const {
        return Field(*this) /= other;
    }
    Field& operator+=(const Field& other) {
        val = plus(val, other.val);
        return *this;
    }
    Field operator+(const Field& other) const {
        return Field(*this) += other;
    }
    Field operator-() const {
        return Field(plusinv(val));
    }
    Field& operator-=(const Field& other) {
        return *this += -other;
    }
    Field operator-(const Field& other) const {
        return Field(*this) -= other;
    }
    Field pow(ll n) const {
        if(n < 0) {
            return inv().pow(-n);
        }
        Field res = one();
        Field a = *this;
        while(n > 0) {
            if(n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    friend istream& operator>>(istream& is, Field& f) {
        return is >> f.val;
    }
    friend ostream& operator<<(ostream& os, const Field& f) {
        return os << f.val;
    }
};
namespace std {
    template <typename T, T (*mult)(const T, const T), T (*one)(), T (*multinv)(const T), T (*plus)(const T, const T), T (*zero)(), T (*plusinv)(const T)>
    struct hash<Field<T, mult, one, multinv, plus, zero, plusinv>> {
        size_t operator()(const Field<T, mult, one, multinv, plus, zero, plusinv>& f) const {
            return hash<T>()(f.val);
        }
    };
}
