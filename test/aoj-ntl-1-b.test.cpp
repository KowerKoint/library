#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "algebra/modint.hpp"

int main() {
    int m, n; cin >> m >> n;
    print(MI7(m).pow(n));
}
