#include "base.hpp"

template <typename T=double>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << p.x << ' ' << p.y;
        return os;
    }
    Point& operator+= (const Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point operator+(const Point& p) const {
        return Point(*this) += p;
    }
    Point& operator-= (const Point& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point operator-(const Point& p) const {
        return Point(*this) -= p;
    }
    Point& operator*=(T k) {
        x *= k;
        y *= k;
        return *this;
    }
    Point operator*(T k) const {
        return Point(*this) *= k;
    }
    T inner_product(const Point& p) const {
        return x * p.x + y * p.y;
    }
    T outer_product(const Point& p) const {
        return x * p.y - y * p.x;
    }
    T r2() const {
        return x * x + y * y;
    }
    double r() const {
        return sqrt(x * x + y * y);
    }
    double theta() const {
        return atan2(y, x);
    }
    double operator/(const Point& p) const {
        T r1 = r(), r2 = p.r();
        double theta1 = theta(), theta2 = p.theta();
        return r1 / r2 * cos(theta1 - theta2);
    }
};

template <typename T=double>
struct Line {
    T a, b, c; // ax + by + c = 0
    Line(Point<T> p1, Point<T> p2) {
        a = p2.y - p1.y;
        b = -(p2.x - p1.x);
        c = -a * p1.x - b * p1.y;
    }
    Line(T a, T b, T c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    Point<T> direction() {
        return Point<T>(b, -a);
    }
    Point<T> proj(Point<T> p) {
        T x = (b * (b * p.x - a * p.y) - a * c) / (a * a + b * b);
        T y = (a * (a * p.y - b * p.x) - b * c) / (a * a + b * b);
        return Point<T>(x, y);
    }
    Point<T> reflect(Point<T> p) {
        return p + (proj(p) - p) * 2;
    }
};
