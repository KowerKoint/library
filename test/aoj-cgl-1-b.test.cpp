#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR "1e-6"

#include "../geometry/line.hpp"

int main() {
    Point<double> p1, p2; cin >> p1 >> p2;
    Line<double> l(p1, p2);
    int q; cin >> q;
    cout << fixed << setprecision(10);
    while(q--) {
        Point<double> p; cin >> p;
        cout << l.reflect(p) << endl;
    }
}
