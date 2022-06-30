---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: internal_operator.hpp
    title: internal_operator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AtCoder-abc185_f/main.test.cpp
    title: test/AtCoder-abc185_f/main.test.cpp
  - icon: ':x:'
    path: test/AtCoder-practice2_j/main.test.cpp
    title: test/AtCoder-practice2_j/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n\n#ifdef DEBUG\n#define _GLIBCXX_DEBUG\n#endif\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define REP(i, n) for(int\
    \ i = 0; i < (int)(n); i++)\n#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)\n\
    #define ALL(a) (a).begin(),(a).end()\n#define END(...) { print(__VA_ARGS__); return;\
    \ }\n\nusing VI = vector<int>;\nusing VVI = vector<VI>;\nusing VVVI = vector<VVI>;\n\
    using ll = long long;\nusing VL = vector<ll>;\nusing VVL = vector<VL>;\nusing\
    \ VVVL = vector<VVL>;\nusing VD = vector<double>;\nusing VVD = vector<VD>;\nusing\
    \ VVVD = vector<VVD>;\nusing VS = vector<string>;\nusing VVS = vector<VS>;\nusing\
    \ VVVS = vector<VVS>;\nusing VC = vector<char>;\nusing VVC = vector<VC>;\nusing\
    \ VVVC = vector<VVC>;\nusing P = pair<int, int>;\nusing VP = vector<P>;\nusing\
    \ VVP = vector<VP>;\nusing VVVP = vector<VVP>;\nusing LP = pair<ll, ll>;\nusing\
    \ VLP = vector<LP>;\nusing VVLP = vector<VLP>;\nusing VVVLP = vector<VVLP>;\n\n\
    template <typename T>\nusing PQ = priority_queue<T>;\ntemplate <typename T>\n\
    using GPQ = priority_queue<T, vector<T>, greater<T>>;\n\nconstexpr int INF = 1001001001;\n\
    constexpr ll LINF = 1001001001001001001ll;\nconstexpr int DX[] = {1, 0, -1, 0};\n\
    constexpr int DY[] = {0, 1, 0, -1};\n\nvoid print() { cout << '\\n'; }\ntemplate<typename\
    \ T>\nvoid print(const T &t) { cout << t << '\\n'; }\ntemplate<typename Head,\
    \ typename... Tail>\nvoid print(const Head &head, const Tail &... tail) {\n  \
    \  cout << head << ' ';\n    print(tail...);\n}\n\n#ifdef DEBUG\nvoid dbg() {\
    \ cerr << '\\n'; }\ntemplate<typename T>\nvoid dbg(const T &t) { cerr << t <<\
    \ '\\n'; }\ntemplate<typename Head, typename... Tail>\nvoid dbg(const Head &head,\
    \ const Tail &... tail) {\n    cerr << head << ' ';\n    dbg(tail...);\n}\n#else\n\
    template<typename... Args>\nvoid dbg(const Args &... args) {}\n#endif\n\ntemplate<\
    \ typename T1, typename T2 >\nostream &operator<<(ostream &os, const pair< T1,\
    \ T2 >& p) {\n    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate<\
    \ typename T1, typename T2 >\nistream &operator>>(istream &is, pair< T1, T2 >\
    \ &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate< typename\
    \ T >\nostream &operator<<(ostream &os, const vector< T > &v) {\n    for(int i\
    \ = 0; i < (int) v.size(); i++) {\n        os << v[i] << (i + 1 != (int) v.size()\
    \ ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate< typename T >\nistream\
    \ &operator>>(istream &is, vector< T > &v) {\n    for(T &in : v) is >> in;\n \
    \   return is;\n}\n\ntemplate<typename T>\nvector<vector<T>> split(typename vector<T>::const_iterator\
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
    }\n#line 3 \"internal_operator.hpp\"\n\nnamespace internal_operator {\n    template\
    \ <typename T>\n    T default_add(T a, T b) { return a + b; }\n    template <typename\
    \ T>\n    T default_sub(T a, T b) { return a - b; }\n    template <typename T>\n\
    \    T zero() { return T(0); }\n    template <typename T>\n    T default_div(T\
    \ a, T b) { return a / b; }\n    template <typename T>\n    T default_mult(T a,\
    \ T b) { return a * b; }\n    template <typename T>\n    T one() { return T(1);\
    \ }\n    template <typename T>\n    T default_xor(T a, T b) { return a ^ b; }\n\
    \    template <typename T>\n    T default_and(T a, T b) { return a & b; }\n  \
    \  template <typename T>\n    T default_or(T a, T b) { return a | b; }\n    ll\
    \ mod3() { return 998244353LL; }\n    ll mod7() { return 1000000007LL; }\n   \
    \ ll mod9() { return 1000000009LL; }\n    template <typename T>\n    T default_max(T\
    \ a, T b) { return max(a, b); }\n    template <typename T>\n    T default_min(T\
    \ a, T b) { return min(a, b); }\n}\n\n#line 2 \"segtree.hpp\"\n\ntemplate <typename\
    \ T, T (*func)(const T, const T), T (*e)()>\nstruct SegTree {\n    int n, sz;\n\
    \    vector<T> state;\n\n    SegTree(int n_): n(n_) {\n        sz = 1;\n     \
    \   while(sz < n) sz <<= 1;\n        state = vector<T>(sz*2, e());\n    }\n  \
    \  SegTree(vector<T> v): n(v.size()) {\n        sz = 1;\n        while(sz < n)\
    \ sz <<= 1;\n        state = vector<T>(sz*2, e());\n        REP(i, v.size()) state[sz+i]\
    \ = v[i];\n        for(int i = sz-1; i > 0; i--) state[i] = func(state[i*2], state[i*2+1]);\n\
    \    }\n\n    T operator[](int i) const {\n        assert(0 <= i && i < n);\n\
    \        return state[sz+i];\n    }\n    T get(int i) const {\n        assert(0\
    \ <= i && i < n);\n        return state[sz+i];\n    }\n\n    void set(int i, const\
    \ T &x) {\n        assert(0 <= i && i < n);\n        i += sz;\n        state[i]\
    \ = x;\n        while(i >>= 1) {\n            state[i] = func(state[i*2], state[i*2+1]);\n\
    \        }\n    }\n    void apply(int i, const T &x) {\n        set(i, x);\n \
    \   }\n\n    T prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        T left_prod = e(), right_prod = e();\n        l += sz, r +=\
    \ sz;\n        while(l < r) {\n            if(l & 1) left_prod = func(left_prod,\
    \ state[l++]);\n            if(r & 1) right_prod = func(state[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return func(left_prod,\
    \ right_prod);\n    }\n    \n    T all_prod() const {\n        return state[1];\n\
    \    }\n\n    template <typename F>\n    int max_right(int l, F f) {\n       \
    \ assert(0 <= l && l <= n);\n        assert(f(e()));\n        if(l == n) return\
    \ n;\n        l += sz;\n        while(l % 2 == 0) l >>= 1;\n        T sum = e();\n\
    \        while(f(func(sum, state[l]))) {\n            if(__builtin_clz(l) != __builtin_clz(l+1))\
    \ return n;\n            sum = func(sum, state[l]);\n            l++;\n      \
    \      while(l % 2 == 0) l >>= 1;\n        }\n        while(l < sz) {\n      \
    \      if(!f(func(sum, state[l*2]))) l *= 2;\n            else {\n           \
    \     sum = func(sum, state[l*2]);\n                l = l*2 + 1;\n           \
    \ }\n        }\n        return min(n, l - sz);\n    }\n};\n\ntemplate <typename\
    \ T>\nusing RMaxQ = SegTree<T, internal_operator::default_max<T>, numeric_limits<T>::min>;\n\
    template <typename T>\nusing RMinQ = SegTree<T, internal_operator::default_min<T>,\
    \ numeric_limits<T>::max>;\ntemplate <typename T>\nusing RSumQ = SegTree<T, internal_operator::default_add<T>,\
    \ internal_operator::zero<T>>;\n"
  code: "#include \"internal_operator.hpp\"\n\ntemplate <typename T, T (*func)(const\
    \ T, const T), T (*e)()>\nstruct SegTree {\n    int n, sz;\n    vector<T> state;\n\
    \n    SegTree(int n_): n(n_) {\n        sz = 1;\n        while(sz < n) sz <<=\
    \ 1;\n        state = vector<T>(sz*2, e());\n    }\n    SegTree(vector<T> v):\
    \ n(v.size()) {\n        sz = 1;\n        while(sz < n) sz <<= 1;\n        state\
    \ = vector<T>(sz*2, e());\n        REP(i, v.size()) state[sz+i] = v[i];\n    \
    \    for(int i = sz-1; i > 0; i--) state[i] = func(state[i*2], state[i*2+1]);\n\
    \    }\n\n    T operator[](int i) const {\n        assert(0 <= i && i < n);\n\
    \        return state[sz+i];\n    }\n    T get(int i) const {\n        assert(0\
    \ <= i && i < n);\n        return state[sz+i];\n    }\n\n    void set(int i, const\
    \ T &x) {\n        assert(0 <= i && i < n);\n        i += sz;\n        state[i]\
    \ = x;\n        while(i >>= 1) {\n            state[i] = func(state[i*2], state[i*2+1]);\n\
    \        }\n    }\n    void apply(int i, const T &x) {\n        set(i, x);\n \
    \   }\n\n    T prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        T left_prod = e(), right_prod = e();\n        l += sz, r +=\
    \ sz;\n        while(l < r) {\n            if(l & 1) left_prod = func(left_prod,\
    \ state[l++]);\n            if(r & 1) right_prod = func(state[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return func(left_prod,\
    \ right_prod);\n    }\n    \n    T all_prod() const {\n        return state[1];\n\
    \    }\n\n    template <typename F>\n    int max_right(int l, F f) {\n       \
    \ assert(0 <= l && l <= n);\n        assert(f(e()));\n        if(l == n) return\
    \ n;\n        l += sz;\n        while(l % 2 == 0) l >>= 1;\n        T sum = e();\n\
    \        while(f(func(sum, state[l]))) {\n            if(__builtin_clz(l) != __builtin_clz(l+1))\
    \ return n;\n            sum = func(sum, state[l]);\n            l++;\n      \
    \      while(l % 2 == 0) l >>= 1;\n        }\n        while(l < sz) {\n      \
    \      if(!f(func(sum, state[l*2]))) l *= 2;\n            else {\n           \
    \     sum = func(sum, state[l*2]);\n                l = l*2 + 1;\n           \
    \ }\n        }\n        return min(n, l - sz);\n    }\n};\n\ntemplate <typename\
    \ T>\nusing RMaxQ = SegTree<T, internal_operator::default_max<T>, numeric_limits<T>::min>;\n\
    template <typename T>\nusing RMinQ = SegTree<T, internal_operator::default_min<T>,\
    \ numeric_limits<T>::max>;\ntemplate <typename T>\nusing RSumQ = SegTree<T, internal_operator::default_add<T>,\
    \ internal_operator::zero<T>>;\n"
  dependsOn:
  - internal_operator.hpp
  - base.hpp
  isVerificationFile: false
  path: segtree.hpp
  requiredBy: []
  timestamp: '2022-06-21 20:28:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AtCoder-abc185_f/main.test.cpp
  - test/AtCoder-practice2_j/main.test.cpp
documentation_of: segtree.hpp
layout: document
redirect_from:
- /library/segtree.hpp
- /library/segtree.hpp.html
title: segtree.hpp
---
