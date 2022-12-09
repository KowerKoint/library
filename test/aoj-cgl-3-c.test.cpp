#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"
#include "../geometry/polygon.hpp"

int main() {
    int n; cin >> n;
    Polygon<int> poly(n); cin >> poly;
    int q; cin >> q;
    while(q--) {
        Point<int> p; cin >> p;
        print(poly.contains(p));
    }
}
