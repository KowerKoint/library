#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "KowerKoint/matrix.hpp"

int main(void) {
    int n; cin >> n;
    VL a(n); cin >> a;
    XorMatrix mat(61, n);
    REP(i, 61) REP(j, n) mat[i][j] = a[j] >> i & 1LL;
    auto basis = mat.gaussian_elimination().first;
    ll ans = 1;
    REP(i, 61) {
        REP(j, n) if(basis[i][j]) {
            ans <<= 1LL;
            break;
        }
    }
    print(ans);
}
