#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR "1e-6"
#include "../geometry/point.hpp"

int main() {
    int n; cin >> n;
    vector<Point<double>> ps(n); cin >> ps;
    cout << fixed << setprecision(10) << closest_point_pair(ps) << endl;
}
