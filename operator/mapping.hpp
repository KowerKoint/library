#pragma once
#include "monoid.hpp"

template <typename T>
struct AddMapping {
    T operator()(const T& a, const T& b) const {
        return a + b;
    }
};
template <typename T>
struct AddMappingWithSize {
    T operator()(const T& a, const T& b, int size) const {
        return b + a * size;
    }
};
template <typename T>
struct AffineMapping {
    T operator()(const pair<T, T> &a, const T &b) const {
        return a.first * b + a.second;
    }
};
template <typename T>
struct AffineMappingWithSize {
    T operator()(const pair<T, T> &a, const T &b, size_t size) const {
        return a.first * b + a.second * size;
    }
};
template <typename T>
struct MinMapping {
    T operator()(const T& a, const T& b) const {
        return min(a, b);
    }
};
template <typename T>
struct MaxMapping {
    T operator()(const T& a, const T& b) const {
        return max(a, b);
    }
};
template <typename T>
struct GcdMapping {
    T operator()(const T& a, const T& b) const {
        return gcd(a, b);
    }
};
template <typename T>
struct LcmMapping {
    T operator()(const T& a, const T& b) const {
        return lcm(a, b);
    }
};
template <typename T>
struct AndMapping {
    T operator()(const T& a, const T& b) const {
        return a & b;
    }
};
template <typename T>
struct OrMapping {
    T operator()(const T& a, const T& b) const {
        return a | b;
    }
};
template <typename T>
struct XorMapping {
    T operator()(const T& a, const T& b) const {
        return a ^ b;
    }
};
