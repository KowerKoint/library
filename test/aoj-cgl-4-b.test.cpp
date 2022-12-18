#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR "1e-6"
#include "../geometry/polygon.hpp"

int main() {
    int n; cin >> n;
    Polygon<double> poly(n); cin >> poly;
    int j = 0;
    double ans = 0;
    REP(i, n) {
        double d = (poly[j] - poly[i]).norm();
        chmax(ans, d);
        while(1) {
            double nd = (poly[(j+1)%n] - poly[i]).norm();
            chmax(ans, nd);
            if(d > nd) break;
            d = nd;
            j = (j+1)%n;
        }
    }
    cout << fixed << setprecision(10) << sqrt(ans) << endl;
}
