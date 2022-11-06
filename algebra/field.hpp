#pragma once
#include "../base.hpp"

template <typename T>
struct SumGroup {
    static_assert(is_arithmetic_v<T>);
    constexpr static T& addassign(T& l, const T& r) {
        return l += r;
    }
    constexpr static bool defzero = true;
    constexpr static T zero = 0;
    constexpr static T minus(const T& x) {
        return -x;
    }
};
template <typename T>
struct ProdGroup {
    static_assert(is_arithmetic_v<T>);
    constexpr static T& mulassign(T& l, const T& r) {
        return l *= r;
    }
    constexpr static bool defone = true;
    constexpr static T one = 1;
    constexpr static T inv(const T& x) {
        static_assert(is_floating_point_v<T>);
        return one / x;
    }
};
template <typename T>
struct Representation {
    using R = decltype(T::val);
    constexpr static T construct(const R& x) { return {x}; }
    constexpr static R represent(const T& x) { return x.val; }
};
template <typename T>
struct FiniteProperty {
    constexpr static bool is_finite = false;
};

template <typename T>
struct Field {
    using R = typename Representation<T>::R;
    T val;
    constexpr static T zero() {
        return SumGroup<T>::zero;
    }
    constexpr static T one() {
        return ProdGroup<T>::one;
    }
    constexpr Field() {
        if constexpr(SumGroup<T>::defzero) val = SumGroup<T>::zero;
        else if constexpr(SumGroup<T>::defone) val = SumGroup<T>::one;
        else val = T();
    }
    constexpr Field(const R& r) : val(Representation<T>::construct(r)) {}
    constexpr Field(const T& r) : val(r) {}
    constexpr R represent() const { return Representation<T>::represent(val); }
    constexpr static Field premitive_root() {
        return {FiniteProperty<T>::premitive_root()};
    }
    constexpr static size_t order() {
        return FiniteProperty<T>::order();
    }
    constexpr Field& operator*=(const Field& other) {
        ProdGroup<T>::mulassign(val, other.val);
        return *this;
    }
    constexpr Field operator*(const Field& other) const {
        return Field(*this) *= other;
    }
    constexpr Field inv() const {
        return ProdGroup<T>::inv(val);
    }
    constexpr Field& operator/=(const Field& other) {
        return *this *= other.inv();
    }
    constexpr Field operator/(const Field& other) const {
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
    constexpr Field operator+() const {
        return *this;
    }
    constexpr Field& operator+=(const Field& other) {
        SumGroup<T>::addassign(val, other.val);
        return *this;
    }
    constexpr Field operator+(const Field& other) const {
        return Field(*this) += other;
    }
    constexpr Field operator-() const {
        return SumGroup<T>::minus(val);
    }
    constexpr Field& operator-=(const Field& other) {
        return *this += -other;
    }
    constexpr Field operator-(const Field& other) const {
        return Field(*this) -= other;
    }
    constexpr Field& operator++() {
        return *this += Field(one());
    }
    Field operator++(int) {
        Field ret = *this;
        ++*this;
        return ret;
    }
    constexpr Field& operator--() {
        return *this -= Field(one());
    }
    Field operator--(int) {
        Field ret = *this;
        --*this;
        return ret;
    }
    constexpr bool operator==(const Field& other) const {
        return represent() == other.represent();
    }
    constexpr bool operator!=(const Field& other) const {
        return !(*this == other);
    }
    constexpr bool operator<(const Field& other) const {
        return represent() < other.represent();
    }
    constexpr bool operator>(const Field& other) const {
        return other < *this;
    }
    constexpr bool operator<=(const Field& other) const {
        return !(other < *this);
    }
    constexpr bool operator>=(const Field& other) const {
        return !(*this < other);
    }
    friend istream& operator>>(istream& is, Field& f) {
        R r; is >> r;
        f = Field(r);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Field& f) {
        return os << f.represent();
    }
};
namespace std {
    template <typename T>
    struct hash<Field<T>> {
        size_t operator()(const Field<T>& f) const {
            return hash<typename Field<T>::R>()(f.represent());
        }
    };
}
template <typename T>
struct FiniteProperty<Field<T>> {
    constexpr static bool is_finite = FiniteProperty<T>::is_finite;
};
