---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/field.hpp
    title: algebra/field.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/modint.hpp
    title: algebra/modint.hpp
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: integer/extgcd.hpp
    title: integer/extgcd.hpp
  - icon: ':heavy_check_mark:'
    path: integer/pow-mod.hpp
    title: integer/pow-mod.hpp
  - icon: ':heavy_check_mark:'
    path: operator.hpp
    title: operator.hpp
  - icon: ':heavy_check_mark:'
    path: segtree/lazy-segtree.hpp
    title: segtree/lazy-segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo-range-affine-range-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#line 2 \"stl-expansion.hpp\"\
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
    }\n#line 3 \"integer/extgcd.hpp\"\n\nconstexpr ll extgcd(ll a, ll b, ll& x, ll&\
    \ y) {\n    x = 1, y = 0;\n    ll nx = 0, ny = 1;\n    while(b) {\n        ll\
    \ q = a / b;\n        ll r = a % b;\n        a = b, b = r;\n        ll nnx = x\
    \ - q * nx;\n        ll nny = y - q * ny;\n        x = nx, nx = nnx;\n       \
    \ y = ny, ny = nny;\n    }\n    return a;\n}\n#line 3 \"integer/pow-mod.hpp\"\n\
    \nconstexpr ll inv_mod(ll n, ll m) {\n    n %= m;\n    if (n < 0) n += m;\n  \
    \  ll x = -1, y = -1;\n    if(extgcd(n, m, x, y) != 1) throw logic_error(\"\"\
    );\n    x %= m;\n    if(x < 0) x += m;\n    return x;\n}\n\nconstexpr ll pow_mod(ll\
    \ a, ll n, ll m) {\n    if(n == 0) return 1LL;\n    if(n < 0) return inv_mod(pow_mod(a,\
    \ -n, m), m);\n    a %= m;\n    if (a < 0) n += m;\n    ll res = 1;\n    while(n)\
    \ {\n        if(n & 1) {\n            res *= a;\n            res %= m;\n     \
    \   }\n        n >>= 1;\n        a *= a;\n        a %= m;\n    }\n    return res;\n\
    }\n#line 3 \"algebra/field.hpp\"\n\ntemplate <typename T>\nstruct SumGroupBase\
    \ {\n    constexpr static bool defzero = false;\n    using Coef = nullptr_t;\n\
    \    using Scalar = nullptr_t;\n};\ntemplate <typename T>\nstruct ProdGroupBase\
    \ {\n    constexpr static bool defone = false;\n};\ntemplate <typename T>\nstruct\
    \ RepresentationBase {\n    using R = T;\n    constexpr static T construct(const\
    \ R& x) { return x; }\n    constexpr static R represent(const T& x) { return x;\
    \ }\n};\ntemplate <typename T>\nstruct CompareBase {\n    constexpr static bool\
    \ eq(const T& x, const T& y) { return x == y; }\n    constexpr static bool lt(const\
    \ T& x, const T& y) { return x < y; }\n};\ntemplate <typename T>\nstruct FinitePropertyBase\
    \ {\n    constexpr static bool is_finite = false;\n};\n\ntemplate <typename T,\
    \ typename SumGroup = SumGroupBase<T>, typename ProdGroup = ProdGroupBase<T>,\
    \ typename Representation = RepresentationBase<T>, typename Compare = CompareBase<T>,\
    \ typename FiniteProperty = FinitePropertyBase<T>>\nstruct Field {\n    using\
    \ R = typename Representation::R;\n    using Coef = typename SumGroup::Coef;\n\
    \    using Scalar = typename SumGroup::Scalar;\n    T val;\n    constexpr static\
    \ Field zero() {\n        return SumGroup::zero;\n    }\n    constexpr static\
    \ Field one() {\n        return ProdGroup::one;\n    }\n    constexpr static bool\
    \ defzero = SumGroup::defzero;\n    constexpr static bool defone = ProdGroup::defone;\n\
    \    constexpr static bool is_finite = FiniteProperty::is_finite;\n    constexpr\
    \ Field() {\n        if constexpr(SumGroup::defzero) val = SumGroup::zero;\n \
    \       else if constexpr(SumGroup::defone) val = ProdGroup::one;\n        else\
    \ val = T();\n    }\n    constexpr Field(const R& r) : val(Representation::construct(r))\
    \ {}\n    constexpr R represent() const { return Representation::represent(val);\
    \ }\n    constexpr decltype(auto) operator[](size_t i) const {\n        return\
    \ val[i];\n    }\n    constexpr static Field premitive_root() {\n        return\
    \ FiniteProperty::premitive_root();\n    }\n    constexpr static size_t order()\
    \ {\n        return FiniteProperty::order();\n    }\n    constexpr Field& operator*=(const\
    \ Field& other) {\n        ProdGroup::mulassign(val, other.val);\n        return\
    \ *this;\n    }\n    constexpr Field operator*(const Field& other) const {\n \
    \       return Field(*this) *= other;\n    }\n    constexpr Field inv() const\
    \ {\n        return ProdGroup::inv(val);\n    }\n    constexpr Field& operator/=(const\
    \ Field& other) {\n        return *this *= other.inv();\n    }\n    constexpr\
    \ Field operator/(const Field& other) const {\n        return Field(*this) /=\
    \ other;\n    }\n    constexpr Field pow(ll n) const {\n        if(n < 0) {\n\
    \            return inv().pow(-n);\n        }\n        Field res = one();\n  \
    \      Field a = *this;\n        while(n > 0) {\n            if(n & 1) res *=\
    \ a;\n            a *= a;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n    constexpr Field operator+() const {\n        return *this;\n    }\n\
    \    constexpr Field& operator+=(const Field& other) {\n        SumGroup::addassign(val,\
    \ other.val);\n        return *this;\n    }\n    constexpr Field operator+(const\
    \ Field& other) const {\n        return Field(*this) += other;\n    }\n    constexpr\
    \ Field operator-() const {\n        return SumGroup::minus(val);\n    }\n   \
    \ constexpr Field& operator-=(const Field& other) {\n        return *this += -other;\n\
    \    }\n    constexpr Field operator-(const Field& other) const {\n        return\
    \ Field(*this) -= other;\n    }\n    constexpr Field& operator++() {\n       \
    \ return *this += one();\n    }\n    Field operator++(int) {\n        Field ret\
    \ = *this;\n        ++*this;\n        return ret;\n    }\n    constexpr Field&\
    \ operator--() {\n        return *this -= one();\n    }\n    Field operator--(int)\
    \ {\n        Field ret = *this;\n        --*this;\n        return ret;\n    }\n\
    \    constexpr Field& operator*=(const Coef& other) {\n        SumGroup::coefassign(val,\
    \ other);\n        return *this;\n    }\n    constexpr Field operator*(const Coef&\
    \ other) const {\n        return Field(*this) *= other;\n    }\n    constexpr\
    \ Scalar dot(const Field& other) const {\n        return SumGroup::dot(val, other.val);\n\
    \    }\n    constexpr Scalar norm() const {\n        return dot(*this);\n    }\n\
    \    constexpr bool operator==(const Field& other) const {\n        return Compare::eq(val,\
    \ other.val);\n    }\n    constexpr bool operator!=(const Field& other) const\
    \ {\n        return !(*this == other);\n    }\n    constexpr bool operator<(const\
    \ Field& other) const {\n        return Compare::lt(represent(), other.represent());\n\
    \    }\n    constexpr bool operator>(const Field& other) const {\n        return\
    \ other < *this;\n    }\n    constexpr bool operator<=(const Field& other) const\
    \ {\n        return !(*this > other);\n    }\n    constexpr bool operator>=(const\
    \ Field& other) const {\n        return !(*this < other);\n    }\n    friend istream&\
    \ operator>>(istream& is, Field& f) {\n        R r; is >> r;\n        f = r;\n\
    \        return is;\n    }\n    friend ostream& operator<<(ostream& os, const\
    \ Field& f) {\n        return os << f.represent();\n    }\n};\nnamespace std {\n\
    \    template <typename T>\n    struct hash<Field<T>> {\n        size_t operator()(const\
    \ Field<T>& f) const {\n            return hash<typename Field<T>::R>()(f.represent());\n\
    \        }\n    };\n}\ntemplate <typename>\nstruct is_field : false_type {};\n\
    template <typename T, typename SumGroup, typename ProdGroup, typename Representation,\
    \ typename FiniteProperty>\nstruct is_field<Field<T, SumGroup, ProdGroup, Representation,\
    \ FiniteProperty>> : true_type {};\ntemplate <typename T>\nconstexpr bool is_field_v\
    \ = is_field<T>::value;\ntemplate <typename T>\nconstexpr T zero() {\n    if constexpr(is_field_v<T>)\
    \ return T::zero();\n    else return 0;\n}\ntemplate <typename T>\nconstexpr T\
    \ one() {\n    if constexpr(is_field_v<T>) return T::one();\n    else return 1;\n\
    }\ntemplate <typename T>\nconstexpr bool is_finite() {\n    if constexpr(is_field_v<T>)\
    \ return T::is_finite;\n    else return false;\n}\n#line 4 \"algebra/modint.hpp\"\
    \n\ntemplate <ll mod>\nstruct SumGroupModint : SumGroupBase<ll> {\n    static\
    \ ll& addassign(ll& l, const ll& r) {\n        ll ret;\n        if(__builtin_add_overflow(l,\
    \ r, &ret)) {\n            l = l % mod + r % mod;\n        } else {\n        \
    \    l = ret;\n        }\n        return l;\n    }\n    constexpr static bool\
    \ defzero = true;\n    constexpr static ll zero = 0;\n    constexpr static ll\
    \ minus(const ll& x) {\n        return -x;\n    }\n};\ntemplate <ll mod>\nstruct\
    \ ProdGroupModint : ProdGroupBase<ll> {\n    constexpr static bool defmul = true;\n\
    \    static ll& mulassign(ll& l, const ll& r) {\n        ll ret;\n        if(__builtin_mul_overflow(l,\
    \ r, &ret)) {\n            l = (l % mod) * (r % mod);\n        } else {\n    \
    \        l = ret;\n        }\n        return l;\n    }\n    constexpr static bool\
    \ defone = true;\n    constexpr static ll one = 1;\n    constexpr static bool\
    \ definv = true;\n    constexpr static ll inv(const ll& x) {\n        return inv_mod(x,\
    \ mod);\n    }\n};\ntemplate <ll mod>\nstruct RepresentationModint : RepresentationBase<ll>\
    \ {\n    using R = ll;\n    constexpr static ll construct(const R& x) { return\
    \ x % mod; }\n    constexpr static R represent(const ll& x) {\n        ll ret\
    \ = x % mod;\n        if(ret < 0) ret += mod;\n        return ret;\n    }\n};\n\
    template <ll mod>\nstruct CompareModint : CompareBase<ll> {\n    constexpr static\
    \ bool lt(const ll& l, const ll& r) {\n        return RepresentationModint<mod>::represent(l)\
    \ < RepresentationModint<mod>::represent(r);\n    }\n    constexpr static bool\
    \ eq(const ll& l, const ll& r) {\n        return RepresentationModint<mod>::represent(l)\
    \ == RepresentationModint<mod>::represent(r);\n    }\n};\ntemplate <ll mod>\n\
    struct FinitePropertyModint : FinitePropertyBase<ll> {\n    constexpr static bool\
    \ is_finite = true;\n    constexpr static ll premitive_root() {\n        static_assert(mod\
    \ == 998244353);\n        return 3;\n    }\n    constexpr static size_t order()\
    \ {\n        return mod - 1;\n    }\n};\n\ntemplate <ll mod>\nusing Modint = Field<ll,\
    \ SumGroupModint<mod>, ProdGroupModint<mod>, RepresentationModint<mod>, CompareModint<mod>,\
    \ FinitePropertyModint<mod>>;\n\nusing MI3 = Modint<998244353>;\nusing V3 = vector<MI3>;\n\
    using VV3 = vector<V3>;\nusing VVV3 = vector<VV3>;\nusing MI7 = Modint<1000000007>;\n\
    using V7 = vector<MI7>;\nusing VV7 = vector<V7>;\nusing VVV7 = vector<VV7>;\n\
    #line 3 \"operator.hpp\"\n\ntemplate <typename T>\nT add_op(T a, T b) { return\
    \ a + b; }\ntemplate <typename T>\nT sub_op(T a, T b) { return a - b; }\ntemplate\
    \ <typename T>\nT zero_e() { return T(0); }\ntemplate <typename T>\nT div_op(T\
    \ a, T b) { return a / b; }\ntemplate <typename T>\nT mult_op(T a, T b) { return\
    \ a * b; }\ntemplate <typename T>\nT one_e() { return T(1); }\ntemplate <typename\
    \ T>\nT xor_op(T a, T b) { return a ^ b; }\ntemplate <typename T>\nT and_op(T\
    \ a, T b) { return a & b; }\ntemplate <typename T>\nT or_op(T a, T b) { return\
    \ a | b; }\nll mod3() { return 998244353LL; }\nll mod7() { return 1000000007LL;\
    \ }\nll mod9() { return 1000000009LL; }\ntemplate <typename T>\nT max_op(T a,\
    \ T b) { return max(a, b); }\ntemplate <typename T>\nT min_op(T a, T b) { return\
    \ min(a, b); }\n\ntemplate <typename T>\nT max_e() { return numeric_limits<T>::max();\
    \ }\ntemplate <typename T>\nT min_e() { return numeric_limits<T>::min(); }\n#line\
    \ 3 \"segtree/lazy-segtree.hpp\"\n\ntemplate <typename S, S (*op)(S, S), S (*e)(),\
    \ typename F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\nstruct LazySegTree\
    \ {\nprotected:\n    int n, sz, height;\n    vector<S> state;\n    vector<F> lazy;\n\
    \    void update(int k) {\n        assert(0 <= k && k < sz);\n        state[k]\
    \ = op(state[k*2], state[k*2+1]);\n    }\n    void all_apply(int k, const F& f)\
    \ {\n        assert(0 <= k && k < sz*2);\n        state[k] = mapping(f, state[k]);\n\
    \        if(k < sz) lazy[k] = composition(f, lazy[k]);\n    }\n    void push(int\
    \ k) {\n        assert(0 <= k && k < sz);\n        all_apply(k*2, lazy[k]);\n\
    \        all_apply(k*2+1, lazy[k]);\n        lazy[k] = id();\n    }\npublic:\n\
    \    LazySegTree(int n = 0): n(n) {\n        assert(0 <= n);\n        sz = 1;\n\
    \        height = 0;\n        while(sz < n) {\n            height++;\n       \
    \     sz <<= 1;\n        }\n        state.assign(sz*2, e());\n        lazy.assign(sz*2,\
    \ id());\n    }\n    LazySegTree(const vector<S>& v): n(v.size()) {\n        sz\
    \ = 1;\n        height = 0;\n        while(sz < n) {\n            height++;\n\
    \            sz <<= 1;\n        }\n        state.assign(sz*2, e());\n        REP(i,\
    \ v.size()) state[sz+i] = v[i];\n        for(int i = sz-1; i > 0; i--) update(i);\n\
    \        lazy.assign(sz*2, id());\n    }\n    S get(int i) {\n        assert(0\
    \ <= i && i < n);\n        i += sz;\n        for(int k = height; k > 0; k--) {\n\
    \            push(i >> k);\n        }\n        return state[i];\n    }\n    void\
    \ set(int i, const S& x) {\n        assert(0 <= i && i < n);\n        i += sz;\n\
    \        for(int k = height; k > 0; k--) {\n            push(i >> k);\n      \
    \  }\n        state[i] = x;\n        while(i >>= 1) update(i);\n    }\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        l += sz, r\
    \ += sz;\n        for(int k = height; k > 0; k--) {\n            if(((l >> k)\
    \ << k) != l) push(l >> k);\n            if(((r >> k) << k) != r) push(r >> k);\n\
    \        }\n        S left_prod = e(), right_prod = e();\n        while(l < r)\
    \ {\n            if(l & 1) left_prod = op(left_prod, state[l++]);\n          \
    \  if(r & 1) right_prod = op(state[--r], right_prod);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(left_prod, right_prod);\n\
    \    }\n    void apply(int i, const F& f) {\n        assert(0 <= i && i < n);\n\
    \        i += sz;\n        for(int k = height; k > 0; k--) push(i >> k);\n   \
    \     state[i] = mapping(f, state[i]);\n        while(i >>= 1) update(i);\n  \
    \  }\n    void apply(int l, int r, const F& f) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        if(l == r) return;\n        l += sz, r += sz;\n     \
    \   for(int k = height; k > 0; k--) {\n            if(((l >> k) << k) != l) push(l\
    \ >> k);\n            if(((r >> k) << k) != r) push(r >> k);\n        }\n    \
    \    {\n            int l2 = l, r2 = r;\n            while(l < r) {\n        \
    \        if(l & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r,\
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
    \        }\n        }\n        return r - sz + 1;\n    }\n};\n\ntemplate <typename\
    \ S>\nstruct S_sz {\n    S val; int sz;\n    S_sz() : val(0), sz(0) {}\n    S_sz(S\
    \ val, int sz = 1) : val(val), sz(sz) {}\n    S_sz<S> operator+(const S_sz<S>&\
    \ o) const {\n        return S_sz<S>(val + o.val, sz + o.sz);\n    }\n};\ntemplate\
    \ <typename S>\nS_sz<S> s_sz_zero() {\n    return S_sz<S>();\n}\ntemplate <typename\
    \ S>\nstruct Affine {\n    S a, b;\n    Affine() : a(1), b(0) {}\n    Affine(S\
    \ a, S b) : a(a), b(b) {}\n};\ntemplate <typename S>\nAffine<S> affine_identity()\
    \ {\n    return Affine<S>(1, 0);\n}\ntemplate <typename S>\nS affine_mapping(Affine<S>\
    \ f, S s) {\n    return f.a * s + f.b;\n};\ntemplate <typename S>\nS_sz<S> affine_mapping_sz(Affine<S>\
    \ f, S_sz<S> s) {\n    return S_sz<S>(f.a * s.val + f.b * s.sz, s.sz);\n}\ntemplate\
    \ <typename S>\nAffine<S> affine_composition(Affine<S> f, Affine<S> g) {\n   \
    \ return Affine(f.a * g.a, f.a * g.b + f.b);\n}\ntemplate <typename S>\nS_sz<S>\
    \ chmin_mapping_sz(S f, S_sz<S> s) {\n    return S_sz(f < s.val ? f : s.val, s.sz);\n\
    }\ntemplate <typename S>\nS_sz<S> chmax_mapping_sz(S f, S_sz<S> s) {\n    return\
    \ S_sz(f > s.val ? f : s.val, s.sz);\n}\ntemplate <typename S>\nS_sz<S> add_mapping_sz(S\
    \ f, S_sz<S> s) {\n    return S_sz(s.val + f * s.sz, s.sz);\n}\ntemplate <typename\
    \ S>\nusing RChminMinQ = LazySegTree<S, min_op<S>, max_e<S>, S, min_op<S>, min_op<S>,\
    \ max_e<S>>;\ntemplate <typename S>\nusing RChminMaxQ = LazySegTree<S, max_op<S>,\
    \ min_e<S>, S, min_op<S>, min_op<S>, max_e<S>>;\n\ntemplate <typename S>\nusing\
    \ RChmaxMinQ = LazySegTree<S, min_op<S>, max_e<S>, S, max_op<S>, max_op<S>, min_e<S>>;\n\
    template <typename S>\nusing RChmaxMaxQ = LazySegTree<S, max_op<S>, min_e<S>,\
    \ S, max_op<S>, max_op<S>, min_e<S>>;\n\ntemplate <typename S>\nusing RAddMinQ\
    \ = LazySegTree<S, min_op<S>, max_e<S>, S, add_op<S>, add_op<S>, zero_e<S>>;\n\
    template <typename S>\nusing RAddMaxQ = LazySegTree<S, max_op<S>, min_e<S>, S,\
    \ add_op<S>, add_op<S>, zero_e<S>>;\ntemplate <typename S>\nusing RAddSumQ = LazySegTree<S_sz<S>,\
    \ add_op<S_sz<S>>, s_sz_zero<S>, S, add_mapping_sz<S>, add_op<S>, zero_e<S>>;\n\
    \ntemplate <typename S>\nusing RAffineMinQ = LazySegTree<S, min_op<S>, max_e<S>,\
    \ Affine<S>, affine_mapping<S>, affine_composition<S>, affine_identity<S>>;\n\
    template <typename S>\nusing RAffineMaxQ = LazySegTree<S, max_op<S>, min_e<S>,\
    \ Affine<S>, affine_mapping<S>, affine_composition<S>, affine_identity<S>>;\n\
    template <typename S>\nusing RAffineSumQ = LazySegTree<S_sz<S>, add_op<S_sz<S>>,\
    \ s_sz_zero<S>, Affine<S>, affine_mapping_sz<S>, affine_composition<S>, affine_identity<S>>;\n\
    #line 4 \"test/yosupo-range-affine-range-sum.test.cpp\"\n\nint main() {\n    int\
    \ n, q; cin >> n >> q;\n    vector<S_sz<MI3>> a(n);\n    REP(i, n) {\n       \
    \ cin >> a[i].val;\n        a[i].sz = 1;\n    }\n    RAffineSumQ<MI3> seg(a);\n\
    \    while(q--) {\n        int t; cin >> t;\n        if(t == 0) {\n          \
    \  int l, r; MI3 b, c; cin >> l >> r >> b >> c;\n            seg.apply(l, r, Affine<MI3>(b,\
    \ c));\n        } else {\n            int l, r; cin >> l >> r;\n            print(seg.prod(l,\
    \ r).val);\n        }\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../algebra/modint.hpp\"\n#include \"../segtree/lazy-segtree.hpp\"\
    \n\nint main() {\n    int n, q; cin >> n >> q;\n    vector<S_sz<MI3>> a(n);\n\
    \    REP(i, n) {\n        cin >> a[i].val;\n        a[i].sz = 1;\n    }\n    RAffineSumQ<MI3>\
    \ seg(a);\n    while(q--) {\n        int t; cin >> t;\n        if(t == 0) {\n\
    \            int l, r; MI3 b, c; cin >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, Affine<MI3>(b, c));\n        } else {\n            int l, r; cin >> l >>\
    \ r;\n            print(seg.prod(l, r).val);\n        }\n    }\n}\n\n"
  dependsOn:
  - algebra/modint.hpp
  - integer/pow-mod.hpp
  - integer/extgcd.hpp
  - base.hpp
  - stl-expansion.hpp
  - algebra/field.hpp
  - segtree/lazy-segtree.hpp
  - operator.hpp
  isVerificationFile: true
  path: test/yosupo-range-affine-range-sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-05 21:42:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-range-affine-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-range-affine-range-sum.test.cpp
- /verify/test/yosupo-range-affine-range-sum.test.cpp.html
title: test/yosupo-range-affine-range-sum.test.cpp
---
