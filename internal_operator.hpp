#pragma once
#include "base.hpp"

namespace kowerkoint {
    template <typename T>
    T add(T a, T b) { return a + b; }
    template <typename T>
    T sub(T a, T b) { return a - b; }
    template <typename T>
    T zero() { return T(0); }
    template <typename T>
    T div(T a, T b) { return a / b; }
    template <typename T>
    T mult(T a, T b) { return a * b; }
    template <typename T>
    T one() { return T(1); }
    template <typename T>
    T default_xor(T a, T b) { return a ^ b; }
    template <typename T>
    T default_and(T a, T b) { return a & b; }
    template <typename T>
    T default_or(T a, T b) { return a | b; }
    ll mod3() { return 998244353LL; }
    ll mod7() { return 1000000007LL; }
    ll mod9() { return 1000000009LL; }
    template <typename T>
    T max(T a, T b) { return max(a, b); }
    template <typename T>
    T min(T a, T b) { return min(a, b); }
}

