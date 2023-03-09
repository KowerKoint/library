---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: stl-expansion.hpp
    title: stl-expansion.hpp
  - icon: ':heavy_check_mark:'
    path: structure/union-find.hpp
    title: structure/union-find.hpp
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
    }\n#line 3 \"structure/union-find.hpp\"\n\ntemplate<typename GroupValue_, typename\
    \ VertexValue_, typename VertexValueCoef_>\nstruct UnionFindData {\n    GroupValue_\
    \ group_value;\n    bool vertex_value_determined;\n    VertexValue_ vertex_value;\n\
    \    VertexValueCoef_ a;\n    VertexValue_ b;\n};\ntemplate<>\nstruct UnionFindData<nullptr_t,\
    \ nullptr_t, nullptr_t> {\n};\ntemplate<typename VertexValue_>\nstruct UnionFindData<nullptr_t,\
    \ VertexValue_, nullptr_t> {\n    bool vertex_value_determined;\n    VertexValue_\
    \ vertex_value;\n    VertexValue_ b;\n};\ntemplate<typename VertexValue_, typename\
    \ VertexValueCoef_>\nstruct UnionFindData<nullptr_t, VertexValue_, VertexValueCoef_>\
    \ {\n    bool vertex_value_determined;\n    VertexValue_ vertex_value;\n    VertexValueCoef_\
    \ a;\n    VertexValue_ b;\n};\ntemplate <typename GroupValue_>\nstruct UnionFindData<GroupValue_,\
    \ nullptr_t, nullptr_t> {\n    GroupValue_ group_value;\n};\ntemplate<typename\
    \ GroupValue_, typename VertexValue_>\nstruct UnionFindData<GroupValue_, VertexValue_,\
    \ nullptr_t> {\n    GroupValue_ group_value;\n    bool vertex_value_determined;\n\
    \    VertexValue_ vertex_value;\n    VertexValue_ b;\n};\n\ntemplate <typename\
    \ GroupValue=nullptr_t, typename MergeGroupValue=nullptr_t, typename VertexValue=nullptr_t,\
    \ typename VertexValueCoef = nullptr_t>\nclass UnionFind {\n    int _n;\n    VI\
    \ _par; //size if value is negative\n    vector<UnionFindData<GroupValue, VertexValue,\
    \ VertexValueCoef>> _data;\n    MergeGroupValue _merge_group_value;\n\npublic:\n\
    \    UnionFind(int n=0) : _n(n), _par(n, -1), _data(n) {\n        for(auto &d\
    \ : _data) {\n            if constexpr(!is_same_v<VertexValue, nullptr_t>) {\n\
    \                d.vertex_value_determined = false;\n                d.b = 0;\n\
    \                if constexpr(!is_same_v<VertexValueCoef, nullptr_t>) {\n    \
    \                d.a = 1;\n                }\n            }\n        }\n    }\n\
    \    int root(int x) {\n        if (_par[x] < 0) return x;\n        int r = root(_par[x]);\n\
    \        if constexpr (!is_same_v<VertexValue, nullptr_t>) {\n            if constexpr\
    \ (is_same_v<VertexValueCoef, nullptr_t>) {\n                _data[x].b += _data[_par[x]].b;\n\
    \            } else {\n                _data[x].b =_data[x].a * _data[_par[x]].b\
    \ + _data[x].b;\n                _data[x].a *= _data[_par[x]].a;\n           \
    \ }\n        }\n        return _par[x] = r;\n    }\n    GroupValue get_group_value(int\
    \ x) {\n        return _data[root(x)].group_value;\n    }\n    void set_group_value(int\
    \ x, GroupValue v) {\n        _data[root(x)].group_value = v;\n    }\n    pair<bool,\
    \ VertexValue> get_vertex_value(int x) {\n        int r = root(x);\n        if(!_data[r].vertex_value_determined)\
    \ return {false, {}};\n        if constexpr (is_same_v<VertexValueCoef, nullptr_t>)\
    \ {\n            return {true, _data[r].vertex_value + _data[x].b};\n        }\
    \ else {\n            return {true, _data[x].a * _data[r].vertex_value + _data[x].b};\n\
    \        }\n    }\n    bool set_vertex_value(int x, VertexValue v) {\n       \
    \ auto [determined, old] = get_vertex_value(x);\n        if(determined) return\
    \ old == v;\n        int r = root(x);\n        _data[r].vertex_value_determined\
    \ = true;\n        _data[r].vertex_value = (v - _data[x].b) / _data[x].a;\n  \
    \      return true;\n    }\n    int size(int x) {\n        return -_par[root(x)];\n\
    \    }\n    bool merge(int x, int y) {\n        static_assert(is_same_v<VertexValue,\
    \ nullptr_t>);\n        x = root(x);\n        y = root(y);\n        if (x == y)\
    \ return false;\n        if (_par[x] > _par[y]) swap(x, y);\n        _par[x] +=\
    \ _par[y];\n        _par[y] = x;\n        if constexpr (!is_same_v<GroupValue,\
    \ nullptr_t>) {\n            _data[x].group_value = _merge_group_value(_data[x].group_value,\
    \ _data[y].group_value);\n        }\n        return true;\n    }\n    pair<bool,\
    \ bool> merge(int x, int y, VertexValue b) {\n        static_assert(!is_same_v<VertexValue,\
    \ nullptr_t>);\n        static_assert(is_same_v<VertexValueCoef, nullptr_t>);\n\
    \        int rx = root(x);\n        int ry = root(y);\n        if (rx == ry) {\n\
    \            if(_data[x].b + b != _data[y].b) return {false, false};\n       \
    \     return {true, false};\n        }\n        b += _data[x].b;\n        b -=\
    \ _data[y].b;\n        x = rx, y = ry;\n        if (_par[x] > _par[y]) {\n   \
    \         swap(x, y);\n            b = -b;\n        }\n        if(_data[y].vertex_value_determined)\
    \ {\n            if(_data[x].vertex_value_determined) {\n                if(_data[x].vertex_value\
    \ + b != _data[y].vertex_value) return {false, false};\n            } else {\n\
    \                _data[x].vertex_value_determined = true;\n                _data[x].vertex_value\
    \ = _data[y].vertex_value - b;\n            }\n        }\n        _par[x] += _par[y];\n\
    \        _par[y] = x;\n        if constexpr (!is_same_v<GroupValue, nullptr_t>)\
    \ {\n            _data[x].group_value = _merge_group_value(_data[x].group_value,\
    \ _data[y].group_value);\n        }\n        _data[y].b = b;\n        return {true,\
    \ true};\n    }\n    pair<bool, bool> merge(int x, int y, VertexValueCoef a, VertexValue\
    \ b) {\n        static_assert(!is_same_v<VertexValue, nullptr_t>);\n        static_assert(!is_same_v<VertexValueCoef,\
    \ nullptr_t>);\n        int rx = root(x);\n        int ry = root(y);\n       \
    \ if (rx == ry) {\n            VertexValueCoef a1 = a * _data[x].a - _data[y].a;\n\
    \            VertexValue b1 = a * _data[x].b + b - _data[y].b;\n            if(a1\
    \ == 0) {\n                if(b1 != 0) return {false, false};\n            } else\
    \ if(_data[rx].vertex_value_determined) {\n                if(a1 * _data[rx].vertex_value\
    \ + b1 != 0) return {false, false};\n            } else {\n                _data[rx].vertex_value_determined\
    \ = true;\n                _data[rx].vertex_value = -b1 / a1;\n            }\n\
    \            return {true, false};\n        }\n        b = a * _data[x].b + b;\n\
    \        a *= _data[x].a;\n        b = (b - _data[y].b) / _data[y].a;\n      \
    \  a /= _data[y].a;\n        x = rx, y = ry;\n        if (_par[x] > _par[y]) {\n\
    \            swap(x, y);\n            a = 1 / a;\n            b *= -a;\n     \
    \   }\n        if(_data[y].vertex_value_determined) {\n            if(_data[x].vertex_value_determined)\
    \ {\n                if(a * _data[x].vertex_value + b != _data[y].vertex_value)\
    \ return {false, false};\n            } else {\n                _data[x].vertex_value_determined\
    \ = true;\n                _data[x].vertex_value = (_data[y].vertex_value - b)\
    \ / a;\n            }\n        }\n        _par[x] += _par[y];\n        _par[y]\
    \ = x;\n        if constexpr (!is_same_v<GroupValue, nullptr_t>) {\n         \
    \   _data[x].group_value = _merge_group_value(_data[x].group_value, _data[y].group_value);\n\
    \        }\n        _data[y].a = a;\n        _data[y].b = b;\n        return {true,\
    \ true};\n    }\n    bool same(int x, int y) {\n        return root(x) == root(y);\n\
    \    }\n    VertexValue diff(int x, int y) {\n        static_assert(!is_same_v<VertexValue,\
    \ nullptr_t>);\n        static_assert(is_same_v<VertexValueCoef, nullptr_t>);\n\
    \        assert(root(x) == root(y));\n        return _data[y].b - _data[x].b;\n\
    \    }\n    pair<VertexValueCoef, VertexValue> relation(int x, int y) {\n    \
    \    static_assert(!is_same_v<VertexValue, nullptr_t>);\n        static_assert(!is_same_v<VertexValueCoef,\
    \ nullptr_t>);\n        assert(root(x) == root(y));\n        VertexValueCoef a\
    \ = _data[y].a / _data[x].a;\n        VertexValue b = _data[y].b - a * _data[x].b;\n\
    \        return {a, b};\n    }\n    VVI groups() {\n        VVI res(_n);\n   \
    \     REP(i, _n) {\n            res[root(i)].push_back(i);\n        }\n      \
    \  sort(ALL(res), [](const VI &a, const VI &b) { return a.size() > b.size(); });\n\
    \        while (res.size() && res.back().empty()) res.pop_back();\n        return\
    \ res;\n    }\n};\n\ntemplate <typename Potential>\nusing PotentialUnionFind =\
    \ UnionFind<nullptr_t, nullptr_t, Potential>;\ntemplate <typename Coef, typename\
    \ Potential>\nusing RelationUnionFind = UnionFind<nullptr_t, nullptr_t, Potential,\
    \ Coef>;\n#line 3 \"test/aoj-dsl-1-b.test.cpp\"\n\nint main() {\n    int n, q;\
    \ cin >> n >> q;\n    PotentialUnionFind<int> uf(n);\n    while(q--) {\n     \
    \   int cmd; cin >> cmd;\n        if(cmd == 0) {\n            int x, y, z; cin\
    \ >> x >> y >> z;\n            uf.merge(x, y, z);\n        } else {\n        \
    \    int x, y; cin >> x >> y;\n            if(uf.same(x, y)) print(uf.diff(x,\
    \ y));\n            else print('?');\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include \"../structure/union-find.hpp\"\n\nint main() {\n    int n, q; cin\
    \ >> n >> q;\n    PotentialUnionFind<int> uf(n);\n    while(q--) {\n        int\
    \ cmd; cin >> cmd;\n        if(cmd == 0) {\n            int x, y, z; cin >> x\
    \ >> y >> z;\n            uf.merge(x, y, z);\n        } else {\n            int\
    \ x, y; cin >> x >> y;\n            if(uf.same(x, y)) print(uf.diff(x, y));\n\
    \            else print('?');\n        }\n    }\n}\n"
  dependsOn:
  - structure/union-find.hpp
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: true
  path: test/aoj-dsl-1-b.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 07:30:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-dsl-1-b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-dsl-1-b.test.cpp
- /verify/test/aoj-dsl-1-b.test.cpp.html
title: test/aoj-dsl-1-b.test.cpp
---
