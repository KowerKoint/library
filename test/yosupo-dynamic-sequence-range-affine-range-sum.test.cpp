#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "structure/implicit-treap.hpp"
#include "algebra/modint.hpp"
#include "operator/mapping.hpp"

int main() {
    int n, q; cin >> n >> q;
    V3 a(n); cin >> a;
    ImplicitTreap<MI3, SumMonoid<MI3>, pair<MI3, MI3>, AffineMonoid<MI3>, AffineMappingWithSize<MI3>, true> treap(ALL(a));
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int i; MI3 x; cin >> i >> x;
            treap.insert(i, x);
        } else if(t == 1) {
            int i; cin >> i;
            treap.erase(i);
        } else if(t == 2) {
            int l, r; cin >> l >> r;
            treap.reverse(l, r);
        } else if(t == 3) {
            int l, r; MI3 b, c; cin >> l >> r >> b >> c;
            treap.apply(l, r, {b, c});
        } else {
            int l, r; cin >> l >> r;
            cout << treap.query(l, r) << endl;
        }
    }
}
