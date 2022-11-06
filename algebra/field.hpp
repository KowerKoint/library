#pragma once
#include "../base.hpp"

template <typename T>
struct SumGroupBase {
    constexpr static bool defzero = false;
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
struct FinitePropertyBase {
    constexpr static bool is_finite = false;
};

template <typename T, typename SumGroup = SumGroupBase<T>, typename ProdGroup = ProdGroupBase<T>, typename Representation = RepresentationBase<T>, typename FiniteProperty = FinitePropertyBase<T>>
struct Field {
    using R = typename Representation::R;
    T val;
    constexpr static T zero() {
        return SumGroup::zero;
    }
    constexpr static T one() {
        return ProdGroup::one;
    }
    constexpr static bool defzero = SumGroup::defzero;
    constexpr static bool defone = ProdGroup::defone;
    constexpr static bool is_finite = FiniteProperty::is_finite;
    constexpr Field() {
        if constexpr(SumGroup::defzero) val = zero();
        else if constexpr(SumGroup::defone) val = one();
        else val = T();
    }
    constexpr Field(const R& r) : val(Representation::construct(r)) {}
    constexpr R represent() const { return Representation::represent(val); }
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
