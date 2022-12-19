---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: stl-expansion.hpp
    title: stl-expansion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-6-b.test.cpp
    title: test/aoj-grl-6-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"stl-expansion.hpp\"\n#include <bits/stdc++.h>\n\ntemplate\
    \ <typename T1, typename T2>\nstd::istream& operator>>(std::istream& is, std::pair<T1,\
    \ T2>& p) {\n    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename\
    \ T, size_t N>\nstd::istream& operator>>(std::istream& is, std::array<T, N>& a)\
    \ {\n    for (size_t i = 0; i < N; ++i) {\n        is >> a[i];\n    }\n    return\
    \ is;\n}\ntemplate <typename T>\nstd::istream& operator>>(std::istream& is, std::vector<T>&\
    \ v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream& operator<<(std::ostream& os, const std::pair<T1,\
    \ T2>& p) {\n    os << p.first << \" \" << p.second;\n    return os;\n}\ntemplate\
    \ <typename T, size_t N>\nstd::ostream& operator<<(std::ostream& os, const std::array<T,\
    \ N>& a) {\n    for (size_t i = 0; i < N; ++i) {\n        os << a[i] << (i + 1\
    \ == a.size() ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T>\n\
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {\n    for\
    \ (size_t i = 0; i < v.size(); ++i) {\n        os << v[i] << (i + 1 == v.size()\
    \ ? \"\" : \" \");\n    }\n    return os;\n}\n#line 3 \"base.hpp\"\nusing namespace\
    \ std;\n\n#define REP(i, n) for(int i = 0; i < (int)(n); i++)\n#define FOR(i,\
    \ a, b) for(ll i = a; i < (ll)(b); i++)\n#define ALL(a) (a).begin(),(a).end()\n\
    #define RALL(a) (a).rbegin(),(a).rend()\n#define END(...) { print(__VA_ARGS__);\
    \ return; }\n\nusing VI = vector<int>;\nusing VVI = vector<VI>;\nusing VVVI =\
    \ vector<VVI>;\nusing ll = long long;\nusing VL = vector<ll>;\nusing VVL = vector<VL>;\n\
    using VVVL = vector<VVL>;\nusing ull = unsigned long long;\nusing VUL = vector<ull>;\n\
    using VVUL = vector<VUL>;\nusing VVVUL = vector<VVUL>;\nusing VD = vector<double>;\n\
    using VVD = vector<VD>;\nusing VVVD = vector<VVD>;\nusing VS = vector<string>;\n\
    using VVS = vector<VS>;\nusing VVVS = vector<VVS>;\nusing VC = vector<char>;\n\
    using VVC = vector<VC>;\nusing VVVC = vector<VVC>;\nusing P = pair<int, int>;\n\
    using VP = vector<P>;\nusing VVP = vector<VP>;\nusing VVVP = vector<VVP>;\nusing\
    \ LP = pair<ll, ll>;\nusing VLP = vector<LP>;\nusing VVLP = vector<VLP>;\nusing\
    \ VVVLP = vector<VVLP>;\n\ntemplate <typename T>\nusing PQ = priority_queue<T>;\n\
    template <typename T>\nusing GPQ = priority_queue<T, vector<T>, greater<T>>;\n\
    \nconstexpr int INF = 1001001001;\nconstexpr ll LINF = 1001001001001001001ll;\n\
    constexpr int DX[] = {1, 0, -1, 0};\nconstexpr int DY[] = {0, 1, 0, -1};\n\nvoid\
    \ print() { cout << '\\n'; }\ntemplate<typename T>\nvoid print(const T &t) { cout\
    \ << t << '\\n'; }\ntemplate<typename Head, typename... Tail>\nvoid print(const\
    \ Head &head, const Tail &... tail) {\n    cout << head << ' ';\n    print(tail...);\n\
    }\n\n#ifdef DEBUG\nvoid dbg() { cerr << '\\n'; }\ntemplate<typename T>\nvoid dbg(const\
    \ T &t) { cerr << t << '\\n'; }\ntemplate<typename Head, typename... Tail>\nvoid\
    \ dbg(const Head &head, const Tail &... tail) {\n    cerr << head << ' ';\n  \
    \  dbg(tail...);\n}\n#else\ntemplate<typename... Args>\nvoid dbg(const Args &...\
    \ args) {}\n#endif\n\ntemplate<typename T>\nvector<vector<T>> split(typename vector<T>::const_iterator\
    \ begin, typename vector<T>::const_iterator end, T val) {\n    vector<vector<T>>\
    \ res;\n    vector<T> cur;\n    for(auto it = begin; it != end; it++) {\n    \
    \    if(*it == val) {\n            res.push_back(cur);\n            cur.clear();\n\
    \        } else cur.push_back(*it);\n    }\n    res.push_back(cur);\n    return\
    \ res;\n}\n\nvector<string> split(typename string::const_iterator begin, typename\
    \ string::const_iterator end, char val) {\n    vector<string> res;\n    string\
    \ cur = \"\";\n    for(auto it = begin; it != end; it++) {\n        if(*it ==\
    \ val) {\n            res.push_back(cur);\n            cur.clear();\n        }\
    \ else cur.push_back(*it);\n    }\n    res.push_back(cur);\n    return res;\n\
    }\n\ntemplate< typename T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return\
    \ a < b && (a = b, true); }\n\ntemplate< typename T1, typename T2 >\ninline bool\
    \ chmin(T1 &a, T2 b) { return a > b && (a = b, true); }\n\ntemplate <typename\
    \ T>\npair<VI, vector<T>> compress(const vector<T> &a) {\n    int n = a.size();\n\
    \    vector<T> x;\n    REP(i, n) x.push_back(a[i]);\n    sort(ALL(x)); x.erase(unique(ALL(x)),\
    \ x.end());\n    VI res(n);\n    REP(i, n) res[i] = lower_bound(ALL(x), a[i])\
    \ - x.begin();\n    return make_pair(res, x);\n}\n\ntemplate <typename It>\nauto\
    \ rle(It begin, It end) {\n    vector<pair<typename It::value_type, int>> res;\n\
    \    if(begin == end) return res;\n    auto pre = *begin;\n    int num = 1;\n\
    \    for(auto it = begin + 1; it != end; it++) {\n        if(pre != *it) {\n \
    \           res.emplace_back(pre, num);\n            pre = *it;\n            num\
    \ = 1;\n        } else num++;\n    }\n    res.emplace_back(pre, num);\n    return\
    \ res;\n}\n\ntemplate <typename It>\nvector<pair<typename It::value_type, int>>\
    \ rle_sort(It begin, It end) {\n    vector<typename It::value_type> cloned(begin,\
    \ end);\n    sort(ALL(cloned));\n    auto e = rle(ALL(cloned));\n    sort(ALL(e),\
    \ [](const auto& l, const auto& r) { return l.second < r.second; });\n    return\
    \ e;\n}\n\ntemplate <typename T>\npair<vector<T>, vector<T>> factorial(int n)\
    \ {\n    vector<T> res(n+1), rev(n+1);\n    res[0] = 1;\n    REP(i, n) res[i+1]\
    \ = res[i] * (i+1);\n    rev[n] = 1 / res[n];\n    for(int i = n; i > 0; i--)\
    \ {\n        rev[i-1] = rev[i] * i;\n    }\n    return make_pair(res, rev);\n\
    }\n#line 3 \"graph/min-cost-flow.hpp\"\n\ntemplate <typename T=int>\nstruct MinCostFlowEdge\
    \ {\n    int to;\n    T cap, cost, flow;\n    int rev;\n    bool is_rev;\n   \
    \ MinCostFlowEdge(int to, T cap, T cost, int rev, bool is_rev)\n        : to(to),\
    \ cap(cap), cost(cost), flow(0), rev(rev), is_rev(is_rev) {}\n};\n\ntemplate <typename\
    \ T=int>\nstruct MinCostFlowGraph {\n    int n;\n    vector<vector<MinCostFlowEdge<T>>>\
    \ g;\n    vector<T> h;\n    MinCostFlowGraph(int n) : n(n), g(n), h(n) {\n   \
    \     static_assert(is_integral<T>::value);\n        assert(n > 0);\n    }\n \
    \   void add_edge(int from, int to, T cap, T cost) {\n        assert(0 <= from\
    \ && from < n && 0 <= to && to < n);\n        assert(cap >= 0);\n        assert(cost\
    \ >= 0);\n        MinCostFlowEdge<T> e(to, cap, cost, g[to].size(), false);\n\
    \        MinCostFlowEdge<T> re(from, 0, -cost, g[from].size(), true);\n      \
    \  g[from].push_back(e);\n        g[to].push_back(re);\n    }\n    pair<T, T>\
    \ min_cost_one_flow(int s, int t, T f=numeric_limits<T>::max()) {\n        assert(0\
    \ <= s && s < n && 0 <= t && t < n);\n        assert(s != t);\n        vector<T>\
    \ dist(n, numeric_limits<T>::max());\n        dist[s] = 0;\n        vector<int>\
    \ pre(n);\n        GPQ<pair<T, int>> pq;\n        pq.emplace(0, s);\n        while(!pq.empty())\
    \ {\n            auto [d, u] = pq.top(); pq.pop();\n            if(dist[u] < d)\
    \ continue;\n            REP(i, g[u].size()) {\n                auto& e = g[u][i];\n\
    \                if(e.cap > e.flow && chmin(dist[e.to], dist[u] + e.cost + h[u]\
    \ - h[e.to])) {\n                    pre[e.to] = e.rev;\n                    pq.emplace(dist[e.to],\
    \ e.to);\n                }\n            }\n        }\n        if(dist[t] == numeric_limits<T>::max())\
    \ return {0, 0};\n        REP(i, n) h[i] += dist[i];\n        for(int u = t; u\
    \ != s; u = g[u][pre[u]].to) {\n            auto& e = g[g[u][pre[u]].to][g[u][pre[u]].rev];\n\
    \            chmin(f, e.cap - e.flow);\n        }\n        for(int u = t; u !=\
    \ s; u = g[u][pre[u]].to) {\n            auto& e = g[g[u][pre[u]].to][g[u][pre[u]].rev];\n\
    \            e.flow += f;\n            g[u][pre[u]].flow -= f;\n        }\n  \
    \      return {f, f * (h[t] - h[s])};\n    }\n    pair<T, T> min_cost_flow(int\
    \ s, int t, T f) {\n        assert(0 <= s && s < n && 0 <= t && t < n);\n    \
    \    assert(s != t);\n        T flow = 0, cost = 0;\n        while(f > 0) {\n\
    \            auto [cur_flow, cur_cost] = min_cost_one_flow(s, t, f);\n       \
    \     if(cur_flow == 0) break;\n            flow += cur_flow;\n            cost\
    \ += cur_cost;\n            f -= cur_flow;\n        }\n        return {flow, cost};\n\
    \    }\n    vector<pair<T, T>> min_cost_slope(int s, int t, T f = numeric_limits<T>::max())\
    \ {\n        assert(0 <= s && s < n && 0 <= t && t < n);\n        assert(s !=\
    \ t);\n        vector<pair<T, T>> res;\n        res.emplace_back(0, 0);\n    \
    \    T flow = 0, cost = 0;\n        pair<T, T> prev_rate = {0, 0};\n        while(f\
    \ > 0) {\n            auto [cur_flow, cur_cost] = min_cost_one_flow(s, t, f);\n\
    \            if(cur_flow == 0) break;\n            flow += cur_flow;\n       \
    \     cost += cur_cost;\n            f -= cur_flow;\n            T g = gcd(cur_cost,\
    \ cur_flow);\n            if(prev_rate == make_pair(cur_cost / g, cur_flow / g))\
    \ {\n                res.pop_back();\n            } else {\n                prev_rate\
    \ = {cur_cost / g, cur_flow / g};\n            }\n            res.emplace_back(flow,\
    \ cost);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate <typename T=int>\nstruct\
    \ MinCostFlowEdge {\n    int to;\n    T cap, cost, flow;\n    int rev;\n    bool\
    \ is_rev;\n    MinCostFlowEdge(int to, T cap, T cost, int rev, bool is_rev)\n\
    \        : to(to), cap(cap), cost(cost), flow(0), rev(rev), is_rev(is_rev) {}\n\
    };\n\ntemplate <typename T=int>\nstruct MinCostFlowGraph {\n    int n;\n    vector<vector<MinCostFlowEdge<T>>>\
    \ g;\n    vector<T> h;\n    MinCostFlowGraph(int n) : n(n), g(n), h(n) {\n   \
    \     static_assert(is_integral<T>::value);\n        assert(n > 0);\n    }\n \
    \   void add_edge(int from, int to, T cap, T cost) {\n        assert(0 <= from\
    \ && from < n && 0 <= to && to < n);\n        assert(cap >= 0);\n        assert(cost\
    \ >= 0);\n        MinCostFlowEdge<T> e(to, cap, cost, g[to].size(), false);\n\
    \        MinCostFlowEdge<T> re(from, 0, -cost, g[from].size(), true);\n      \
    \  g[from].push_back(e);\n        g[to].push_back(re);\n    }\n    pair<T, T>\
    \ min_cost_one_flow(int s, int t, T f=numeric_limits<T>::max()) {\n        assert(0\
    \ <= s && s < n && 0 <= t && t < n);\n        assert(s != t);\n        vector<T>\
    \ dist(n, numeric_limits<T>::max());\n        dist[s] = 0;\n        vector<int>\
    \ pre(n);\n        GPQ<pair<T, int>> pq;\n        pq.emplace(0, s);\n        while(!pq.empty())\
    \ {\n            auto [d, u] = pq.top(); pq.pop();\n            if(dist[u] < d)\
    \ continue;\n            REP(i, g[u].size()) {\n                auto& e = g[u][i];\n\
    \                if(e.cap > e.flow && chmin(dist[e.to], dist[u] + e.cost + h[u]\
    \ - h[e.to])) {\n                    pre[e.to] = e.rev;\n                    pq.emplace(dist[e.to],\
    \ e.to);\n                }\n            }\n        }\n        if(dist[t] == numeric_limits<T>::max())\
    \ return {0, 0};\n        REP(i, n) h[i] += dist[i];\n        for(int u = t; u\
    \ != s; u = g[u][pre[u]].to) {\n            auto& e = g[g[u][pre[u]].to][g[u][pre[u]].rev];\n\
    \            chmin(f, e.cap - e.flow);\n        }\n        for(int u = t; u !=\
    \ s; u = g[u][pre[u]].to) {\n            auto& e = g[g[u][pre[u]].to][g[u][pre[u]].rev];\n\
    \            e.flow += f;\n            g[u][pre[u]].flow -= f;\n        }\n  \
    \      return {f, f * (h[t] - h[s])};\n    }\n    pair<T, T> min_cost_flow(int\
    \ s, int t, T f) {\n        assert(0 <= s && s < n && 0 <= t && t < n);\n    \
    \    assert(s != t);\n        T flow = 0, cost = 0;\n        while(f > 0) {\n\
    \            auto [cur_flow, cur_cost] = min_cost_one_flow(s, t, f);\n       \
    \     if(cur_flow == 0) break;\n            flow += cur_flow;\n            cost\
    \ += cur_cost;\n            f -= cur_flow;\n        }\n        return {flow, cost};\n\
    \    }\n    vector<pair<T, T>> min_cost_slope(int s, int t, T f = numeric_limits<T>::max())\
    \ {\n        assert(0 <= s && s < n && 0 <= t && t < n);\n        assert(s !=\
    \ t);\n        vector<pair<T, T>> res;\n        res.emplace_back(0, 0);\n    \
    \    T flow = 0, cost = 0;\n        pair<T, T> prev_rate = {0, 0};\n        while(f\
    \ > 0) {\n            auto [cur_flow, cur_cost] = min_cost_one_flow(s, t, f);\n\
    \            if(cur_flow == 0) break;\n            flow += cur_flow;\n       \
    \     cost += cur_cost;\n            f -= cur_flow;\n            T g = gcd(cur_cost,\
    \ cur_flow);\n            if(prev_rate == make_pair(cur_cost / g, cur_flow / g))\
    \ {\n                res.pop_back();\n            } else {\n                prev_rate\
    \ = {cur_cost / g, cur_flow / g};\n            }\n            res.emplace_back(flow,\
    \ cost);\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: graph/min-cost-flow.hpp
  requiredBy: []
  timestamp: '2022-12-20 07:37:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-6-b.test.cpp
documentation_of: graph/min-cost-flow.hpp
layout: document
redirect_from:
- /library/graph/min-cost-flow.hpp
- /library/graph/min-cost-flow.hpp.html
title: graph/min-cost-flow.hpp
---
