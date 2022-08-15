#pragma once
#include "base.hpp"

template <typename T>
T add_op(T a, T b) { return a + b; }
template <typename T>
T sub_op(T a, T b) { return a - b; }
template <typename T>
T zero_e() { return T(0); }
template <typename T>
T div_op(T a, T b) { return a / b; }
template <typename T>
T mult_op(T a, T b) { return a * b; }
template <typename T>
T one_e() { return T(1); }
template <typename T>
T xor_op(T a, T b) { return a ^ b; }
template <typename T>
T and_op(T a, T b) { return a & b; }
template <typename T>
T or_op(T a, T b) { return a | b; }
ll mod3() { return 998244353LL; }
ll mod7() { return 1000000007LL; }
ll mod9() { return 1000000009LL; }
template <typename T>
T max_op(T a, T b) { return max(a, b); }
template <typename T>
T min_op(T a, T b) { return min(a, b); }

template <typename T>
T max_e() { return numeric_limits<T>::max(); }
template <typename T>
T min_e() { return numeric_limits<T>::min(); }
