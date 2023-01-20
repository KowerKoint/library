#pragma once
#include "../base.hpp"

template <typename T=int>
struct MinCostFlowEdge {
    int to;
    T cap, cost, flow;
    int rev;
    bool is_rev;
    MinCostFlowEdge(int to, T cap, T cost, int rev, bool is_rev)
        : to(to), cap(cap), cost(cost), flow(0), rev(rev), is_rev(is_rev) {}
};

template <typename T=int>
struct MinCostFlowGraph {
    int n;
    vector<vector<MinCostFlowEdge<T>>> g;
    vector<T> h;
    MinCostFlowGraph(int n) : n(n), g(n), h(n) {
        static_assert(is_integral<T>::value);
        assert(n > 0);
    }
    void add_edge(int from, int to, T cap, T cost) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        assert(cap >= 0);
        assert(cost >= 0);
        MinCostFlowEdge<T> e(to, cap, cost, g[to].size(), false);
        MinCostFlowEdge<T> re(from, 0, -cost, g[from].size(), true);
        g[from].push_back(e);
        g[to].push_back(re);
    }
    pair<T, T> min_cost_one_flow(int s, int t, T f=numeric_limits<T>::max()) {
        assert(0 <= s && s < n && 0 <= t && t < n);
        assert(s != t);
        vector<T> dist(n, numeric_limits<T>::max());
        dist[s] = 0;
        vector<int> pre(n);
        GPQ<pair<T, int>> pq;
        pq.emplace(0, s);
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(dist[u] < d) continue;
            REP(i, g[u].size()) {
                auto& e = g[u][i];
                if(e.cap > e.flow && chmin(dist[e.to], dist[u] + e.cost + h[u] - h[e.to])) {
                    pre[e.to] = e.rev;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
        if(dist[t] == numeric_limits<T>::max()) return {0, 0};
        REP(i, n) if(dist[i] < numeric_limits<T>::max()) h[i] += dist[i];
        for(int u = t; u != s; u = g[u][pre[u]].to) {
            auto& e = g[g[u][pre[u]].to][g[u][pre[u]].rev];
            chmin(f, e.cap - e.flow);
        }
        for(int u = t; u != s; u = g[u][pre[u]].to) {
            auto& e = g[g[u][pre[u]].to][g[u][pre[u]].rev];
            e.flow += f;
            g[u][pre[u]].flow -= f;
        }
        return {f, f * (h[t] - h[s])};
    }
    pair<T, T> min_cost_flow(int s, int t, T f) {
        assert(0 <= s && s < n && 0 <= t && t < n);
        assert(s != t);
        T flow = 0, cost = 0;
        while(f > 0) {
            auto [cur_flow, cur_cost] = min_cost_one_flow(s, t, f);
            if(cur_flow == 0) break;
            flow += cur_flow;
            cost += cur_cost;
            f -= cur_flow;
        }
        return {flow, cost};
    }
    vector<pair<T, T>> min_cost_slope(int s, int t, T f = numeric_limits<T>::max()) {
        assert(0 <= s && s < n && 0 <= t && t < n);
        assert(s != t);
        vector<pair<T, T>> res;
        res.emplace_back(0, 0);
        T flow = 0, cost = 0;
        pair<T, T> prev_rate = {0, 0};
        while(f > 0) {
            auto [cur_flow, cur_cost] = min_cost_one_flow(s, t, f);
            if(cur_flow == 0) break;
            flow += cur_flow;
            cost += cur_cost;
            f -= cur_flow;
            T g = gcd(cur_cost, cur_flow);
            if(prev_rate == make_pair(cur_cost / g, cur_flow / g)) {
                res.pop_back();
            } else {
                prev_rate = {cur_cost / g, cur_flow / g};
            }
            res.emplace_back(flow, cost);
        }
        return res;
    }
};
