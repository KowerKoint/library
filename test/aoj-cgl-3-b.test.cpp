#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"
#include "../geometry/polygon.hpp"

int main() {
    int n; cin >> n;
    Polygon<ll> poly(n); cin >> poly;
    print(poly.is_convex());
}
