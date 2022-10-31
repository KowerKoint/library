#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include "algebra/nimber.hpp"

int main() {
    int t; cin >> t;
    while(t--) {
        Nimber a, b; cin >> a >> b;
        print(a * b);
    }
}
