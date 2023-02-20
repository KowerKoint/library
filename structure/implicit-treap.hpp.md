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
    path: test/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
    title: test/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/implicit-treap.md
    document_title: ImplicitTreap
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
    }\n#line 3 \"structure/implicit-treap.hpp\"\n\n/**\n * @brief ImplicitTreap\n\
    \ * @docs docs/implicit-treap.md\n */\ntemplate <typename Value, typename ValueMonoid\
    \ = void*, typename Update = void*, typename UpdateMonoid = void*, typename Mapping\
    \ = void*, bool MappingWithSize = false>\nclass ImplicitTreap {\n    struct Node\
    \ {\n        Value value;\n        ull pri;\n        Node *l, *r, *par;\n    \
    \    size_t cnt;\n        Value sum;\n        bool rev;\n        Update lazy;\n\
    \        Node(const Value &value, ull pri) : value(value), pri(pri), l(nullptr),\
    \ r(nullptr), par(nullptr), cnt(1), sum(value), rev(false), lazy(UpdateMonoid::id())\
    \ {}\n    };\n\n    mt19937_64 _rng;\n    Node *_root;\n    Mapping _mapping;\n\
    \n    inline void _update(Node *t) {\n        t->cnt = 1;\n        if (t->l) t->cnt\
    \ += t->l->cnt;\n        if (t->r) t->cnt += t->r->cnt;\n        if constexpr\
    \ (!is_same_v<ValueMonoid, void*>) {\n            t->sum = t->value;\n       \
    \     if (t->l) t->sum = ValueMonoid::op(t->l->sum, t->sum);\n            if (t->r)\
    \ t->sum = ValueMonoid::op(t->sum, t->r->sum);\n        }\n    }\n    void _push(Node\
    \ *t) {\n        if(t->rev) {\n            swap(t->l, t->r);\n            if (t->l)\
    \ t->l->rev ^= true;\n            if (t->r) t->r->rev ^= true;\n            t->rev\
    \ = false;\n        }\n        if constexpr (!is_same_v<Update, void*>) {\n  \
    \          if(t->l) {\n                t->l->lazy = UpdateMonoid::op(t->lazy,\
    \ t->l->lazy);\n                if constexpr(MappingWithSize) {\n            \
    \        t->l->sum = _mapping(t->lazy, t->l->sum, t->l->cnt);\n              \
    \  } else {\n                    t->l->sum = _mapping(t->lazy, t->l->sum);\n \
    \               }\n            }\n            if(t->r) {\n                t->r->lazy\
    \ = UpdateMonoid::op(t->lazy, t->r->lazy);\n                if constexpr(MappingWithSize)\
    \ {\n                    t->r->sum = _mapping(t->lazy, t->r->sum, t->r->cnt);\n\
    \                } else {\n                    t->r->sum = _mapping(t->lazy, t->r->sum);\n\
    \                }\n            }\n            if constexpr(MappingWithSize) {\n\
    \                t->value = _mapping(t->lazy, t->value, 1);\n            } else\
    \ {\n                t->value = _mapping(t->lazy, t->value);\n            }\n\
    \            t->lazy = UpdateMonoid::id();\n            _update(t);\n        }\n\
    \    }\n    void _free_subtree(Node *t) {\n        if(!t) return;\n        stack<Node\
    \ *> stk;\n        stk.push(t);\n        while(!stk.empty()) {\n            Node\
    \ *p = stk.top(); stk.pop();\n            if(p->l) stk.push(p->l);\n         \
    \   if(p->r) stk.push(p->r);\n            delete p;\n        }\n    }\n    pair<Node*,\
    \ Node*> _split(Node *t, size_t k) {\n        stack<pair<Node*, bool>> ret;\n\
    \        while(t) {\n            _push(t);\n            size_t implicit_key =\
    \ 1;\n            if(t->l) implicit_key += t->l->cnt;\n            if(k < implicit_key)\
    \ {\n                ret.push({t, true});\n                t = t->l;\n       \
    \     } else {\n                ret.push({t, false});\n                t = t->r;\n\
    \                k -= implicit_key;\n            }\n        }\n        Node *l\
    \ = nullptr, *r = nullptr;\n        while(!ret.empty()) {\n            auto [p,\
    \ b] = ret.top(); ret.pop();\n            if(b) {\n                p->l = r;\n\
    \                if(r) r->par = p;\n                _update(p);\n            \
    \    r = p;\n            } else {\n                p->r = l;\n               \
    \ if(l) l->par = p;\n                _update(p);\n                l = p;\n   \
    \         }\n        }\n        return {l, r};\n    }\n    Node* _merge(Node *l,\
    \ Node *r) {\n        stack<pair<Node*, bool>> stk;\n        while(1) {\n    \
    \        if(l) _push(l);\n            if(r) _push(r);\n            if(!l || !r)\
    \ break;\n            if(l->pri > r->pri) {\n                stk.push({l, true});\n\
    \                l = l->r;\n            } else {\n                stk.push({r,\
    \ false});\n                r = r->l;\n            }\n        }\n        Node\
    \ *t = l ? l : r;\n        while(!stk.empty()) {\n            auto [p, b] = stk.top();\
    \ stk.pop();\n            if(b) {\n                p->r = t;\n               \
    \ if(t) t->par = p;\n                _update(p);\n                t = p;\n   \
    \         } else {\n                p->l = t;\n                if(t) t->par =\
    \ p;\n                _update(p);\n                t = p;\n            }\n   \
    \     }\n        return t;\n    }\n\npublic:\n    class ValueReference {\n   \
    \ private:\n        ImplicitTreap &treap;\n        Node *node;\n    public:\n\
    \        ValueReference(ImplicitTreap &treap, Node *node) : treap(treap), node(node)\
    \ {}\n        ValueReference& operator=(const Value& v) {\n            stack<Node*>\
    \ stk;\n            Node *t = node;\n            while(t->par) {\n           \
    \     stk.push(t);\n                t = t->par;\n            }\n            while(!stk.empty())\
    \ {\n                treap._push(t);\n                t = stk.top(); stk.pop();\n\
    \            }\n            treap._push(t);\n            t->value = v;\n     \
    \       treap._update(t);\n            while(t->par) {\n                t = t->par;\n\
    \                treap._update(t);\n            }\n            return *this;\n\
    \        }\n        operator Value() const {\n            stack<Node*> stk;\n\
    \            Node *t = node;\n            while(t->par) {\n                stk.push(t);\n\
    \                t = t->par;\n            }\n            while(!stk.empty()) {\n\
    \                treap._push(t);\n                t = stk.top(); stk.pop();\n\
    \            }\n            treap._push(t);\n            return t->value;\n  \
    \      }\n    };\n\n    class Iterator {\n    private:\n        ImplicitTreap\
    \ &treap;\n        Node *node;\n    public:\n        Iterator(ImplicitTreap &treap,\
    \ Node *node) : treap(treap), node(node) {}\n        Iterator& operator++() {\n\
    \            if(node->r) {\n                node = node->r;\n                while(node->l)\
    \ node = node->l;\n            } else {\n                while(node->par && node->par->r\
    \ == node) node = node->par;\n                node = node->par;\n            }\n\
    \            return *this;\n        }\n        Iterator& operator--() {\n    \
    \        if(!node) node = treap._root->rightmost();\n            else if(node->l)\
    \ {\n                node = node->l;\n                while(node->r) node = node->r;\n\
    \            } else {\n                while(node->par && node->par->l == node)\
    \ node = node->par;\n                node = node->par;\n            }\n      \
    \      return *this;\n        }\n        bool operator==(const Iterator& itr)\
    \ const { return node == itr.node; }\n        bool operator!=(const Iterator&\
    \ itr) const { return node != itr.node; }\n        ValueReference operator*()\
    \ { return ValueReference(treap, node); }\n        ValueReference operator->()\
    \ { return ValueReference(treap, node); }\n    };\n    friend class Iterator;\n\
    \n    ImplicitTreap(ull seed = random_device{}()) : _rng(seed), _root(nullptr),\
    \ _mapping() {}\n    template <typename It>\n    ImplicitTreap(It first, It last,\
    \ ull seed = random_device{}()) : ImplicitTreap(seed) {\n        while(first !=\
    \ last) {\n            push_back(*first);\n            ++first;\n        }\n \
    \   }\n    ~ImplicitTreap() { _free_subtree(_root); }\n    Iterator begin() {\n\
    \        if(!_root) return Iterator(*this, nullptr);\n        auto [l, r] = _split(_root,\
    \ 1);\n        _root = _merge(l, r);\n        return Iterator(*this, l);\n   \
    \ }\n    Iterator end() { return Iterator(_root, nullptr); }\n    size_t size()\
    \ const { return _root ? _root->cnt : 0; }\n    Iterator kth_element(size_t k)\
    \ {\n        auto [l, r] = _split(_root, k);\n        auto [m, r2] = _split(r,\
    \ 1);\n        _root = _merge(_merge(l, m), r2);\n        return Iterator(*this,\
    \ m);\n    }\n    ValueReference operator[](size_t k) {\n        auto [l, r] =\
    \ _split(_root, k);\n        auto [m, rr] = _split(r, 1);\n        _root = _merge(l,\
    \ rr);\n        return ValueReference(*this, m);\n    }\n    Value query(size_t\
    \ l, size_t r) {\n        auto [l1, r1] = _split(_root, l);\n        auto [m,\
    \ r2] = _split(r1, r - l);\n        Value ret = m->sum;\n        _root = _merge(_merge(l1,\
    \ m), r2);\n        return ret;\n    }\n    void insert(size_t k, const Value&\
    \ v) {\n        auto [l, r] = _split(_root, k);\n        _root = _merge(_merge(l,\
    \ new Node(v, _rng())), r);\n    }\n    void push_back(const Value& v) { insert(size(),\
    \ v); }\n    void erase(size_t k) {\n        auto [l, r] = _split(_root, k);\n\
    \        auto [m, r2] = _split(r, 1);\n        _root = _merge(l, r2);\n      \
    \  delete m;\n    }\n    void pop_back() { erase(size() - 1); }\n    void reverse(size_t\
    \ l, size_t r) {\n        auto [l1, r1] = _split(_root, l);\n        auto [m,\
    \ r2] = _split(r1, r - l);\n        m->rev ^= true;\n        _root = _merge(_merge(l1,\
    \ m), r2);\n    }\n    void apply(size_t l, size_t r, const Update& f) {\n   \
    \     auto [l1, r1] = _split(_root, l);\n        auto [m, r2] = _split(r1, r -\
    \ l);\n        if constexpr(MappingWithSize) {\n            m->sum = _mapping(f,\
    \ m->sum, m->cnt);\n        } else {\n            m->sum = _mapping(f, m->sum);\n\
    \        }\n        m->lazy = UpdateMonoid::op(f, m->lazy);\n        _root = _merge(_merge(l1,\
    \ m), r2);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief ImplicitTreap\n\
    \ * @docs docs/implicit-treap.md\n */\ntemplate <typename Value, typename ValueMonoid\
    \ = void*, typename Update = void*, typename UpdateMonoid = void*, typename Mapping\
    \ = void*, bool MappingWithSize = false>\nclass ImplicitTreap {\n    struct Node\
    \ {\n        Value value;\n        ull pri;\n        Node *l, *r, *par;\n    \
    \    size_t cnt;\n        Value sum;\n        bool rev;\n        Update lazy;\n\
    \        Node(const Value &value, ull pri) : value(value), pri(pri), l(nullptr),\
    \ r(nullptr), par(nullptr), cnt(1), sum(value), rev(false), lazy(UpdateMonoid::id())\
    \ {}\n    };\n\n    mt19937_64 _rng;\n    Node *_root;\n    Mapping _mapping;\n\
    \n    inline void _update(Node *t) {\n        t->cnt = 1;\n        if (t->l) t->cnt\
    \ += t->l->cnt;\n        if (t->r) t->cnt += t->r->cnt;\n        if constexpr\
    \ (!is_same_v<ValueMonoid, void*>) {\n            t->sum = t->value;\n       \
    \     if (t->l) t->sum = ValueMonoid::op(t->l->sum, t->sum);\n            if (t->r)\
    \ t->sum = ValueMonoid::op(t->sum, t->r->sum);\n        }\n    }\n    void _push(Node\
    \ *t) {\n        if(t->rev) {\n            swap(t->l, t->r);\n            if (t->l)\
    \ t->l->rev ^= true;\n            if (t->r) t->r->rev ^= true;\n            t->rev\
    \ = false;\n        }\n        if constexpr (!is_same_v<Update, void*>) {\n  \
    \          if(t->l) {\n                t->l->lazy = UpdateMonoid::op(t->lazy,\
    \ t->l->lazy);\n                if constexpr(MappingWithSize) {\n            \
    \        t->l->sum = _mapping(t->lazy, t->l->sum, t->l->cnt);\n              \
    \  } else {\n                    t->l->sum = _mapping(t->lazy, t->l->sum);\n \
    \               }\n            }\n            if(t->r) {\n                t->r->lazy\
    \ = UpdateMonoid::op(t->lazy, t->r->lazy);\n                if constexpr(MappingWithSize)\
    \ {\n                    t->r->sum = _mapping(t->lazy, t->r->sum, t->r->cnt);\n\
    \                } else {\n                    t->r->sum = _mapping(t->lazy, t->r->sum);\n\
    \                }\n            }\n            if constexpr(MappingWithSize) {\n\
    \                t->value = _mapping(t->lazy, t->value, 1);\n            } else\
    \ {\n                t->value = _mapping(t->lazy, t->value);\n            }\n\
    \            t->lazy = UpdateMonoid::id();\n            _update(t);\n        }\n\
    \    }\n    void _free_subtree(Node *t) {\n        if(!t) return;\n        stack<Node\
    \ *> stk;\n        stk.push(t);\n        while(!stk.empty()) {\n            Node\
    \ *p = stk.top(); stk.pop();\n            if(p->l) stk.push(p->l);\n         \
    \   if(p->r) stk.push(p->r);\n            delete p;\n        }\n    }\n    pair<Node*,\
    \ Node*> _split(Node *t, size_t k) {\n        stack<pair<Node*, bool>> ret;\n\
    \        while(t) {\n            _push(t);\n            size_t implicit_key =\
    \ 1;\n            if(t->l) implicit_key += t->l->cnt;\n            if(k < implicit_key)\
    \ {\n                ret.push({t, true});\n                t = t->l;\n       \
    \     } else {\n                ret.push({t, false});\n                t = t->r;\n\
    \                k -= implicit_key;\n            }\n        }\n        Node *l\
    \ = nullptr, *r = nullptr;\n        while(!ret.empty()) {\n            auto [p,\
    \ b] = ret.top(); ret.pop();\n            if(b) {\n                p->l = r;\n\
    \                if(r) r->par = p;\n                _update(p);\n            \
    \    r = p;\n            } else {\n                p->r = l;\n               \
    \ if(l) l->par = p;\n                _update(p);\n                l = p;\n   \
    \         }\n        }\n        return {l, r};\n    }\n    Node* _merge(Node *l,\
    \ Node *r) {\n        stack<pair<Node*, bool>> stk;\n        while(1) {\n    \
    \        if(l) _push(l);\n            if(r) _push(r);\n            if(!l || !r)\
    \ break;\n            if(l->pri > r->pri) {\n                stk.push({l, true});\n\
    \                l = l->r;\n            } else {\n                stk.push({r,\
    \ false});\n                r = r->l;\n            }\n        }\n        Node\
    \ *t = l ? l : r;\n        while(!stk.empty()) {\n            auto [p, b] = stk.top();\
    \ stk.pop();\n            if(b) {\n                p->r = t;\n               \
    \ if(t) t->par = p;\n                _update(p);\n                t = p;\n   \
    \         } else {\n                p->l = t;\n                if(t) t->par =\
    \ p;\n                _update(p);\n                t = p;\n            }\n   \
    \     }\n        return t;\n    }\n\npublic:\n    class ValueReference {\n   \
    \ private:\n        ImplicitTreap &treap;\n        Node *node;\n    public:\n\
    \        ValueReference(ImplicitTreap &treap, Node *node) : treap(treap), node(node)\
    \ {}\n        ValueReference& operator=(const Value& v) {\n            stack<Node*>\
    \ stk;\n            Node *t = node;\n            while(t->par) {\n           \
    \     stk.push(t);\n                t = t->par;\n            }\n            while(!stk.empty())\
    \ {\n                treap._push(t);\n                t = stk.top(); stk.pop();\n\
    \            }\n            treap._push(t);\n            t->value = v;\n     \
    \       treap._update(t);\n            while(t->par) {\n                t = t->par;\n\
    \                treap._update(t);\n            }\n            return *this;\n\
    \        }\n        operator Value() const {\n            stack<Node*> stk;\n\
    \            Node *t = node;\n            while(t->par) {\n                stk.push(t);\n\
    \                t = t->par;\n            }\n            while(!stk.empty()) {\n\
    \                treap._push(t);\n                t = stk.top(); stk.pop();\n\
    \            }\n            treap._push(t);\n            return t->value;\n  \
    \      }\n    };\n\n    class Iterator {\n    private:\n        ImplicitTreap\
    \ &treap;\n        Node *node;\n    public:\n        Iterator(ImplicitTreap &treap,\
    \ Node *node) : treap(treap), node(node) {}\n        Iterator& operator++() {\n\
    \            if(node->r) {\n                node = node->r;\n                while(node->l)\
    \ node = node->l;\n            } else {\n                while(node->par && node->par->r\
    \ == node) node = node->par;\n                node = node->par;\n            }\n\
    \            return *this;\n        }\n        Iterator& operator--() {\n    \
    \        if(!node) node = treap._root->rightmost();\n            else if(node->l)\
    \ {\n                node = node->l;\n                while(node->r) node = node->r;\n\
    \            } else {\n                while(node->par && node->par->l == node)\
    \ node = node->par;\n                node = node->par;\n            }\n      \
    \      return *this;\n        }\n        bool operator==(const Iterator& itr)\
    \ const { return node == itr.node; }\n        bool operator!=(const Iterator&\
    \ itr) const { return node != itr.node; }\n        ValueReference operator*()\
    \ { return ValueReference(treap, node); }\n        ValueReference operator->()\
    \ { return ValueReference(treap, node); }\n    };\n    friend class Iterator;\n\
    \n    ImplicitTreap(ull seed = random_device{}()) : _rng(seed), _root(nullptr),\
    \ _mapping() {}\n    template <typename It>\n    ImplicitTreap(It first, It last,\
    \ ull seed = random_device{}()) : ImplicitTreap(seed) {\n        while(first !=\
    \ last) {\n            push_back(*first);\n            ++first;\n        }\n \
    \   }\n    ~ImplicitTreap() { _free_subtree(_root); }\n    Iterator begin() {\n\
    \        if(!_root) return Iterator(*this, nullptr);\n        auto [l, r] = _split(_root,\
    \ 1);\n        _root = _merge(l, r);\n        return Iterator(*this, l);\n   \
    \ }\n    Iterator end() { return Iterator(_root, nullptr); }\n    size_t size()\
    \ const { return _root ? _root->cnt : 0; }\n    Iterator kth_element(size_t k)\
    \ {\n        auto [l, r] = _split(_root, k);\n        auto [m, r2] = _split(r,\
    \ 1);\n        _root = _merge(_merge(l, m), r2);\n        return Iterator(*this,\
    \ m);\n    }\n    ValueReference operator[](size_t k) {\n        auto [l, r] =\
    \ _split(_root, k);\n        auto [m, rr] = _split(r, 1);\n        _root = _merge(l,\
    \ rr);\n        return ValueReference(*this, m);\n    }\n    Value query(size_t\
    \ l, size_t r) {\n        auto [l1, r1] = _split(_root, l);\n        auto [m,\
    \ r2] = _split(r1, r - l);\n        Value ret = m->sum;\n        _root = _merge(_merge(l1,\
    \ m), r2);\n        return ret;\n    }\n    void insert(size_t k, const Value&\
    \ v) {\n        auto [l, r] = _split(_root, k);\n        _root = _merge(_merge(l,\
    \ new Node(v, _rng())), r);\n    }\n    void push_back(const Value& v) { insert(size(),\
    \ v); }\n    void erase(size_t k) {\n        auto [l, r] = _split(_root, k);\n\
    \        auto [m, r2] = _split(r, 1);\n        _root = _merge(l, r2);\n      \
    \  delete m;\n    }\n    void pop_back() { erase(size() - 1); }\n    void reverse(size_t\
    \ l, size_t r) {\n        auto [l1, r1] = _split(_root, l);\n        auto [m,\
    \ r2] = _split(r1, r - l);\n        m->rev ^= true;\n        _root = _merge(_merge(l1,\
    \ m), r2);\n    }\n    void apply(size_t l, size_t r, const Update& f) {\n   \
    \     auto [l1, r1] = _split(_root, l);\n        auto [m, r2] = _split(r1, r -\
    \ l);\n        if constexpr(MappingWithSize) {\n            m->sum = _mapping(f,\
    \ m->sum, m->cnt);\n        } else {\n            m->sum = _mapping(f, m->sum);\n\
    \        }\n        m->lazy = UpdateMonoid::op(f, m->lazy);\n        _root = _merge(_merge(l1,\
    \ m), r2);\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: structure/implicit-treap.hpp
  requiredBy: []
  timestamp: '2023-02-20 20:29:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
documentation_of: structure/implicit-treap.hpp
layout: document
redirect_from:
- /library/structure/implicit-treap.hpp
- /library/structure/implicit-treap.hpp.html
title: ImplicitTreap
---
