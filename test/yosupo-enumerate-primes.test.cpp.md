---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: bit/bitset.hpp
    title: bit/bitset.hpp
  - icon: ':heavy_check_mark:'
    path: integer/kth-root-integer.hpp
    title: integer/kth-root-integer.hpp
  - icon: ':heavy_check_mark:'
    path: integer/prime.hpp
    title: integer/prime.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo-enumerate-primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#line 2 \"stl-expansion.hpp\"\
    \n#include <bits/stdc++.h>\n\ntemplate <typename T1, typename T2>\nstd::istream&\
    \ operator>>(std::istream& is, std::pair<T1, T2>& p) {\n    is >> p.first >> p.second;\n\
    \    return is;\n}\ntemplate <typename T, size_t N>\nstd::istream& operator>>(std::istream&\
    \ is, std::array<T, N>& a) {\n    for (size_t i = 0; i < N; ++i) {\n        is\
    \ >> a[i];\n    }\n    return is;\n}\ntemplate <typename T>\nstd::istream& operator>>(std::istream&\
    \ is, std::vector<T>& v) {\n    for (auto& e : v) is >> e;\n    return is;\n}\n\
    template <typename T1, typename T2>\nstd::ostream& operator<<(std::ostream& os,\
    \ const std::pair<T1, T2>& p) {\n    os << p.first << \" \" << p.second;\n   \
    \ return os;\n}\ntemplate <typename T, size_t N>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::array<T, N>& a) {\n    for (size_t i = 0; i < N; ++i) {\n   \
    \     os << a[i] << (i + 1 == a.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T>\nstd::ostream& operator<<(std::ostream& os, const std::vector<T>&\
    \ v) {\n    for (size_t i = 0; i < v.size(); ++i) {\n        os << v[i] << (i\
    \ + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\n#line 3 \"base.hpp\"\
    \nusing namespace std;\n\n#define REP(i, n) for(int i = 0; i < (int)(n); i++)\n\
    #define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)\n#define ALL(a) (a).begin(),(a).end()\n\
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
    }\n#line 3 \"integer/kth-root-integer.hpp\"\n\null kth_root_integer(ull x, ull\
    \ k) {\n    if(k == 1) return x;\n    ll res = 0;\n    for(int i = 31; i >= 0;\
    \ i--) {\n        bool over = false;\n        ull tmp = 1;\n        ull nxt =\
    \ res | 1ULL << i;\n        REP(i, k) {\n            if(tmp > x / nxt) {\n   \
    \             over = true;\n                break;\n            }\n          \
    \  tmp *= nxt;\n        }\n        if(!over) res = nxt;\n    }\n    return res;\n\
    }\n\n#line 2 \"bit/bitset.hpp\"\n\nstruct Bitset {\n    private:\n    constexpr\
    \ static ull mask[] = {\n        0x0000000000000000ull, 0x0000000000000001ull,\
    \ 0x0000000000000003ull, 0x0000000000000007ull,\n        0x000000000000000Full,\
    \ 0x000000000000001Full, 0x000000000000003Full, 0x000000000000007Full,\n     \
    \   0x00000000000000FFull, 0x00000000000001FFull, 0x00000000000003FFull, 0x00000000000007FFull,\n\
    \        0x0000000000000FFFull, 0x0000000000001FFFull, 0x0000000000003FFFull,\
    \ 0x0000000000007FFFull,\n        0x000000000000FFFFull, 0x000000000001FFFFull,\
    \ 0x000000000003FFFFull, 0x000000000007FFFFull,\n        0x00000000000FFFFFull,\
    \ 0x00000000001FFFFFull, 0x00000000003FFFFFull, 0x00000000007FFFFFull,\n     \
    \   0x0000000000FFFFFFull, 0x0000000001FFFFFFull, 0x0000000003FFFFFFull, 0x0000000007FFFFFFull,\n\
    \        0x000000000FFFFFFFull, 0x000000001FFFFFFFull, 0x000000003FFFFFFFull,\
    \ 0x000000007FFFFFFFull,\n        0x00000000FFFFFFFFull, 0x00000001FFFFFFFFull,\
    \ 0x00000003FFFFFFFFull, 0x00000007FFFFFFFFull,\n        0x0000000FFFFFFFFFull,\
    \ 0x0000001FFFFFFFFFull, 0x0000003FFFFFFFFFull, 0x0000007FFFFFFFFFull,\n     \
    \   0x000000FFFFFFFFFFull, 0x000001FFFFFFFFFFull, 0x000003FFFFFFFFFFull, 0x000007FFFFFFFFFFull,\n\
    \        0x00000FFFFFFFFFFFull, 0x00001FFFFFFFFFFFull, 0x00003FFFFFFFFFFFull,\
    \ 0x00007FFFFFFFFFFFull,\n        0x0000FFFFFFFFFFFFull, 0x0001FFFFFFFFFFFFull,\
    \ 0x0003FFFFFFFFFFFFull, 0x0007FFFFFFFFFFFFull,\n        0x000FFFFFFFFFFFFFull,\
    \ 0x001FFFFFFFFFFFFFull, 0x003FFFFFFFFFFFFFull, 0x007FFFFFFFFFFFFFull,\n     \
    \   0x00FFFFFFFFFFFFFFull, 0x01FFFFFFFFFFFFFFull, 0x03FFFFFFFFFFFFFFull, 0x07FFFFFFFFFFFFFFull,\n\
    \        0x0FFFFFFFFFFFFFFFull, 0x1FFFFFFFFFFFFFFFull, 0x3FFFFFFFFFFFFFFFull,\
    \ 0x7FFFFFFFFFFFFFFFull,\n        0xFFFFFFFFFFFFFFFFull\n    };\n    void correct()\
    \ {\n        if(n % 64) v[bnum-1] &= mask[n % 64];\n    }\n    public:\n    vector<ull>\
    \ v;\n    int n, bnum;\n    Bitset(int n_ = 0) : n(n_) {\n        assert(n_ >=\
    \ 0);\n        bnum = (n+63) / 64;\n        v.resize(bnum);\n    }\n    int operator[](int\
    \ i) const {\n        assert(0 <= i && i < n);\n        return (v[i/64] >> (i%64))\
    \ & 1;\n    }\n    int count() const {\n        int c = 0;\n        for (int i\
    \ = 0; i < v.size(); i++) {\n            c += __builtin_popcountll(v[i]);\n  \
    \      }\n        return c;\n    }\n    // not tested\n    int count_range(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        int\
    \ c = 0;\n        int l2 = l / 64;\n        int r2 = r / 64;\n        for(int\
    \ i = l2; i < r2; i++) {\n            c += __builtin_popcountll(v[i]);\n     \
    \   }\n        if(l % 64) {\n            c -= __builtin_popcountll(v[l2] & mask[l\
    \ % 64]);\n        }\n        if(r % 64) {\n            c += __builtin_popcountll(v[r2]\
    \ & mask[r % 64]);\n        }\n        return c;\n    }\n    bool all() const\
    \ {\n        return count() == n;\n    }\n    bool any() const {\n        return\
    \ count() > 0;\n    }\n    bool none() const {\n        return count() == 0;\n\
    \    }\n    void set(int i) {\n        assert(0 <= i && i < n);\n        v[i /\
    \ 64] |= 1ull << (i % 64);\n    }\n    void reset(int i) {\n        assert(0 <=\
    \ i && i < n);\n        v[i / 64] &= ~(1ull << (i % 64));\n    }\n    void flip(int\
    \ i) {\n        assert(0 <= i && i < n);\n        v[i / 64] ^= 1ull << (i % 64);\n\
    \    }\n    void resize(int n_) {\n        assert(n_ >= 0);\n        n = n_;\n\
    \        bnum = (n+63) / 64;\n        v.resize(bnum);\n        correct();\n  \
    \  }\n    void all_set() {\n        fill(v.begin(), v.end(),  ~0ULL);\n      \
    \  correct();\n    }\n    void all_reset() {\n        fill(v.begin(), v.end(),\
    \ 0);\n    }\n    void all_flip() {\n        for (int i = 0; i < v.size(); i++)\
    \ {\n            v[i] = ~v[i];\n        }\n        correct();\n    }\n    Bitset&\
    \ operator&=(const Bitset& b) {\n        assert(n == b.n);\n        for(int i\
    \ = 0; i < min(bnum, b.bnum); i++) {\n            v[i] &= b.v[i];\n        }\n\
    \        return *this;\n    }\n    Bitset operator&(const Bitset& b) const {\n\
    \        assert(n == b.n);\n        return Bitset(*this) &= b;\n    }\n    Bitset&\
    \ operator|=(const Bitset& b) {\n        assert(n == b.n);\n        for(int i\
    \ = 0; i < min(bnum, b.bnum); i++) {\n            v[i] |= b.v[i];\n        }\n\
    \        correct();\n        return *this;\n    }\n    Bitset operator|(const\
    \ Bitset& b) const {\n        assert(n == b.n);\n        return Bitset(*this)\
    \ |= b;\n    }\n    Bitset& operator^=(const Bitset& b) {\n        assert(n ==\
    \ b.n);\n        for(int i = 0; i < min(bnum, b.bnum); i++) {\n            v[i]\
    \ ^= b.v[i];\n        }\n        correct();\n        return *this;\n    }\n  \
    \  Bitset operator^(const Bitset& b) const {\n        assert(n == b.n);\n    \
    \    return Bitset(*this) ^= b;\n    }\n    Bitset operator~() const {\n     \
    \   Bitset b(*this);\n        b.all_flip();\n        return b;\n    }\n    bool\
    \ operator==(const Bitset& b) const {\n        assert(n == b.n);\n        return\
    \ v == b.v;\n    }\n    bool operator!=(const Bitset& b) const {\n        assert(n\
    \ == b.n);\n        return v != b.v;\n    }\n    Bitset& operator<<=(int sz) {\n\
    \        assert(sz >= 0);\n        for(int i = bnum-1; i >= 0; i--) {\n      \
    \      if(i-sz/64 < 0) v[i] = 0;\n            else if(i-sz/64-1 < 0 || sz%64 ==\
    \ 0) v[i] = v[i-sz/64] << (sz%64);\n            else v[i] = (v[i-sz/64] << (sz%64))\
    \ | (v[i-sz/64-1] >> (64-sz%64));\n        }\n        correct();\n        return\
    \ *this;\n    }\n    Bitset operator<<(int sz) const {\n        assert(sz >= 0);\n\
    \        return Bitset(*this) <<= sz;\n    }\n    Bitset& operator>>=(int sz)\
    \ {\n        assert(sz >= 0);\n        for(int i = 0; i < bnum; i++) {\n     \
    \       if(i+sz/64 < bnum) v[i] = v[i+sz/64] >> (sz%64);\n            if(i+sz/64+1\
    \ < bnum) v[i] |= v[i+sz/64+1] << (64-sz%64);\n        }\n        return *this;\n\
    \    }\n    Bitset operator>>(int sz) const {\n        assert(sz >= 0);\n    \
    \    return Bitset(*this) >>= sz;\n    }\n};\n#line 4 \"integer/prime.hpp\"\n\n\
    struct Prime {\n    Bitset sieved;\n    VI primes;\n\n    Prime() {}\n    Prime(int\
    \ n) {\n        assert(n >= 0);\n        expand(n);\n    }\n\n    void expand(int\
    \ n) {\n        assert(n >= 0);\n        int sz = (int)sieved.n - 1;\n       \
    \ if(n <= sz) return;\n        sieved.resize(n+1);\n        sieved.set(0);\n \
    \       sieved.set(1);\n        primes.clear();\n        if(n >= 2) primes.push_back(2);\n\
    \        for(int d = 3; d <= n; d += 2) {\n            if(!sieved[d]) {\n    \
    \            primes.push_back(d);\n                for(ll i = (ll)d*d; i <= n;\
    \ i += d*2) sieved.set(i);\n            }\n        }\n    }\n\n    bool is_prime(ull\
    \ n) {\n        assert(n > 0);\n        if(n == 2) return true;\n        if(!(n\
    \ & 1)) return false;\n        if(n+1 <= (ull)sieved.n) return !sieved[n];\n \
    \       for(ull d = 2; d*d <= n; d++) {\n            if(n % d == 0) return false;\n\
    \        }\n        return true;\n    }\n\n    VI prime_list(int n) {\n      \
    \  assert(n > 0);\n        expand(n);\n        return VI(primes.begin(), upper_bound(ALL(primes),\
    \ n));\n    }\n\n    vector<pair<ull, int>> prime_factor(ull n) {\n        assert(n\
    \ > 0);\n        vector<pair<ull, int>> factor;\n        expand(kth_root_integer(n,\
    \ 2));\n        for(ull prime : primes) {\n            if(prime * prime > n) break;\n\
    \            int cnt = 0;\n            while(n % prime == 0) {\n             \
    \   n /= prime;\n                cnt++;\n            }\n            if(cnt) factor.emplace_back(prime,\
    \ cnt);\n        }\n        if(n > 1) factor.emplace_back(n, 1);\n        return\
    \ factor;\n    }\n\n    VUL divisor(ull n) {\n        assert(n > 0);\n       \
    \ auto factor = prime_factor(n);\n        VUL res = {1};\n        for(auto [prime,\
    \ cnt] : factor) {\n            int sz = res.size();\n            res.resize(sz\
    \ * (cnt+1));\n            REP(i, sz*cnt) res[sz+i] = res[i] * prime;\n      \
    \      REP(i, cnt) inplace_merge(res.begin(), res.begin() + sz*(i+1), res.begin()\
    \ + sz*(i+2));\n        }\n        return res;\n    }\n};\n#line 3 \"test/yosupo-enumerate-primes.test.cpp\"\
    \n\nint main() {\n    int n, a, b; cin >> n >> a >> b;\n    Prime pm(n);\n   \
    \ auto primes = pm.prime_list(n);\n    VI ans;\n    for(ll i = b; i < primes.size();\
    \ i += a) ans.push_back(primes[i]);\n    print(primes.size(), ans.size());\n \
    \   print(ans);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ \"../integer/prime.hpp\"\n\nint main() {\n    int n, a, b; cin >> n >> a >>\
    \ b;\n    Prime pm(n);\n    auto primes = pm.prime_list(n);\n    VI ans;\n   \
    \ for(ll i = b; i < primes.size(); i += a) ans.push_back(primes[i]);\n    print(primes.size(),\
    \ ans.size());\n    print(ans);\n}\n"
  dependsOn:
  - integer/prime.hpp
  - integer/kth-root-integer.hpp
  - base.hpp
  - stl-expansion.hpp
  - bit/bitset.hpp
  isVerificationFile: true
  path: test/yosupo-enumerate-primes.test.cpp
  requiredBy: []
  timestamp: '2023-02-22 17:51:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-enumerate-primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-enumerate-primes.test.cpp
- /verify/test/yosupo-enumerate-primes.test.cpp.html
title: test/yosupo-enumerate-primes.test.cpp
---
