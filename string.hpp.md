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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string.hpp\"\n\n#line 2 \"stl-expansion.hpp\"\n#include\
    \ <bits/stdc++.h>\n\ntemplate <typename T1, typename T2>\nstd::istream& operator>>(std::istream&\
    \ is, std::pair<T1, T2>& p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T, size_t N>\nstd::istream& operator>>(std::istream& is,\
    \ std::array<T, N>& a) {\n    for (size_t i = 0; i < N; ++i) {\n        is >>\
    \ a[i];\n    }\n    return is;\n}\ntemplate <typename T>\nstd::istream& operator>>(std::istream&\
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
    }\n#line 4 \"string.hpp\"\n\ntemplate <typename It>\nvector<int> kmp_table(It\
    \ begin, It end) {\n    int m = end - begin;\n    vector<int> table(m);\n    int\
    \ j = 0;\n    FOR(i, 1, m) {\n        while(j > 0 && *(begin+i) != *(begin+j))\
    \ j = table[j-1];\n        if(*(begin+i) == *(begin+j)) table[i] = ++j;\n    }\n\
    \    return table;\n}\n\nvector<int> kmp_table(string& t) {\n    return kmp_table(ALL(t));\n\
    }\n\ntemplate <typename It>\nvector<int> kmp_find(It s_begin, It s_end, It t_begin,\
    \ It t_end, vector<int>& table) {\n    int n = s_end - s_begin;\n    int m = t_end\
    \ - t_begin;\n    vector<int> res;\n    int j = 0;\n    REP(i, n) {\n        while(j\
    \ > 0 && *(s_begin+i) != *(t_begin+j)) j = table[j-1];\n        if(*(s_begin+i)\
    \ == *(t_begin+j)) {\n            if(++j == m) {\n                res.push_back(i\
    \ - (m-1));\n                j = table[m-1];\n            }\n        }\n    }\n\
    \    return res;\n}\n\nvector<int> kmp_find(string& s, string& t, vector<int>&\
    \ table) {\n    return kmp_find(ALL(s), ALL(t), table);\n}\n\ntemplate <typename\
    \ T=char, T begin_char='a', int char_sz=26>\nstruct Trie {\n    struct Node {\n\
    \        T c;\n        int sz = 0;\n        int depth;\n        vector<Node*>\
    \ nxt;\n        Node* failure;\n        vector<int> fullmatch_keyword_id;\n  \
    \      vector<int> suffixmatch_keyword_id;\n\n        Node(T _c, int _d): c(_c),\
    \ depth(_d) {\n            nxt.resize(char_sz);\n            fill(ALL(nxt), nullptr);\n\
    \        }\n        ~Node() {\n            for(auto& p: nxt) if(p) delete p;\n\
    \        }\n    };\n\n    Node* root;\n    int keyword_id = 0;\n\n    Trie() {\n\
    \        root = new Node(begin_char-1, 0);\n    }\n    ~Trie() {\n        delete\
    \ root;\n    }\n\n    template <typename It>\n    void add(It begin, It end, int\
    \ keyword_id_=-1) {\n        if(keyword_id_ == -1) keyword_id_ = keyword_id++;\n\
    \        Node* cursor = root;\n        cursor->sz++;\n        for(It it = begin;\
    \ it != end; it++) {\n            if(!cursor->nxt[*it-begin_char]) cursor->nxt[*it-begin_char]\
    \ = new Node(*it, cursor->depth+1);\n            cursor = cursor->nxt[*it-begin_char];\n\
    \            cursor->sz++;\n        }\n        cursor->fullmatch_keyword_id.push_back(keyword_id_);\n\
    \    }\n\n    void add(const string& str, int keyword_id_=-1) {\n        add(ALL(str),\
    \ keyword_id_ == -1? keyword_id++ : keyword_id_);\n    }\n\n    void build_failure()\
    \ {\n        queue<Node*> que;\n        REP(i, char_sz) {\n            Node* to\
    \ = root->nxt[i];\n            if(!to) continue;\n            to->failure = root;\n\
    \            for(int x : to->fullmatch_keyword_id) {\n                to->suffixmatch_keyword_id.push_back(x);\n\
    \            }\n            que.push(to);\n        }\n        while(!que.empty())\
    \ {\n            Node* from = que.front(); que.pop();\n            REP(i, char_sz)\
    \ {\n                Node* to = from->nxt[i];\n                if(!to) continue;\n\
    \                Node* cursor = from->failure;\n                while(cursor !=\
    \ root && !cursor->nxt[i]) cursor = cursor->failure;\n                if(cursor->nxt[i])\
    \ to->failure = cursor->nxt[i];\n                else to->failure = root;\n  \
    \              for(int x : to->fullmatch_keyword_id) {\n                    to->suffixmatch_keyword_id.push_back(x);\n\
    \                }\n                for(int x : to->failure->suffixmatch_keyword_id)\
    \ {\n                    to->suffixmatch_keyword_id.push_back(x);\n          \
    \      }\n                que.push(to);\n            }\n        }\n    }\n\n \
    \   template <typename It>\n    void aho_corasick(It begin, It end, function<void(vector<int>&)>&\
    \ f) {\n        Node* cursor = root;\n        for(It it = begin; it != end; it++)\
    \ {\n            while(cursor != root && !cursor->nxt[*it-begin_char]) cursor\
    \ = cursor->failure;\n            if(cursor->nxt[*it-begin_char]) {\n        \
    \        cursor = cursor->nxt[*it-begin_char];\n                f(cursor->suffixmatch_keyword_id);\n\
    \            }\n        }\n    }\n\n    template <typename It>\n    ll aho_corasick(It\
    \ begin, It end) {\n        ll res = 0;\n        function<void(vector<int>&)>\
    \ f = [&](vector<int>& v) {\n            res += v.size();\n        };\n      \
    \  aho_corasick(begin, end, f);\n        return res;\n    }\n\n    void aho_corasick(string\
    \ &s, function<void(vector<int>&)>& f) {\n        aho_corasick(ALL(s), f);\n \
    \   }\n\n    ll aho_corasick(string &s) {\n        return aho_corasick(ALL(s));\n\
    \    }\n};\n\ntemplate <typename T>\nstruct RollingHash {\n    int num;\n    vector<T>\
    \ base;\n    vector<vector<T>> power;\n\n    RollingHash(const vector<T>& base_)\
    \ : num(base_.size()), base(base_) {\n        power = vector<vector<T>>(num, vector<T>(1,\
    \ 1));\n    }\n\n    RollingHash(int num_=3) : num(num_) {\n        assert(num_\
    \ > 0);\n        power = vector<vector<T>>(num, vector<T>(1, 1));\n        mt19937\
    \ engine((random_device){}());\n        REP(i, num) base.push_back(engine());\n\
    \    }\n\n    void expand(int n) {\n        int m = power[0].size();\n       \
    \ if(m > n) return;\n        REP(i, num) {\n            power[i].resize(n+1);\n\
    \            FOR(j, m, n+1) power[i][j] = power[i][j-1] * base[i];\n        }\n\
    \    }\n\n    template<typename It>\n    vector<vector<T>> build(It begin, It\
    \ end) {\n        int n = end - begin;\n        vector<vector<T>> res(num, vector<T>(n+1));\n\
    \        REP(i, num) REP(j, n) {\n            res[i][j+1] = res[i][j] * base[i]\
    \ + *(begin+j);\n        }\n        return res;\n    }\n\n    vector<vector<T>>\
    \ build(const string& s) {\n        return build(ALL(s));\n    }\n\n    vector<T>\
    \ query(const vector<vector<T>>& hash, int l, int r) {\n        assert(hash.size()\
    \ == num);\n        assert(0 <= l && l <= r && r < hash[0].size());\n        expand(r\
    \ - l);\n        vector<T> res(num);\n        REP(i, num) res[i] = hash[i][r]\
    \ - hash[i][l] * power[i][r-l];\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\ntemplate <typename It>\nvector<int>\
    \ kmp_table(It begin, It end) {\n    int m = end - begin;\n    vector<int> table(m);\n\
    \    int j = 0;\n    FOR(i, 1, m) {\n        while(j > 0 && *(begin+i) != *(begin+j))\
    \ j = table[j-1];\n        if(*(begin+i) == *(begin+j)) table[i] = ++j;\n    }\n\
    \    return table;\n}\n\nvector<int> kmp_table(string& t) {\n    return kmp_table(ALL(t));\n\
    }\n\ntemplate <typename It>\nvector<int> kmp_find(It s_begin, It s_end, It t_begin,\
    \ It t_end, vector<int>& table) {\n    int n = s_end - s_begin;\n    int m = t_end\
    \ - t_begin;\n    vector<int> res;\n    int j = 0;\n    REP(i, n) {\n        while(j\
    \ > 0 && *(s_begin+i) != *(t_begin+j)) j = table[j-1];\n        if(*(s_begin+i)\
    \ == *(t_begin+j)) {\n            if(++j == m) {\n                res.push_back(i\
    \ - (m-1));\n                j = table[m-1];\n            }\n        }\n    }\n\
    \    return res;\n}\n\nvector<int> kmp_find(string& s, string& t, vector<int>&\
    \ table) {\n    return kmp_find(ALL(s), ALL(t), table);\n}\n\ntemplate <typename\
    \ T=char, T begin_char='a', int char_sz=26>\nstruct Trie {\n    struct Node {\n\
    \        T c;\n        int sz = 0;\n        int depth;\n        vector<Node*>\
    \ nxt;\n        Node* failure;\n        vector<int> fullmatch_keyword_id;\n  \
    \      vector<int> suffixmatch_keyword_id;\n\n        Node(T _c, int _d): c(_c),\
    \ depth(_d) {\n            nxt.resize(char_sz);\n            fill(ALL(nxt), nullptr);\n\
    \        }\n        ~Node() {\n            for(auto& p: nxt) if(p) delete p;\n\
    \        }\n    };\n\n    Node* root;\n    int keyword_id = 0;\n\n    Trie() {\n\
    \        root = new Node(begin_char-1, 0);\n    }\n    ~Trie() {\n        delete\
    \ root;\n    }\n\n    template <typename It>\n    void add(It begin, It end, int\
    \ keyword_id_=-1) {\n        if(keyword_id_ == -1) keyword_id_ = keyword_id++;\n\
    \        Node* cursor = root;\n        cursor->sz++;\n        for(It it = begin;\
    \ it != end; it++) {\n            if(!cursor->nxt[*it-begin_char]) cursor->nxt[*it-begin_char]\
    \ = new Node(*it, cursor->depth+1);\n            cursor = cursor->nxt[*it-begin_char];\n\
    \            cursor->sz++;\n        }\n        cursor->fullmatch_keyword_id.push_back(keyword_id_);\n\
    \    }\n\n    void add(const string& str, int keyword_id_=-1) {\n        add(ALL(str),\
    \ keyword_id_ == -1? keyword_id++ : keyword_id_);\n    }\n\n    void build_failure()\
    \ {\n        queue<Node*> que;\n        REP(i, char_sz) {\n            Node* to\
    \ = root->nxt[i];\n            if(!to) continue;\n            to->failure = root;\n\
    \            for(int x : to->fullmatch_keyword_id) {\n                to->suffixmatch_keyword_id.push_back(x);\n\
    \            }\n            que.push(to);\n        }\n        while(!que.empty())\
    \ {\n            Node* from = que.front(); que.pop();\n            REP(i, char_sz)\
    \ {\n                Node* to = from->nxt[i];\n                if(!to) continue;\n\
    \                Node* cursor = from->failure;\n                while(cursor !=\
    \ root && !cursor->nxt[i]) cursor = cursor->failure;\n                if(cursor->nxt[i])\
    \ to->failure = cursor->nxt[i];\n                else to->failure = root;\n  \
    \              for(int x : to->fullmatch_keyword_id) {\n                    to->suffixmatch_keyword_id.push_back(x);\n\
    \                }\n                for(int x : to->failure->suffixmatch_keyword_id)\
    \ {\n                    to->suffixmatch_keyword_id.push_back(x);\n          \
    \      }\n                que.push(to);\n            }\n        }\n    }\n\n \
    \   template <typename It>\n    void aho_corasick(It begin, It end, function<void(vector<int>&)>&\
    \ f) {\n        Node* cursor = root;\n        for(It it = begin; it != end; it++)\
    \ {\n            while(cursor != root && !cursor->nxt[*it-begin_char]) cursor\
    \ = cursor->failure;\n            if(cursor->nxt[*it-begin_char]) {\n        \
    \        cursor = cursor->nxt[*it-begin_char];\n                f(cursor->suffixmatch_keyword_id);\n\
    \            }\n        }\n    }\n\n    template <typename It>\n    ll aho_corasick(It\
    \ begin, It end) {\n        ll res = 0;\n        function<void(vector<int>&)>\
    \ f = [&](vector<int>& v) {\n            res += v.size();\n        };\n      \
    \  aho_corasick(begin, end, f);\n        return res;\n    }\n\n    void aho_corasick(string\
    \ &s, function<void(vector<int>&)>& f) {\n        aho_corasick(ALL(s), f);\n \
    \   }\n\n    ll aho_corasick(string &s) {\n        return aho_corasick(ALL(s));\n\
    \    }\n};\n\ntemplate <typename T>\nstruct RollingHash {\n    int num;\n    vector<T>\
    \ base;\n    vector<vector<T>> power;\n\n    RollingHash(const vector<T>& base_)\
    \ : num(base_.size()), base(base_) {\n        power = vector<vector<T>>(num, vector<T>(1,\
    \ 1));\n    }\n\n    RollingHash(int num_=3) : num(num_) {\n        assert(num_\
    \ > 0);\n        power = vector<vector<T>>(num, vector<T>(1, 1));\n        mt19937\
    \ engine((random_device){}());\n        REP(i, num) base.push_back(engine());\n\
    \    }\n\n    void expand(int n) {\n        int m = power[0].size();\n       \
    \ if(m > n) return;\n        REP(i, num) {\n            power[i].resize(n+1);\n\
    \            FOR(j, m, n+1) power[i][j] = power[i][j-1] * base[i];\n        }\n\
    \    }\n\n    template<typename It>\n    vector<vector<T>> build(It begin, It\
    \ end) {\n        int n = end - begin;\n        vector<vector<T>> res(num, vector<T>(n+1));\n\
    \        REP(i, num) REP(j, n) {\n            res[i][j+1] = res[i][j] * base[i]\
    \ + *(begin+j);\n        }\n        return res;\n    }\n\n    vector<vector<T>>\
    \ build(const string& s) {\n        return build(ALL(s));\n    }\n\n    vector<T>\
    \ query(const vector<vector<T>>& hash, int l, int r) {\n        assert(hash.size()\
    \ == num);\n        assert(0 <= l && l <= r && r < hash[0].size());\n        expand(r\
    \ - l);\n        vector<T> res(num);\n        REP(i, num) res[i] = hash[i][r]\
    \ - hash[i][l] * power[i][r-l];\n        return res;\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: string.hpp
  requiredBy: []
  timestamp: '2023-02-20 21:14:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string.hpp
layout: document
redirect_from:
- /library/string.hpp
- /library/string.hpp.html
title: string.hpp
---
