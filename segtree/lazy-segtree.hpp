#pragma once
#include "../operator.hpp"

template <typename S, S (*op)(S, S), S (*e)(), typename F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct LazySegTree {
protected:
    int n, sz, height;
    vector<S> state;
    vector<F> lazy;
    void update(int k) {
        state[k] = op(state[k*2], state[k*2+1]);
    }
    void all_apply(int k, const F& f) {
        state[k] = mapping(f, state[k]);
        if(k < sz) lazy[k] = composition(f, lazy[k]);
    }
    void push(int k) {
        all_apply(k*2, lazy[k]);
        all_apply(k*2+1, lazy[k]);
        lazy[k] = id();
    }
public:
    LazySegTree(int n = 0): n(n) {
        sz = 1;
        height = 0;
        while(sz < n) {
            height++;
            sz <<= 1;
        }
        state.assign(sz*2, e());
        lazy.assign(sz*2, id());
    }
    LazySegTree(const vector<S>& v): n(v.size()) {
        sz = 1;
        height = 0;
        while(sz < n) {
            height++;
            sz <<= 1;
        }
        state.assign(sz*2, e());
        REP(i, v.size()) state[sz+i] = v[i];
        for(int i = sz-1; i > 0; i--) update(i);
        lazy.assign(sz*2, id());
    }
    S get(int i) {
        assert(0 <= i && i < n);
        i += sz;
        for(int k = height; k > 0; k--) {
            push(i >> k);
        }
        return state[i];
    }
    void set(int i, const S& x) {
        assert(0 <= i && i < n);
        i += sz;
        for(int k = height; k > 0; k--) {
            push(i >> k);
        }
        state[i] = x;
        while(i >>= 1) update(i);
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        l += sz, r += sz;
        for(int k = height; k > 0; k--) {
            if(((l >> k) << k) != l) push(l >> k);
            if(((r >> k) << k) != r) push(r >> k);
        }
        S left_prod = e(), right_prod = e();
        while(l < r) {
            if(l & 1) left_prod = op(left_prod, state[l++]);
            if(r & 1) right_prod = op(state[--r], right_prod);
            l >>= 1;
            r >>= 1;
        }
        return op(left_prod, right_prod);
    }
    void apply(int i, const F& f) {
        assert(0 <= i && i < n);
        i += sz;
        for(int k = height; k > 0; k--) push(i >> k);
        state[i] = mapping(f, state[i]);
        while(i >>= 1) update(i);
    }
    void apply(int l, int r, const F& f) {
        assert(0 <= l && l <= r && r <= n);
        if(l == r) return;
        l += sz, r += sz;
        for(int k = height; k > 0; k--) {
            if(((l >> k) << k) != l) push(l >> k);
            if(((r >> k) << k) != r) push(r >> k);
        }
        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2, r = r2;
        }
        for(int k = 1; k <= height; k++) {
            if (((l >> k) << k) != l) update(l >> k);
            if (((r >> k) << k) != r) update((r-1) >> k);
        }
    }
    template <typename Judge>
    int max_right(int l, Judge f) {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if(l == n) return n;
        l += sz;
        for(int k = height; k > 0; k--) push(l >> k);
        while(l % 2 == 0) l >>= 1;
        S sum = e();
        while(f(op(sum, state[l]))) {
            if(__builtin_clz(l) != __builtin_clz(l+1)) return n;
            sum = op(sum, state[l]);
            l++;
            while(l % 2 == 0) l >>= 1;
        }
        while(l < sz) {
            push(l);
            if(!f(op(sum, state[l*2]))) l *= 2;
            else {
                sum = op(sum, state[l*2]);
                l = l*2 + 1;
            }
        }
        return l - sz;
    }
    template <typename Judge>
    int min_left(int r, Judge f) {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if(r == 0) return 0;
        r += sz-1;
        for(int k = height; k > 0; k--) push(r >> k);
        while(r % 2 == 1) r >>= 1;
        S sum = e();
        while(f(op(state[r], sum))) {
            if(__builtin_clz(r) != __builtin_clz(r-1)) return 0;
            sum = op(state[r], sum);
            r--;
            while(r % 2 == 1) r >>= 1;
        }
        while(r < sz) {
            push(r);
            if(!f(op(state[r*2+1], sum))) r = r*2 + 1;
            else {
                sum = op(state[r*2+1], sum);
                r = r*2;
            }
        }
        return r - sz + 1;
    }
};

