#include "KowerKoint/base.hpp"
#include <atcoder/all>
using namespace atcoder;
#include "KowerKoint/expansion/ac-library/modint.hpp"
#include "KowerKoint/matrix.hpp"

int main(void) {
    int n; cin >> n;
    Matrix<MI3> a(n, n); cin >> a;
    print(a.gaussian_elimination().second);
}
