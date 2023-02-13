#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../structure/treap.hpp"

int main() {
    struct CompareFirst {
        bool operator()(const LP& a, const LP& b) const {
            return a.first < b.first;
        }
    };
    Treap<LP, CompareFirst> treap;
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 0) {
            ll k, v; cin >> k >> v;
            treap.insert({k, v});
        } else if(t == 1) {
            ll k; cin >> k;
            auto p = treap.find({k, 0LL});
            print(p? p->key.second : 0);
        }
    }
}
