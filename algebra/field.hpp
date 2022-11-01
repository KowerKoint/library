#pragma once
#include "ring.hpp"

template <
    typename T,
    T (*mult)(const T, const T),
    T (*one)(),
    T (*multinv)(const T),
    T (*plus)(const T, const T),
    T (*zero)(),
    T (*plusinv)(const T)
>
struct Field : Ring<T, mult, one, plus, zero, plusinv> {
    Field& operator/=(const Field& r) {
        this->val = multinv(this->val, r.val);
        return *this;
    }
    Field operator/(const Field& r) const {
        return Field(*this) /= r;
    }
    Field pow(ll n) const {
        if(n < 0) {
            return Field(multinv(this->val)).pow(-n);
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
};
