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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-associative-array.test.cpp
    title: test/yosupo-associative-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/treap.md
    document_title: Treap
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
    }\n#line 3 \"structure/treap.hpp\"\n\n/**\n * @brief Treap\n * @docs docs/treap.md\n\
    \ */\ntemplate <typename Key, typename Compare = less<Key>, bool multi = false>\n\
    class Treap {\n    struct Node {\n        Key key;\n        size_t id;\n     \
    \   ull pri;\n        Node *l, *r, *par;\n        size_t cnt;\n        Node(const\
    \ Key &key, ull pri) : key(key), pri(pri), l(nullptr), r(nullptr), par(nullptr),\
    \ cnt(1) {\n            static size_t id = 0;\n            this->id = id++;\n\
    \        }\n    };\n\n    mt19937_64 _rng;\n    Node *_root;\n    Compare _comp;\n\
    \n    bool _comp_key_id(const Key &key1, size_t id1, const Key &key2, size_t id2)\
    \ {\n        return _comp(key1, key2) || (!_comp(key2, key1) && id1 < id2);\n\
    \    }\n\n    void _update(Node *t) {\n        t->cnt = 1;\n        if (t->l)\
    \ t->cnt += t->l->cnt;\n        if (t->r) t->cnt += t->r->cnt;\n    }\n\n    void\
    \ _free_subtree(Node *t) {\n        if(!t) return;\n        stack<Node *> stk;\n\
    \        stk.push(t);\n        while(!stk.empty()) {\n            Node *p = stk.top();\
    \ stk.pop();\n            if(p->l) stk.push(p->l);\n            if(p->r) stk.push(p->r);\n\
    \            delete p;\n        }\n    }\n\n    pair<Node *, Node *> _split(Node\
    \ *t, const Key &key, size_t id) {\n        stack<pair<Node *, bool>> ret;\n \
    \       while(t) {\n            if(_comp_key_id(t->key, t->id, key, id)) {\n \
    \               ret.push({t, true});\n                t = t->r;\n            }\
    \ else {\n                ret.push({t, false});\n                t = t->l;\n \
    \           }\n        }\n        Node *l = nullptr, *r = nullptr;\n        while(!ret.empty())\
    \ {\n            auto [p, b] = ret.top(); ret.pop();\n            if(b) {\n  \
    \              p->r = l;\n                if(l) l->par = p;\n                _update(p);\n\
    \                l = p;\n            } else {\n                p->l = r;\n   \
    \             if(r) r->par = p;\n                _update(p);\n               \
    \ r = p;\n            }\n        }\n        return {l, r};\n    }\n\n    Node\
    \ *_merge(Node *l, Node *r) {\n        stack<pair<Node *, bool>> stk;\n      \
    \  while(1) {\n            if(!l || !r) break;\n            if(l->pri > r->pri)\
    \ {\n                stk.push({l, true});\n                l = l->r;\n       \
    \     } else {\n                stk.push({r, false});\n                r = r->l;\n\
    \            }\n        }\n        Node *t = l ? l : r;\n        while(!stk.empty())\
    \ {\n            auto [p, b] = stk.top(); stk.pop();\n            if(b) {\n  \
    \              p->r = t;\n                if(t) t->par = p;\n                _update(p);\n\
    \                t = p;\n            } else {\n                p->l = t;\n   \
    \             if(t) t->par = p;\n                _update(p);\n               \
    \ t = p;\n            }\n        }\n        return t;\n    }\n\n    Node *_lower_bound(Node\
    \ *t, const Key& key, size_t id) {\n        Node *ret = nullptr;\n        while(t)\
    \ {\n            if(_comp_key_id(t->key, t->id, key, id)) {\n                t\
    \ = t->r;\n            } else {\n                ret = t;\n                t =\
    \ t->l;\n            }\n        }\n        return ret;\n    }\n    const Node\
    \ *_lower_bound(const Node *t, const Key& key, size_t id) const {\n        const\
    \ Node *ret = nullptr;\n        while(t) {\n            if(_comp_key_id(t->key,\
    \ t->id, key, id)) {\n                t = t->r;\n            } else {\n      \
    \          ret = t;\n                t = t->l;\n            }\n        }\n   \
    \     return ret;\n    }\n\n    Node *_leftmost(Node *t) {\n        if(!t) return\
    \ nullptr;\n        while(t->l) t = t->l;\n        return t;\n    }\n    const\
    \ Node *_leftmost(const Node *t) const {\n        if(!t) return nullptr;\n   \
    \     while(t->l) t = t->l;\n        return t;\n    }\n\n    Node *_erase_leftmost(Node\
    \ *t) {\n        if(!t->l) {\n            Node *p = t->r;\n            if(p) p->par\
    \ = nullptr;\n            delete t;\n            return p;\n        }\n      \
    \  Node *p = t;\n        while(p->l->l) p = p->l;\n        Node *q = p->l;\n \
    \       p->l = q->r;\n        if(q->r) q->r->par = p;\n        delete q;\n   \
    \     return t;\n    }\n\npublic:\n    class Iterator {\n    private:\n      \
    \  Node *p;\n    public:\n        Iterator(Node *p) : p(p) {}\n        Iterator&\
    \ operator++() {\n            if(p->r) {\n                p = p->r;\n        \
    \        while(p->l) p = p->l;\n            } else {\n                while(p->par\
    \ && p->par->r == p) p = p->par;\n                p = p->par;\n            }\n\
    \            return *this;\n        }\n        Iterator& operator--() {\n    \
    \        if(p->l) {\n                p = p->l;\n                while(p->r) p\
    \ = p->r;\n            } else {\n                while(p->par && p->par->l ==\
    \ p) p = p->par;\n                p = p->par;\n            }\n            return\
    \ *this;\n        }\n        bool operator==(const Iterator &rhs) const { return\
    \ p == rhs.p; }\n        bool operator!=(const Iterator &rhs) const { return p\
    \ != rhs.p; }\n        Key& operator*() const { return p->key; }\n        Key*\
    \ operator->() const { return &p->key; }\n    };\n    class ConstIterator {\n\
    \    private:\n        const Node *p;\n    public:\n        ConstIterator(const\
    \ Node *p) : p(p) {}\n        ConstIterator& operator++() {\n            if(p->r)\
    \ {\n                p = p->r;\n                while(p->l) p = p->l;\n      \
    \      } else {\n                while(p->par && p->par->r == p) p = p->par;\n\
    \                p = p->par;\n            }\n            return *this;\n     \
    \   }\n        ConstIterator& operator--() {\n            if(p->l) {\n       \
    \         p = p->l;\n                while(p->r) p = p->r;\n            } else\
    \ {\n                while(p->par && p->par->l == p) p = p->par;\n           \
    \     p = p->par;\n            }\n            return *this;\n        }\n     \
    \   bool operator==(const ConstIterator &rhs) const { return p == rhs.p; }\n \
    \       bool operator!=(const ConstIterator &rhs) const { return p != rhs.p; }\n\
    \        const Key& operator*() const { return p->key; }\n        const Key* operator->()\
    \ const { return &p->key; }\n    };\n    friend struct Iterator;\n    friend struct\
    \ ConstIterator;\n\n    Treap(ull seed = random_device{}()) : _rng(seed), _root(nullptr),\
    \ _comp()  {}\n    ~Treap() { _free_subtree(_root); }\n    Iterator begin() {\
    \ return Iterator(_leftmost(_root)); }\n    ConstIterator begin() const { return\
    \ ConstIterator(_leftmost(_root)); }\n    Iterator end() { return Iterator(nullptr);\
    \ }\n    ConstIterator end() const { return ConstIterator(nullptr); }\n    size_t\
    \ size() const { return _root ? _root->size : 0; }\n    Iterator lower_bound(Key\
    \ key) {\n        return Iterator(_lower_bound(_root, key, 0ULL));\n    }\n  \
    \  ConstIterator lower_bound(Key key) const {\n        return ConstIterator(_lower_bound(_root,\
    \ key, 0ULL));\n    }\n    Iterator upper_bound(Key key) {\n        return Iterator(_lower_bound(_root,\
    \ key, numeric_limits<size_t>::max()));\n    }\n    ConstIterator upper_bound(Key\
    \ key) const {\n        return ConstIterator(_lower_bound(_root, key, numeric_limits<size_t>::max()));\n\
    \    }\n    Iterator find(const Key &key) {\n        Node *p = _lower_bound(_root,\
    \ key, 0ULL);\n        if(!p || _comp(key, p->key)) return end();\n        return\
    \ Iterator(p);\n    }\n    ConstIterator find(const Key &key) const {\n      \
    \  const Node *p = _lower_bound(_root, key, 0ULL);\n        if(!p || _comp(key,\
    \ p->key)) return end();\n        return ConstIterator(p);\n    }\n    bool contains(Key\
    \ key) const {\n        Node *p = _lower_bound(_root, key, 0ULL);\n        return\
    \ p && !_comp(key, p->key);\n    }\n    pair<Iterator, bool> insert(const Key\
    \ &key) {\n        if constexpr(!multi) {\n            Node *p = _lower_bound(_root,\
    \ key, 0ULL);\n            if(p && !_comp(key, p->key)) {\n                p->key\
    \ = key;\n                return {Iterator(p), false};\n            }\n      \
    \  }\n        Node *p = new Node(key, _rng());\n        auto [l, r] = _split(_root,\
    \ key, p->id);\n        _root = _merge(_merge(l, p), r);\n        return {Iterator(p),\
    \ true};\n    }\n    size_t erase(const Key &key) {\n        auto [l, r] = _split(_root,\
    \ key, 0ULL);\n        auto [m, r2] = _split(r, key, numeric_limits<size_t>::max());\n\
    \        _root = _merge(l, r2);\n        size_t ret = m ? m->cnt : 0;\n      \
    \  _free_subtree(m);\n        return ret;\n    }\n    Iterator erase(Iterator\
    \ it) {\n        Node *p = it.p;\n        auto [l, r] = _split(_root, p->key,\
    \ p->id);\n        auto [m, r2] = _split(r, p->key, p->id + 1);\n        Node\
    \ *ret = r2 ? _leftmost(r2) : nullptr;\n        _root = _merge(l, r2);\n     \
    \   delete m;\n        return Iterator(ret);\n    }\n    void clear() {\n    \
    \    _free_subtree(_root);\n        _root = nullptr;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Treap\n * @docs\
    \ docs/treap.md\n */\ntemplate <typename Key, typename Compare = less<Key>, bool\
    \ multi = false>\nclass Treap {\n    struct Node {\n        Key key;\n       \
    \ size_t id;\n        ull pri;\n        Node *l, *r, *par;\n        size_t cnt;\n\
    \        Node(const Key &key, ull pri) : key(key), pri(pri), l(nullptr), r(nullptr),\
    \ par(nullptr), cnt(1) {\n            static size_t id = 0;\n            this->id\
    \ = id++;\n        }\n    };\n\n    mt19937_64 _rng;\n    Node *_root;\n    Compare\
    \ _comp;\n\n    bool _comp_key_id(const Key &key1, size_t id1, const Key &key2,\
    \ size_t id2) {\n        return _comp(key1, key2) || (!_comp(key2, key1) && id1\
    \ < id2);\n    }\n\n    void _update(Node *t) {\n        t->cnt = 1;\n       \
    \ if (t->l) t->cnt += t->l->cnt;\n        if (t->r) t->cnt += t->r->cnt;\n   \
    \ }\n\n    void _free_subtree(Node *t) {\n        if(!t) return;\n        stack<Node\
    \ *> stk;\n        stk.push(t);\n        while(!stk.empty()) {\n            Node\
    \ *p = stk.top(); stk.pop();\n            if(p->l) stk.push(p->l);\n         \
    \   if(p->r) stk.push(p->r);\n            delete p;\n        }\n    }\n\n    pair<Node\
    \ *, Node *> _split(Node *t, const Key &key, size_t id) {\n        stack<pair<Node\
    \ *, bool>> ret;\n        while(t) {\n            if(_comp_key_id(t->key, t->id,\
    \ key, id)) {\n                ret.push({t, true});\n                t = t->r;\n\
    \            } else {\n                ret.push({t, false});\n               \
    \ t = t->l;\n            }\n        }\n        Node *l = nullptr, *r = nullptr;\n\
    \        while(!ret.empty()) {\n            auto [p, b] = ret.top(); ret.pop();\n\
    \            if(b) {\n                p->r = l;\n                if(l) l->par\
    \ = p;\n                _update(p);\n                l = p;\n            } else\
    \ {\n                p->l = r;\n                if(r) r->par = p;\n          \
    \      _update(p);\n                r = p;\n            }\n        }\n       \
    \ return {l, r};\n    }\n\n    Node *_merge(Node *l, Node *r) {\n        stack<pair<Node\
    \ *, bool>> stk;\n        while(1) {\n            if(!l || !r) break;\n      \
    \      if(l->pri > r->pri) {\n                stk.push({l, true});\n         \
    \       l = l->r;\n            } else {\n                stk.push({r, false});\n\
    \                r = r->l;\n            }\n        }\n        Node *t = l ? l\
    \ : r;\n        while(!stk.empty()) {\n            auto [p, b] = stk.top(); stk.pop();\n\
    \            if(b) {\n                p->r = t;\n                if(t) t->par\
    \ = p;\n                _update(p);\n                t = p;\n            } else\
    \ {\n                p->l = t;\n                if(t) t->par = p;\n          \
    \      _update(p);\n                t = p;\n            }\n        }\n       \
    \ return t;\n    }\n\n    Node *_lower_bound(Node *t, const Key& key, size_t id)\
    \ {\n        Node *ret = nullptr;\n        while(t) {\n            if(_comp_key_id(t->key,\
    \ t->id, key, id)) {\n                t = t->r;\n            } else {\n      \
    \          ret = t;\n                t = t->l;\n            }\n        }\n   \
    \     return ret;\n    }\n    const Node *_lower_bound(const Node *t, const Key&\
    \ key, size_t id) const {\n        const Node *ret = nullptr;\n        while(t)\
    \ {\n            if(_comp_key_id(t->key, t->id, key, id)) {\n                t\
    \ = t->r;\n            } else {\n                ret = t;\n                t =\
    \ t->l;\n            }\n        }\n        return ret;\n    }\n\n    Node *_leftmost(Node\
    \ *t) {\n        if(!t) return nullptr;\n        while(t->l) t = t->l;\n     \
    \   return t;\n    }\n    const Node *_leftmost(const Node *t) const {\n     \
    \   if(!t) return nullptr;\n        while(t->l) t = t->l;\n        return t;\n\
    \    }\n\n    Node *_erase_leftmost(Node *t) {\n        if(!t->l) {\n        \
    \    Node *p = t->r;\n            if(p) p->par = nullptr;\n            delete\
    \ t;\n            return p;\n        }\n        Node *p = t;\n        while(p->l->l)\
    \ p = p->l;\n        Node *q = p->l;\n        p->l = q->r;\n        if(q->r) q->r->par\
    \ = p;\n        delete q;\n        return t;\n    }\n\npublic:\n    class Iterator\
    \ {\n    private:\n        Node *p;\n    public:\n        Iterator(Node *p) :\
    \ p(p) {}\n        Iterator& operator++() {\n            if(p->r) {\n        \
    \        p = p->r;\n                while(p->l) p = p->l;\n            } else\
    \ {\n                while(p->par && p->par->r == p) p = p->par;\n           \
    \     p = p->par;\n            }\n            return *this;\n        }\n     \
    \   Iterator& operator--() {\n            if(p->l) {\n                p = p->l;\n\
    \                while(p->r) p = p->r;\n            } else {\n               \
    \ while(p->par && p->par->l == p) p = p->par;\n                p = p->par;\n \
    \           }\n            return *this;\n        }\n        bool operator==(const\
    \ Iterator &rhs) const { return p == rhs.p; }\n        bool operator!=(const Iterator\
    \ &rhs) const { return p != rhs.p; }\n        Key& operator*() const { return\
    \ p->key; }\n        Key* operator->() const { return &p->key; }\n    };\n   \
    \ class ConstIterator {\n    private:\n        const Node *p;\n    public:\n \
    \       ConstIterator(const Node *p) : p(p) {}\n        ConstIterator& operator++()\
    \ {\n            if(p->r) {\n                p = p->r;\n                while(p->l)\
    \ p = p->l;\n            } else {\n                while(p->par && p->par->r ==\
    \ p) p = p->par;\n                p = p->par;\n            }\n            return\
    \ *this;\n        }\n        ConstIterator& operator--() {\n            if(p->l)\
    \ {\n                p = p->l;\n                while(p->r) p = p->r;\n      \
    \      } else {\n                while(p->par && p->par->l == p) p = p->par;\n\
    \                p = p->par;\n            }\n            return *this;\n     \
    \   }\n        bool operator==(const ConstIterator &rhs) const { return p == rhs.p;\
    \ }\n        bool operator!=(const ConstIterator &rhs) const { return p != rhs.p;\
    \ }\n        const Key& operator*() const { return p->key; }\n        const Key*\
    \ operator->() const { return &p->key; }\n    };\n    friend struct Iterator;\n\
    \    friend struct ConstIterator;\n\n    Treap(ull seed = random_device{}()) :\
    \ _rng(seed), _root(nullptr), _comp()  {}\n    ~Treap() { _free_subtree(_root);\
    \ }\n    Iterator begin() { return Iterator(_leftmost(_root)); }\n    ConstIterator\
    \ begin() const { return ConstIterator(_leftmost(_root)); }\n    Iterator end()\
    \ { return Iterator(nullptr); }\n    ConstIterator end() const { return ConstIterator(nullptr);\
    \ }\n    size_t size() const { return _root ? _root->size : 0; }\n    Iterator\
    \ lower_bound(Key key) {\n        return Iterator(_lower_bound(_root, key, 0ULL));\n\
    \    }\n    ConstIterator lower_bound(Key key) const {\n        return ConstIterator(_lower_bound(_root,\
    \ key, 0ULL));\n    }\n    Iterator upper_bound(Key key) {\n        return Iterator(_lower_bound(_root,\
    \ key, numeric_limits<size_t>::max()));\n    }\n    ConstIterator upper_bound(Key\
    \ key) const {\n        return ConstIterator(_lower_bound(_root, key, numeric_limits<size_t>::max()));\n\
    \    }\n    Iterator find(const Key &key) {\n        Node *p = _lower_bound(_root,\
    \ key, 0ULL);\n        if(!p || _comp(key, p->key)) return end();\n        return\
    \ Iterator(p);\n    }\n    ConstIterator find(const Key &key) const {\n      \
    \  const Node *p = _lower_bound(_root, key, 0ULL);\n        if(!p || _comp(key,\
    \ p->key)) return end();\n        return ConstIterator(p);\n    }\n    bool contains(Key\
    \ key) const {\n        Node *p = _lower_bound(_root, key, 0ULL);\n        return\
    \ p && !_comp(key, p->key);\n    }\n    pair<Iterator, bool> insert(const Key\
    \ &key) {\n        if constexpr(!multi) {\n            Node *p = _lower_bound(_root,\
    \ key, 0ULL);\n            if(p && !_comp(key, p->key)) {\n                p->key\
    \ = key;\n                return {Iterator(p), false};\n            }\n      \
    \  }\n        Node *p = new Node(key, _rng());\n        auto [l, r] = _split(_root,\
    \ key, p->id);\n        _root = _merge(_merge(l, p), r);\n        return {Iterator(p),\
    \ true};\n    }\n    size_t erase(const Key &key) {\n        auto [l, r] = _split(_root,\
    \ key, 0ULL);\n        auto [m, r2] = _split(r, key, numeric_limits<size_t>::max());\n\
    \        _root = _merge(l, r2);\n        size_t ret = m ? m->cnt : 0;\n      \
    \  _free_subtree(m);\n        return ret;\n    }\n    Iterator erase(Iterator\
    \ it) {\n        Node *p = it.p;\n        auto [l, r] = _split(_root, p->key,\
    \ p->id);\n        auto [m, r2] = _split(r, p->key, p->id + 1);\n        Node\
    \ *ret = r2 ? _leftmost(r2) : nullptr;\n        _root = _merge(l, r2);\n     \
    \   delete m;\n        return Iterator(ret);\n    }\n    void clear() {\n    \
    \    _free_subtree(_root);\n        _root = nullptr;\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: structure/treap.hpp
  requiredBy: []
  timestamp: '2023-02-17 22:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-associative-array.test.cpp
documentation_of: structure/treap.hpp
layout: document
redirect_from:
- /library/structure/treap.hpp
- /library/structure/treap.hpp.html
title: Treap
---
