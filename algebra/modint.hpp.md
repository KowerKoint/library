---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/field.hpp
    title: algebra/field.hpp
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
    path: stl-expansion.hpp
    title: stl-expansion.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/fps.hpp
    title: algebra/fps.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
  - icon: ':warning:'
    path: general.hpp
    title: general.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-b.test.cpp
    title: test/aoj-dpl-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-d.test.cpp
    title: test/aoj-dpl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-e.test.cpp
    title: test/aoj-dpl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-g.test.cpp
    title: test/aoj-dpl-5-g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-i.test.cpp
    title: test/aoj-dpl-5-i.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-j.test.cpp
    title: test/aoj-dpl-5-j.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-ntl-1-b.test.cpp
    title: test/aoj-ntl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-convolution.test.cpp
    title: test/yosupo-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-determinant-of-matrix.test.cpp
    title: test/yosupo-determinant-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
    title: test/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-range-affine-range-sum.test.cpp
    title: test/yosupo-range-affine-range-sum.test.cpp
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
    using V7 = vector<MI7>;\nusing VV7 = vector<V7>;\nusing VVV7 = vector<VV7>;\n"
  code: "#pragma once\n#include \"../integer/pow-mod.hpp\"\n#include \"field.hpp\"\
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
    using V7 = vector<MI7>;\nusing VV7 = vector<V7>;\nusing VVV7 = vector<VV7>;\n"
  dependsOn:
  - integer/pow-mod.hpp
  - integer/extgcd.hpp
  - base.hpp
  - stl-expansion.hpp
  - algebra/field.hpp
  isVerificationFile: false
  path: algebra/modint.hpp
  requiredBy:
  - convolution/ntt.hpp
  - algebra/fps.hpp
  - general.hpp
  timestamp: '2023-03-02 00:13:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - test/yosupo-range-affine-range-sum.test.cpp
  - test/aoj-ntl-1-b.test.cpp
  - test/aoj-dpl-5-b.test.cpp
  - test/yosupo-determinant-of-matrix.test.cpp
  - test/aoj-dpl-5-g.test.cpp
  - test/aoj-dpl-5-i.test.cpp
  - test/aoj-dpl-5-d.test.cpp
  - test/yosupo-convolution.test.cpp
  - test/aoj-dpl-5-j.test.cpp
  - test/aoj-dpl-5-e.test.cpp
documentation_of: algebra/modint.hpp
layout: document
redirect_from:
- /library/algebra/modint.hpp
- /library/algebra/modint.hpp.html
title: algebra/modint.hpp
---
