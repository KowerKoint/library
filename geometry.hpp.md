---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    }\n#line 2 \"geometry.hpp\"\n\ntemplate <typename T=double>\nstruct Point {\n\
    \    T x, y;\n    Point(T x = 0, T y = 0) : x(x), y(y) {}\n    friend istream&\
    \ operator>>(istream& is, Point& p) {\n        is >> p.x >> p.y;\n        return\
    \ is;\n    }\n    friend ostream& operator<<(ostream& os, const Point& p) {\n\
    \        os << p.x << ' ' << p.y;\n        return os;\n    }\n    Point& operator+=\
    \ (const Point& p) {\n        x += p.x;\n        y += p.y;\n        return *this;\n\
    \    }\n    Point operator+(const Point& p) const {\n        return Point(*this)\
    \ += p;\n    }\n    Point& operator-= (const Point& p) {\n        x -= p.x;\n\
    \        y -= p.y;\n        return *this;\n    }\n    Point operator-(const Point&\
    \ p) const {\n        return Point(*this) -= p;\n    }\n    Point& operator*=(T\
    \ k) {\n        x *= k;\n        y *= k;\n        return *this;\n    }\n    Point\
    \ operator*(T k) const {\n        return Point(*this) *= k;\n    }\n    T inner_product(const\
    \ Point& p) const {\n        return x * p.x + y * p.y;\n    }\n    T outer_product(const\
    \ Point& p) const {\n        return x * p.y - y * p.x;\n    }\n    T r2() const\
    \ {\n        return x * x + y * y;\n    }\n    double r() const {\n        return\
    \ sqrt(x * x + y * y);\n    }\n    double theta() const {\n        return atan2(y,\
    \ x);\n    }\n    double operator/(const Point& p) const {\n        T r1 = r(),\
    \ r2 = p.r();\n        double theta1 = theta(), theta2 = p.theta();\n        return\
    \ r1 / r2 * cos(theta1 - theta2);\n    }\n};\n\ntemplate <typename T=double>\n\
    struct Line {\n    T a, b, c; // ax + by + c = 0\n    Line(Point<T> p1, Point<T>\
    \ p2) {\n        a = p2.y - p1.y;\n        b = -(p2.x - p1.x);\n        c = -a\
    \ * p1.x - b * p1.y;\n    }\n    Line(T a, T b, T c) {\n        this->a = a;\n\
    \        this->b = b;\n        this->c = c;\n    }\n    Point<T> direction() {\n\
    \        return Point<T>(b, -a);\n    }\n    Point<T> proj(Point<T> p) {\n   \
    \     T x = (b * (b * p.x - a * p.y) - a * c) / (a * a + b * b);\n        T y\
    \ = (a * (a * p.y - b * p.x) - b * c) / (a * a + b * b);\n        return Point<T>(x,\
    \ y);\n    }\n    Point<T> reflect(Point<T> p) {\n        return p + (proj(p)\
    \ - p) * 2;\n    }\n};\n"
  code: "#include \"base.hpp\"\n\ntemplate <typename T=double>\nstruct Point {\n \
    \   T x, y;\n    Point(T x = 0, T y = 0) : x(x), y(y) {}\n    friend istream&\
    \ operator>>(istream& is, Point& p) {\n        is >> p.x >> p.y;\n        return\
    \ is;\n    }\n    friend ostream& operator<<(ostream& os, const Point& p) {\n\
    \        os << p.x << ' ' << p.y;\n        return os;\n    }\n    Point& operator+=\
    \ (const Point& p) {\n        x += p.x;\n        y += p.y;\n        return *this;\n\
    \    }\n    Point operator+(const Point& p) const {\n        return Point(*this)\
    \ += p;\n    }\n    Point& operator-= (const Point& p) {\n        x -= p.x;\n\
    \        y -= p.y;\n        return *this;\n    }\n    Point operator-(const Point&\
    \ p) const {\n        return Point(*this) -= p;\n    }\n    Point& operator*=(T\
    \ k) {\n        x *= k;\n        y *= k;\n        return *this;\n    }\n    Point\
    \ operator*(T k) const {\n        return Point(*this) *= k;\n    }\n    T inner_product(const\
    \ Point& p) const {\n        return x * p.x + y * p.y;\n    }\n    T outer_product(const\
    \ Point& p) const {\n        return x * p.y - y * p.x;\n    }\n    T r2() const\
    \ {\n        return x * x + y * y;\n    }\n    double r() const {\n        return\
    \ sqrt(x * x + y * y);\n    }\n    double theta() const {\n        return atan2(y,\
    \ x);\n    }\n    double operator/(const Point& p) const {\n        T r1 = r(),\
    \ r2 = p.r();\n        double theta1 = theta(), theta2 = p.theta();\n        return\
    \ r1 / r2 * cos(theta1 - theta2);\n    }\n};\n\ntemplate <typename T=double>\n\
    struct Line {\n    T a, b, c; // ax + by + c = 0\n    Line(Point<T> p1, Point<T>\
    \ p2) {\n        a = p2.y - p1.y;\n        b = -(p2.x - p1.x);\n        c = -a\
    \ * p1.x - b * p1.y;\n    }\n    Line(T a, T b, T c) {\n        this->a = a;\n\
    \        this->b = b;\n        this->c = c;\n    }\n    Point<T> direction() {\n\
    \        return Point<T>(b, -a);\n    }\n    Point<T> proj(Point<T> p) {\n   \
    \     T x = (b * (b * p.x - a * p.y) - a * c) / (a * a + b * b);\n        T y\
    \ = (a * (a * p.y - b * p.x) - b * c) / (a * a + b * b);\n        return Point<T>(x,\
    \ y);\n    }\n    Point<T> reflect(Point<T> p) {\n        return p + (proj(p)\
    \ - p) * 2;\n    }\n};\n"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: geometry.hpp
  requiredBy: []
  timestamp: '2022-06-30 23:59:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry.hpp
layout: document
redirect_from:
- /library/geometry.hpp
- /library/geometry.hpp.html
title: geometry.hpp
---
