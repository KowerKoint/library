#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include "../graph/min-cost-flow.hpp"

int main() {
    int v, e, f; cin >> v >> e >> f;
    MinCostFlowGraph g(v);
    for (int i = 0; i < e; i++) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        g.add_edge(u, v, c, d);
    }
    auto [flow, cost] = g.min_cost_flow(0, v - 1, f);
    print(flow < f ? -1 : cost);
}
