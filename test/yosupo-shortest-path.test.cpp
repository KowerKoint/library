#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../graph/graph.hpp"

int main() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    Graph<ll> g(n);
    g.read(m, 0, true, true);
    auto [dist, pre] = g.dijkstra(s);
    if(dist[t] >= LINF) {
        cout << "-1\n";
        return 0;
    }
    VP uv;
    int cur = t;
    while(cur != s) {
        auto& e = pre[cur];
        uv.emplace_back(e.from, e.to);
        cur = e.from;
    }
    reverse(ALL(uv));
    cout << dist[t] << ' ' << uv.size() << '\n';
    for(auto p : uv) print(p);
}
