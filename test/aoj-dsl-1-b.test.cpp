#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include "../connectivity/union-find.hpp"

int main() {
    int n, q; cin >> n >> q;
    WeightedUnionFind<int> uf(n);
    while(q--) {
        int cmd; cin >> cmd;
        if(cmd == 0) {
            int x, y, z; cin >> x >> y >> z;
            uf.merge(x, y, z);
        } else {
            int x, y; cin >> x >> y;
            if(uf.same(x, y)) print(uf.diff(x, y));
            else print('?');
        }
    }
}
