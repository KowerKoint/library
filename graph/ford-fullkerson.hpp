#pragma once
#include "../base.hpp"

template <typename T=int>
struct FordFulkersonEdge {
    int to;
    T cap, flow;
    int rev;
    bool is_rev;
    FordFulkersonEdge(int to, T cap, int rev, bool is_rev) : to(to), cap(cap), flow(0), rev(rev), is_rev(is_rev){}
};

template <typename T=int>
struct FordFulkersonGraph {
    int n;
    vector<vector<FordFulkersonEdge<T>>> g;
    FordFulkersonGraph(int n_ = 0) : n(n_), g(n_) {}
    void add_edge(int from, int to, T cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(cap >= 0);
        assert(from != to);
        FordFulkersonEdge<T> e(to, cap, g[to].size(), false);
        FordFulkersonEdge<T> re(from, 0, g[from].size(), true);
        g[from].push_back(e);
        g[to].push_back(re);
    }
    T max_flow(int s, int t) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);
        T res = 0;
        while (true) {
            VI seen(n);
            VI processed(n);
            VVI child_edge(n);
            vector<T> flow(n);
            stack<pair<int, T>> stk;
            stk.emplace(~s, -1);
            stk.emplace(s, numeric_limits<T>::max());
            T d = 0;
            while(!stk.empty()) {
                auto [from, f] = stk.top(); stk.pop();
                if(from >= 0) {
                    seen[from] = 1;
                    if(from == t) {
                        flow[from] = f;
                        continue;
                    }
                    for(int i = 0; i < g[from].size(); i++) {
                        auto& e = g[from][i];
                        if(seen[e.to]) continue;
                        if(e.cap - e.flow == 0) continue;
                        child_edge[from].push_back(i);
                        stk.emplace(~e.to, 0);
                        stk.emplace(e.to, min(f, e.cap - e.flow));
                    }
                } else {
                    from = ~from;
                    pair<T, int> mx = {0, -1};
                    for(int i : child_edge[from]) {
                        int to = g[from][i].to;
                        if(processed[to]) continue;
                        processed[to] = 1;
                        chmax(mx, make_pair(flow[to], i));
                    }
                    if(mx.first == 0) continue;
                    flow[from] = mx.first;
                    auto& e = g[from][mx.second];
                    e.flow += mx.first;
                    g[e.to][e.rev].flow -= mx.first;
                    if(from == s) d = mx.first;
                }
            }
            if(d == 0) break;
            res += d;
        }
        return res;
    }
};
