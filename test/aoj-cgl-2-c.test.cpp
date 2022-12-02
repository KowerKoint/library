#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"


#include "../geometry/point.hpp"
int main() {
    int q; cin >> q;
    cout << fixed << setprecision(10);
    while(q--) {
        Point<double> p0, p1, p2, p3; cin >> p0 >> p1 >> p2 >> p3;
        cout << segment_intersect(p0, p1, p2, p3).second << endl;
    }
}
