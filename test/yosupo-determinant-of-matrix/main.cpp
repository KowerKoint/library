#define aclmodint
#include "atcoder/all"
using namespace atcoder;
#include "KowerKoint/template.cpp"
#include "KowerKoint/math/matrix.hpp"

int main(void) {
    int n; cin >> n;
    Matrix<MI3> a(n, n); cin >> a;
    print(a.gaussian_elimination().second);
}
