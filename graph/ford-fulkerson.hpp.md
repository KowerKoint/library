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
    path: test/aoj-grl-6-a.test.cpp
    title: test/aoj-grl-6-a.test.cpp
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
    }\n#line 3 \"graph/ford-fulkerson.hpp\"\n\ntemplate <typename T=int>\nstruct FordFulkersonEdge\
    \ {\n    int to;\n    T cap, flow;\n    int rev;\n    bool is_rev;\n    FordFulkersonEdge(int\
    \ to, T cap, int rev, bool is_rev) : to(to), cap(cap), flow(0), rev(rev), is_rev(is_rev){}\n\
    };\n\ntemplate <typename T=int>\nstruct FordFulkersonGraph {\n    int n;\n   \
    \ vector<vector<FordFulkersonEdge<T>>> g;\n    FordFulkersonGraph(int n_ = 0)\
    \ : n(n_), g(n_) {\n        assert(n_ >= 0);\n    }\n    void add_edge(int from,\
    \ int to, T cap) {\n        assert(0 <= from && from < n);\n        assert(0 <=\
    \ to && to < n);\n        assert(cap >= 0);\n        assert(from != to);\n   \
    \     FordFulkersonEdge<T> e(to, cap, g[to].size(), false);\n        FordFulkersonEdge<T>\
    \ re(from, 0, g[from].size(), true);\n        g[from].push_back(e);\n        g[to].push_back(re);\n\
    \    }\n    T max_flow(int s, int t) {\n        assert(0 <= s && s < n);\n   \
    \     assert(0 <= t && t < n);\n        assert(s != t);\n        T res = 0;\n\
    \        while (true) {\n            VI seen(n);\n            VI processed(n);\n\
    \            VI pre(n);\n            stack<pair<int, T>> stk;\n            seen[s]\
    \ = 1;\n            stk.emplace(s, numeric_limits<T>::max());\n            T flow\
    \ = 0;\n            while(!stk.empty()) {\n                auto [from, f] = stk.top();\
    \ stk.pop();\n                seen[from] = 1;\n                if(from == t) {\n\
    \                    flow = f;\n                    continue;\n              \
    \  }\n                for(int i = 0; i < g[from].size(); i++) {\n            \
    \        auto& e = g[from][i];\n                    if(seen[e.to]) continue;\n\
    \                    if(e.cap - e.flow == 0) continue;\n                    seen[e.to]\
    \ = 1;\n                    pre[e.to] = e.rev;\n                    stk.emplace(e.to,\
    \ min(f, e.cap - e.flow));\n                }\n            }\n            if(flow\
    \ == 0) break;\n            int cur = t;\n            while(cur != s) {\n    \
    \            auto& re = g[cur][pre[cur]];\n                auto& e = g[re.to][re.rev];\n\
    \                e.flow += flow;\n                re.flow -= flow;\n         \
    \       cur = re.to;\n            }\n            res += flow;\n        }\n   \
    \     return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate <typename T=int>\nstruct\
    \ FordFulkersonEdge {\n    int to;\n    T cap, flow;\n    int rev;\n    bool is_rev;\n\
    \    FordFulkersonEdge(int to, T cap, int rev, bool is_rev) : to(to), cap(cap),\
    \ flow(0), rev(rev), is_rev(is_rev){}\n};\n\ntemplate <typename T=int>\nstruct\
    \ FordFulkersonGraph {\n    int n;\n    vector<vector<FordFulkersonEdge<T>>> g;\n\
    \    FordFulkersonGraph(int n_ = 0) : n(n_), g(n_) {\n        assert(n_ >= 0);\n\
    \    }\n    void add_edge(int from, int to, T cap) {\n        assert(0 <= from\
    \ && from < n);\n        assert(0 <= to && to < n);\n        assert(cap >= 0);\n\
    \        assert(from != to);\n        FordFulkersonEdge<T> e(to, cap, g[to].size(),\
    \ false);\n        FordFulkersonEdge<T> re(from, 0, g[from].size(), true);\n \
    \       g[from].push_back(e);\n        g[to].push_back(re);\n    }\n    T max_flow(int\
    \ s, int t) {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t <\
    \ n);\n        assert(s != t);\n        T res = 0;\n        while (true) {\n \
    \           VI seen(n);\n            VI processed(n);\n            VI pre(n);\n\
    \            stack<pair<int, T>> stk;\n            seen[s] = 1;\n            stk.emplace(s,\
    \ numeric_limits<T>::max());\n            T flow = 0;\n            while(!stk.empty())\
    \ {\n                auto [from, f] = stk.top(); stk.pop();\n                seen[from]\
    \ = 1;\n                if(from == t) {\n                    flow = f;\n     \
    \               continue;\n                }\n                for(int i = 0; i\
    \ < g[from].size(); i++) {\n                    auto& e = g[from][i];\n      \
    \              if(seen[e.to]) continue;\n                    if(e.cap - e.flow\
    \ == 0) continue;\n                    seen[e.to] = 1;\n                    pre[e.to]\
    \ = e.rev;\n                    stk.emplace(e.to, min(f, e.cap - e.flow));\n \
    \               }\n            }\n            if(flow == 0) break;\n         \
    \   int cur = t;\n            while(cur != s) {\n                auto& re = g[cur][pre[cur]];\n\
    \                auto& e = g[re.to][re.rev];\n                e.flow += flow;\n\
    \                re.flow -= flow;\n                cur = re.to;\n            }\n\
    \            res += flow;\n        }\n        return res;\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: graph/ford-fulkerson.hpp
  requiredBy: []
  timestamp: '2022-12-18 23:57:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-6-a.test.cpp
documentation_of: graph/ford-fulkerson.hpp
layout: document
redirect_from:
- /library/graph/ford-fulkerson.hpp
- /library/graph/ford-fulkerson.hpp.html
title: graph/ford-fulkerson.hpp
---
