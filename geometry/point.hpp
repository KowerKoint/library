#include "../algebra/field.hpp"

template <typename T, size_t dim>
struct SumGroupPoint : SumGroupBase<array<T, dim>> {
    static array<T, dim> addassign(array<T, dim> &a, const array<T, dim> &b) {
        for (size_t i = 0; i < dim; i++) {
            a[i] += b[i];
        }
        return a;
    }
    constexpr static bool defzero = true;
    const static array<T, dim> zero;
    static array<T, dim> minus(const array<T, dim> &a) {
        array<T, dim> res;
        for (size_t i = 0; i < dim; i++) {
            res[i] = -a[i];
        }
        return res;
    }
    using Coef = T;
    using Scalar = T;
    static array<T, dim> coefassign(array<T, dim> &a, const T &b) {
        for (size_t i = 0; i < dim; i++) {
            a[i] *= b;
        }
        return a;
    }
    static T dot(const array<T, dim> &a, const array<T, dim> &b) {
        T res = ::zero<T>();
        for (size_t i = 0; i < dim; i++) {
            res += a[i] * b[i];
        }
        return res;
    }
};
template <typename T, size_t dim>
const array<T, dim> SumGroupPoint<T, dim>::zero = [] {
    array<T, dim> res;
    for (size_t i = 0; i < dim; i++) {
        res[i] = ::zero<T>();
    }
    return res;
}();
template <typename T, size_t dim=2>
using Point = Field<array<T, dim>, SumGroupPoint<T, dim>>;

template <typename T, size_t dim>
double abs(const Point<T, dim> &a) {
    return sqrt(a.norm());
}
template <typename T>
double theta(const Point<T, 2> &a) {
    return atan2(a[1], a[0]);
}
template <typename T>
struct CompareTheta {
    bool operator()(const Point<T, 2> &a, const Point<T, 2> &b) const {
        if (a[1] >= 0 && b[1] < 0) return true;
        if (a[1] < 0 && b[1] >= 0) return false;
        if (a[1] == 0 && b[1] == 0) {
            if (a[0] >= 0 && b[0] < 0) return true;
            return false;
        }
        return a[0] * b[1] - a[1] * b[0] > 0;
    }
};
template <typename T>
T outer_product(const Point<T, 2> &a, const Point<T, 2> &b) {
    return a[0] * b[1] - a[1] * b[0];
}
template <typename T>
Point<T, 3> outer_product(const Point<T, 3> &a, const Point<T, 3> &b) {
    return Point<T, 3>({a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]});
}
