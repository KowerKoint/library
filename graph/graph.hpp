#pragma once
#include "../base.hpp"
#include "../connectivity/union-find.hpp"

template <typename T=int>
struct Edge {
    int from, to;
    T cost;
    int id;
    Edge() = default;
    Edge(int from, int to, T cost=1, int id=-1) : from(from), to(to), cost(cost), id(id) {}
    operator int() const { return to; }
};

template <typename T=int>
struct Graph {
    int n;
    int m;
    vector<vector<Edge<T>>> g;
    Graph(int n_=0) : n(n_), m(0), g(n_) {
        assert(n_ >= 0);
    }
    void add_edge(int u, int v, T w=1) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back({u, v, w, m});
        g[v].push_back({v, u, w, m++});
    }
    void add_directed_edge(int u, int v, T w=1) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back({u, v, w, m++});
    }
    void read(int m_, int padding=-1, bool weighted=false, bool directed=false) {
        assert(m_ >= 0);
        REP(i, m_) {
            int u, v; cin >> u >> v; u += padding, v += padding;
            T c(1);
            if(weighted) cin >> c;
            if(directed) add_directed_edge(u, v, c);
            else add_edge(u, v, c);
        }
    }
    vector<Edge<T>>& operator[](int u) {
        assert(0 <= u && u < n);
        return g[u];
    }
    const vector<Edge<T>>& operator[](int u) const {
        assert(0 <= u && u < n);
        return g[u];
    }
    pair<vector<T>, vector<Edge<T>>> dijkstra(int st) const {
        assert(0 <= st && st < n);
        T inf = numeric_limits<T>::max();
        vector<T> dist(n, inf);
        vector<Edge<T>> pre(n);
        GPQ<pair<T, int>> pq;
        dist[st] = 0;
        pq.emplace(0, st);
        while(!pq.empty()) {
            auto [d, from] = pq.top(); pq.pop();
            if(dist[from] < d) continue;
            for(auto& e : g[from]) {
                if(chmin(dist[e.to], d + e.cost)) {
                    pre[e.to] = e;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
        return {dist, pre};
    }
    pair<vector<T>, vector<Edge<T>>> bfs(int st) const {
        assert(0 <= st && st < n);
        T inf = numeric_limits<T>::max();
        vector<T> dist(n, inf);
        vector<Edge<T>> pre(n);
        queue<int> que;
        dist[st] = 0;
        que.emplace(st);
        while(!que.empty()) {
            int from = que.front(); que.pop();
            for(auto& e : g[from]) {
                if(chmin(dist[e.to], dist[e.from] + 1)) {
                    pre[e.to] = e;
                    que.emplace(e.to);
                }
            }
        }
        return {dist, pre};
    }
    vector<Edge<T>> edges() const {
        vector<Edge<T>> res;
        REP(i, n) for(auto& e : g[i]) res.emplace_back(e);
        sort(res.begin(), res.end(), [](const Edge<T>& a, const Edge<T>& b) {
            return a.id < b.id;
        });
        res.erase(unique(ALL(res), [](const Edge<T>& a, const Edge<T>& b) {
            return a.id == b.id;
        }), res.end());
        return res;
    }
    vector<Edge<T>> kruskal() const {
        vector<Edge<T>> res;
        vector<Edge<T>> es = edges();
        UnionFind uf(n);
        sort(ALL(es), [](const Edge<T>& a, const Edge<T>& b) {
            return a.cost < b.cost;
        });
        for(auto& e : edges()) {
            if(uf.merge(e.from, e.to)) res.emplace_back(e);
        }
        return res;
    }
};