template <typename S>
struct S_sz {
    S val; int sz;
    S_sz() : val(0), sz(0) {}
    S_sz(S val, int sz = 1) : val(val), sz(sz) {}
    S_sz<S> operator+(const S_sz<S>& o) const {
        return S_sz<S>(val + o.val, sz + o.sz);
    }
};
template <typename S>
S_sz<S> s_sz_zero() {
    return S_sz<S>();
}
template <typename S>
struct Affine {
    S a, b;
    Affine() : a(1), b(0) {}
    Affine(S a, S b) : a(a), b(b) {}
};
template <typename S>
Affine<S> affine_identity() {
    return Affine<S>(1, 0);
}
template <typename S>
S affine_mapping(Affine<S> f, S s) {
    return f.a * s + f.b;
};
template <typename S>
S_sz<S> affine_mapping_sz(Affine<S> f, S_sz<S> s) {
    return S_sz<S>(f.a * s.val + f.b * s.sz, s.sz);
}
template <typename S>
Affine<S> affine_composition(Affine<S> f, Affine<S> g) {
    return Affine(f.a * g.a, f.a * g.b + f.b);
}
template <typename S>
S_sz<S> chmin_mapping_sz(S f, S_sz<S> s) {
    return S_sz(f < s.val ? f : s.val, s.sz);
}
template <typename S>
S_sz<S> chmax_mapping_sz(S f, S_sz<S> s) {
    return S_sz(f > s.val ? f : s.val, s.sz);
}
template <typename S>
S_sz<S> add_mapping_sz(S f, S_sz<S> s) {
    return S_sz(s.val + f * s.sz, s.sz);
}
template <typename S>
using RChminMinQ = LazySegTree<S, min_op<S>, max_e<S>, S, min_op<S>, min_op<S>, max_e<S>>;
template <typename S>
using RChminMaxQ = LazySegTree<S, max_op<S>, min_e<S>, S, min_op<S>, min_op<S>, max_e<S>>;

template <typename S>
using RChmaxMinQ = LazySegTree<S, min_op<S>, max_e<S>, S, max_op<S>, max_op<S>, min_e<S>>;
template <typename S>
using RChmaxMaxQ = LazySegTree<S, max_op<S>, min_e<S>, S, max_op<S>, max_op<S>, min_e<S>>;

template <typename S>
using RAddMinQ = LazySegTree<S, min_op<S>, max_e<S>, S, add_op<S>, add_op<S>, zero_e<S>>;
template <typename S>
using RAddMaxQ = LazySegTree<S, max_op<S>, min_e<S>, S, add_op<S>, add_op<S>, zero_e<S>>;
template <typename S>
using RAddSumQ = LazySegTree<S_sz<S>, add_op<S_sz<S>>, s_sz_zero<S>, S, add_mapping_sz<S>, add_op<S>, zero_e<S>>;

template <typename S>
using RAffineMinQ = LazySegTree<S, min_op<S>, max_e<S>, Affine<S>, affine_mapping<S>, affine_composition<S>, affine_identity<S>>;
template <typename S>
using RAffineMaxQ = LazySegTree<S, max_op<S>, min_e<S>, Affine<S>, affine_mapping<S>, affine_composition<S>, affine_identity<S>>;
template <typename S>
using RAffineSumQ = LazySegTree<S_sz<S>, add_op<S_sz<S>>, s_sz_zero<S>, Affine<S>, affine_mapping_sz<S>, affine_composition<S>, affine_identity<S>>;
