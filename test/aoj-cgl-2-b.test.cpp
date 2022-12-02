#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include "../geometry/point.hpp"
int main() {
    int q; cin >> q;
    while(q--) {
        Point<double> p0, p1, p2, p3; cin >> p0 >> p1 >> p2 >> p3;
        cout << (segment_intersect(p0, p1, p2, p3).first ? 1 : 0) << endl;
    }
}
