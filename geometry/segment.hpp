#pragma once
#include "line.hpp"

template <typename T>
struct Segment {
    Point<T, 2> a, b;
    Segment() = default;
    Segment(const Point<T, 2>& a, const Point<T, 2>& b) : a(a), b(b) {}
    bool operator==(const Segment& rhs) const { return a == rhs.a && b == rhs.b; }
    bool operator!=(const Segment& rhs) const { return !(*this == rhs); }
    bool intersect(const Segment<T>& other) const {
        if(Line<T, 2>(a, b) == Line<T, 2>(other.a, other.b)) {
            if((other.a-a).dot(other.b-a) <= 0) return true;
            if((other.a-a).dot(other.a-b) <= 0) return true;
            if((other.a-a).dot(other.b-b) <= 0) return true;
            return false;
        }
        T o012 = outer_product(b - a, other.a - a);
        int s012 = (o012 > zero<T>()) - (o012 < zero<T>());
        T o013 = outer_product(b - a, other.b - a);
        int s013 = (o013 > zero<T>()) - (o013 < zero<T>());
        T o230 = outer_product(other.b - other.a, a - other.a);
        int s230 = (o230 > zero<T>()) - (o230 < zero<T>());
        T o231 = outer_product(other.b - other.a, b - other.a);
        int s231 = (o231 > zero<T>()) - (o231 < zero<T>());
        return s012 * s013 <= 0 && s230 * s231 <= 0;
    }
    bool on_segment(const Point<T, 2>& p) const {
        if(outer_product(b - a, p - a) != zero<T>()) return false;
        if(p[0] < min(a[0], b[0]) || p[0] > max(a[0], b[0])) return false;
        if(p[1] < min(a[1], b[1]) || p[1] > max(a[1], b[1])) return false;
        return true;
    }
    double dist(const Point<T, 2>& p) const {
        if((b - a).dot(p - a) < zero<T>()) return abs(p - a);
        if((a - b).dot(p - b) < zero<T>()) return abs(p - b);
        return abs(outer_product(b - a, p - a)) / abs(b - a);
    }
    double dist(const Segment<T>& other) const {
        if(intersect(other)) return 0;
        return min({dist(other.a), dist(other.b), other.dist(a), other.dist(b)});
    }
    int outer_product_sign(const Point<T, 2>& p) const {
        T o = outer_product(b - a, p - a);
        return (o > zero<T>()) - (o < zero<T>());
    }
};
