#pragma once
#include "../base.hpp"

template <typename T, T neighbor=1>
struct SegmentSet {
    map<T, T> segments;
    using It = typename map<T, T>::iterator;

    It get(T x) const {
        auto it = segments.upper_bound(x);
        if (it == segments.begin()) return segments.end();
        return prev(it);
    }

    bool contains(T x) const {
        return get(x) != segments.end();
    }

    It insert(T l, T r) {
        auto it = segments.upper_bound(l);
        if(it != segments.begin() && prev(it)->second + neighbor >= l) {
            it = prev(it);
            l = it->first;
        }
        while(it != segments.end() && it->first <= r + neighbor) {
            r = max(r, it->second);
            it = segments.erase(it);
        }
        return segments.emplace_hint(it, l, r);
    }

    // not verified
    void erase(T l, T r) {
        auto it = segments.upper_bound(l);
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
