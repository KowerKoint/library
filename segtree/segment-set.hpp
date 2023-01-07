#pragma once
#include "../base.hpp"

template <typename T, T neighbor=1>
struct SegmentSet {
    map<T, T> segments;
    using It = typename map<T, T>::iterator;
    using CIt = typename map<T, T>::const_iterator;

    It begin() { return segments.begin(); }
    It end() { return segments.end(); }
    CIt begin() const { return segments.begin(); }
    CIt end() const { return segments.end(); }

    CIt get(T x) const {
        CIt it = segments.upper_bound(x);
        if (it == segments.begin()) return segments.end();
        it--;
        if (it->first <= x && x <= it->second) return it;
        return segments.end();
    }

    bool contains(T x) const {
        return get(x) != segments.end();
    }

    CIt insert(T l, T r) {
        It it = segments.upper_bound(l);
        if(it != segments.begin() && prev(it)->second + neighbor >= l) {
            it = prev(it);
            l = it->first;
        }
        while(it != segments.end() && it->first <= r + neighbor) {
            r = max(r, it->second);
            it = segments.erase(it);
        }
        return segments.emplace(l, r).first;
    }

    // not verified
    void erase(T l, T r) {
        It it = segments.upper_bound(l);
        if(it != segments.begin() && prev(it)->second + neighbor > l) {
            it = prev(it);
        }
        while(it != segments.end() && it->first < r + neighbor) {
            T nl = it->first, nr = it->second;
            if(nl + neighbor < l) {
                segments.emplace(nl, l - neighbor);
            }
            if(r + neighbor < nr) {
                segments.emplace(r + neighbor, nr);
            }
            it = segments.erase(it);
        }
    }
};

