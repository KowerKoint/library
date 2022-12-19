#pragma once
#include "../base.hpp"

template <typename T=int>
struct MaxFlowEdge {
    int to;
    T cap, flow;
    int rev;
    bool is_rev;
    MaxFlowEdge(int to, T cap, int rev, bool is_rev) : to(to), cap(cap), flow(0), rev(rev), is_rev(is_rev){}
};

template <typename T=int>
struct MaxFlowGraph {
    int n;
    vector<vector<MaxFlowEdge<T>>> g;
    MaxFlowGraph(int n_ = 0) : n(n_), g(n_) {
        assert(n_ >= 0);
    }
    void add_edge(int from, int to, T cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(cap >= 0);
        assert(from != to);
        MaxFlowEdge<T> e(to, cap, g[to].size(), false);
        MaxFlowEdge<T> re(from, 0, g[from].size(), true);
        g[from].push_back(e);
        g[to].push_back(re);
    }

    T max_flow(int s, int t) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);
        T res = 0;
        while (true) {
            VI dist(n, numeric_limits<int>::max());
            dist[s] = 0;
            queue<int> que;
            que.push(s);
            while(!que.empty()) {
                int from = que.front(); que.pop();
                for(auto& e : g[from]) {
                    if(e.cap - e.flow == 0) continue;
                    if(dist[e.to] != numeric_limits<int>::max()) continue;
                    dist[e.to] = dist[from] + 1;
                    que.push(e.to);
                }
            }
            if(dist[t] == numeric_limits<int>::max()) break;
            VI iter(n);
            while(1) {
                stack<pair<int, T>> stk;
                stk.emplace(s, numeric_limits<T>::max());
                VI pre(n);
                T flow = 0;
                while(!stk.empty()) {
                    auto [from, f] = stk.top(); stk.pop();
                    if(from == t && f > 0) {
                        flow = f;
                        break;
                    }
                    for(int& i = iter[from]; i < (int)g[from].size(); i++) {
                        auto& e = g[from][i];
                        if(e.cap - e.flow == 0) continue;
                        if(dist[e.to] != dist[from] + 1) continue;
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
        }
        return res;
    }
    vector<int> min_cut(int s) {
        assert(0 <= s && s < n);
        VI seen(n);
        stack<int> stk;
        stk.push(s);
        while(!stk.empty()) {
            int from = stk.top(); stk.pop();
            seen[from] = true;
            for(auto& e : g[from]) {
                if(e.cap - e.flow == 0) continue;
                if(seen[e.to]) continue;
                stk.push(e.to);
            }
        }
        VI res;
        REP(i, n) if(seen[i]) res.push_back(i);
        return res;
    }
};
