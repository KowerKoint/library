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
template <typename T>
pair<bool, Point<T, 2>> segment_intersect(const Point<T, 2> &p0, const Point<T, 2> &p1, const Point<T, 2> &p2, const Point<T, 2> &p3) {
    T o012 = outer_product(p1 - p0, p2 - p0);
    int s012 = (o012 > 0) - (o012 < 0);
    T o013 = outer_product(p1 - p0, p3 - p0);
    int s013 = (o013 > 0) - (o013 < 0);
    T o230 = outer_product(p3 - p2, p0 - p2);
    int s230 = (o230 > 0) - (o230 < 0);
    T o231 = outer_product(p3 - p2, p1 - p2);
    int s231 = (o231 > 0) - (o231 < 0);
    if(s012 == 0 && s013 == 0) {
        if((p2-p0).dot(p3-p0) <= 0) return {true, p0};
        if((p2-p1).dot(p3-p1) <= 0) return {true, p1};
        if((p0-p2).dot(p1-p2) <= 0) return {true, p2};
        if((p0-p3).dot(p1-p3) <= 0) return {true, p3};
        return {false, Point<double>()};
    }
    if(s012 * s013 <= 0 && s230 * s231 <= 0) {
        T kn = o230;
        T kd = outer_product(p1-p0, p3-p2);
        Point<T> p01 = p1 - p0;
        if constexpr(is_integral<T>::value) {
            T g = gcd(kn, kd);
            kn /= g;
            kd /= g;
            assert(gcd(p01[0], p01[1]) % kd == 0);
            p01[0] /= kd;
            p01[1] /= kd;
            return {true, p0 + p01 * kn};
        } else {
            return {true, p0 + p01 * kn * (one<T>()/ kd)};
        }
    }
    return {false, Point<double>()};
}

template <typename T>
double closest_point_pair(const vector<Point<T, 2>>& _ps) {
    vector<Point<T, 2>> ps = _ps;
    sort(ps.begin(), ps.end(), [](const Point<T, 2> &a, const Point<T, 2> &b) {
        return a[0] < b[0];
    });
    int n = ps.size();
    stack<tuple<int, int, int>> stk;
    stk.emplace(~0, n, 0);
    stk.emplace(0, n, 0);
    vector<double> retval;
    VI par;
    par.push_back(-1);
    while(!stk.empty()) {
        auto [l, r, d] = stk.top(); stk.pop();
        if(l >= 0) {
            if(l + 1 >= r) continue;
            if((int)retval.size() <= d) retval.resize(d+1, 1e100);
            int m = (l + r) / 2;
            stk.emplace(~l, m, par.size());
            stk.emplace(l, m, par.size());
            par.push_back(d);
            stk.emplace(~m, r, par.size());
            stk.emplace(m, r, par.size());
            par.push_back(d);
        } else {
            l = ~l;
            if(l + 1 >= r) continue;
            int m = (l + r) / 2;
            vector<Point<T, 2>> ps2;
            for(int i = l; i < r; i++) {
                if(abs(ps[i][0] - ps[m][0]) + 1e-12 < retval[d]) {
                    ps2.push_back(ps[i]);
                }
            }
            sort(ps2.begin(), ps2.end(), [](const Point<T, 2> &a, const Point<T, 2> &b) {
                return a[1] < b[1];
            });
            REP(i, ps2.size()) {
                for(int j = i+1; j < (int)ps2.size() && ps2[j][1] - ps2[i][1] + 1e-12 < retval[d]; j++) {
                    chmin(retval[d], abs(ps2[i] - ps2[j]));
                }
            }
            if(d > 0) {
                chmin(retval[par[d]], retval[d]);
            }
        }
    }
    return retval[0];
}
