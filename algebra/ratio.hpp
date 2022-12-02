#pragma once
#include "field.hpp"

template <typename T, size_t dim>
struct RepresentationRatio : RepresentationBase<T> {
    using R = array<T, dim>;
    constexpr static array<T, dim> construct(const R& x) {
        return x;
    }
    constexpr static R represent(const array<T, dim>& x) {
        array<T, dim> ret = x;
        if constexpr(is_integral_v<T>) {
            T g = 0;
            for(size_t i = 0; i < dim; i++) {
                g = gcd(g, ret[i]);
            }
            for(size_t i = 0; i < dim; i++) {
                ret[i] /= g;
            }
            for(size_t i = 0; i < dim; i++) {
                if(ret[i] == 0) continue;
                if(ret[i] < 0) {
                    for(size_t j = i; j < dim; j++) {
                        ret[j] = -ret[j];
                    }
                }
                break;
            }
        }
        return ret;
    }
};
template <typename T, size_t dim>
struct CompareRatio : CompareBase<T> {
    constexpr static bool lt(const array<T, dim>& x, const array<T, dim>& y) {
        static_assert(dim == 2);
        return x[0] * y[1] < x[1] * y[0];
    }
    constexpr static bool eq(const array<T, dim>& x, const array<T, dim>& y) {
        return RepresentationRatio<T, dim>::represent(x) == RepresentationRatio<T, dim>::represent(y);
    }
};
template <typename T, size_t dim>
using Ratio = Field<array<T, dim>, SumGroupBase<array<T, dim>>, ProdGroupBase<array<T, dim>>, RepresentationRatio<T, dim>, CompareRatio<T, dim>>;
