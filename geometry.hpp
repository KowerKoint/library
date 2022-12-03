#include "base.hpp"


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
    vector<Point<T>> Points;
    Polygon(int n) {
        assert(n >= 1);
        Points.resize(n);
    }
    Polygon(vector<Point<T>> Points) : Points(Points) {}
    friend istream& operator>>(istream& is, Polygon& polygon) {
        for(int i = 0; i < polygon.Points.size(); i++) is >> polygon.Points[i];
        return is;
    }
    T area() {
        T res = 0;
        int n = Points.size();
        for(int i = 1; i + 1 < Points.size(); i++) {
            res += (Points[i] - Points[0]).outer_product(Points[i+1] - Points[0]);
        }
        return res / 2;
    }
    bool is_convex() {
        int n = Points.size();
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            if((Points[k] - Points[j]).outer_product(Points[i] - Points[j]) < 0) return false;
        }
        return true;
    }
    // inside: 2, on: 1, outside: 0
    int contains(Point<T> p) {
        int n = Points.size();
        int cnt = 0;
        double theta_sum = 0;
        for(int i = 0; i < n; i++) {
            if(on_segment(Points[i], Points[(i+1)%n], p)) return 1;
            double theta = (Points[(i+1)%n] - p).theta() - (Points[i] - p).theta();
            if(theta < -M_PI) theta += 2 * M_PI;
            if(theta > M_PI) theta -= 2 * M_PI;
            theta_sum += theta;
        }
        if(abs(theta_sum) < M_PI) return 0;
        return 2;
    }
};
