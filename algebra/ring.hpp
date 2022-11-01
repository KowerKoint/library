#pragma once

#include "monoid.hpp"

template<
    typename T,
    T (*mult)(const T, const T),
    T (*one)(),
    T (*plus)(const T, const T),
    T (*zero)(),
    T (*plusinv)(const T)
>
struct Ring : Monoid<T, mult, one> {
    Ring(T val=zero()) : Monoid<T, mult, one>(val) {
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
};
