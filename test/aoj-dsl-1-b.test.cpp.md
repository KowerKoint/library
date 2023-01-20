---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: connectivity/union-find.hpp
    title: connectivity/union-find.hpp
  - icon: ':heavy_check_mark:'
    path: stl-expansion.hpp
    title: stl-expansion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj-dsl-1-b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#line 2 \"stl-expansion.hpp\"\n#include <bits/stdc++.h>\n\ntemplate <typename\
    \ T1, typename T2>\nstd::istream& operator>>(std::istream& is, std::pair<T1, T2>&\
    \ p) {\n    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename\
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
    }\n#line 3 \"connectivity/union-find.hpp\"\n\ntemplate <typename Value=nullptr_t,\
    \ Value (*merge_value)(Value, Value)=nullptr, typename Potential=int>\nstruct\
    \ UnionFind {\n    int n;\n    VI par; // size if value is negative\n    vector<Value>\
    \ val;\n    vector<Potential> pot;\n    UnionFind(int n=0) : n(n), par(n, -1),\
    \ val(n), pot(n) {\n        assert(n >= 0);\n    }\n    int root(int x) {\n  \
    \      assert(0 <= x && x < n);\n        if(par[x] < 0) return x;\n        int\
    \ rt = root(par[x]);\n        pot[x] += pot[par[x]];\n        return par[x] =\
    \ rt;\n    }\n    Value get_value(int x) {\n        assert(0 <= x && x < n);\n\
    \        return val[root(x)];\n    }\n    void set_value(int x, Value v) {\n \
    \       assert(0 <= x && x < n);\n        val[root(x)] = v;\n    }\n    Potential\
    \ potential(int x) {\n        assert(0 <= x && x < n);\n        root(x);\n   \
    \     return pot[x];\n    }\n    Potential diff(int x, int y) {\n        assert(0\
    \ <= x && x < n);\n        assert(0 <= y && y < n);\n        return potential(y)\
    \ - potential(x);\n    }\n    int size(int x) {\n        assert(0 <= x && x <\
    \ n);\n        return -par[root(x)];\n    }\n    bool merge(int x, int y, Potential\
    \ p=0) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n\
    \        p += potential(x);\n        p -= potential(y);\n        x = root(x),\
    \ y = root(y);\n        if(x == y) return false;\n        if(par[x] > par[y])\
    \ {\n            swap(x, y);\n            p = -p;\n        }\n        par[x] +=\
    \ par[y];\n        par[y] = x;\n        if(merge_value != nullptr) val[x] = merge_value(val[x],\
    \ val[y]);\n        pot[y] = p;\n        return true;\n    }\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y <\
    \ n);\n        return root(x) == root(y);\n    }\n    VVI groups() {\n       \
    \ VVI res(n);\n        REP(i, n) {\n            res[root(i)].push_back(i);\n \
    \       }\n        sort(ALL(res), [](VI& a, VI& b) {\n            return a.size()\
    \ > b.size();\n        });\n        while(!res.empty() && res.back().empty())\
    \ res.pop_back();\n        return res;\n    }\n};\n\ntemplate <typename Potential>\n\
    using WeightedUnionFind = UnionFind<nullptr_t, nullptr, Potential>;\n#line 3 \"\
    test/aoj-dsl-1-b.test.cpp\"\n\nint main() {\n    int n, q; cin >> n >> q;\n  \
    \  WeightedUnionFind<int> uf(n);\n    while(q--) {\n        int cmd; cin >> cmd;\n\
    \        if(cmd == 0) {\n            int x, y, z; cin >> x >> y >> z;\n      \
    \      uf.merge(x, y, z);\n        } else {\n            int x, y; cin >> x >>\
    \ y;\n            if(uf.same(x, y)) print(uf.diff(x, y));\n            else print('?');\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include \"../connectivity/union-find.hpp\"\n\nint main() {\n    int n, q; cin\
    \ >> n >> q;\n    WeightedUnionFind<int> uf(n);\n    while(q--) {\n        int\
    \ cmd; cin >> cmd;\n        if(cmd == 0) {\n            int x, y, z; cin >> x\
    \ >> y >> z;\n            uf.merge(x, y, z);\n        } else {\n            int\
    \ x, y; cin >> x >> y;\n            if(uf.same(x, y)) print(uf.diff(x, y));\n\
    \            else print('?');\n        }\n    }\n}\n"
  dependsOn:
  - connectivity/union-find.hpp
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: true
  path: test/aoj-dsl-1-b.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 00:25:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-dsl-1-b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-dsl-1-b.test.cpp
- /verify/test/aoj-dsl-1-b.test.cpp.html
title: test/aoj-dsl-1-b.test.cpp
---
