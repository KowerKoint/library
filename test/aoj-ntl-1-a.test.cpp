#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include "integer/prime.hpp"

int main() {
    ll n; cin >> n;
    Prime pr;
    cout << n << ':';
    for(auto [p, c] : pr.prime_factor(n)) {
        REP(i, c) cout << ' ' << p;
    }
    print();
}
