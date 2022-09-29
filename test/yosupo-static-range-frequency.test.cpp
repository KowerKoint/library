#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include "segtree/wavelet-matrix.hpp"

int main() {
    int n, q; cin >> n >> q;
    VI a(n); cin >> a;
    WaveletMatrix<int, 30> wm(a);
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        cout << wm.rank(k, r) - wm.rank(k, l) << '\n';
    }
}
