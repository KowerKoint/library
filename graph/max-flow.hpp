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
        static_assert(is_integral<T>::value);
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
            vector<T> sink_limit(n), sink_flow(n);
            stack<int> stk;
            stk.push(t);
            sink_limit[t] = numeric_limits<T>::max();
            while(!stk.empty()) {
                int from = stk.top();
                if(from == s) {
                    sink_flow[from] = sink_limit[from];
                }
                if(from == s || sink_limit[from] == 0 || iter[from] == (int)g[from].size()) {
                    stk.pop();
                    if(!stk.empty()) {
                        int par = stk.top();
                        auto& re = g[par][iter[par]];
                        auto& e = g[re.to][re.rev];
                        e.flow += sink_flow[from];
                        re.flow -= sink_flow[from];
                        sink_flow[par] += sink_flow[from];
                        sink_limit[par] -= sink_flow[from];
                        if(sink_limit[par] > 0) iter[par]++;
                    }
                    continue;
                }
                while(iter[from] < (int)g[from].size()) {
                    auto& re = g[from][iter[from]];
                    auto& e = g[re.to][re.rev];
                    if(e.cap - e.flow == 0 || dist[re.to] >= dist[from]) {
                        iter[from]++;
                        continue;
                    }
                    assert(e.cap - e.flow > 0);
                    stk.push(re.to);
                    sink_limit[re.to] = min(sink_limit[from], e.cap - e.flow);
                    sink_flow[re.to] = 0;
                    break;
                }
            }
            if(sink_flow[t] == 0) break;
            res += sink_flow[t];
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
