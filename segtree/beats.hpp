#include "../base.hpp"

template <typename S, S (*op)(S, S), S (*e)(), typename F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct SegTreeBeats {
protected:
    int n, sz, height;
    vector<S> state;
    vector<F> lazy;
    void update(int k) {
        state[k] = op(state[k*2], state[k*2+1]);
    }
    void all_apply(int k, const F& f) {
        state[k] = mapping(f, state[k]);
        if(k < sz) {
            lazy[k] = composition(f, lazy[k]);
            if(state[k].fail) {
                push(k);
                update(k);
            }
        }
    }
    void push(int k) {
        all_apply(k*2, lazy[k]);
        all_apply(k*2+1, lazy[k]);
        lazy[k] = id();
    }
public:
    SegTreeBeats(int n = 0): n(n) {
        sz = 1;
        height = 0;
        while(sz < n) {
            height++;
            sz <<= 1;
        }
        state.assign(sz*2, e());
        lazy.assign(sz*2, id());
    }
    SegTreeBeats(const vector<S>& v): n(v.size()) {
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
        assert(f(e));
        if(r == 0) return 0;
        r += sz;
        for(int k = height; k > 0; k--) push(r >> k);
        while(r % 2 == 0) r >>= 1;
        S sum = e();
        while(f(op(state[r], sum))) {
            if(__builtin_clz(r) != __builtin_clz(r+1)) return 0;
            sum = op(state[r], sum);
            r--;
            while(r % 2 == 0) r >>= 1;
        }
        while(r < sz) {
            push(r);
            if(!f(op(state[r*2+1], sum))) r = r*2 + 1;
            else {
                sum = op(state[r*2+1], sum);
                r = r*2;
            }
        }
        return r+1 - sz;
    }
};
