---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: general.hpp
    title: general.hpp
  - icon: ':question:'
    path: modint.hpp
    title: modint.hpp
  - icon: ':x:'
    path: string.hpp
    title: string.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ-ALDS_1_14_B/main.test.cpp
    title: test/AOJ-ALDS_1_14_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-ALDS_1_1_C/main.test.cpp
    title: test/AOJ-ALDS_1_1_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_A/main.test.cpp
    title: test/AOJ-DPL_5_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_B/main.test.cpp
    title: test/AOJ-DPL_5_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_C/main.test.cpp
    title: test/AOJ-DPL_5_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_D/main.test.cpp
    title: test/AOJ-DPL_5_D/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_E/main.test.cpp
    title: test/AOJ-DPL_5_E/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_F/main.test.cpp
    title: test/AOJ-DPL_5_F/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_G/main.test.cpp
    title: test/AOJ-DPL_5_G/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_I/main.test.cpp
    title: test/AOJ-DPL_5_I/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_J/main.test.cpp
    title: test/AOJ-DPL_5_J/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DPL_5_L/main.test.cpp
    title: test/AOJ-DPL_5_L/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-ITP1_3_D/main.test.cpp
    title: test/AOJ-ITP1_3_D/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-NTL_1_A/main.test.cpp
    title: test/AOJ-NTL_1_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ-NTL_1_E/main.test.cpp
    title: test/AOJ-NTL_1_E/main.test.cpp
  - icon: ':x:'
    path: test/AtCoder-abc019_b/main.test.cpp
    title: test/AtCoder-abc019_b/main.test.cpp
  - icon: ':x:'
    path: test/AtCoder-abc110d/main.test.cpp
    title: test/AtCoder-abc110d/main.test.cpp
  - icon: ':x:'
    path: test/AtCoder-abc185_f/main.test.cpp
    title: test/AtCoder-abc185_f/main.test.cpp
  - icon: ':x:'
    path: test/AtCoder-abc241_e/main.test.cpp
    title: test/AtCoder-abc241_e/main.test.cpp
  - icon: ':x:'
    path: test/AtCoder-practice2_j/main.test.cpp
    title: test/AtCoder-practice2_j/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-enumerate-primes/main.test.cpp
    title: test/yosupo-enumerate-primes/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder-391/main.test.cpp
    title: test/yukicoder-391/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder-430/main.test.cpp
    title: test/yukicoder-430/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder-502/main.test.cpp
    title: test/yukicoder-502/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    }\n#line 3 \"integer.hpp\"\n\nll kth_root(ll x, ll k) {\n    if(k == 1) return\
    \ x;\n    ll res = 0;\n    for(int i = 31; i >= 0; i--) {\n        bool over =\
    \ false;\n        ll tmp = 1;\n        ll nxt = res | 1LL << i;\n        REP(i,\
    \ k) {\n            if(tmp > x / nxt) {\n                over = true;\n      \
    \          break;\n            }\n            tmp *= nxt;\n        }\n       \
    \ if(!over) res = nxt;\n    }\n    return res;\n}\n\nll sqrt(ll x) {\n    return\
    \ kth_root(x, 2);\n}\n\nstruct Prime {\n    VI sieved;\n    VL primes;\n\n   \
    \ Prime() {}\n    Prime(ll n) {\n        expand(n);\n    }\n\n    void expand(ll\
    \ n) {\n        ll sz = (ll)sieved.size() - 1;\n        if(n <= sz) return;\n\
    \        sieved.resize(n+1);\n        sieved[0] = sieved[1] = 1;\n        primes.clear();\n\
    \        primes.push_back(2);\n        for(ll d = 4; d <= n; d += 2) sieved[d]\
    \ = 1;\n        FOR(d, 3, n+1) {\n            if(!sieved[d]) {\n             \
    \   primes.push_back(d);\n                for(ll i = d*d; i <= n; i += d*2) sieved[i]\
    \ = 1;\n            }\n        }\n    }\n\n    bool is_prime(ll n) {\n       \
    \ assert(n > 0);\n        if(n <= (ll)sieved.size() - 1) return !sieved[n];\n\
    \        for(ll d = 2; d*d <= n; d++) {\n            if(n % d == 0) return false;\n\
    \        }\n        return true;\n    }\n\n    VL least_prime_factors(ll n) {\n\
    \        assert(n > 0);\n        VL lpfs(n+1, -1), primes;\n        FOR(d, 2,\
    \ n+1) {\n            if(lpfs[d] == -1) {\n                lpfs[d] = d;\n    \
    \            primes.push_back(d);\n            }\n            for(ll p : primes)\
    \ {\n                if(p * d > n || p > lpfs[d]) break;\n                lpfs[p*d]\
    \ = p;\n            }\n        }\n        return lpfs;\n    }\n\n    VL prime_list(ll\
    \ n) {\n        assert(n > 0);\n        expand(n);\n        return VL(primes.begin(),\
    \ upper_bound(ALL(primes), n));\n    }\n\n    vector<pair<ll, int>> prime_factor(ll\
    \ n) {\n        assert(n > 0);\n        vector<pair<ll, int>> factor;\n      \
    \  expand(sqrt(n));\n        for(ll prime : primes) {\n            if(prime *\
    \ prime > n) break;\n            int cnt = 0;\n            while(n % prime ==\
    \ 0) {\n                n /= prime;\n                cnt++;\n            }\n \
    \           if(cnt) factor.emplace_back(prime, cnt);\n        }\n        if(n\
    \ > 1) factor.emplace_back(n, 1);\n        return factor;\n    }\n\n\n    VL divisor(ll\
    \ n) {\n        assert(n > 0);\n        auto factor = prime_factor(n);\n     \
    \   VL res = {1};\n        for(auto [prime, cnt] : factor) {\n            int\
    \ sz = res.size();\n            res.resize(sz * (cnt+1));\n            REP(i,\
    \ sz*cnt) res[sz+i] = res[i] * prime;\n            REP(i, cnt) inplace_merge(res.begin(),\
    \ res.begin() + sz*(i+1), res.begin() + sz*(i+2));\n        }\n        return\
    \ res;\n    }\n};\n\nll extgcd(ll a, ll b, ll& x, ll& y) {\n    x = 1, y = 0;\n\
    \    ll nx = 0, ny = 1;\n    while(b) {\n        ll q = a / b;\n        tie(a,\
    \ b) = LP(b, a % b);\n        tie(x, nx) = LP(nx, x - nx*q);\n        tie(y, ny)\
    \ = LP(ny, y - ny*q);\n    }\n    return a;\n}\n\nll inv_mod(ll n, ll m) {\n \
    \   ll x, y;\n    assert(extgcd(n, m, x, y) == 1);\n    x %= m;\n    if(x < 0)\
    \ x += m;\n    return x;\n}\n\nll pow_mod(ll a, ll n, ll m) {\n    if(n == 0)\
    \ return 1LL;\n    if(n < 0) return inv_mod(pow_mod(a, -n, m), m);\n    ll res\
    \ = 1;\n    while(n) {\n        if(n & 1) {\n            res *= a;\n         \
    \   res %= m;\n        }\n        n >>= 1;\n        a *= a;\n        a %= m;\n\
    \    }\n    return res;\n}\n\n"
  code: "#pragma once\n#include \"base.hpp\"\n\nll kth_root(ll x, ll k) {\n    if(k\
    \ == 1) return x;\n    ll res = 0;\n    for(int i = 31; i >= 0; i--) {\n     \
    \   bool over = false;\n        ll tmp = 1;\n        ll nxt = res | 1LL << i;\n\
    \        REP(i, k) {\n            if(tmp > x / nxt) {\n                over =\
    \ true;\n                break;\n            }\n            tmp *= nxt;\n    \
    \    }\n        if(!over) res = nxt;\n    }\n    return res;\n}\n\nll sqrt(ll\
    \ x) {\n    return kth_root(x, 2);\n}\n\nstruct Prime {\n    VI sieved;\n    VL\
    \ primes;\n\n    Prime() {}\n    Prime(ll n) {\n        expand(n);\n    }\n\n\
    \    void expand(ll n) {\n        ll sz = (ll)sieved.size() - 1;\n        if(n\
    \ <= sz) return;\n        sieved.resize(n+1);\n        sieved[0] = sieved[1] =\
    \ 1;\n        primes.clear();\n        primes.push_back(2);\n        for(ll d\
    \ = 4; d <= n; d += 2) sieved[d] = 1;\n        FOR(d, 3, n+1) {\n            if(!sieved[d])\
    \ {\n                primes.push_back(d);\n                for(ll i = d*d; i <=\
    \ n; i += d*2) sieved[i] = 1;\n            }\n        }\n    }\n\n    bool is_prime(ll\
    \ n) {\n        assert(n > 0);\n        if(n <= (ll)sieved.size() - 1) return\
    \ !sieved[n];\n        for(ll d = 2; d*d <= n; d++) {\n            if(n % d ==\
    \ 0) return false;\n        }\n        return true;\n    }\n\n    VL least_prime_factors(ll\
    \ n) {\n        assert(n > 0);\n        VL lpfs(n+1, -1), primes;\n        FOR(d,\
    \ 2, n+1) {\n            if(lpfs[d] == -1) {\n                lpfs[d] = d;\n \
    \               primes.push_back(d);\n            }\n            for(ll p : primes)\
    \ {\n                if(p * d > n || p > lpfs[d]) break;\n                lpfs[p*d]\
    \ = p;\n            }\n        }\n        return lpfs;\n    }\n\n    VL prime_list(ll\
    \ n) {\n        assert(n > 0);\n        expand(n);\n        return VL(primes.begin(),\
    \ upper_bound(ALL(primes), n));\n    }\n\n    vector<pair<ll, int>> prime_factor(ll\
    \ n) {\n        assert(n > 0);\n        vector<pair<ll, int>> factor;\n      \
    \  expand(sqrt(n));\n        for(ll prime : primes) {\n            if(prime *\
    \ prime > n) break;\n            int cnt = 0;\n            while(n % prime ==\
    \ 0) {\n                n /= prime;\n                cnt++;\n            }\n \
    \           if(cnt) factor.emplace_back(prime, cnt);\n        }\n        if(n\
    \ > 1) factor.emplace_back(n, 1);\n        return factor;\n    }\n\n\n    VL divisor(ll\
    \ n) {\n        assert(n > 0);\n        auto factor = prime_factor(n);\n     \
    \   VL res = {1};\n        for(auto [prime, cnt] : factor) {\n            int\
    \ sz = res.size();\n            res.resize(sz * (cnt+1));\n            REP(i,\
    \ sz*cnt) res[sz+i] = res[i] * prime;\n            REP(i, cnt) inplace_merge(res.begin(),\
    \ res.begin() + sz*(i+1), res.begin() + sz*(i+2));\n        }\n        return\
    \ res;\n    }\n};\n\nll extgcd(ll a, ll b, ll& x, ll& y) {\n    x = 1, y = 0;\n\
    \    ll nx = 0, ny = 1;\n    while(b) {\n        ll q = a / b;\n        tie(a,\
    \ b) = LP(b, a % b);\n        tie(x, nx) = LP(nx, x - nx*q);\n        tie(y, ny)\
    \ = LP(ny, y - ny*q);\n    }\n    return a;\n}\n\nll inv_mod(ll n, ll m) {\n \
    \   ll x, y;\n    assert(extgcd(n, m, x, y) == 1);\n    x %= m;\n    if(x < 0)\
    \ x += m;\n    return x;\n}\n\nll pow_mod(ll a, ll n, ll m) {\n    if(n == 0)\
    \ return 1LL;\n    if(n < 0) return inv_mod(pow_mod(a, -n, m), m);\n    ll res\
    \ = 1;\n    while(n) {\n        if(n & 1) {\n            res *= a;\n         \
    \   res %= m;\n        }\n        n >>= 1;\n        a *= a;\n        a %= m;\n\
    \    }\n    return res;\n}\n\n"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: integer.hpp
  requiredBy:
  - string.hpp
  - modint.hpp
  - general.hpp
  timestamp: '2022-06-21 20:28:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ-DPL_5_C/main.test.cpp
  - test/AOJ-ALDS_1_14_B/main.test.cpp
  - test/AOJ-DPL_5_D/main.test.cpp
  - test/AOJ-DPL_5_F/main.test.cpp
  - test/AOJ-DPL_5_L/main.test.cpp
  - test/AtCoder-abc185_f/main.test.cpp
  - test/yukicoder-502/main.test.cpp
  - test/yukicoder-391/main.test.cpp
  - test/AtCoder-abc110d/main.test.cpp
  - test/AOJ-DPL_5_A/main.test.cpp
  - test/AOJ-DPL_5_B/main.test.cpp
  - test/AOJ-ITP1_3_D/main.test.cpp
  - test/AtCoder-abc019_b/main.test.cpp
  - test/AOJ-DPL_5_G/main.test.cpp
  - test/AtCoder-abc241_e/main.test.cpp
  - test/AOJ-ALDS_1_1_C/main.test.cpp
  - test/yukicoder-430/main.test.cpp
  - test/AOJ-NTL_1_A/main.test.cpp
  - test/AtCoder-practice2_j/main.test.cpp
  - test/AOJ-DPL_5_J/main.test.cpp
  - test/AOJ-DPL_5_I/main.test.cpp
  - test/AOJ-NTL_1_E/main.test.cpp
  - test/AOJ-DPL_5_E/main.test.cpp
  - test/yosupo-enumerate-primes/main.test.cpp
documentation_of: integer.hpp
layout: document
redirect_from:
- /library/integer.hpp
- /library/integer.hpp.html
title: integer.hpp
---
