#pragma once
#include "point.hpp"
#include "../algebra/ratio.hpp"

template <typename T, size_t dim=2>
struct Line {
    Point<T, dim> a;
    Ratio<T, dim> d;
    Line() = default;
    Line(const Point<T, dim>& a, const Point<T, dim>& b) : a(a), d((b - a).represent()) {}
    Line(const Point<T, dim>& a, const Ratio<T, dim>& d) : a(a), d(d) {}
    Point<T, dim> operator()(const T& k) const {
        Point<T, dim> dp(d.represent());
        return a + dp * k;
    }
    Point<T, dim> proj(const Point<T, dim>& p) const {
        Point<T, dim> dp(d.represent());
        T kn = dp.dot(p - a);
        T kd = dp.norm();
        if constexpr(is_integral_v<T>) {
            assert(kn % kd == 0);
        }
        return a + dp * (kn / kd);
    }
    Point<T, dim> reflect(const Point<T, dim>& p) const {
        return proj(p) * 2 - p;
    }
    bool parallel(const Line& l) const {
        return d == l.d;
    }
    bool orthogonal(const Line& l) const {
        Point<T, dim> dp(d.represent());
        Point<T, dim> ldp(l.d.represent());
        return dp.dot(ldp) == 0;
    }
    bool on_line(const Point<T, dim>& p) const {
        Point<T, dim> dp(d.represent());
        T inpro = dp.dot(p - a);
        return inpro * inpro == d.norm() * (p - a).norm();
    }
    bool operator==(const Line& l) const {
        return parallel(l) && on_line(l.a);
    }
    double dist(const Point<T, dim>& p) const {
        return abs(p - proj(p));
    }
};

template <typename T>
struct Line2D {
    T a, b, c; // ax + by + c = 0
    Line2D(Point<T,2> p1, Point<T,2> p2) {
        a = p2[1] - p1[1];
        b = -(p2[0] - p1[0]);
        c = -a * p1[0] - b * p1[1];
    }
    Line2D(T a, T b, T c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    Line2D(const Line<T, 2>& l) {
        a = l.d[1];
        b = -l.d[0];
        c = -a * l.a[0] - b * l.a[1];
    }
    Ratio<T,2> direction() {
        return {b, -a};
    }
    Point<T,2> proj(Point<T,2> Points) {
        T d = a * a + b * b;
        T x_n = b * (b * Points[0] - a * Points[1]) - a * c;
        T y_n = a * (a * Points[1] - b * Points[0]) - b * c;
        if constexpr(is_integral_v<T>) {
            assert(x_n % d == 0);
            assert(y_n % d == 0);
        }
        return {x_n / d, y_n / d};
    }
    Point<T,2> reflect(Point<T,2> Points) {
        return Points + (proj(Points) - Points) * 2;
    }
    bool parallel(const Line2D<T>& l) const {
        return a * l.b == b * l.a;
    }
    bool orthogonal(const Line2D<T>& l) const {
        return a * l.a + b * l.b == 0;
    }
    bool on_line(Point<T,2> Points) {
        return a * Points[0] + b * Points[1] + c == 0;
    }
    bool operator==(const Line2D<T>& l) const {
        return a * l.c == c * l.a && b * l.c == c * l.b;
    }
    Point<T,2> cross_point(Line2D<T> l) {
        T x_n = b * l.c - c * l.b;
        T x_d = a * l.b - b * l.a;
        T y_n = a * l.c - c * l.a;
        T y_d = b * l.a - a * l.b;
        if constexpr(is_integral_v<T>) {
            assert(x_n % x_d == 0);
            assert(y_n % y_d == 0);
        }
        return Point<T, 2>({x_n / x_d, y_n / y_d});
    }
    double dist(Point<T,2> Points) {
        return sqrt(dist2(Points));
    }
};
