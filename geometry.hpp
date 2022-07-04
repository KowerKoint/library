#include "base.hpp"

template <typename T=double>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    friend istream& operator>>(istream& is, Point& points) {
        is >> points.x >> points.y;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Point& points) {
        os << points.x << ' ' << points.y;
        return os;
    }
    Point& operator+= (const Point& points) {
        x += points.x;
        y += points.y;
        return *this;
    }
    Point operator+(const Point& points) const {
        return Point(*this) += points;
    }
    Point& operator-= (const Point& points) {
        x -= points.x;
        y -= points.y;
        return *this;
    }
    Point operator-(const Point& points) const {
        return Point(*this) -= points;
    }
    Point& operator*=(T k) {
        x *= k;
        y *= k;
        return *this;
    }
    Point operator*(T k) const {
        return Point(*this) *= k;
    }
    bool operator==(const Point& points) const {
        return x == points.x && y == points.y;
    }
    template<typename U>
    operator Point<U>() const {
        return Point<U>(static_cast<U>(x), static_cast<U>(y));
    }
    T inner_product(const Point& points) const {
        return x * points.x + y * points.y;
    }
    T outer_product(const Point& points) const {
        return x * points.y - y * points.x;
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
    double operator/(const Point& points) const {
        T r1 = r(), r2 = points.r();
        double theta1 = theta(), theta2 = points.theta();
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
    Point<T> proj(Point<T> points) {
        T x = (b * (b * points.x - a * points.y) - a * c) / (a * a + b * b);
        T y = (a * (a * points.y - b * points.x) - b * c) / (a * a + b * b);
        return Point<T>(x, y);
    }
    Point<T> reflect(Point<T> points) {
        return points + (proj(points) - points) * 2;
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
    double dist(Point<T> points) {
        return abs(a * points.x + b * points.y + c) / sqrt(a * a + b * b);
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
bool on_segment(Point<T> p0, Point<T> p1, Point<T> q) {
    if((p1 - p0).outer_product(q - p0) != 0) return false;
    if(q.x < min(p0.x, p1.x)) return false;
    if(q.x > max(p0.x, p1.x)) return false;
    if(q.y < min(p0.y, p1.y)) return false;
    if(q.y > max(p0.y, p1.y)) return false;
    return true;
}

template<typename T>
double dist_ss(Point<T> p0, Point<T> p1, Point<T> p2, Point<T> p3) {
    if(intersection(p0, p1, p2, p3)) return 0;
    Line<T> l1(p0, p1), l2(p2, p3);
    double res = min(min((p2-p0).r(), (p3-p0).r()), min((p2-p1).r(), (p3-p1).r()));
    Point<T> pr0 = l2.proj(p0), pr1 = l2.proj(p1), pr2 = l1.proj(p2), pr3 = l1.proj(p3);
    if(on_segment(p2, p3, pr0)) chmin(res, l2.dist(p0));
    if(on_segment(p2, p3, pr1)) chmin(res, l2.dist(p1));
    if(on_segment(p0, p1, pr2)) chmin(res, l1.dist(p2));
    if(on_segment(p0, p1, pr3)) chmin(res, l1.dist(p3));
    return res;
}

template<typename T=double>
struct Polygon {
    vector<Point<T>> points;
    Polygon(int n) {
        points.resize(n);
    }
    Polygon(vector<Point<T>> points) : points(points) {}
    friend istream& operator>>(istream& is, Polygon& polygon) {
        for(int i = 0; i < polygon.points.size(); i++) is >> polygon.points[i];
        return is;
    }
    T area() {
        T res = 0;
        int n = points.size();
        for(int i = 1; i + 1 < points.size(); i++) {
            res += (points[i] - points[0]).outer_product(points[i+1] - points[0]);
        }
        return res / 2;
    }
    bool is_convex() {
        int n = points.size();
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            if((points[k] - points[j]).outer_product(points[i] - points[j]) < 0) return false;
        }
        return true;
    }
    // inside: 2, on: 1, outside: 0
    int contains(Point<T> p) {
        int n = points.size();
        int cnt = 0;
        double theta_sum = 0;
        for(int i = 0; i < n; i++) {
            if(on_segment(points[i], points[(i+1)%n], p)) return 1;
            double theta = (points[(i+1)%n] - p).theta() - (points[i] - p).theta();
            if(theta < -M_PI) theta += 2 * M_PI;
            if(theta > M_PI) theta -= 2 * M_PI;
            theta_sum += theta;
        }
        if(abs(theta_sum) < M_PI) return 0;
        return 2;
    }
};
