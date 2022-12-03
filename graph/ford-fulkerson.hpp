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
    FordFulkersonGraph(int n_ = 0) : n(n_), g(n_) {
        assert(n_ >= 0);
    }
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
            VI pre(n);
            stack<pair<int, T>> stk;
            seen[s] = 1;
            stk.emplace(s, numeric_limits<T>::max());
            T flow = 0;
            while(!stk.empty()) {
                auto [from, f] = stk.top(); stk.pop();
                seen[from] = 1;
                if(from == t) {
                    flow = f;
                    continue;
                }
                for(int i = 0; i < g[from].size(); i++) {
                    auto& e = g[from][i];
                    if(seen[e.to]) continue;
                    if(e.cap - e.flow == 0) continue;
                    seen[e.to] = 1;
                    pre[e.to] = e.rev;
                    stk.emplace(e.to, min(f, e.cap - e.flow));
                }
            }
            if(flow == 0) break;
            int cur = t;
            while(cur != s) {
                auto& re = g[cur][pre[cur]];
                auto& e = g[re.to][re.rev];
                e.flow += flow;
                re.flow -= flow;
                cur = re.to;
            }
            res += flow;
        }
        return res;
    }
};
