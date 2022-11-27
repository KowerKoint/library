#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#include "../geometry/line.hpp"

int main() {
    Point<double> p1, p2; cin >> p1 >> p2;
    Line<double> l(p1, p2);
    int q; cin >> q;
    while(q--) {
        Point<double> p; cin >> p;
        cout << l.proj(p) << endl;
    }
}
