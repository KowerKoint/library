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
private:
    T _val;
public:
    Field() : _val(zero()) {}
    Field(const R& r) : _val(rtot(r)) {}
    Field(const T& t) : _val(t) {}
    R val() const { return ttor(_val); }
    Field& operator*=(const Field& other) {
        _val = mult(_val, other._val);
        return *this;
    }
    Field operator*(const Field& other) const {
        return Field(*this) *= other;
    }
    Field inv() const {
        return Field(multinv(_val));
    }
    Field& operator/=(const Field& other) {
        return *this *= other.inv();
    }
    Field operator/(const Field& other) const {
        return Field(*this) /= other;
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
    Field operator+() const {
        return *this;
    }
    Field& operator+=(const Field& other) {
        _val = plus(_val, other._val);
        return *this;
    }
    Field operator+(const Field& other) const {
        return Field(*this) += other;
    }
    Field operator-() const {
        return Field(plusinv(_val));
    }
    Field& operator-=(const Field& other) {
        return *this += -other;
    }
    Field operator-(const Field& other) const {
        return Field(*this) -= other;
    }
    Field& operator++() {
        return *this += Field(one());
    }
    Field operator++(int) {
        Field ret = *this;
        ++*this;
        return ret;
    }
    Field& operator--() {
        return *this -= Field(one());
    }
    Field operator--(int) {
        Field ret = *this;
        --*this;
        return ret;
    }
    bool operator==(const Field& other) const {
        return val() == other.val();
    }
    bool operator!=(const Field& other) const {
        return !(*this == other);
    }
    bool operator<(const Field& other) const {
        return val() < other.val();
    }
    bool operator>(const Field& other) const {
        return other < *this;
    }
    bool operator<=(const Field& other) const {
        return !(other < *this);
    }
    bool operator>=(const Field& other) const {
        return !(*this < other);
    }
    friend istream& operator>>(istream& is, Field& f) {
        R r; is >> r;
        f = Field(r);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Field& f) {
        return os << f.val();
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
            return hash<R>()(f.val());
        }
    };
}
