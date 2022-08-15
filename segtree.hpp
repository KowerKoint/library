#include "internal_operator.hpp"

template <typename T, T (*func)(const T, const T), T (*e)()>
struct SegTree {
    int n, sz;
    vector<T> state;

    SegTree(int n_): n(n_) {
        sz = 1;
        while(sz < n) sz <<= 1;
        state = vector<T>(sz*2, e());
    }
    SegTree(vector<T> v): n(v.size()) {
        sz = 1;
        while(sz < n) sz <<= 1;
        state = vector<T>(sz*2, e());
        REP(i, v.size()) state[sz+i] = v[i];
        for(int i = sz-1; i > 0; i--) state[i] = func(state[i*2], state[i*2+1]);
    }

    T operator[](int i) const {
        assert(0 <= i && i < n);
        return state[sz+i];
    }
    T get(int i) const {
        assert(0 <= i && i < n);
        return state[sz+i];
    }

    void set(int i, const T &x) {
        assert(0 <= i && i < n);
        i += sz;
        state[i] = x;
        while(i >>= 1) {
            state[i] = func(state[i*2], state[i*2+1]);
        }
    }
    void apply(int i, const T &x) {
        set(i, x);
    }

    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        T left_prod = e(), right_prod = e();
        l += sz, r += sz;
        while(l < r) {
            if(l & 1) left_prod = func(left_prod, state[l++]);
            if(r & 1) right_prod = func(state[--r], right_prod);
            l >>= 1;
            r >>= 1;
        }
        return func(left_prod, right_prod);
    }
    
    T all_prod() const {
        return state[1];
    }

    template <typename F>
    int max_right(int l, F f) {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if(l == n) return n;
        l += sz;
        while(l % 2 == 0) l >>= 1;
        T sum = e();
        while(f(func(sum, state[l]))) {
            if(__builtin_clz(l) != __builtin_clz(l+1)) return n;
            sum = func(sum, state[l]);
            l++;
            while(l % 2 == 0) l >>= 1;
        }
        while(l < sz) {
            if(!f(func(sum, state[l*2]))) l *= 2;
            else {
                sum = func(sum, state[l*2]);
                l = l*2 + 1;
            }
        }
        return min(n, l - sz);
    }
};

template <typename T>
using RMaxQ = SegTree<T, kowerkoint::max<T>, numeric_limits<T>::min>;
template <typename T>
using RMinQ = SegTree<T, kowerkoint::min<T>, numeric_limits<T>::max>;
template <typename T>
using RSumQ = SegTree<T, kowerkoint::add<T>, kowerkoint::zero<T>>;
