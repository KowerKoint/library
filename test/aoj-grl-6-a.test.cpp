#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../graph/ford-fullkerson.hpp"

int main() {
    int v, e; cin >> v >> e;
    FordFulkersonGraph g(v);
    REP(i, e) {
        int a, b, c; cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    print(g.max_flow(0, v - 1));
}
