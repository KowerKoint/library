#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "integer/prime.hpp"

int main() {
    int a, b, c; cin >> a >> b >> c;
    Prime pm;
    auto divisors = pm.divisor(c);
    print(upper_bound(ALL(divisors), b) - lower_bound(ALL(divisors), a));
}
