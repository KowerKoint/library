#pragma once
#include "../base.hpp"

template <typename T>
struct SumMonoid {
    static T id() { return 0; }
    static T op(const T& a, const T& b) { return a + b; }
};
template <typename T>
struct MinMonoid {
    static T id() { return numeric_limits<T>::max(); }
    static T op(const T& a, const T& b) { return min(a, b); }
};
template <typename T>
struct MaxMonoid {
    static T id() { return numeric_limits<T>::min(); }
    static T op(const T& a, const T& b) { return max(a, b); }
};
template <typename T>
struct GcdMonoid {
    static T id() { return 0; }
    static T op(const T& a, const T& b) { return gcd(a, b); }
};
template <typename T>
struct LcmMonoid {
    static T id() { return 1; }
    static T op(const T& a, const T& b) { return lcm(a, b); }
};
template <typename T>
struct AndMonoid {
    static T id() { return numeric_limits<T>::max(); }
    static T op(const T& a, const T& b) { return a & b; }
};
template <typename T>
struct OrMonoid {
    static T id() { return 0; }
    static T op(const T& a, const T& b) { return a | b; }
};
template <typename T>
struct XorMonoid {
    static T id() { return 0; }
    static T op(const T& a, const T& b) { return a ^ b; }
};
template <typename T>
struct AffineMonoid {
    static pair<T, T> id() { return {1, 0}; }
    static pair<T, T> op(const pair<T, T>& a, const pair<T, T>& b) {
        return {a.first * b.first, a.first * b.second + a.second};
    }
};
