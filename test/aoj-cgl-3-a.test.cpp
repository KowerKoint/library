#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#include "../geometry/polygon.hpp"

int main() {
    int n; cin >> n;
    Polygon<double> poly(n); cin >> poly;
    cout << fixed << setprecision(1) << poly.area() << endl;
}
