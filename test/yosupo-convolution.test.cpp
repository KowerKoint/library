#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "convolution/ntt.hpp"

int main() {
    int n, m; cin >> n >> m;
    vector<MI3> a(n), b(m); cin >> a >> b;
    vector<MI3> ans = sum_convolution(a, b);
    print(ans);
}
