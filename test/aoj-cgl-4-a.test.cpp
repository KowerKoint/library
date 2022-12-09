#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include "../geometry/polygon.hpp"

int main() {
    int n; cin >> n;
    vector<Point<int, 2>> ps(n); cin >> ps;
    Polygon<int> poly = convex_hull(ps);
    vector<Point<int, 2>> ans = poly.points;
    P mny(INF, -1);
    REP(i, ans.size()) {
        if(ans[i][1] < mny.first) mny = {ans[i][1], i};
    }
    print(ans.size());
    REP(i, ans.size()) {
        print(ans[(mny.second + i) % ans.size()]);
    }
}
