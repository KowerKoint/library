#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "integer/prime.hpp"

int main() {
    int n; cin >> n;
    Prime prime(100000000);
    int ans = 0;
    REP(i, n) {
        int a; cin >> a;
        ans += prime.is_prime(a);
    }
    print(ans);
}
