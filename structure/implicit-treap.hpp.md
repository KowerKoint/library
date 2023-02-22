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
    \ *\n * @tparam Value \u5024\u306E\u578B\n * @tparam ValueMonoid \u5024\u306E\u7DCF\
    \u548C\u3092\u8A08\u7B97\u3059\u308B\u30E2\u30CE\u30A4\u30C9 void*\u306E\u5834\
    \u5408\u306F\u8A08\u7B97\u3057\u306A\u3044\n * @tparam Update \u66F4\u65B0\u5024\
    \ void*\u306E\u5834\u5408\u306F\u66F4\u65B0\u3057\u306A\u3044\n * @tparam UpdateMonoid\
    \ \u66F4\u65B0\u5024\u306E\u5408\u6210\u95A2\u6570\u3092\u793A\u3059\u30E2\u30CE\
    \u30A4\u30C9\n * @tparam Mapping \u66F4\u65B0\u5024\u3092\u5024\u3084\u7DCF\u548C\
    \u306B\u4F5C\u7528\u3055\u305B\u308B\u95A2\u6570(Update, Value)\u307E\u305F\u306F\
    (Update, Value, size_t)\n * @tparam MappingWithSize Mapping\u304C3\u5F15\u6570\
    \u304B\u3069\u3046\u304B 3\u756A\u76EE\u306E\u5F15\u6570\u306F\u7DCF\u548C\u306B\
    \u542B\u307E\u308C\u308B\u5024\u306E\u500B\u6570\n */\ntemplate <typename Value,\
    \ typename ValueMonoid = void*, typename Update = void*, typename UpdateMonoid\
    \ = void*, typename Mapping = void*, bool MappingWithSize = false>\nclass ImplicitTreap\
    \ {\n    struct Node {\n        Value value;\n        ull pri;\n        Node *l,\
    \ *r, *par;\n        size_t cnt;\n        Value sum;\n        bool rev;\n    \
    \    Update lazy;\n        Node(const Value &value, ull pri) : value(value), pri(pri),\
    \ l(nullptr), r(nullptr), par(nullptr), cnt(1), sum(value), rev(false), lazy(UpdateMonoid::id())\
    \ {}\n    };\n\n    mt19937_64 _rng;\n    Node *_root;\n    Mapping _mapping;\n\
    \n    void _update(Node *t) {\n        t->cnt = 1;\n        if (t->l) t->cnt +=\
    \ t->l->cnt;\n        if (t->r) t->cnt += t->r->cnt;\n        if constexpr (!is_same_v<ValueMonoid,\
    \ void*>) {\n            t->sum = t->value;\n            if (t->l) t->sum = ValueMonoid::op(t->l->sum,\
    \ t->sum);\n            if (t->r) t->sum = ValueMonoid::op(t->sum, t->r->sum);\n\
    \        }\n    }\n    void _push(Node *t) {\n        if(t->rev) {\n         \
    \   swap(t->l, t->r);\n            if (t->l) t->l->rev ^= true;\n            if\
    \ (t->r) t->r->rev ^= true;\n            t->rev = false;\n        }\n        if\
    \ constexpr (!is_same_v<Update, void*>) {\n            if(t->l) {\n          \
    \      t->l->lazy = UpdateMonoid::op(t->lazy, t->l->lazy);\n                if\
    \ constexpr(MappingWithSize) {\n                    t->l->sum = _mapping(t->lazy,\
    \ t->l->sum, t->l->cnt);\n                } else {\n                    t->l->sum\
    \ = _mapping(t->lazy, t->l->sum);\n                }\n            }\n        \
    \    if(t->r) {\n                t->r->lazy = UpdateMonoid::op(t->lazy, t->r->lazy);\n\
    \                if constexpr(MappingWithSize) {\n                    t->r->sum\
    \ = _mapping(t->lazy, t->r->sum, t->r->cnt);\n                } else {\n     \
    \               t->r->sum = _mapping(t->lazy, t->r->sum);\n                }\n\
    \            }\n            if constexpr(MappingWithSize) {\n                t->value\
    \ = _mapping(t->lazy, t->value, 1);\n            } else {\n                t->value\
    \ = _mapping(t->lazy, t->value);\n            }\n            t->lazy = UpdateMonoid::id();\n\
    \            _update(t);\n        }\n    }\n    void _free_subtree(Node *t) {\n\
    \        if(!t) return;\n        stack<Node *> stk;\n        stk.push(t);\n  \
    \      while(!stk.empty()) {\n            Node *p = stk.top(); stk.pop();\n  \
    \          if(p->l) stk.push(p->l);\n            if(p->r) stk.push(p->r);\n  \
    \          delete p;\n        }\n    }\n    pair<Node*, Node*> _split(Node *t,\
    \ size_t k) {\n        stack<pair<Node*, bool>> ret;\n        while(t) {\n   \
    \         _push(t);\n            size_t implicit_key = 1;\n            if(t->l)\
    \ implicit_key += t->l->cnt;\n            if(k < implicit_key) {\n           \
    \     ret.push({t, true});\n                t = t->l;\n            } else {\n\
    \                ret.push({t, false});\n                t = t->r;\n          \
    \      k -= implicit_key;\n            }\n        }\n        Node *l = nullptr,\
    \ *r = nullptr;\n        while(!ret.empty()) {\n            auto [p, b] = ret.top();\
    \ ret.pop();\n            if(b) {\n                p->l = r;\n               \
    \ if(r) r->par = p;\n                _update(p);\n                r = p;\n   \
    \         } else {\n                p->r = l;\n                if(l) l->par =\
    \ p;\n                _update(p);\n                l = p;\n            }\n   \
    \     }\n        return {l, r};\n    }\n    Node* _merge(Node *l, Node *r) {\n\
    \        stack<pair<Node*, bool>> stk;\n        while(1) {\n            if(l)\
    \ _push(l);\n            if(r) _push(r);\n            if(!l || !r) break;\n  \
    \          if(l->pri > r->pri) {\n                stk.push({l, true});\n     \
    \           l = l->r;\n            } else {\n                stk.push({r, false});\n\
    \                r = r->l;\n            }\n        }\n        Node *t = l ? l\
    \ : r;\n        while(!stk.empty()) {\n            auto [p, b] = stk.top(); stk.pop();\n\
    \            if(b) {\n                p->r = t;\n                if(t) t->par\
    \ = p;\n                _update(p);\n                t = p;\n            } else\
    \ {\n                p->l = t;\n                if(t) t->par = p;\n          \
    \      _update(p);\n                t = p;\n            }\n        }\n       \
    \ return t;\n    }\n\npublic:\n    class ValueReference {\n    private:\n    \
    \    ImplicitTreap &treap;\n        Node *node;\n        ValueReference(ImplicitTreap\
    \ &treap, Node *node) : treap(treap), node(node) {}\n    public:\n        ValueReference&\
    \ operator=(const Value& v) {\n            stack<Node*> stk;\n            Node\
    \ *t = node;\n            while(t->par) {\n                stk.push(t);\n    \
    \            t = t->par;\n            }\n            while(!stk.empty()) {\n \
    \               treap._push(t);\n                t = stk.top(); stk.pop();\n \
    \           }\n            treap._push(t);\n            t->value = v;\n      \
    \      treap._update(t);\n            while(t->par) {\n                t = t->par;\n\
    \                treap._update(t);\n            }\n            return *this;\n\
    \        }\n        operator Value() {\n            stack<Node*> stk;\n      \
    \      Node *t = node;\n            while(t->par) {\n                stk.push(t);\n\
    \                t = t->par;\n            }\n            while(!stk.empty()) {\n\
    \                treap._push(t);\n                t = stk.top(); stk.pop();\n\
    \            }\n            treap._push(t);\n            return t->value;\n  \
    \      }\n    };\n\n    class Iterator {\n    private:\n        ImplicitTreap\
    \ &treap;\n        Node *node;\n        Iterator(ImplicitTreap &treap, Node *node)\
    \ : treap(treap), node(node) {}\n    public:\n        Iterator& operator++() {\n\
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
    \n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ seed \u4E71\u6570\u751F\u6210\u5668\u306E\u30B7\u30FC\u30C9\n     *\n     *\
    \ O(1)\n     */\n    ImplicitTreap(ull seed = random_device{}()) : _rng(seed),\
    \ _root(nullptr), _mapping() {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF(\u521D\u671F\u5316\u4ED8\u304D)\n     * @param first \u521D\
    \u671F\u5316\u306B\u7528\u3044\u308B\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u5148\
    \u982D\n     * @param last \u521D\u671F\u5316\u306B\u7528\u3044\u308B\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u306E\u672B\u5C3E\n     * @param seed \u4E71\u6570\u751F\u6210\
    \u5668\u306E\u30B7\u30FC\u30C9\n     *\n     * O(N)\n     */\n    template <typename\
    \ It>\n    ImplicitTreap(It first, It last, ull seed = random_device{}()) : ImplicitTreap(seed)\
    \ {\n        while(first != last) {\n            push_back(*first);\n        \
    \    ++first;\n        }\n    }\n    /**\n     * @brief \u30C7\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     *\n     * O(N)\n     */\n    ~ImplicitTreap() { _free_subtree(_root);\
    \ }\n    /**\n     * @brief begin\u30A4\u30C6\u30EC\u30FC\u30BF\n     * @return\
    \ begin\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\n     * O(log N)\n     * \u30A4\u30C6\
    \u30EC\u30FC\u30BF\u95A2\u9023\u306E\u64CD\u4F5C\u306FO(log N)\n     */\n    Iterator\
    \ begin() {\n        if(!_root) return Iterator(*this, nullptr);\n        auto\
    \ [l, r] = _split(_root, 1);\n        _root = _merge(l, r);\n        return Iterator(*this,\
    \ l);\n    }\n    /**\n     * @brief end\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\
    \ @return end\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\n     * O(1)\n     * \u30A4\
    \u30C6\u30EC\u30FC\u30BF\u95A2\u9023\u306E\u64CD\u4F5C\u306FO(log N)\n     */\n\
    \    Iterator end() { return Iterator(_root, nullptr); }\n    /**\n     * @brief\
    \ \u8981\u7D20\u6570\n     * @return \u8981\u7D20\u6570\n     *\n     * O(1)\n\
    \     */\n    size_t size() const { return _root ? _root->cnt : 0; }\n    /**\n\
    \     * @brief \u7A7A\u304B\u3069\u3046\u304B\n     * @return \u7A7A\u306A\u3089\
    true\n     *\n     * O(1)\n     */\n    bool empty() const { return !_root; }\n\
    \    /**\n     * @brief k\u756A\u76EE\u306E\u8981\u7D20\u3078\u306E\u53C2\u7167\
    \n     * @param k \u8981\u7D20\u306E\u6DFB\u5B57\n     * @return k\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\n     * O(log N)\n\
    \     */\n    Iterator kth_element(size_t k) {\n        auto [l, r] = _split(_root,\
    \ k);\n        auto [m, r2] = _split(r, 1);\n        _root = _merge(_merge(l,\
    \ m), r2);\n        return Iterator(*this, m);\n    }\n    /**\n     * @brief\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u3078\u306E\u53C2\u7167\n     * @param k \u8981\
    \u7D20\u306E\u6DFB\u5B57\n     * @return k\u756A\u76EE\u306E\u8981\u7D20\u3078\
    \u306E\u53C2\u7167\n     *\n     * O(log N)\n     * \u4EE3\u5165\u53EF\u80FD\n\
    \     * \u53C2\u7167\u306E\u6271\u3044\u3082O(log N)\u304B\u304B\u308B\n     */\n\
    \    ValueReference operator[](size_t k) {\n        auto [l, r] = _split(_root,\
    \ k);\n        auto [m, rr] = _split(r, 1);\n        _root = _merge(l, rr);\n\
    \        return ValueReference(*this, m);\n    }\n    /**\n     * @brief \u7DCF\
    \u548C\n     * @param l \u7BC4\u56F2\u306E\u5148\u982D\n     * @param r \u7BC4\
    \u56F2\u306E\u672B\u5C3E\n     * @return [l,r)\u306E\u7DCF\u548C\n     */\n  \
    \  Value query(size_t l, size_t r) {\n        if(l == r) return ValueMonoid::id();\n\
    \        auto [l1, r1] = _split(_root, l);\n        auto [m, r2] = _split(r1,\
    \ r - l);\n        Value ret = m->sum;\n        _root = _merge(_merge(l1, m),\
    \ r2);\n        return ret;\n    }\n    /**\n     * @brief \u633F\u5165\n    \
    \ * @param k \u633F\u5165\u3059\u308B\u8981\u7D20\u306E\u6DFB\u5B57\n     *\n\
    \     * O(log N)\n     */\n    void insert(size_t k, const Value& v) {\n     \
    \   auto [l, r] = _split(_root, k);\n        _root = _merge(_merge(l, new Node(v,\
    \ _rng())), r);\n    }\n    /**\n     * @brief \u672B\u5C3E\u3078\u306E\u633F\u5165\
    \n     *\n     * O(log N)\n     */\n    void push_back(const Value& v) { insert(size(),\
    \ v); }\n    /**\n     * @brief \u524A\u9664\n     * @param k \u524A\u9664\u3059\
    \u308B\u8981\u7D20\u306E\u6DFB\u5B57\n     *\n     * O(log N)\n     */\n    void\
    \ erase(size_t k) {\n        auto [l, r] = _split(_root, k);\n        auto [m,\
    \ r2] = _split(r, 1);\n        _root = _merge(l, r2);\n        delete m;\n   \
    \ }\n    /**\n     * @brief \u672B\u5C3E\u306E\u524A\u9664\n     *\n     * O(log\
    \ N)\n     */\n    void pop_back() { erase(size() - 1); }\n    /**\n     * @brief\
    \ [l,r)\u306E\u53CD\u8EE2\n     * @param l \u7BC4\u56F2\u306E\u5148\u982D\n  \
    \   * @param r \u7BC4\u56F2\u306E\u672B\u5C3E\n     *\n     * O(log N)\n     *\
    \ ValueMonoid\u3092\u6307\u5B9A\u3059\u308B\u5834\u5408\u306F\u53EF\u63DB\u3067\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\n     */\n    void reverse(size_t\
    \ l, size_t r) {\n        if(l == r) return;\n        auto [l1, r1] = _split(_root,\
    \ l);\n        auto [m, r2] = _split(r1, r - l);\n        m->rev ^= true;\n  \
    \      _root = _merge(_merge(l1, m), r2);\n    }\n    /**\n     * @brief [l,r)\u306E\
    \u66F4\u65B0\n     * @param l \u7BC4\u56F2\u306E\u5148\u982D\n     * @param r\
    \ \u7BC4\u56F2\u306E\u672B\u5C3E\n     * @param v \u66F4\u65B0\u3059\u308B\u5024\
    \n     *\n     * O(log N)\n     */\n    void apply(size_t l, size_t r, const Update&\
    \ f) {\n        if(l == r) return;\n        auto [l1, r1] = _split(_root, l);\n\
    \        auto [m, r2] = _split(r1, r - l);\n        if constexpr(MappingWithSize)\
    \ {\n            m->sum = _mapping(f, m->sum, m->cnt);\n        } else {\n   \
    \         m->sum = _mapping(f, m->sum);\n        }\n        m->lazy = UpdateMonoid::op(f,\
    \ m->lazy);\n        _root = _merge(_merge(l1, m), r2);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief ImplicitTreap\n\
    \ *\n * @tparam Value \u5024\u306E\u578B\n * @tparam ValueMonoid \u5024\u306E\u7DCF\
    \u548C\u3092\u8A08\u7B97\u3059\u308B\u30E2\u30CE\u30A4\u30C9 void*\u306E\u5834\
    \u5408\u306F\u8A08\u7B97\u3057\u306A\u3044\n * @tparam Update \u66F4\u65B0\u5024\
    \ void*\u306E\u5834\u5408\u306F\u66F4\u65B0\u3057\u306A\u3044\n * @tparam UpdateMonoid\
    \ \u66F4\u65B0\u5024\u306E\u5408\u6210\u95A2\u6570\u3092\u793A\u3059\u30E2\u30CE\
    \u30A4\u30C9\n * @tparam Mapping \u66F4\u65B0\u5024\u3092\u5024\u3084\u7DCF\u548C\
    \u306B\u4F5C\u7528\u3055\u305B\u308B\u95A2\u6570(Update, Value)\u307E\u305F\u306F\
    (Update, Value, size_t)\n * @tparam MappingWithSize Mapping\u304C3\u5F15\u6570\
    \u304B\u3069\u3046\u304B 3\u756A\u76EE\u306E\u5F15\u6570\u306F\u7DCF\u548C\u306B\
    \u542B\u307E\u308C\u308B\u5024\u306E\u500B\u6570\n */\ntemplate <typename Value,\
    \ typename ValueMonoid = void*, typename Update = void*, typename UpdateMonoid\
    \ = void*, typename Mapping = void*, bool MappingWithSize = false>\nclass ImplicitTreap\
    \ {\n    struct Node {\n        Value value;\n        ull pri;\n        Node *l,\
    \ *r, *par;\n        size_t cnt;\n        Value sum;\n        bool rev;\n    \
    \    Update lazy;\n        Node(const Value &value, ull pri) : value(value), pri(pri),\
    \ l(nullptr), r(nullptr), par(nullptr), cnt(1), sum(value), rev(false), lazy(UpdateMonoid::id())\
    \ {}\n    };\n\n    mt19937_64 _rng;\n    Node *_root;\n    Mapping _mapping;\n\
    \n    void _update(Node *t) {\n        t->cnt = 1;\n        if (t->l) t->cnt +=\
    \ t->l->cnt;\n        if (t->r) t->cnt += t->r->cnt;\n        if constexpr (!is_same_v<ValueMonoid,\
    \ void*>) {\n            t->sum = t->value;\n            if (t->l) t->sum = ValueMonoid::op(t->l->sum,\
    \ t->sum);\n            if (t->r) t->sum = ValueMonoid::op(t->sum, t->r->sum);\n\
    \        }\n    }\n    void _push(Node *t) {\n        if(t->rev) {\n         \
    \   swap(t->l, t->r);\n            if (t->l) t->l->rev ^= true;\n            if\
    \ (t->r) t->r->rev ^= true;\n            t->rev = false;\n        }\n        if\
    \ constexpr (!is_same_v<Update, void*>) {\n            if(t->l) {\n          \
    \      t->l->lazy = UpdateMonoid::op(t->lazy, t->l->lazy);\n                if\
    \ constexpr(MappingWithSize) {\n                    t->l->sum = _mapping(t->lazy,\
    \ t->l->sum, t->l->cnt);\n                } else {\n                    t->l->sum\
    \ = _mapping(t->lazy, t->l->sum);\n                }\n            }\n        \
    \    if(t->r) {\n                t->r->lazy = UpdateMonoid::op(t->lazy, t->r->lazy);\n\
    \                if constexpr(MappingWithSize) {\n                    t->r->sum\
    \ = _mapping(t->lazy, t->r->sum, t->r->cnt);\n                } else {\n     \
    \               t->r->sum = _mapping(t->lazy, t->r->sum);\n                }\n\
    \            }\n            if constexpr(MappingWithSize) {\n                t->value\
    \ = _mapping(t->lazy, t->value, 1);\n            } else {\n                t->value\
    \ = _mapping(t->lazy, t->value);\n            }\n            t->lazy = UpdateMonoid::id();\n\
    \            _update(t);\n        }\n    }\n    void _free_subtree(Node *t) {\n\
    \        if(!t) return;\n        stack<Node *> stk;\n        stk.push(t);\n  \
    \      while(!stk.empty()) {\n            Node *p = stk.top(); stk.pop();\n  \
    \          if(p->l) stk.push(p->l);\n            if(p->r) stk.push(p->r);\n  \
    \          delete p;\n        }\n    }\n    pair<Node*, Node*> _split(Node *t,\
    \ size_t k) {\n        stack<pair<Node*, bool>> ret;\n        while(t) {\n   \
    \         _push(t);\n            size_t implicit_key = 1;\n            if(t->l)\
    \ implicit_key += t->l->cnt;\n            if(k < implicit_key) {\n           \
    \     ret.push({t, true});\n                t = t->l;\n            } else {\n\
    \                ret.push({t, false});\n                t = t->r;\n          \
    \      k -= implicit_key;\n            }\n        }\n        Node *l = nullptr,\
    \ *r = nullptr;\n        while(!ret.empty()) {\n            auto [p, b] = ret.top();\
    \ ret.pop();\n            if(b) {\n                p->l = r;\n               \
    \ if(r) r->par = p;\n                _update(p);\n                r = p;\n   \
    \         } else {\n                p->r = l;\n                if(l) l->par =\
    \ p;\n                _update(p);\n                l = p;\n            }\n   \
    \     }\n        return {l, r};\n    }\n    Node* _merge(Node *l, Node *r) {\n\
    \        stack<pair<Node*, bool>> stk;\n        while(1) {\n            if(l)\
    \ _push(l);\n            if(r) _push(r);\n            if(!l || !r) break;\n  \
    \          if(l->pri > r->pri) {\n                stk.push({l, true});\n     \
    \           l = l->r;\n            } else {\n                stk.push({r, false});\n\
    \                r = r->l;\n            }\n        }\n        Node *t = l ? l\
    \ : r;\n        while(!stk.empty()) {\n            auto [p, b] = stk.top(); stk.pop();\n\
    \            if(b) {\n                p->r = t;\n                if(t) t->par\
    \ = p;\n                _update(p);\n                t = p;\n            } else\
    \ {\n                p->l = t;\n                if(t) t->par = p;\n          \
    \      _update(p);\n                t = p;\n            }\n        }\n       \
    \ return t;\n    }\n\npublic:\n    class ValueReference {\n    private:\n    \
    \    ImplicitTreap &treap;\n        Node *node;\n        ValueReference(ImplicitTreap\
    \ &treap, Node *node) : treap(treap), node(node) {}\n    public:\n        ValueReference&\
    \ operator=(const Value& v) {\n            stack<Node*> stk;\n            Node\
    \ *t = node;\n            while(t->par) {\n                stk.push(t);\n    \
    \            t = t->par;\n            }\n            while(!stk.empty()) {\n \
    \               treap._push(t);\n                t = stk.top(); stk.pop();\n \
    \           }\n            treap._push(t);\n            t->value = v;\n      \
    \      treap._update(t);\n            while(t->par) {\n                t = t->par;\n\
    \                treap._update(t);\n            }\n            return *this;\n\
    \        }\n        operator Value() {\n            stack<Node*> stk;\n      \
    \      Node *t = node;\n            while(t->par) {\n                stk.push(t);\n\
    \                t = t->par;\n            }\n            while(!stk.empty()) {\n\
    \                treap._push(t);\n                t = stk.top(); stk.pop();\n\
    \            }\n            treap._push(t);\n            return t->value;\n  \
    \      }\n    };\n\n    class Iterator {\n    private:\n        ImplicitTreap\
    \ &treap;\n        Node *node;\n        Iterator(ImplicitTreap &treap, Node *node)\
    \ : treap(treap), node(node) {}\n    public:\n        Iterator& operator++() {\n\
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
    \n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ seed \u4E71\u6570\u751F\u6210\u5668\u306E\u30B7\u30FC\u30C9\n     *\n     *\
    \ O(1)\n     */\n    ImplicitTreap(ull seed = random_device{}()) : _rng(seed),\
    \ _root(nullptr), _mapping() {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF(\u521D\u671F\u5316\u4ED8\u304D)\n     * @param first \u521D\
    \u671F\u5316\u306B\u7528\u3044\u308B\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u5148\
    \u982D\n     * @param last \u521D\u671F\u5316\u306B\u7528\u3044\u308B\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u306E\u672B\u5C3E\n     * @param seed \u4E71\u6570\u751F\u6210\
    \u5668\u306E\u30B7\u30FC\u30C9\n     *\n     * O(N)\n     */\n    template <typename\
    \ It>\n    ImplicitTreap(It first, It last, ull seed = random_device{}()) : ImplicitTreap(seed)\
    \ {\n        while(first != last) {\n            push_back(*first);\n        \
    \    ++first;\n        }\n    }\n    /**\n     * @brief \u30C7\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     *\n     * O(N)\n     */\n    ~ImplicitTreap() { _free_subtree(_root);\
    \ }\n    /**\n     * @brief begin\u30A4\u30C6\u30EC\u30FC\u30BF\n     * @return\
    \ begin\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\n     * O(log N)\n     * \u30A4\u30C6\
    \u30EC\u30FC\u30BF\u95A2\u9023\u306E\u64CD\u4F5C\u306FO(log N)\n     */\n    Iterator\
    \ begin() {\n        if(!_root) return Iterator(*this, nullptr);\n        auto\
    \ [l, r] = _split(_root, 1);\n        _root = _merge(l, r);\n        return Iterator(*this,\
    \ l);\n    }\n    /**\n     * @brief end\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\
    \ @return end\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\n     * O(1)\n     * \u30A4\
    \u30C6\u30EC\u30FC\u30BF\u95A2\u9023\u306E\u64CD\u4F5C\u306FO(log N)\n     */\n\
    \    Iterator end() { return Iterator(_root, nullptr); }\n    /**\n     * @brief\
    \ \u8981\u7D20\u6570\n     * @return \u8981\u7D20\u6570\n     *\n     * O(1)\n\
    \     */\n    size_t size() const { return _root ? _root->cnt : 0; }\n    /**\n\
    \     * @brief \u7A7A\u304B\u3069\u3046\u304B\n     * @return \u7A7A\u306A\u3089\
    true\n     *\n     * O(1)\n     */\n    bool empty() const { return !_root; }\n\
    \    /**\n     * @brief k\u756A\u76EE\u306E\u8981\u7D20\u3078\u306E\u53C2\u7167\
    \n     * @param k \u8981\u7D20\u306E\u6DFB\u5B57\n     * @return k\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     *\n     * O(log N)\n\
    \     */\n    Iterator kth_element(size_t k) {\n        auto [l, r] = _split(_root,\
    \ k);\n        auto [m, r2] = _split(r, 1);\n        _root = _merge(_merge(l,\
    \ m), r2);\n        return Iterator(*this, m);\n    }\n    /**\n     * @brief\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u3078\u306E\u53C2\u7167\n     * @param k \u8981\
    \u7D20\u306E\u6DFB\u5B57\n     * @return k\u756A\u76EE\u306E\u8981\u7D20\u3078\
    \u306E\u53C2\u7167\n     *\n     * O(log N)\n     * \u4EE3\u5165\u53EF\u80FD\n\
    \     * \u53C2\u7167\u306E\u6271\u3044\u3082O(log N)\u304B\u304B\u308B\n     */\n\
    \    ValueReference operator[](size_t k) {\n        auto [l, r] = _split(_root,\
    \ k);\n        auto [m, rr] = _split(r, 1);\n        _root = _merge(l, rr);\n\
    \        return ValueReference(*this, m);\n    }\n    /**\n     * @brief \u7DCF\
    \u548C\n     * @param l \u7BC4\u56F2\u306E\u5148\u982D\n     * @param r \u7BC4\
    \u56F2\u306E\u672B\u5C3E\n     * @return [l,r)\u306E\u7DCF\u548C\n     */\n  \
    \  Value query(size_t l, size_t r) {\n        if(l == r) return ValueMonoid::id();\n\
    \        auto [l1, r1] = _split(_root, l);\n        auto [m, r2] = _split(r1,\
    \ r - l);\n        Value ret = m->sum;\n        _root = _merge(_merge(l1, m),\
    \ r2);\n        return ret;\n    }\n    /**\n     * @brief \u633F\u5165\n    \
    \ * @param k \u633F\u5165\u3059\u308B\u8981\u7D20\u306E\u6DFB\u5B57\n     *\n\
    \     * O(log N)\n     */\n    void insert(size_t k, const Value& v) {\n     \
    \   auto [l, r] = _split(_root, k);\n        _root = _merge(_merge(l, new Node(v,\
    \ _rng())), r);\n    }\n    /**\n     * @brief \u672B\u5C3E\u3078\u306E\u633F\u5165\
    \n     *\n     * O(log N)\n     */\n    void push_back(const Value& v) { insert(size(),\
    \ v); }\n    /**\n     * @brief \u524A\u9664\n     * @param k \u524A\u9664\u3059\
    \u308B\u8981\u7D20\u306E\u6DFB\u5B57\n     *\n     * O(log N)\n     */\n    void\
    \ erase(size_t k) {\n        auto [l, r] = _split(_root, k);\n        auto [m,\
    \ r2] = _split(r, 1);\n        _root = _merge(l, r2);\n        delete m;\n   \
    \ }\n    /**\n     * @brief \u672B\u5C3E\u306E\u524A\u9664\n     *\n     * O(log\
    \ N)\n     */\n    void pop_back() { erase(size() - 1); }\n    /**\n     * @brief\
    \ [l,r)\u306E\u53CD\u8EE2\n     * @param l \u7BC4\u56F2\u306E\u5148\u982D\n  \
    \   * @param r \u7BC4\u56F2\u306E\u672B\u5C3E\n     *\n     * O(log N)\n     *\
    \ ValueMonoid\u3092\u6307\u5B9A\u3059\u308B\u5834\u5408\u306F\u53EF\u63DB\u3067\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\n     */\n    void reverse(size_t\
    \ l, size_t r) {\n        if(l == r) return;\n        auto [l1, r1] = _split(_root,\
    \ l);\n        auto [m, r2] = _split(r1, r - l);\n        m->rev ^= true;\n  \
    \      _root = _merge(_merge(l1, m), r2);\n    }\n    /**\n     * @brief [l,r)\u306E\
    \u66F4\u65B0\n     * @param l \u7BC4\u56F2\u306E\u5148\u982D\n     * @param r\
    \ \u7BC4\u56F2\u306E\u672B\u5C3E\n     * @param v \u66F4\u65B0\u3059\u308B\u5024\
    \n     *\n     * O(log N)\n     */\n    void apply(size_t l, size_t r, const Update&\
    \ f) {\n        if(l == r) return;\n        auto [l1, r1] = _split(_root, l);\n\
    \        auto [m, r2] = _split(r1, r - l);\n        if constexpr(MappingWithSize)\
    \ {\n            m->sum = _mapping(f, m->sum, m->cnt);\n        } else {\n   \
    \         m->sum = _mapping(f, m->sum);\n        }\n        m->lazy = UpdateMonoid::op(f,\
    \ m->lazy);\n        _root = _merge(_merge(l1, m), r2);\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  isVerificationFile: false
  path: structure/implicit-treap.hpp
  requiredBy: []
  timestamp: '2023-02-22 17:51:21+09:00'
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
