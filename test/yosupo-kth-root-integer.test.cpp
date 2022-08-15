#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "../integer/kth-root-integer.hpp"

int main() {
    int t; cin >> t;
    while(t--) {
        ull a, k; cin >> a >> k;
        print(kth_root_integer(a, k));
    }
}
