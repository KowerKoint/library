#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../convolution/ntt.hpp"

int main() {
    int n, m; cin >> n >> m;
    V3 a(n), b(m); cin >> a >> b;
    V3 ans = sum_convolution<mod998244353>(a, b);
    print(ans);
}
