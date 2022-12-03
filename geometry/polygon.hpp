#pragma once
#include "line.hpp"

template<typename T=double>
struct Polygon {
    vector<Point<T, 2>> Points;
    Polygon(int n) {
        assert(n >= 1);
        Points.resize(n);
    }
    Polygon(vector<Point<T, 2>> Points) : Points(Points) {}
    friend istream& operator>>(istream& is, Polygon& polygon) {
        return is >> polygon.Points;
    }
    friend ostream& operator<<(ostream& os, Polygon& polygon) {
        return os << polygon.Points;
    }
    Point<T, 2>& operator[](int i) {
        return Points[i];
    }
    const Point<T, 2>& operator[](int i) const {
        return Points[i];
    }
    int size() const {
        return Points.size();
    }
    T area2() {
        T res = 0;
        int n = Points.size();
        for(int i = 1; i + 1 < Points.size(); i++) {
            res += (Points[i] - Points[0]).outer_product(Points[i+1] - Points[0]);
        }
        return res;
    }
    T area() {
        T a = area2();
        assert(!is_integral_v<T> || a % 2 == 0);
        return a / 2;
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
    int contains(Point<T, 2> p) {
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

template <typename T>
vector<Point<T, 2>> select_convex(const vector<Point<T, 2>>& v) {
    vector<Point<T, 2>> res;
    for(auto& p : v) {
        while(res.size() >= 2 && (res.back() - res[res.size()-2]).outer_product(p - res.back()) <= 0) {
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
    for(int i = 1; i + 1 < upper_hull.size(); i++) res.push_back(upper_hull[i]);
    return Polygon<T>(res);
}
