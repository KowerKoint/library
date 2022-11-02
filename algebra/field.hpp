#pragma once
#include "../base.hpp"
#include "ordinal_operator.hpp"

template <
    typename T,
    T (*mult)(const T&, const T&),
    T (*one)(),
    T (*multinv)(const T&),
    T (*plus)(const T&, const T&),
    T (*zero)(),
    T (*plusinv)(const T&),
    typename R = T,
    T (*rtot)(const R&) = ordinal_identity<R>,
    R (*ttor)(const T&) = ordinal_identity<T>
>
struct Field {
    T val;
    Field() : val(zero()) {}
    Field(const R& r) : val(rtot(r)) {}
    operator R() const { return ttor(val); }
    Field& operator*=(const Field& other) {
        val = mult(val, other.val);
        return *this;
    }
    Field operator*(const Field& other) const {
        return Field(*this) *= other;
    }
    Field operator*(const R& other) const {
        return Field(*this) *= Field(other);
    }
    friend Field operator*(const R& other, const Field& field) {
        return field * other;
    }
    Field inv() const {
        return Field(multinv(val));
    }
    Field& operator/=(const Field& other) {
        return *this *= other.inv();
    }
    Field operator/(const Field& other) const {
        return Field(*this) /= other;
    }
    Field operator/(const R& other) const {
        return Field(*this) /= Field(other);
    }
    friend Field operator/(const R& other, const Field& field) {
        return Field(other) / field;
    }
    Field& operator+=(const Field& other) {
        val = plus(val, other.val);
        return *this;
    }
    Field operator+(const Field& other) const {
        return Field(*this) += other;
    }
    Field operator+(const R& other) const {
        return Field(*this) += Field(other);
    }
    friend Field operator+(const R& other, const Field& field) {
        return field + other;
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
    Field operator-(const R& other) const {
        return Field(*this) -= Field(other);
    }
    friend Field operator-(const R& other, const Field& field) {
        return Field(other) - field;
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
        R r; is >> r;
        f = Field(r);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Field& f) {
        return os << (R)f;
    }
};
namespace std {
    template <
        typename T,
        T (*mult)(const T, const T),
        T (*one)(),
        T (*multinv)(const T),
        T (*plus)(const T, const T),
        T (*zero)(),
        T (*plusinv)(const T),
        typename R,
        T (*rtot)(const R),
        R (*ttor)(const T)
    >
    struct hash<Field<T, mult, one, multinv, plus, zero, plusinv, R, rtot, ttor>> {
        size_t operator()(const Field<T, mult, one, multinv, plus, zero, plusinv, R, rtot, ttor>& f) const {
            return hash<T>()((R)f.val);
        }
    };
}
