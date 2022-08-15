#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"
#include "integer/extgcd.hpp"

int main() {
    ll a, b; cin >> a >> b;
    ll x, y;
    extgcd(a, b, x, y);
    print(x, y);
}
