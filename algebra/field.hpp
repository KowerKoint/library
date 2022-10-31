#pragma once
#include "../base.hpp"

template <
    typename T,
    T (*plus)(const T, const T)=nullptr,
    T (*zero)()=nullptr,
    T (*mult)(const T, const T)=nullptr,
    T (*one)()=nullptr,
    T (*plusinv)(const T)=nullptr,
    T (*multinv)(const T)=nullptr
>
struct Field {
    T val;

    Field(T val=zero()) : val(val) {
    }
    operator T() const {
        return val;
    }
    Field& operator+=(const Field& r) {
        val = plus(val, r.val);
        return *this;
    }
    Field operator+(const Field& r) const {
        return Field(*this) += r;
    }
    Field& operator-=(const Field& r) {
        val = plus(val, plusinv(r.val));
        return *this;
    }
    Field operator-(const Field& r) const {
        return Field(*this) -= r;
    }
    Field& operator*=(const Field& r) {
        val = mult(val, r.val);
        return *this;
    }
    Field operator*(const Field& r) const {
        return Field(*this) *= r;
    }
    Field& operator/=(const Field& r) {
        val = mult(val, multinv(r.val));
        return *this;
    }
    Field operator/(const Field& r) const {
        return Field(*this) /= r;
    }
    Field operator-() const {
        return Field(plusinv(val));
    }
    Field inv() const {
        return Field(multinv(val));
    }
    Field pow(ll n) const {
        if(n < 0) return inv().pow(-n);
        Field res = one();
        Field a = *this;
        while(n > 0) {
            if(n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    friend istream& operator>>(istream& is, Field& r) {
        T val; is >> val;
        r = Field(val);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Field& r) {
        return os << r.val;
    }
};

template <typename T>
T ordinal_plus(const T a, const T b) {
    return a + b;
}
template <typename T>
T ordinal_zero() {
    return T(0);
}
template <typename T>
T ordinal_mult(const T a, const T b) {
    return a * b;
}
template <typename T>
T ordinal_one() {
    return T(1);
}
template <typename T>
T ordinal_plusinv(const T a) {
    return -a;
}
template <typename T>
T ordinal_multinv(const T a) {
    return T(1) / a;
}
template <typename T>
T ordinal_xor(const T a, const T b) {
    return a ^ b;
}
template <typename T>
using RealField = Field<T, ordinal_plus<T>, ordinal_zero<T>, ordinal_mult<T>, ordinal_one<T>, ordinal_plusinv<T>, ordinal_multinv<T>>;
