#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../segtree/beats.hpp"

ll inf = 1LL << 61;

template <typename Num> inline Num second_lowest(Num a, Num a2, Num c, Num c2) noexcept {
    // a < a2, c < c2 のとき全引数を昇順ソートして二番目の値
    return a == c ? std::min(a2, c2) : a2 <= c ? a2 : c2 <= a ? c2 : std::max(a, c);
}
template <typename Num> inline Num second_highest(Num a, Num a2, Num b, Num b2) noexcept {
    // a > a2, b > b2 のとき全引数を降順ソートして二番目の値
    return a == b ? std::max(a2, b2) : a2 >= b ? a2 : b2 >= a ? b2 : std::min(a, b);
}
struct S {
    ll mn1, mn2, mx1, mx2, sum;
    int nmn, nmx, sz;
    bool fail;
    S() : mn1(inf), mn2(inf), mx1(-inf), mx2(-inf), sum(0), nmn(0), nmx(0), sz(0), fail(false) {}
    S(ll x, int sz=1) : mn1(x), mn2(inf), mx1(x), mx2(-inf), sum(x*sz), nmn(sz), nmx(sz), sz(sz), fail(false) {}
};
S op(S l, S r) {
    assert(!l.fail && !r.fail);
    S res;
    res.mn1 = min(l.mn1, r.mn1);
    if(l.mn1 == r.mn1) {
        res.mn2 = min(l.mn2, r.mn2);
    } else if(l.mn2 <= r.mn1) {
        res.mn2 = l.mn2;
    } else if(r.mn2 <= l.mn1) {
        res.mn2 = r.mn2;
    } else {
        res.mn2 = max(l.mn1, r.mn1);
    }
    res.mx1 = max(l.mx1, r.mx1);
    if(l.mx1 == r.mx1) {
        res.mx2 = max(l.mx2, r.mx2);
    } else if(l.mx2 >= r.mx1) {
        res.mx2 = l.mx2;
    } else if(r.mx2 >= l.mx1) {
        res.mx2 = r.mx2;
    } else {
        res.mx2 = min(l.mx1, r.mx1);
    }
    res.sum = l.sum + r.sum;
    res.nmn = l.nmn * (l.mn1 <= r.mn1) + r.nmn * (r.mn1 <= l.mn1);
    res.nmx = l.nmx * (l.mx1 >= r.mx1) + r.nmx * (r.mx1 >= l.mx1);
    res.sz = l.sz + r.sz;
    return res;
}
S e() { return S(); }
struct F {
    ll l, r, pote;
    F(ll l, ll r, ll pote) : l(l), r(r), pote(pote) {}
    static F chmin(ll x) {
        return F(-inf, x, 0);
    }
    static F chmax(ll x) {
        return F(x, inf, 0);
    }
    static F add(ll x) {
        return F(-inf, inf, x);
    }
};
S mapping(F f, S s) {
    if(s.sz == 0) return e();
    if(s.mn1 == s.mx1 or f.r <= s.mn1 or s.mx1 <= f.l or f.l == f.r) {
        return S(clamp(s.mn1, f.l, f.r) + f.pote, s.sz);
    }
    if(s.mn2 == s.mx1) {
        s.mn1 = s.mx2 = max(s.mn1, f.l) + f.pote;
        s.mx1 = s.mn2 = min(s.mx1, f.r) + f.pote;
        s.sum = s.mn1 * s.nmn + s.mx1 * s.nmx;
        return s;
    }
    if(s.mn2 <= f.l or f.r <= s.mx2) {
        s.fail = true;
        return s;
    }
    s.sum -= s.mn1 * s.nmn + s.mx1 * s.nmx;
    s.sum += f.pote * (s.sz - s.nmn - s.nmx);
    s.mn1 = max(s.mn1, f.l) + f.pote;
    s.mx1 = min(s.mx1, f.r) + f.pote;
    s.mn2 += f.pote;
    s.mx2 += f.pote;
    s.sum += s.mn1 * s.nmn + s.mx1 * s.nmx;
    return s;
}
F composition(F f, F g) {
    F res(clamp(g.l, f.l - g.pote, f.r - g.pote), clamp(g.r, f.l - g.pote, f.r - g.pote), f.pote + g.pote);
    return res;
}
F id() { return F(-inf, inf, 0); }

int main() {
    int n, q; cin >> n >> q;
    VL a(n); cin >> a;
    vector<S> iv(n);
    REP(i, n) iv[i] = a[i];
    SegTreeBeats<S, op, e, F, mapping, composition, id> seg(iv);
    while(q--) {
        int t, l, r; cin >> t >> l >> r;
        if(t == 0) {
            ll b; cin >> b;
            seg.apply(l, r, F::chmin(b));
        } else if(t == 1) {
            ll b; cin >> b;
            seg.apply(l, r, F::chmax(b));
        } else if(t == 2) {
            ll b; cin >> b;
            seg.apply(l, r, F::add(b));
        } else {
            print(seg.prod(l, r).sum);
        }
    }
}
