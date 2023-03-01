---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/field.hpp
    title: algebra/field.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/ratio.hpp
    title: algebra/ratio.hpp
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
  bundledCode: "#line 1 \"test/aoj-cgl-3-a.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
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
    \ return T::is_finite;\n    else return false;\n}\n#line 2 \"geometry/point.hpp\"\
    \n\ntemplate <typename T, size_t dim>\nstruct SumGroupPoint : SumGroupBase<array<T,\
    \ dim>> {\n    static array<T, dim> addassign(array<T, dim> &a, const array<T,\
    \ dim> &b) {\n        for (size_t i = 0; i < dim; i++) {\n            a[i] +=\
    \ b[i];\n        }\n        return a;\n    }\n    constexpr static bool defzero\
    \ = true;\n    const static array<T, dim> zero;\n    static array<T, dim> minus(const\
    \ array<T, dim> &a) {\n        array<T, dim> res;\n        for (size_t i = 0;\
    \ i < dim; i++) {\n            res[i] = -a[i];\n        }\n        return res;\n\
    \    }\n    using Coef = T;\n    using Scalar = T;\n    static array<T, dim> coefassign(array<T,\
    \ dim> &a, const T &b) {\n        for (size_t i = 0; i < dim; i++) {\n       \
    \     a[i] *= b;\n        }\n        return a;\n    }\n    static T dot(const\
    \ array<T, dim> &a, const array<T, dim> &b) {\n        T res = ::zero<T>();\n\
    \        for (size_t i = 0; i < dim; i++) {\n            res += a[i] * b[i];\n\
    \        }\n        return res;\n    }\n};\ntemplate <typename T, size_t dim>\n\
    const array<T, dim> SumGroupPoint<T, dim>::zero = [] {\n    array<T, dim> res;\n\
    \    for (size_t i = 0; i < dim; i++) {\n        res[i] = ::zero<T>();\n    }\n\
    \    return res;\n}();\ntemplate <typename T, size_t dim=2>\nusing Point = Field<array<T,\
    \ dim>, SumGroupPoint<T, dim>>;\n\ntemplate <typename T, size_t dim>\ndouble abs(const\
    \ Point<T, dim> &a) {\n    return sqrt(a.norm());\n}\ntemplate <typename T>\n\
    double theta(const Point<T, 2> &a) {\n    return atan2(a[1], a[0]);\n}\ntemplate\
    \ <typename T>\nstruct CompareTheta {\n    bool operator()(const Point<T, 2> &a,\
    \ const Point<T, 2> &b) const {\n        if (a[1] >= 0 && b[1] < 0) return true;\n\
    \        if (a[1] < 0 && b[1] >= 0) return false;\n        if (a[1] == 0 && b[1]\
    \ == 0) {\n            if (a[0] >= 0 && b[0] < 0) return true;\n            return\
    \ false;\n        }\n        return a[0] * b[1] - a[1] * b[0] > 0;\n    }\n};\n\
    template <typename T>\nT outer_product(const Point<T, 2> &a, const Point<T, 2>\
    \ &b) {\n    return a[0] * b[1] - a[1] * b[0];\n}\ntemplate <typename T>\nPoint<T,\
    \ 3> outer_product(const Point<T, 3> &a, const Point<T, 3> &b) {\n    return Point<T,\
    \ 3>({a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1]\
    \ * b[0]});\n}\ntemplate <typename T>\npair<bool, Point<T, 2>> segment_intersect(const\
    \ Point<T, 2> &p0, const Point<T, 2> &p1, const Point<T, 2> &p2, const Point<T,\
    \ 2> &p3) {\n    T o012 = outer_product(p1 - p0, p2 - p0);\n    int s012 = (o012\
    \ > 0) - (o012 < 0);\n    T o013 = outer_product(p1 - p0, p3 - p0);\n    int s013\
    \ = (o013 > 0) - (o013 < 0);\n    T o230 = outer_product(p3 - p2, p0 - p2);\n\
    \    int s230 = (o230 > 0) - (o230 < 0);\n    T o231 = outer_product(p3 - p2,\
    \ p1 - p2);\n    int s231 = (o231 > 0) - (o231 < 0);\n    if(s012 == 0 && s013\
    \ == 0) {\n        if((p2-p0).dot(p3-p0) <= 0) return {true, p0};\n        if((p2-p1).dot(p3-p1)\
    \ <= 0) return {true, p1};\n        if((p0-p2).dot(p1-p2) <= 0) return {true,\
    \ p2};\n        if((p0-p3).dot(p1-p3) <= 0) return {true, p3};\n        return\
    \ {false, Point<double>()};\n    }\n    if(s012 * s013 <= 0 && s230 * s231 <=\
    \ 0) {\n        T kn = o230;\n        T kd = outer_product(p1-p0, p3-p2);\n  \
    \      Point<T> p01 = p1 - p0;\n        if constexpr(is_integral<T>::value) {\n\
    \            T g = gcd(kn, kd);\n            kn /= g;\n            kd /= g;\n\
    \            assert(gcd(p01[0], p01[1]) % kd == 0);\n            p01[0] /= kd;\n\
    \            p01[1] /= kd;\n            return {true, p0 + p01 * kn};\n      \
    \  } else {\n            return {true, p0 + p01 * kn * (one<T>()/ kd)};\n    \
    \    }\n    }\n    return {false, Point<double>()};\n}\n\ntemplate <typename T>\n\
    double closest_point_pair(const vector<Point<T, 2>>& _ps) {\n    vector<Point<T,\
    \ 2>> ps = _ps;\n    sort(ps.begin(), ps.end(), [](const Point<T, 2> &a, const\
    \ Point<T, 2> &b) {\n        return a[0] < b[0];\n    });\n    int n = ps.size();\n\
    \    stack<tuple<int, int, int>> stk;\n    stk.emplace(~0, n, 0);\n    stk.emplace(0,\
    \ n, 0);\n    vector<double> retval;\n    VI par;\n    par.push_back(-1);\n  \
    \  while(!stk.empty()) {\n        auto [l, r, d] = stk.top(); stk.pop();\n   \
    \     if(l >= 0) {\n            if(l + 1 >= r) continue;\n            if((int)retval.size()\
    \ <= d) retval.resize(d+1, 1e100);\n            int m = (l + r) / 2;\n       \
    \     stk.emplace(~l, m, par.size());\n            stk.emplace(l, m, par.size());\n\
    \            par.push_back(d);\n            stk.emplace(~m, r, par.size());\n\
    \            stk.emplace(m, r, par.size());\n            par.push_back(d);\n \
    \       } else {\n            l = ~l;\n            if(l + 1 >= r) continue;\n\
    \            int m = (l + r) / 2;\n            vector<Point<T, 2>> ps2;\n    \
    \        for(int i = l; i < r; i++) {\n                if(abs(ps[i][0] - ps[m][0])\
    \ + 1e-12 < retval[d]) {\n                    ps2.push_back(ps[i]);\n        \
    \        }\n            }\n            sort(ps2.begin(), ps2.end(), [](const Point<T,\
    \ 2> &a, const Point<T, 2> &b) {\n                return a[1] < b[1];\n      \
    \      });\n            REP(i, ps2.size()) {\n                for(int j = i+1;\
    \ j < (int)ps2.size() && ps2[j][1] - ps2[i][1] + 1e-12 < retval[d]; j++) {\n \
    \                   chmin(retval[d], abs(ps2[i] - ps2[j]));\n                }\n\
    \            }\n            if(d > 0) {\n                chmin(retval[par[d]],\
    \ retval[d]);\n            }\n        }\n    }\n    return retval[0];\n}\n#line\
    \ 3 \"algebra/ratio.hpp\"\n\ntemplate <typename T, size_t dim>\nstruct RepresentationRatio\
    \ : RepresentationBase<T> {\n    using R = array<T, dim>;\n    constexpr static\
    \ array<T, dim> construct(const R& x) {\n        return x;\n    }\n    constexpr\
    \ static R represent(const array<T, dim>& x) {\n        array<T, dim> ret = x;\n\
    \        if constexpr(is_integral_v<T>) {\n            T g = 0;\n            for(size_t\
    \ i = 0; i < dim; i++) {\n                g = gcd(g, ret[i]);\n            }\n\
    \            for(size_t i = 0; i < dim; i++) {\n                ret[i] /= g;\n\
    \            }\n            for(size_t i = 0; i < dim; i++) {\n              \
    \  if(ret[i] == 0) continue;\n                if(ret[i] < 0) {\n             \
    \       for(size_t j = i; j < dim; j++) {\n                        ret[j] = -ret[j];\n\
    \                    }\n                }\n                break;\n          \
    \  }\n        }\n        return ret;\n    }\n};\ntemplate <typename T, size_t\
    \ dim>\nstruct CompareRatio : CompareBase<T> {\n    constexpr static bool lt(const\
    \ array<T, dim>& x, const array<T, dim>& y) {\n        static_assert(dim == 2);\n\
    \        return x[0] * y[1] < x[1] * y[0];\n    }\n    constexpr static bool eq(const\
    \ array<T, dim>& x, const array<T, dim>& y) {\n        return RepresentationRatio<T,\
    \ dim>::represent(x) == RepresentationRatio<T, dim>::represent(y);\n    }\n};\n\
    template <typename T, size_t dim>\nusing Ratio = Field<array<T, dim>, SumGroupBase<array<T,\
    \ dim>>, ProdGroupBase<array<T, dim>>, RepresentationRatio<T, dim>, CompareRatio<T,\
    \ dim>>;\n#line 4 \"geometry/line.hpp\"\n\ntemplate <typename T, size_t dim=2>\n\
    struct Line {\n    Point<T, dim> a;\n    Ratio<T, dim> d;\n    Line() = default;\n\
    \    Line(const Point<T, dim>& a, const Point<T, dim>& b) : a(a), d((b - a).represent())\
    \ {}\n    Line(const Point<T, dim>& a, const Ratio<T, dim>& d) : a(a), d(d) {}\n\
    \    Point<T, dim> operator()(const T& k) const {\n        Point<T, dim> dp(d.represent());\n\
    \        return a + dp * k;\n    }\n    Point<T, dim> proj(const Point<T, dim>&\
    \ p) const {\n        Point<T, dim> dp(d.represent());\n        T kn = dp.dot(p\
    \ - a);\n        T kd = dp.norm();\n        if constexpr(is_integral_v<T>) {\n\
    \            assert(kn % kd == 0);\n        }\n        return a + dp * (kn / kd);\n\
    \    }\n    Point<T, dim> reflect(const Point<T, dim>& p) const {\n        return\
    \ proj(p) * 2 - p;\n    }\n    bool parallel(const Line& l) const {\n        return\
    \ d == l.d;\n    }\n    bool orthogonal(const Line& l) const {\n        Point<T,\
    \ dim> dp(d.represent());\n        Point<T, dim> ldp(l.d.represent());\n     \
    \   return dp.dot(ldp) == 0;\n    }\n    bool on_line(const Point<T, dim>& p)\
    \ const {\n        Point<T, dim> dp(d.represent());\n        T inpro = dp.dot(p\
    \ - a);\n        return inpro * inpro == d.norm() * (p - a).norm();\n    }\n \
    \   bool operator==(const Line& l) const {\n        return parallel(l) && on_line(l.a);\n\
    \    }\n    double dist(const Point<T, dim>& p) const {\n        return abs(p\
    \ - proj(p));\n    }\n};\n\ntemplate <typename T>\nstruct Line2D {\n    T a, b,\
    \ c; // ax + by + c = 0\n    Line2D(Point<T,2> p1, Point<T,2> p2) {\n        a\
    \ = p2[1] - p1[1];\n        b = -(p2[0] - p1[0]);\n        c = -a * p1[0] - b\
    \ * p1[1];\n    }\n    Line2D(T a, T b, T c) {\n        this->a = a;\n       \
    \ this->b = b;\n        this->c = c;\n    }\n    Line2D(const Line<T, 2>& l) {\n\
    \        a = l.d[1];\n        b = -l.d[0];\n        c = -a * l.a[0] - b * l.a[1];\n\
    \    }\n    Ratio<T,2> direction() {\n        return {b, -a};\n    }\n    Point<T,2>\
    \ proj(Point<T,2> Points) {\n        T d = a * a + b * b;\n        T x_n = b *\
    \ (b * Points[0] - a * Points[1]) - a * c;\n        T y_n = a * (a * Points[1]\
    \ - b * Points[0]) - b * c;\n        if constexpr(is_integral_v<T>) {\n      \
    \      assert(x_n % d == 0);\n            assert(y_n % d == 0);\n        }\n \
    \       return {x_n / d, y_n / d};\n    }\n    Point<T,2> reflect(Point<T,2> Points)\
    \ {\n        return Points + (proj(Points) - Points) * 2;\n    }\n    bool parallel(const\
    \ Line2D<T>& l) const {\n        return a * l.b == b * l.a;\n    }\n    bool orthogonal(const\
    \ Line2D<T>& l) const {\n        return a * l.a + b * l.b == 0;\n    }\n    bool\
    \ on_line(Point<T,2> Points) {\n        return a * Points[0] + b * Points[1] +\
    \ c == 0;\n    }\n    bool operator==(const Line2D<T>& l) const {\n        return\
    \ a * l.c == c * l.a && b * l.c == c * l.b;\n    }\n    Point<T,2> cross_point(Line2D<T>\
    \ l) {\n        T x_n = b * l.c - c * l.b;\n        T x_d = a * l.b - b * l.a;\n\
    \        T y_n = a * l.c - c * l.a;\n        T y_d = b * l.a - a * l.b;\n    \
    \    if constexpr(is_integral_v<T>) {\n            assert(x_n % x_d == 0);\n \
    \           assert(y_n % y_d == 0);\n        }\n        return Point<T, 2>({x_n\
    \ / x_d, y_n / y_d});\n    }\n    double dist(Point<T,2> Points) {\n        return\
    \ sqrt(dist2(Points));\n    }\n};\n#line 3 \"geometry/segment.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Segment {\n    Point<T, 2> a, b;\n    Segment() = default;\n\
    \    Segment(const Point<T, 2>& a, const Point<T, 2>& b) : a(a), b(b) {}\n   \
    \ bool operator==(const Segment& rhs) const { return a == rhs.a && b == rhs.b;\
    \ }\n    bool operator!=(const Segment& rhs) const { return !(*this == rhs); }\n\
    \    bool intersect(const Segment<T>& other) const {\n        if(Line<T, 2>(a,\
    \ b) == Line<T, 2>(other.a, other.b)) {\n            if((other.a-a).dot(other.b-a)\
    \ <= 0) return true;\n            if((other.a-a).dot(other.a-b) <= 0) return true;\n\
    \            if((other.a-a).dot(other.b-b) <= 0) return true;\n            return\
    \ false;\n        }\n        T o012 = outer_product(b - a, other.a - a);\n   \
    \     int s012 = (o012 > zero<T>()) - (o012 < zero<T>());\n        T o013 = outer_product(b\
    \ - a, other.b - a);\n        int s013 = (o013 > zero<T>()) - (o013 < zero<T>());\n\
    \        T o230 = outer_product(other.b - other.a, a - other.a);\n        int\
    \ s230 = (o230 > zero<T>()) - (o230 < zero<T>());\n        T o231 = outer_product(other.b\
    \ - other.a, b - other.a);\n        int s231 = (o231 > zero<T>()) - (o231 < zero<T>());\n\
    \        return s012 * s013 <= 0 && s230 * s231 <= 0;\n    }\n    bool on_segment(const\
    \ Point<T, 2>& p) const {\n        if(outer_product(b - a, p - a) != zero<T>())\
    \ return false;\n        if(p[0] < min(a[0], b[0]) || p[0] > max(a[0], b[0]))\
    \ return false;\n        if(p[1] < min(a[1], b[1]) || p[1] > max(a[1], b[1]))\
    \ return false;\n        return true;\n    }\n    double dist(const Point<T, 2>&\
    \ p) const {\n        if((b - a).dot(p - a) < zero<T>()) return abs(p - a);\n\
    \        if((a - b).dot(p - b) < zero<T>()) return abs(p - b);\n        return\
    \ abs(outer_product(b - a, p - a)) / abs(b - a);\n    }\n    double dist(const\
    \ Segment<T>& other) const {\n        if(intersect(other)) return 0;\n       \
    \ return min({dist(other.a), dist(other.b), other.dist(a), other.dist(b)});\n\
    \    }\n    int outer_product_sign(const Point<T, 2>& p) const {\n        T o\
    \ = outer_product(b - a, p - a);\n        return (o > zero<T>()) - (o < zero<T>());\n\
    \    }\n};\n#line 3 \"geometry/polygon.hpp\"\n\ntemplate<typename T=double>\n\
    struct Polygon {\n    vector<Point<T, 2>> points;\n    Polygon(int n) {\n    \
    \    assert(n >= 1);\n        points.resize(n);\n    }\n    Polygon(vector<Point<T,\
    \ 2>> points) : points(points) {}\n    friend istream& operator>>(istream& is,\
    \ Polygon& polygon) {\n        return is >> polygon.points;\n    }\n    friend\
    \ ostream& operator<<(ostream& os, Polygon& polygon) {\n        return os << polygon.points;\n\
    \    }\n    Point<T, 2>& operator[](int i) {\n        return points[i];\n    }\n\
    \    const Point<T, 2>& operator[](int i) const {\n        return points[i];\n\
    \    }\n    int size() const {\n        return points.size();\n    }\n    using\
    \ iterator = typename vector<Point<T, 2>>::iterator;\n    using const_iterator\
    \ = typename vector<Point<T, 2>>::const_iterator;\n    iterator begin() { return\
    \ points.begin(); }\n    iterator end() { return points.end(); }\n    const_iterator\
    \ begin() const { return points.begin(); }\n    const_iterator end() const { return\
    \ points.end(); }\n    T area2() {\n        T res = 0;\n        int n = points.size();\n\
    \        for(int i = 1; i + 1 < n; i++) {\n            res += outer_product(points[i]\
    \ - points[0], points[i+1] - points[0]);\n        }\n        return res;\n   \
    \ }\n    T area() {\n        T a = area2();\n        if constexpr(is_integral_v<T>)\
    \ assert(a % 2 == 0);\n        return a / 2;\n    }\n    bool is_convex() {\n\
    \        int n = points.size();\n        for(int i = 0; i < n; i++) {\n      \
    \      int j = (i + 1) % n;\n            int k = (j + 1) % n;\n            if(outer_product(points[k]\
    \ - points[j], points[i] - points[j]) < 0) return false;\n        }\n        return\
    \ true;\n    }\n    // inside: 2, on: 1, outside: 0\n    int contains(Point<T,\
    \ 2> p) {\n        int n = points.size();\n        double t_sum = 0;\n       \
    \ for(int i = 0; i < n; i++) {\n            if(Segment<T>(points[i], points[(i+1)%n]).on_segment(p))\
    \ return 1;\n            double t = theta(points[(i+1)%n] - p) - theta(points[i]\
    \ - p);\n            if(t < -M_PI) t += 2 * M_PI;\n            if(t > M_PI) t\
    \ -= 2 * M_PI;\n            t_sum += t;\n        }\n        if(abs(t_sum) < M_PI)\
    \ return 0;\n        return 2;\n    }\n};\n\ntemplate <typename T>\nvector<Point<T,\
    \ 2>> select_convex(const vector<Point<T, 2>>& v) {\n    vector<Point<T, 2>> res;\n\
    \    for(auto& p : v) {\n        while(res.size() >= 2 && outer_product(res.back()\
    \ - res[res.size()-2], p - res.back()) < 0) {\n            res.pop_back();\n \
    \       }\n        res.push_back(p);\n    }\n    return res;\n}\n\ntemplate <typename\
    \ T>\nPolygon<T> convex_hull(const vector<Point<T, 2>>& v) {\n    vector<Point<T,\
    \ 2>> sorted = v;\n    vector<Point<T, 2>> res;\n    sort(sorted.begin(), sorted.end());\n\
    \    vector<Point<T, 2>> lower_hull = select_convex(sorted);\n    vector<Point<T,\
    \ 2>> upper_hull = select_convex(vector<Point<T, 2>>(sorted.rbegin(), sorted.rend()));\n\
    \    res.reserve(lower_hull.size() + upper_hull.size() - 2);\n    for(auto& p\
    \ : lower_hull) res.push_back(p);\n    for(int i = 1; i + 1 < (int)upper_hull.size();\
    \ i++) res.push_back(upper_hull[i]);\n    return Polygon<T>(res);\n}\n#line 3\
    \ \"test/aoj-cgl-3-a.test.cpp\"\n\nint main() {\n    int n; cin >> n;\n    Polygon<double>\
    \ poly(n); cin >> poly;\n    cout << fixed << setprecision(1) << poly.area() <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n#include \"../geometry/polygon.hpp\"\n\nint main() {\n    int n; cin >> n;\n\
    \    Polygon<double> poly(n); cin >> poly;\n    cout << fixed << setprecision(1)\
    \ << poly.area() << endl;\n}\n"
  dependsOn:
  - geometry/polygon.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/point.hpp
  - algebra/field.hpp
  - base.hpp
  - stl-expansion.hpp
  - algebra/ratio.hpp
  isVerificationFile: true
  path: test/aoj-cgl-3-a.test.cpp
  requiredBy: []
  timestamp: '2023-03-02 00:13:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-cgl-3-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-cgl-3-a.test.cpp
- /verify/test/aoj-cgl-3-a.test.cpp.html
title: test/aoj-cgl-3-a.test.cpp
---
