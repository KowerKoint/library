---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: counting.hpp
    title: counting.hpp
  - icon: ':question:'
    path: integer.hpp
    title: integer.hpp
  - icon: ':question:'
    path: internal_operator.hpp
    title: internal_operator.hpp
  - icon: ':question:'
    path: modint.hpp
    title: modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_J
    links:
    - https://github.com/online-judge-tools/template-generator)
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_J
  bundledCode: "#line 1 \"test/AOJ-DPL_5_J/main.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_J\"\
    \n#line 2 \"base.hpp\"\n\n#ifdef DEBUG\n#define _GLIBCXX_DEBUG\n#endif\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define REP(i, n) for(int i = 0; i\
    \ < (int)(n); i++)\n#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)\n#define\
    \ ALL(a) (a).begin(),(a).end()\n#define END(...) { print(__VA_ARGS__); return;\
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
    }\n#line 3 \"test/AOJ-DPL_5_J/main.test.cpp\"\n\n/* #include <atcoder/all> */\n\
    /* using namespace atcoder; */\n/* #include \"expansion/ac-library/all.hpp\" */\n\
    #line 3 \"internal_operator.hpp\"\n\nnamespace internal_operator {\n    template\
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
    \ a, T b) { return min(a, b); }\n}\n\n#line 3 \"integer.hpp\"\n\nll kth_root(ll\
    \ x, ll k) {\n    if(k == 1) return x;\n    ll res = 0;\n    for(int i = 31; i\
    \ >= 0; i--) {\n        bool over = false;\n        ll tmp = 1;\n        ll nxt\
    \ = res | 1LL << i;\n        REP(i, k) {\n            if(tmp > x / nxt) {\n  \
    \              over = true;\n                break;\n            }\n         \
    \   tmp *= nxt;\n        }\n        if(!over) res = nxt;\n    }\n    return res;\n\
    }\n\nll sqrt(ll x) {\n    return kth_root(x, 2);\n}\n\nstruct Prime {\n    VI\
    \ sieved;\n    VL primes;\n\n    Prime() {}\n    Prime(ll n) {\n        expand(n);\n\
    \    }\n\n    void expand(ll n) {\n        ll sz = (ll)sieved.size() - 1;\n  \
    \      if(n <= sz) return;\n        sieved.resize(n+1);\n        sieved[0] = sieved[1]\
    \ = 1;\n        primes.clear();\n        primes.push_back(2);\n        for(ll\
    \ d = 4; d <= n; d += 2) sieved[d] = 1;\n        FOR(d, 3, n+1) {\n          \
    \  if(!sieved[d]) {\n                primes.push_back(d);\n                for(ll\
    \ i = d*d; i <= n; i += d*2) sieved[i] = 1;\n            }\n        }\n    }\n\
    \n    bool is_prime(ll n) {\n        assert(n > 0);\n        if(n <= (ll)sieved.size()\
    \ - 1) return !sieved[n];\n        for(ll d = 2; d*d <= n; d++) {\n          \
    \  if(n % d == 0) return false;\n        }\n        return true;\n    }\n\n  \
    \  VL least_prime_factors(ll n) {\n        assert(n > 0);\n        VL lpfs(n+1,\
    \ -1), primes;\n        FOR(d, 2, n+1) {\n            if(lpfs[d] == -1) {\n  \
    \              lpfs[d] = d;\n                primes.push_back(d);\n          \
    \  }\n            for(ll p : primes) {\n                if(p * d > n || p > lpfs[d])\
    \ break;\n                lpfs[p*d] = p;\n            }\n        }\n        return\
    \ lpfs;\n    }\n\n    VL prime_list(ll n) {\n        assert(n > 0);\n        expand(n);\n\
    \        return VL(primes.begin(), upper_bound(ALL(primes), n));\n    }\n\n  \
    \  vector<pair<ll, int>> prime_factor(ll n) {\n        assert(n > 0);\n      \
    \  vector<pair<ll, int>> factor;\n        expand(sqrt(n));\n        for(ll prime\
    \ : primes) {\n            if(prime * prime > n) break;\n            int cnt =\
    \ 0;\n            while(n % prime == 0) {\n                n /= prime;\n     \
    \           cnt++;\n            }\n            if(cnt) factor.emplace_back(prime,\
    \ cnt);\n        }\n        if(n > 1) factor.emplace_back(n, 1);\n        return\
    \ factor;\n    }\n\n\n    VL divisor(ll n) {\n        assert(n > 0);\n       \
    \ auto factor = prime_factor(n);\n        VL res = {1};\n        for(auto [prime,\
    \ cnt] : factor) {\n            int sz = res.size();\n            res.resize(sz\
    \ * (cnt+1));\n            REP(i, sz*cnt) res[sz+i] = res[i] * prime;\n      \
    \      REP(i, cnt) inplace_merge(res.begin(), res.begin() + sz*(i+1), res.begin()\
    \ + sz*(i+2));\n        }\n        return res;\n    }\n};\n\nll extgcd(ll a, ll\
    \ b, ll& x, ll& y) {\n    x = 1, y = 0;\n    ll nx = 0, ny = 1;\n    while(b)\
    \ {\n        ll q = a / b;\n        tie(a, b) = LP(b, a % b);\n        tie(x,\
    \ nx) = LP(nx, x - nx*q);\n        tie(y, ny) = LP(ny, y - ny*q);\n    }\n   \
    \ return a;\n}\n\nll inv_mod(ll n, ll m) {\n    ll x, y;\n    assert(extgcd(n,\
    \ m, x, y) == 1);\n    x %= m;\n    if(x < 0) x += m;\n    return x;\n}\n\nll\
    \ pow_mod(ll a, ll n, ll m) {\n    if(n == 0) return 1LL;\n    if(n < 0) return\
    \ inv_mod(pow_mod(a, -n, m), m);\n    ll res = 1;\n    while(n) {\n        if(n\
    \ & 1) {\n            res *= a;\n            res %= m;\n        }\n        n >>=\
    \ 1;\n        a *= a;\n        a %= m;\n    }\n    return res;\n}\n\n#line 5 \"\
    modint.hpp\"\n\ntemplate <ll (*mod)()>\nstruct Modint {\n    ll val;\n    \n \
    \   Modint(): val(0) {}\n\n    Modint(ll x): val(x) {\n        val %= mod();\n\
    \        if(val < 0) val += mod();\n    }\n\n    Modint& operator+=(const Modint&\
    \ r) {\n        val += r.val;\n        if(val >= mod()) val -= mod();\n      \
    \  return *this;\n    }\n    friend Modint operator+(const Modint& l, const Modint&\
    \ r) {\n        return Modint(l) += r;\n    }\n\n    Modint& operator-=(const\
    \ Modint& r) {\n        val -= r.val;\n        if(val < 0) val += mod();\n   \
    \     return *this;\n    }\n    friend Modint operator-(const Modint& l, const\
    \ Modint& r) {\n        return Modint(l) -= r;\n    }\n\n    Modint& operator*=(const\
    \ Modint& r) {\n        val *= r.val;\n        val %= mod();\n        return *this;\n\
    \    }\n    Modint operator*(const Modint& r) {\n        return (Modint(*this)\
    \ *= r);\n    }\n    friend Modint operator*(const Modint& l, const Modint& r)\
    \ {\n        return Modint(l) *= r;\n    }\n\n    Modint pow(ll n) const {\n \
    \       return Modint(pow_mod(val, n, mod()));\n    }\n\n    Modint inv() const\
    \ {\n        return Modint(inv_mod(val, mod()));\n    }\n\n    Modint& operator/=(const\
    \ Modint& r) {\n        return (*this *= r.inv());\n    }\n    friend Modint operator/(const\
    \ Modint& l, const Modint& r) {\n        return Modint(l) /= r;\n    }\n\n   \
    \ Modint& operator^=(const ll n) {\n        val = pow_mod(val, n, mod());\n  \
    \      return *this;\n    }\n    Modint operator^(const ll n) {\n        return\
    \ this->pow(n);\n    }\n\n    Modint operator+() const { return *this; }\n   \
    \ Modint operator-() const { return Modint() - *this; }\n\n    Modint& operator++()\
    \ {\n        val++;\n        if(val == mod()) val = 0LL;\n        return *this;\n\
    \    }\n    Modint& operator++(int) {\n        Modint res(*this);\n        ++*this;\n\
    \        return res;\n    }\n\n    Modint& operator--() {\n        if(val == 0LL)\
    \ val = mod();\n        val--;\n        return *this;\n    }\n    Modint& operator--(int)\
    \ {\n        Modint res(*this);\n        --*this;\n        return res;\n    }\n\
    \n    friend bool operator==(const Modint& l, const Modint& r) {\n        return\
    \ l.val == r.val;\n    }\n    friend bool operator!=(const Modint& l, const Modint&\
    \ r) {\n        return l.val != r.val;\n    }\n\n    static pair<vector<Modint>,\
    \ vector<Modint>> factorial(int n) {\n        vector<Modint> fact(n+1), rfact(n+1);\n\
    \        fact[0] = 1;\n        REP(i, n) fact[i+1] = fact[i] * (i+1);\n      \
    \  rfact[n] = 1 / fact[n];\n        for(int i = n-1; i >= 0; i--) rfact[i] = rfact[i+1]\
    \ * (i+1);\n        return {fact, rfact};\n    }\n\n    friend istream& operator>>(istream&\
    \ is, Modint& mi) {\n        is >> mi.val;\n        return is;\n    }\n\n    friend\
    \ ostream& operator<<(ostream& os, const Modint& mi) {\n        os << mi.val;\n\
    \        return os;\n    }\n};\n\nusing MI3 = Modint<internal_operator::mod3>;\n\
    using V3 = vector<MI3>;\nusing VV3 = vector<V3>;\nusing VVV3 = vector<VV3>;\n\
    using MI7 = Modint<internal_operator::mod7>;\nusing V7 = vector<MI7>;\nusing VV7\
    \ = vector<V7>;\nusing VVV7 = vector<VV7>;\nusing MI9 = Modint<internal_operator::mod9>;\n\
    using V9 = vector<MI9>;\nusing VV9 = vector<V9>;\nusing VVV9 = vector<VV9>;\n\
    #line 3 \"counting.hpp\"\n\ntemplate <typename T>\nstruct Counting {\n    vector<T>\
    \ fact, ifact;\n\n    Counting() {}\n    Counting(ll n) {\n        expand(n);\n\
    \    }\n\n    void expand(ll n) {\n        ll sz = (ll)fact.size();\n        if(sz\
    \ > n) return;\n        fact.resize(n+1);\n        ifact.resize(n+1);\n      \
    \  fact[0] = 1;\n        FOR(i, max(1LL, sz), n+1) fact[i] = fact[i-1] * i;\n\
    \        ifact[n] = 1 / fact[n];\n        for(ll i = n-1; i >= sz; i--) ifact[i]\
    \ = ifact[i+1] * (i+1);\n    }\n\n    T permutation(ll n, ll r) {\n        assert(n\
    \ >= r);\n        assert(r >= 0);\n        expand(n);\n        return fact[n]\
    \ * ifact[n-r];\n    }\n\n    T combination(ll n, ll r) {\n        assert(n >=\
    \ r);\n        assert(r >= 0);\n        expand(n);\n        return fact[n] * ifact[r]\
    \ * ifact[n-r];\n    }\n\n    T stirling(ll n, ll k) {\n        assert(n >= k);\n\
    \        assert(k >= 0);\n        if(n == 0) return 1;\n        T res = 0;\n \
    \       int sign = k%2? -1 : 1;\n        expand(k);\n        REP(i, k+1) {\n \
    \           res += sign * ifact[i] * ifact[k-i] * T(i).pow(n);\n            sign\
    \ *= -1;\n        }\n        return res;\n    }\n\n    vector<vector<T>> stirling_table(ll\
    \ n, ll k) {\n        assert(n >= 0 && k >= 0);\n        vector<vector<T>> res(n+1,\
    \ vector<T>(k+1));\n        res[0][0] = 1;\n        FOR(i, 1, n+1) FOR(j, 1, k+1)\
    \ {\n            res[i][j] = res[i-1][j-1] + j * res[i-1][j];\n        }\n   \
    \     return res;\n    }\n\n    T bell(ll n, ll k) {\n        assert(n >= 0 &&\
    \ k >= 0);\n        expand(k);\n        vector<T> tmp(k+1);\n        int sign\
    \ = 1;\n        tmp[0] = 1;\n        FOR(i, 1, k+1) {\n            sign *= -1;\n\
    \            tmp[i] = tmp[i-1] + sign * ifact[i];\n        }\n        T res =\
    \ 0;\n        REP(i, k+1) {\n            res += T(i).pow(n) * ifact[i] * tmp[k-i];\n\
    \        }\n        return res;\n    }\n\n    vector<vector<T>> partition_table(ll\
    \ n) {\n        assert(n >= 0);\n        vector<vector<T>> res(n+1, vector<T>(n+1));\n\
    \        REP(i, n+1) res[0][i] = 1;\n        FOR(i, 1, n+1) FOR(j, 1, n+1) {\n\
    \            res[i][j] = res[i][j-1] + (i<j? 0 : res[i-j][j]);\n        }\n  \
    \      return res;\n    }\n};\n#line 9 \"test/AOJ-DPL_5_J/main.test.cpp\"\n\n\
    void solve(){\n    ll n, k; cin >> n >> k;\n    print(Counting<MI7>().partition_table(max(n,\
    \ k))[n][k]);\n}\n\n// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)\n\
    int main() {\n    // Fasterize input/output script\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(100);\n    // scanf/printf\
    \ user should delete this fasterize input/output script\n\n    int t = 1;\n  \
    \  //cin >> t; // comment out if solving multi testcase\n    for(int testCase\
    \ = 1;testCase <= t;++testCase){\n        solve();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_J\"\n#include\
    \ \"base.hpp\"\n\n/* #include <atcoder/all> */\n/* using namespace atcoder; */\n\
    /* #include \"expansion/ac-library/all.hpp\" */\n#include \"modint.hpp\"\n#include\
    \ \"counting.hpp\"\n\nvoid solve(){\n    ll n, k; cin >> n >> k;\n    print(Counting<MI7>().partition_table(max(n,\
    \ k))[n][k]);\n}\n\n// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)\n\
    int main() {\n    // Fasterize input/output script\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(100);\n    // scanf/printf\
    \ user should delete this fasterize input/output script\n\n    int t = 1;\n  \
    \  //cin >> t; // comment out if solving multi testcase\n    for(int testCase\
    \ = 1;testCase <= t;++testCase){\n        solve();\n    }\n    return 0;\n}\n"
  dependsOn:
  - base.hpp
  - modint.hpp
  - internal_operator.hpp
  - integer.hpp
  - counting.hpp
  isVerificationFile: true
  path: test/AOJ-DPL_5_J/main.test.cpp
  requiredBy: []
  timestamp: '2022-06-30 20:37:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-DPL_5_J/main.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-DPL_5_J/main.test.cpp
- /verify/test/AOJ-DPL_5_J/main.test.cpp.html
title: test/AOJ-DPL_5_J/main.test.cpp
---
