#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../integer/modint.hpp"
#include "../segtree/lazy_segtree.hpp"

int main() {
    int n, q; cin >> n >> q;
    vector<S_sz<MI3>> a(n);
    REP(i, n) {
        cin >> a[i].val;
        a[i].sz = 1;
    }
    RAffineSumQ<MI3> seg(a);
    while(q--) {
        int t; cin >> t;
        if(t == 0) {
            int l, r; MI3 b, c; cin >> l >> r >> b >> c;
            seg.apply(l, r, Affine<MI3>(b, c));
        } else {
            int l, r; cin >> l >> r;
            print(seg.prod(l, r).val);
        }
    }
}

