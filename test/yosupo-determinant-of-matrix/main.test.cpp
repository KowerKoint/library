#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "base.hpp"
#include <atcoder/all>
using namespace atcoder;
#include "expansion/ac-library/modint.hpp"
#include "matrix.hpp"

int main(void) {
    int n; cin >> n;
    Matrix<MI3> a(n, n); cin >> a;
    print(a.gaussian_elimination().second);
}
