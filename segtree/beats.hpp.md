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
    path: test/yosupo-range-chmin-chmax-add-range-sum.test.cpp
    title: test/yosupo-range-chmin-chmax-add-range-sum.test.cpp
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
    }\n#line 2 \"segtree/beats.hpp\"\n\ntemplate <typename S, S (*op)(S, S), S (*e)(),\
    \ typename F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\nstruct SegTreeBeats\
    \ {\nprotected:\n    int n, sz, height;\n    vector<S> state;\n    vector<F> lazy;\n\
    \    void update(int k) {\n        assert(0 <= k && k < sz);\n        state[k]\
    \ = op(state[k*2], state[k*2+1]);\n    }\n    void all_apply(int k, const F& f)\
    \ {\n        assert(0 <= k && k < sz*2);\n        state[k] = mapping(f, state[k]);\n\
    \        if(k < sz) {\n            lazy[k] = composition(f, lazy[k]);\n      \
    \      if(state[k].fail) {\n                push(k);\n                update(k);\n\
    \            }\n        }\n    }\n    void push(int k) {\n        assert(0 <=\
    \ k && k < sz);\n        all_apply(k*2, lazy[k]);\n        all_apply(k*2+1, lazy[k]);\n\
    \        lazy[k] = id();\n    }\npublic:\n    SegTreeBeats(int n = 0): n(n) {\n\
    \        assert(0 <= n);\n        sz = 1;\n        height = 0;\n        while(sz\
    \ < n) {\n            height++;\n            sz <<= 1;\n        }\n        state.assign(sz*2,\
    \ e());\n        lazy.assign(sz*2, id());\n    }\n    SegTreeBeats(const vector<S>&\
    \ v): n(v.size()) {\n        sz = 1;\n        height = 0;\n        while(sz <\
    \ n) {\n            height++;\n            sz <<= 1;\n        }\n        state.assign(sz*2,\
    \ e());\n        REP(i, v.size()) state[sz+i] = v[i];\n        for(int i = sz-1;\
    \ i > 0; i--) update(i);\n        lazy.assign(sz*2, id());\n    }\n    S get(int\
    \ i) {\n        assert(0 <= i && i < n);\n        i += sz;\n        for(int k\
    \ = height; k > 0; k--) {\n            push(i >> k);\n        }\n        return\
    \ state[i];\n    }\n    void set(int i, const S& x) {\n        assert(0 <= i &&\
    \ i < n);\n        i += sz;\n        for(int k = height; k > 0; k--) {\n     \
    \       push(i >> k);\n        }\n        state[i] = x;\n        while(i >>= 1)\
    \ update(i);\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        l += sz, r += sz;\n        for(int k = height; k > 0;\
    \ k--) {\n            if(((l >> k) << k) != l) push(l >> k);\n            if(((r\
    \ >> k) << k) != r) push(r >> k);\n        }\n        S left_prod = e(), right_prod\
    \ = e();\n        while(l < r) {\n            if(l & 1) left_prod = op(left_prod,\
    \ state[l++]);\n            if(r & 1) right_prod = op(state[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(left_prod,\
    \ right_prod);\n    }\n    void apply(int i, const F& f) {\n        assert(0 <=\
    \ i && i < n);\n        i += sz;\n        for(int k = height; k > 0; k--) push(i\
    \ >> k);\n        state[i] = mapping(f, state[i]);\n        while(i >>= 1) update(i);\n\
    \    }\n    void apply(int l, int r, const F& f) {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        if(l == r) return;\n        l += sz, r += sz;\n  \
    \      for(int k = height; k > 0; k--) {\n            if(((l >> k) << k) != l)\
    \ push(l >> k);\n            if(((r >> k) << k) != r) push(r >> k);\n        }\n\
    \        {\n            int l2 = l, r2 = r;\n            while(l < r) {\n    \
    \            if(l & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2, r = r2;\n        }\n        for(int k = 1; k <= height; k++)\
    \ {\n            if (((l >> k) << k) != l) update(l >> k);\n            if (((r\
    \ >> k) << k) != r) update((r-1) >> k);\n        }\n    }\n    template <typename\
    \ Judge>\n    int max_right(int l, Judge f) {\n        assert(0 <= l && l <= n);\n\
    \        assert(f(e()));\n        if(l == n) return n;\n        l += sz;\n   \
    \     for(int k = height; k > 0; k--) push(l >> k);\n        while(l % 2 == 0)\
    \ l >>= 1;\n        S sum = e();\n        while(f(op(sum, state[l]))) {\n    \
    \        if(__builtin_clz(l) != __builtin_clz(l+1)) return n;\n            sum\
    \ = op(sum, state[l]);\n            l++;\n            while(l % 2 == 0) l >>=\
    \ 1;\n        }\n        while(l < sz) {\n            push(l);\n            if(!f(op(sum,\
    \ state[l*2]))) l *= 2;\n            else {\n                sum = op(sum, state[l*2]);\n\
    \                l = l*2 + 1;\n            }\n        }\n        return l - sz;\n\
    \    }\n    template <typename Judge>\n    int min_left(int r, Judge f) {\n  \
    \      assert(0 <= r && r <= n);\n        assert(f(e()));\n        if(r == 0)\
    \ return 0;\n        r += sz-1;\n        for(int k = height; k > 0; k--) push(r\
    \ >> k);\n        while(r % 2 == 1) r >>= 1;\n        S sum = e();\n        while(f(op(state[r],\
    \ sum))) {\n            if(__builtin_clz(r) != __builtin_clz(r-1)) return 0;\n\
    \            sum = op(state[r], sum);\n            r--;\n            while(r %\
    \ 2 == 1) r >>= 1;\n        }\n        while(r < sz) {\n            push(r);\n\
    \            if(!f(op(state[r*2+1], sum))) r = r*2 + 1;\n            else {\n\
    \                sum = op(state[r*2+1], sum);\n                r = r*2;\n    \
    \        }\n        }\n        return r - sz + 1;\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\ntemplate <typename S, S (*op)(S, S), S (*e)(),\
    \ typename F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\nstruct SegTreeBeats\
    \ {\nprotected:\n    int n, sz, height;\n    vector<S> state;\n    vector<F> lazy;\n\
    \    void update(int k) {\n        assert(0 <= k && k < sz);\n        state[k]\
    \ = op(state[k*2], state[k*2+1]);\n    }\n    void all_apply(int k, const F& f)\
    \ {\n        assert(0 <= k && k < sz*2);\n        state[k] = mapping(f, state[k]);\n\
    \        if(k < sz) {\n            lazy[k] = composition(f, lazy[k]);\n      \
    \      if(state[k].fail) {\n                push(k);\n                update(k);\n\
    \            }\n        }\n    }\n    void push(int k) {\n        assert(0 <=\
    \ k && k < sz);\n        all_apply(k*2, lazy[k]);\n        all_apply(k*2+1, lazy[k]);\n\
    \        lazy[k] = id();\n    }\npublic:\n    SegTreeBeats(int n = 0): n(n) {\n\
    \        assert(0 <= n);\n        sz = 1;\n        height = 0;\n        while(sz\
    \ < n) {\n            height++;\n            sz <<= 1;\n        }\n        state.assign(sz*2,\
    \ e());\n        lazy.assign(sz*2, id());\n    }\n    SegTreeBeats(const vector<S>&\
    \ v): n(v.size()) {\n        sz = 1;\n        height = 0;\n        while(sz <\
    \ n) {\n            height++;\n            sz <<= 1;\n        }\n        state.assign(sz*2,\
    \ e());\n        REP(i, v.size()) state[sz+i] = v[i];\n        for(int i = sz-1;\
    \ i > 0; i--) update(i);\n        lazy.assign(sz*2, id());\n    }\n    S get(int\
    \ i) {\n        assert(0 <= i && i < n);\n        i += sz;\n        for(int k\
    \ = height; k > 0; k--) {\n            push(i >> k);\n        }\n        return\
    \ state[i];\n    }\n    void set(int i, const S& x) {\n        assert(0 <= i &&\
    \ i < n);\n        i += sz;\n        for(int k = height; k > 0; k--) {\n     \
    \       push(i >> k);\n        }\n        state[i] = x;\n        while(i >>= 1)\
    \ update(i);\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        l += sz, r += sz;\n        for(int k = height; k > 0;\
    \ k--) {\n            if(((l >> k) << k) != l) push(l >> k);\n            if(((r\
    \ >> k) << k) != r) push(r >> k);\n        }\n        S left_prod = e(), right_prod\
    \ = e();\n        while(l < r) {\n            if(l & 1) left_prod = op(left_prod,\
    \ state[l++]);\n            if(r & 1) right_prod = op(state[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(left_prod,\
    \ right_prod);\n    }\n    void apply(int i, const F& f) {\n        assert(0 <=\
    \ i && i < n);\n        i += sz;\n        for(int k = height; k > 0; k--) push(i\
    \ >> k);\n        state[i] = mapping(f, state[i]);\n        while(i >>= 1) update(i);\n\
    \    }\n    void apply(int l, int r, const F& f) {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        if(l == r) return;\n        l += sz, r += sz;\n  \
    \      for(int k = height; k > 0; k--) {\n            if(((l >> k) << k) != l)\
    \ push(l >> k);\n            if(((r >> k) << k) != r) push(r >> k);\n        }\n\
    \        {\n            int l2 = l, r2 = r;\n            while(l < r) {\n    \
    \            if(l & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2, r = r2;\n        }\n        for(int k = 1; k <= height; k++)\
    \ {\n            if (((l >> k) << k) != l) update(l >> k);\n            if (((r\
    \ >> k) << k) != r) update((r-1) >> k);\n        }\n    }\n    template <typename\
    \ Judge>\n    int max_right(int l, Judge f) {\n        assert(0 <= l && l <= n);\n\
    \        assert(f(e()));\n        if(l == n) return n;\n        l += sz;\n   \
    \     for(int k = height; k > 0; k--) push(l >> k);\n        while(l % 2 == 0)\
    \ l >>= 1;\n        S sum = e();\n        while(f(op(sum, state[l]))) {\n    \
    \        if(__builtin_clz(l) != __builtin_clz(l+1)) return n;\n            sum\
    \ = op(sum, state[l]);\n            l++;\n            while(l % 2 == 0) l >>=\
    \ 1;\n        }\n        while(l < sz) {\n            push(l);\n            if(!f(op(sum,\
    \ state[l*2]))) l *= 2;\n            else {\n                sum = op(sum, state[l*2]);\n\
    \                l = l*2 + 1;\n            }\n        }\n        return l - sz;\n\
    \    }\n    template <typename Judge>\n    int min_left(int r, Judge f) {\n  \
    \      assert(0 <= r && r <= n);\n        assert(f(e()));\n        if(r == 0)\
    \ return 0;\n        r += sz-1;\n        for(int k = height; k > 0; k--) push(r\
    \ >> k);\n        while(r % 2 == 1) r >>= 1;\n        S sum = e();\n        while(f(op(state[r],\
    \ sum))) {\n            if(__builtin_clz(r) != __builtin_clz(r-1)) return 0;\n\
    \            sum = op(state[r], sum);\n            r--;\n            while(r %\
    \ 2 == 1) r >>= 1;\n        }\n        while(r < sz) {\n            push(r);\n\
    \            if(!f(op(state[r*2+1], sum))) r = r*2 + 1;\n            else {\n\
    \                sum = op(state[r*2+1], sum);\n                r = r*2;\n    \
    \        }\n        }\n        return r - sz + 1;\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: segtree/beats.hpp
  requiredBy: []
  timestamp: '2022-12-20 05:12:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-range-chmin-chmax-add-range-sum.test.cpp
documentation_of: segtree/beats.hpp
layout: document
redirect_from:
- /library/segtree/beats.hpp
- /library/segtree/beats.hpp.html
title: segtree/beats.hpp
---
