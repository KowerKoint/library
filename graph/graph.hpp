#pragma once
#include "../base.hpp"

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
    Graph(int n_=0) : n(n_), g(n_), m(0) {}
    void add_edge(int u, int v, T w=1) {
        g[u].push_back({u, v, w, m});
        g[v].push_back({v, u, w, m++});
    }
    void add_directed_edge(int u, int v, T w=1) {
        g[u].push_back({u, v, w, m++});
    }
    void read(int m_, int padding=-1, bool weighted=false, bool directed=false) {
        REP(i, m_) {
            int u, v; cin >> u >> v; u += padding, v += padding;
            T c(1);
            if(weighted) cin >> c;
            if(directed) add_directed_edge(u, v, c);
            else add_edge(u, v, c);
        }
    }
    vector<Edge<T>>& operator[](int u) { return g[u]; }
    const vector<Edge<T>>& operator[](int u) const { return g[u]; }
    pair<vector<T>, vector<Edge<T>>> dijkstra(int st) {
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
    pair<vector<T>, vector<Edge<T>>> bfs(int st) {
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
};
