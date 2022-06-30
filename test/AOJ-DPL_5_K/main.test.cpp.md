---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_K
    links:
    - https://github.com/online-judge-tools/template-generator)
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_K
  bundledCode: "#line 1 \"test/AOJ-DPL_5_K/main.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_K\"\
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
    }\n#line 3 \"test/AOJ-DPL_5_K/main.test.cpp\"\n\n/* #include <atcoder/all> */\n\
    /* using namespace atcoder; */\n/* #include \"expansion/ac-library/all.hpp\" */\n\
    \nvoid solve(){\n    ll n, k; cin >> n >> k;\n    print(n <= k? 1 : 0);\n}\n\n\
    // generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)\n\
    int main() {\n    // Fasterize input/output script\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(100);\n    // scanf/printf\
    \ user should delete this fasterize input/output script\n\n    int t = 1;\n  \
    \  //cin >> t; // comment out if solving multi testcase\n    for(int testCase\
    \ = 1;testCase <= t;++testCase){\n        solve();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_K\"\n#include\
    \ \"base.hpp\"\n\n/* #include <atcoder/all> */\n/* using namespace atcoder; */\n\
    /* #include \"expansion/ac-library/all.hpp\" */\n\nvoid solve(){\n    ll n, k;\
    \ cin >> n >> k;\n    print(n <= k? 1 : 0);\n}\n\n// generated by oj-template\
    \ v4.7.2 (https://github.com/online-judge-tools/template-generator)\nint main()\
    \ {\n    // Fasterize input/output script\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(100);\n    // scanf/printf\
    \ user should delete this fasterize input/output script\n\n    int t = 1;\n  \
    \  //cin >> t; // comment out if solving multi testcase\n    for(int testCase\
    \ = 1;testCase <= t;++testCase){\n        solve();\n    }\n    return 0;\n}\n"
  dependsOn:
  - base.hpp
  isVerificationFile: true
  path: test/AOJ-DPL_5_K/main.test.cpp
  requiredBy: []
  timestamp: '2022-06-30 20:37:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-DPL_5_K/main.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-DPL_5_K/main.test.cpp
- /verify/test/AOJ-DPL_5_K/main.test.cpp.html
title: test/AOJ-DPL_5_K/main.test.cpp
---
