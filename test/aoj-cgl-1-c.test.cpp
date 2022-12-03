#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include "../geometry/point.hpp"
int main() {
    Point<int> p0, p1; cin >> p0 >> p1;
    int q; cin >> q;
    while (q--) {
        Point<int> p2; cin >> p2;
        int op = outer_product(p1 - p0, p2 - p0);
        int ip = (p1-p0).dot(p2-p0);
        int norm = (p1-p0).norm();
        if (op > 0) cout << "COUNTER_CLOCKWISE\n";
        else if (op < 0) cout << "CLOCKWISE\n";
        else if(ip < 0) cout << "ONLINE_BACK\n";
        else if (norm < ip) cout << "ONLINE_FRONT\n";
        else cout << "ON_SEGMENT\n";
    }
}
