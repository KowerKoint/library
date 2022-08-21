#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "../segtree/segtree.hpp"

int main() {
    int n, q; cin >> n >> q;
    RMinQ<int> rmq(n);
    while(q--) {
        int com, x, y; cin >> com>> x >> y;
        if(com == 1) print(rmq.prod(x, y+1));
        else rmq.set(x, y);
    }
}
