#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR "1e-6"
#include "../geometry/line.hpp"
#include "../geometry/polygon.hpp"

int main() {
    int n; cin >> n;
    vector<Point<double, 2>> p(n); cin >> p;
    p.resize(n*3);
    for (int i = 0; i < n; ++i) p[i+n] = p[i+n+n] = p[i];
    int q; cin >> q;
    cout << fixed << setprecision(10);
    while(q--) {
        Point<double, 2> a, b; cin >> a >> b;
        int st = 0;
        while(st < n*3 && outer_product(b-a, p[st]-a) >= 0) st++;
        if(st == n*3) {
            Polygon<double> poly(vector<Point<double, 2>>(p.begin(), p.begin()+n));
            print(poly.area());
            continue;
        }
        while(st < n*3 && outer_product(b-a, p[st]-a) < 0) st++;
        if(st == n*3) {
            cout << 0. << endl;
            continue;
        }
        int ed = st;
        while(outer_product(b-a, p[ed]-a) >= 0) ed++;
        vector<Point<double, 2>> res;
        res.push_back(Line2D(p[st-1], p[st]).cross_point(Line2D(a, b)));
        for(int i = st; i < ed; ++i) {
            res.push_back(p[i]);
        }
        res.push_back(Line2D(p[ed-1], p[ed]).cross_point(Line2D(a, b)));
        print(Polygon<double>(res).area());
    }
}

