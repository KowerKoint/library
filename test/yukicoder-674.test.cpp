#define PROBLEM "https://yukicoder.me/problems/no/674"
#include "../segtree/segment-set.hpp"

int main() {
    ll d; int q; cin >> d >> q;
    SegmentSet<ll> seg;
    ll ans = 0;
    while(q--) {
        ll a, b; cin >> a >> b;
        auto it = seg.insert(a, b);
        chmax(ans, it->second - it->first + 1);
        print(ans);
    }
}
