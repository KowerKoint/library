#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../algebra/fps.hpp"

int main() {
    int n, m; cin >> n >> m;
    V3 _a(n), _b(m); cin >> _a >> _b;
    ExpandableFPS<MI3> a(_a), b(_b);
    print(a * b);
}
