#pragma once

template <typename T>
T ordinal_identity(T x) {
    return x;
}
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
T ordinal_and(const T a, const T b) {
    return a & b;
}
template <typename T>
T ordinal_or(const T a, const T b) {
    return a | b;
}
