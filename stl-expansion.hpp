#pragma once
#include <bits/stdc++.h>

template <typename T1, typename T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T, size_t N>
std::istream& operator>>(std::istream& is, std::array<T, N>& a) {
    for (size_t i = 0; i < N; ++i) {
        is >> a[i];
    }
    return is;
}
template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto& e : v) is >> e;
    return is;
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << p.first << " " << p.second;
    return os;
}
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& a) {
    for (size_t i = 0; i < N; ++i) {
        os << a[i] << (i + 1 == a.size() ? "" : " ");
    }
    return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    return os;
}
