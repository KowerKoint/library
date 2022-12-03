---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: stl-expansion.hpp
    title: stl-expansion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    }\n#line 2 \"geometry.hpp\"\n\n\ntemplate <typename T>\nbool intersection(Point<T>\
    \ p0, Point<T> p1, Point<T> p2, Point<T> p3) {\n    T o012 = (p1 - p0).outer_product(p2\
    \ - p0);\n    int s012 = (o012 > 0) - (o012 < 0);\n    T o013 = (p1 - p0).outer_product(p3\
    \ - p0);\n    int s013 = (o013 > 0) - (o013 < 0);\n    T o230 = (p3 - p2).outer_product(p0\
    \ - p2);\n    int s230 = (o230 > 0) - (o230 < 0);\n    T o231 = (p3 - p2).outer_product(p1\
    \ - p2);\n    int s231 = (o231 > 0) - (o231 < 0);\n    if(Line(p0, p1) == Line(p2,\
    \ p3)) {\n        if((p2-p0).inner_product(p3-p0) <= 0) return true;\n       \
    \ if((p2-p0).inner_product(p2-p1) <= 0) return true;\n        if((p2-p0).inner_product(p3-p1)\
    \ <= 0) return true;\n        return false;\n    }\n    return s012 * s013 <=\
    \ 0 && s230 * s231 <= 0;\n}\n\ntemplate<typename T>\nbool on_segment(Point<T>\
    \ p0, Point<T> p1, Point<T> q) {\n    if((p1 - p0).outer_product(q - p0) != 0)\
    \ return false;\n    if(q.x < min(p0.x, p1.x)) return false;\n    if(q.x > max(p0.x,\
    \ p1.x)) return false;\n    if(q.y < min(p0.y, p1.y)) return false;\n    if(q.y\
    \ > max(p0.y, p1.y)) return false;\n    return true;\n}\n\ntemplate<typename T>\n\
    double dist_ss(Point<T> p0, Point<T> p1, Point<T> p2, Point<T> p3) {\n    if(intersection(p0,\
    \ p1, p2, p3)) return 0;\n    Line<T> l1(p0, p1), l2(p2, p3);\n    double res\
    \ = min(min((p2-p0).r(), (p3-p0).r()), min((p2-p1).r(), (p3-p1).r()));\n    Point<T>\
    \ pr0 = l2.proj(p0), pr1 = l2.proj(p1), pr2 = l1.proj(p2), pr3 = l1.proj(p3);\n\
    \    if(on_segment(p2, p3, pr0)) chmin(res, l2.dist(p0));\n    if(on_segment(p2,\
    \ p3, pr1)) chmin(res, l2.dist(p1));\n    if(on_segment(p0, p1, pr2)) chmin(res,\
    \ l1.dist(p2));\n    if(on_segment(p0, p1, pr3)) chmin(res, l1.dist(p3));\n  \
    \  return res;\n}\n\ntemplate<typename T=double>\nstruct Polygon {\n    vector<Point<T>>\
    \ Points;\n    Polygon(int n) {\n        assert(n >= 1);\n        Points.resize(n);\n\
    \    }\n    Polygon(vector<Point<T>> Points) : Points(Points) {}\n    friend istream&\
    \ operator>>(istream& is, Polygon& polygon) {\n        for(int i = 0; i < polygon.Points.size();\
    \ i++) is >> polygon.Points[i];\n        return is;\n    }\n    T area() {\n \
    \       T res = 0;\n        int n = Points.size();\n        for(int i = 1; i +\
    \ 1 < Points.size(); i++) {\n            res += (Points[i] - Points[0]).outer_product(Points[i+1]\
    \ - Points[0]);\n        }\n        return res / 2;\n    }\n    bool is_convex()\
    \ {\n        int n = Points.size();\n        for(int i = 0; i < n; i++) {\n  \
    \          int j = (i + 1) % n;\n            int k = (j + 1) % n;\n          \
    \  if((Points[k] - Points[j]).outer_product(Points[i] - Points[j]) < 0) return\
    \ false;\n        }\n        return true;\n    }\n    // inside: 2, on: 1, outside:\
    \ 0\n    int contains(Point<T> p) {\n        int n = Points.size();\n        int\
    \ cnt = 0;\n        double theta_sum = 0;\n        for(int i = 0; i < n; i++)\
    \ {\n            if(on_segment(Points[i], Points[(i+1)%n], p)) return 1;\n   \
    \         double theta = (Points[(i+1)%n] - p).theta() - (Points[i] - p).theta();\n\
    \            if(theta < -M_PI) theta += 2 * M_PI;\n            if(theta > M_PI)\
    \ theta -= 2 * M_PI;\n            theta_sum += theta;\n        }\n        if(abs(theta_sum)\
    \ < M_PI) return 0;\n        return 2;\n    }\n};\n"
  code: "#include \"base.hpp\"\n\n\ntemplate <typename T>\nbool intersection(Point<T>\
    \ p0, Point<T> p1, Point<T> p2, Point<T> p3) {\n    T o012 = (p1 - p0).outer_product(p2\
    \ - p0);\n    int s012 = (o012 > 0) - (o012 < 0);\n    T o013 = (p1 - p0).outer_product(p3\
    \ - p0);\n    int s013 = (o013 > 0) - (o013 < 0);\n    T o230 = (p3 - p2).outer_product(p0\
    \ - p2);\n    int s230 = (o230 > 0) - (o230 < 0);\n    T o231 = (p3 - p2).outer_product(p1\
    \ - p2);\n    int s231 = (o231 > 0) - (o231 < 0);\n    if(Line(p0, p1) == Line(p2,\
    \ p3)) {\n        if((p2-p0).inner_product(p3-p0) <= 0) return true;\n       \
    \ if((p2-p0).inner_product(p2-p1) <= 0) return true;\n        if((p2-p0).inner_product(p3-p1)\
    \ <= 0) return true;\n        return false;\n    }\n    return s012 * s013 <=\
    \ 0 && s230 * s231 <= 0;\n}\n\ntemplate<typename T>\nbool on_segment(Point<T>\
    \ p0, Point<T> p1, Point<T> q) {\n    if((p1 - p0).outer_product(q - p0) != 0)\
    \ return false;\n    if(q.x < min(p0.x, p1.x)) return false;\n    if(q.x > max(p0.x,\
    \ p1.x)) return false;\n    if(q.y < min(p0.y, p1.y)) return false;\n    if(q.y\
    \ > max(p0.y, p1.y)) return false;\n    return true;\n}\n\ntemplate<typename T>\n\
    double dist_ss(Point<T> p0, Point<T> p1, Point<T> p2, Point<T> p3) {\n    if(intersection(p0,\
    \ p1, p2, p3)) return 0;\n    Line<T> l1(p0, p1), l2(p2, p3);\n    double res\
    \ = min(min((p2-p0).r(), (p3-p0).r()), min((p2-p1).r(), (p3-p1).r()));\n    Point<T>\
    \ pr0 = l2.proj(p0), pr1 = l2.proj(p1), pr2 = l1.proj(p2), pr3 = l1.proj(p3);\n\
    \    if(on_segment(p2, p3, pr0)) chmin(res, l2.dist(p0));\n    if(on_segment(p2,\
    \ p3, pr1)) chmin(res, l2.dist(p1));\n    if(on_segment(p0, p1, pr2)) chmin(res,\
    \ l1.dist(p2));\n    if(on_segment(p0, p1, pr3)) chmin(res, l1.dist(p3));\n  \
    \  return res;\n}\n\ntemplate<typename T=double>\nstruct Polygon {\n    vector<Point<T>>\
    \ Points;\n    Polygon(int n) {\n        assert(n >= 1);\n        Points.resize(n);\n\
    \    }\n    Polygon(vector<Point<T>> Points) : Points(Points) {}\n    friend istream&\
    \ operator>>(istream& is, Polygon& polygon) {\n        for(int i = 0; i < polygon.Points.size();\
    \ i++) is >> polygon.Points[i];\n        return is;\n    }\n    T area() {\n \
    \       T res = 0;\n        int n = Points.size();\n        for(int i = 1; i +\
    \ 1 < Points.size(); i++) {\n            res += (Points[i] - Points[0]).outer_product(Points[i+1]\
    \ - Points[0]);\n        }\n        return res / 2;\n    }\n    bool is_convex()\
    \ {\n        int n = Points.size();\n        for(int i = 0; i < n; i++) {\n  \
    \          int j = (i + 1) % n;\n            int k = (j + 1) % n;\n          \
    \  if((Points[k] - Points[j]).outer_product(Points[i] - Points[j]) < 0) return\
    \ false;\n        }\n        return true;\n    }\n    // inside: 2, on: 1, outside:\
    \ 0\n    int contains(Point<T> p) {\n        int n = Points.size();\n        int\
    \ cnt = 0;\n        double theta_sum = 0;\n        for(int i = 0; i < n; i++)\
    \ {\n            if(on_segment(Points[i], Points[(i+1)%n], p)) return 1;\n   \
    \         double theta = (Points[(i+1)%n] - p).theta() - (Points[i] - p).theta();\n\
    \            if(theta < -M_PI) theta += 2 * M_PI;\n            if(theta > M_PI)\
    \ theta -= 2 * M_PI;\n            theta_sum += theta;\n        }\n        if(abs(theta_sum)\
    \ < M_PI) return 0;\n        return 2;\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: geometry.hpp
  requiredBy: []
  timestamp: '2022-12-03 20:54:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry.hpp
layout: document
redirect_from:
- /library/geometry.hpp
- /library/geometry.hpp.html
title: geometry.hpp
---
