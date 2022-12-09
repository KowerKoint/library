#pragma once
#include "segment.hpp"

template<typename T=double>
struct Polygon {
    vector<Point<T, 2>> points;
    Polygon(int n) {
        assert(n >= 1);
        points.resize(n);
    }
    Polygon(vector<Point<T, 2>> points) : points(points) {}
    friend istream& operator>>(istream& is, Polygon& polygon) {
        return is >> polygon.points;
    }
    friend ostream& operator<<(ostream& os, Polygon& polygon) {
        return os << polygon.points;
    }
    Point<T, 2>& operator[](int i) {
        return points[i];
    }
    const Point<T, 2>& operator[](int i) const {
        return points[i];
    }
    int size() const {
        return points.size();
    }
    using iterator = typename vector<Point<T, 2>>::iterator;
    using const_iterator = typename vector<Point<T, 2>>::const_iterator;
    iterator begin() { return points.begin(); }
    iterator end() { return points.end(); }
    const_iterator begin() const { return points.begin(); }
    const_iterator end() const { return points.end(); }
    T area2() {
        T res = 0;
        int n = points.size();
        for(int i = 1; i + 1 < n; i++) {
            res += outer_product(points[i] - points[0], points[i+1] - points[0]);
        }
        return res;
    }
    T area() {
        T a = area2();
        if constexpr(is_integral_v<T>) assert(a % 2 == 0);
        return a / 2;
    }
    bool is_convex() {
        int n = points.size();
        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            if(outer_product(points[k] - points[j], points[i] - points[j]) < 0) return false;
        }
        return true;
    }
    // inside: 2, on: 1, outside: 0
    int contains(Point<T, 2> p) {
        int n = points.size();
        double t_sum = 0;
        for(int i = 0; i < n; i++) {
            if(Segment<T>(points[i], points[(i+1)%n]).on_segment(p)) return 1;
            double t = theta(points[(i+1)%n] - p) - theta(points[i] - p);
            if(t < -M_PI) t += 2 * M_PI;
            if(t > M_PI) t -= 2 * M_PI;
            t_sum += t;
        }
        if(abs(t_sum) < M_PI) return 0;
        return 2;
    }
};

template <typename T>
vector<Point<T, 2>> select_convex(const vector<Point<T, 2>>& v) {
    vector<Point<T, 2>> res;
    for(auto& p : v) {
        while(res.size() >= 2 && outer_product(res.back() - res[res.size()-2], p - res.back()) < 0) {
            res.pop_back();
        }
        res.push_back(p);
    }
    return res;
}

template <typename T>
Polygon<T> convex_hull(const vector<Point<T, 2>>& v) {
    vector<Point<T, 2>> sorted = v;
    vector<Point<T, 2>> res;
    sort(sorted.begin(), sorted.end());
    vector<Point<T, 2>> lower_hull = select_convex(sorted);
    vector<Point<T, 2>> upper_hull = select_convex(vector<Point<T, 2>>(sorted.rbegin(), sorted.rend()));
    res.reserve(lower_hull.size() + upper_hull.size() - 2);
    for(auto& p : lower_hull) res.push_back(p);
    for(int i = 1; i + 1 < (int)upper_hull.size(); i++) res.push_back(upper_hull[i]);
    return Polygon<T>(res);
}
