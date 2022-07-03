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
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
    template<typename U>
    operator Point<U>() const {
        return Point<U>(static_cast<U>(x), static_cast<U>(y));
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
    bool parallel(const Line<T>& l) const {
        return a * l.b == b * l.a;
    }
    bool operator==(const Line<T>& l) const {
        return a * l.c == c * l.a && b * l.c == c * l.b;
    }
    Point<T> cross_point(Line<T> l) {
        T x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
        T y = (a * l.c - c * l.a) / (b * l.a - a * l.b);
        return Point<T>(x, y);
    }
    double dist(Point<T> p) {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }
};

template <typename T>
bool intersection(Point<T> p0, Point<T> p1, Point<T> p2, Point<T> p3) {
    T o012 = (p1 - p0).outer_product(p2 - p0);
    int s012 = (o012 > 0) - (o012 < 0);
    T o013 = (p1 - p0).outer_product(p3 - p0);
    int s013 = (o013 > 0) - (o013 < 0);
    T o230 = (p3 - p2).outer_product(p0 - p2);
    int s230 = (o230 > 0) - (o230 < 0);
    T o231 = (p3 - p2).outer_product(p1 - p2);
    int s231 = (o231 > 0) - (o231 < 0);
    if(Line(p0, p1) == Line(p2, p3)) {
        if((p2-p0).inner_product(p3-p0) <= 0) return true;
        if((p2-p0).inner_product(p2-p1) <= 0) return true;
        if((p2-p0).inner_product(p3-p1) <= 0) return true;
        return false;
    }
    return s012 * s013 <= 0 && s230 * s231 <= 0;
}

template<typename T>
double dist_ss(Point<T> p0, Point<T> p1, Point<T> p2, Point<T> p3) {
    if(intersection(p0, p1, p2, p3)) return 0;
    Line<T> l1(p0, p1), l2(p2, p3);
    double res = min(min((p2-p0).r(), (p3-p0).r()), min((p2-p1).r(), (p3-p1).r()));
    Point<T> pr0 = l2.proj(p0), pr1 = l2.proj(p1), pr2 = l1.proj(p2), pr3 = l1.proj(p3);
    if(min(p2.x, p3.x) <= pr0.x && pr0.x <= max(p2.x, p3.x) && min(p2.y, p3.y) <= pr0.y && pr0.y <= max(p2.y, p3.y)) chmin(res, l2.dist(p0));
    if(min(p2.x, p3.x) <= pr1.x && pr1.x <= max(p2.x, p3.x) && min(p2.y, p3.y) <= pr1.y && pr1.y <= max(p2.y, p3.y)) chmin(res, l2.dist(p1));
    if(min(p0.x, p1.x) <= pr2.x && pr2.x <= max(p0.x, p1.x) && min(p0.y, p1.y) <= pr2.y && pr2.y <= max(p0.y, p1.y)) chmin(res, l1.dist(p2));
    if(min(p0.x, p1.x) <= pr3.x && pr3.x <= max(p0.x, p1.x) && min(p0.y, p1.y) <= pr3.y && pr3.y <= max(p0.y, p1.y)) chmin(res, l1.dist(p3));
    return res;
}
