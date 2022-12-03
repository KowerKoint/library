#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include "geometry/line.hpp"
int main() {
    int q; cin >> q;
    while(q--) {
        Point<int> p0, p1, p2, p3; cin >> p0 >> p1 >> p2 >> p3;
        Line<int> l0(p0, p1), l1(p2, p3);
        if(l0.parallel(l1)) {
            cout << 2 << endl;
        } else if(l0.orthogonal(l1)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
