#pragma once
#include "../operator.hpp"

template <typename S, S (*op)(const S, const S), S (*e)()>
struct SegTree {
protected:
    int n, sz, height;
    vector<S> state;
    void update(int k) {
        state[k] = op(state[k*2], state[k*2+1]);
    }
public:
    SegTree(int n_): n(n_) {
        sz = 1;
        height = 0;
        while(sz < n) {
            height++;
            sz <<= 1;
        }
        state.assign(sz*2, e());
    }
    SegTree(const vector<S>& v): n(v.size()) {
        sz = 1;
        height = 0;
        while(sz < n) {
            height++;
            sz <<= 1;
        }
        state.assign(sz*2, e());
        REP(i, v.size()) state[sz+i] = v[i];
        for(int i = sz-1; i > 0; i--) update(i);
    }
    S get(int i) const {
        assert(0 <= i && i < n);
        return state[sz+i];
    }
    S operator[](int i) const {
        assert(0 <= i && i < n);
        return get(i);
    }
    void set(int i, const S &x) {
        assert(0 <= i && i < n);
        i += sz;
        state[i] = x;
        while(i >>= 1) update(i);
    }
    void ch_op(int i, const S &x) {
        set(i, op(get(i), x));
    }
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        S left_prod = e(), right_prod = e();
        l += sz, r += sz;
        while(l < r) {
            if(l & 1) left_prod = op(left_prod, state[l++]);
            if(r & 1) right_prod = op(state[--r], right_prod);
            l >>= 1;
            r >>= 1;
        }
        return op(left_prod, right_prod);
    }
    S all_prod() const {
        return state[1];
    }
    template <typename F>
    int max_right(int l, F f) const {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if(l == n) return n;
        l += sz;
        while(l % 2 == 0) l >>= 1;
        S sum = e();
        while(f(op(sum, state[l]))) {
            if(__builtin_clz(l) != __builtin_clz(l+1)) return n;
            sum = op(sum, state[l]);
            l++;
            while(l % 2 == 0) l >>= 1;
        }
        while(l < sz) {
            if(!f(op(sum, state[l*2]))) l *= 2;
            else {
                sum = op(sum, state[l*2]);
                l = l*2 + 1;
            }
        }
        return l - sz;
    }
    template <typename F>
    int min_left(int r, F f) const {
        assert(0 <= r && r <= n);
        assert(f(e));
        if(r == 0) return 0;
        r += sz;
        while(r % 2 == 0) r >>= 1;
        S sum = e();
        while(f(op(state[r], sum))) {
            if(__builtin_clz(r) != __builtin_clz(r+1)) return 0;
            sum = op(state[r], sum);
            r--;
            while(r % 2 == 0) r >>= 1;
        }
        while(r < sz) {
            if(!f(op(state[r*2+1], sum))) r = r*2 + 1;
            else {
                sum = op(state[r*2+1], sum);
                r = r*2;
            }
        }
        return r - sz;
    }
};

template <typename S>
using RMaxQ = SegTree<S, max_op<S>, min_e<S>>;
template <typename S>
using RMinQ = SegTree<S, min_op<S>, max_e<S>>;
template <typename S>
using RSumQ = SegTree<S, add_op<S>, zero_e<S>>;
