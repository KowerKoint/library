#pragma once
#include "../base.hpp"

template <typename T>
struct SumGroupBase {
    constexpr static bool defzero = false;
    using Coef = nullptr_t;
    using Scalar = nullptr_t;
};
template <typename T>
struct ProdGroupBase {
    constexpr static bool defone = false;
};
template <typename T>
struct RepresentationBase {
    using R = T;
    constexpr static T construct(const R& x) { return x; }
    constexpr static R represent(const T& x) { return x; }
};
template <typename T>
struct CompareBase {
    constexpr static bool eq(const T& x, const T& y) { return x == y; }
    constexpr static bool lt(const T& x, const T& y) { return x < y; }
};
template <typename T>
struct FinitePropertyBase {
    constexpr static bool is_finite = false;
};

template <typename T, typename SumGroup = SumGroupBase<T>, typename ProdGroup = ProdGroupBase<T>, typename Representation = RepresentationBase<T>, typename Compare = CompareBase<T>, typename FiniteProperty = FinitePropertyBase<T>>
struct Field {
    using R = typename Representation::R;
    using Coef = typename SumGroup::Coef;
    using Scalar = typename SumGroup::Scalar;
    T val;
    constexpr static Field zero() {
        return SumGroup::zero;
    }
    constexpr static Field one() {
        return ProdGroup::one;
    }
    constexpr static bool defzero = SumGroup::defzero;
    constexpr static bool defone = ProdGroup::defone;
    constexpr static bool is_finite = FiniteProperty::is_finite;
    constexpr Field() {
        if constexpr(SumGroup::defzero) val = SumGroup::zero;
        else if constexpr(SumGroup::defone) val = ProdGroup::one;
        else val = T();
    }
    constexpr Field(const R& r) : val(Representation::construct(r)) {}
    constexpr R represent() const { return Representation::represent(val); }
    constexpr decltype(auto) operator[](size_t i) const {
        return val[i];
    }
    constexpr static Field premitive_root() {
        return FiniteProperty::premitive_root();
    }
    constexpr static size_t order() {
        return FiniteProperty::order();
    }
    constexpr Field& operator*=(const Field& other) {
        ProdGroup::mulassign(val, other.val);
        return *this;
    }
    constexpr Field operator*(const Field& other) const {
        return Field(*this) *= other;
    }
    constexpr Field inv() const {
        return ProdGroup::inv(val);
    }
    constexpr Field& operator/=(const Field& other) {
        return *this *= other.inv();
    }
    constexpr Field operator/(const Field& other) const {
        return Field(*this) /= other;
    }
    constexpr Field pow(ll n) const {
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
        SumGroup::addassign(val, other.val);
        return *this;
    }
    constexpr Field operator+(const Field& other) const {
        return Field(*this) += other;
    }
    constexpr Field operator-() const {
        return SumGroup::minus(val);
    }
    constexpr Field& operator-=(const Field& other) {
        return *this += -other;
    }
    constexpr Field operator-(const Field& other) const {
        return Field(*this) -= other;
    }
    constexpr Field& operator++() {
        return *this += one();
    }
    Field operator++(int) {
        Field ret = *this;
        ++*this;
        return ret;
    }
    constexpr Field& operator--() {
        return *this -= one();
    }
    Field operator--(int) {
        Field ret = *this;
        --*this;
        return ret;
    }
    constexpr Field& operator*=(const Coef& other) {
        SumGroup::coefassign(val, other);
        return *this;
    }
    constexpr Field operator*(const Coef& other) const {
        return Field(*this) *= other;
    }
    constexpr Scalar dot(const Field& other) const {
        return SumGroup::dot(val, other.val);
    }
    constexpr Scalar norm() const {
        return dot(*this);
    }
    constexpr bool operator==(const Field& other) const {
        return Compare::eq(val, other.val);
    }
    constexpr bool operator!=(const Field& other) const {
        return !(*this == other);
    }
    constexpr bool operator<(const Field& other) const {
        return Compare::lt(represent(), other.represent());
    }
    constexpr bool operator>(const Field& other) const {
        return other < *this;
    }
    constexpr bool operator<=(const Field& other) const {
        return !(*this > other);
    }
    constexpr bool operator>=(const Field& other) const {
        return !(*this < other);
    }
    friend istream& operator>>(istream& is, Field& f) {
        R r; is >> r;
        f = r;
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
template <typename>
struct is_field : false_type {};
template <typename T, typename SumGroup, typename ProdGroup, typename Representation, typename FiniteProperty>
struct is_field<Field<T, SumGroup, ProdGroup, Representation, FiniteProperty>> : true_type {};
template <typename T>
constexpr bool is_field_v = is_field<T>::value;
template <typename T>
constexpr T zero() {
    if constexpr(is_field_v<T>) return T::zero();
    else return 0;
}
template <typename T>
constexpr T one() {
    if constexpr(is_field_v<T>) return T::one();
    else return 1;
}
template <typename T>
constexpr bool is_finite() {
    if constexpr(is_field_v<T>) return T::is_finite;
    else return false;
}
