#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../graph/tree.hpp"

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    VI p(n-1); cin >> p;
    Tree g(p, 0);
    g.build(0);
    g.lca_build();
    while(q--) {
        int u, v; cin >> u >> v;
        print(g.lca(u, v));
    }
}
