---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: connectivity/union-find.hpp
    title: connectivity/union-find.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: stl-expansion.hpp
    title: stl-expansion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-lowest-common-ancestor.test.cpp
    title: test/yosupo-lowest-common-ancestor.test.cpp
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
    }\n#line 3 \"connectivity/union-find.hpp\"\n\ntemplate <typename Value=nullptr_t,\
    \ Value (*merge_value)(Value, Value)=nullptr, typename Potential=int>\nstruct\
    \ UnionFind {\n    int n;\n    VI par; // size if value is negative\n    vector<Value>\
    \ val;\n    vector<Potential> pot;\n    UnionFind(int n=0) : n(n), par(n, -1),\
    \ val(n), pot(n) {\n        assert(n >= 0);\n    }\n    int root(int x) {\n  \
    \      assert(0 <= x && x < n);\n        if(par[x] < 0) return x;\n        int\
    \ rt = root(par[x]);\n        pot[x] += pot[par[x]];\n        return par[x] =\
    \ rt;\n    }\n    Value get_value(int x) {\n        assert(0 <= x && x < n);\n\
    \        return val[root(x)];\n    }\n    void set_value(int x, Value v) {\n \
    \       assert(0 <= x && x < n);\n        val[root(x)] = v;\n    }\n    Potential\
    \ potential(int x) {\n        assert(0 <= x && x < n);\n        root(x);\n   \
    \     return pot[x];\n    }\n    Potential diff(int x, int y) {\n        assert(0\
    \ <= x && x < n);\n        assert(0 <= y && y < n);\n        return potential(y)\
    \ - potential(x);\n    }\n    int size(int x) {\n        assert(0 <= x && x <\
    \ n);\n        return -par[root(x)];\n    }\n    bool merge(int x, int y, Potential\
    \ p=0) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n\
    \        p += potential(x);\n        p -= potential(y);\n        x = root(x),\
    \ y = root(y);\n        if(x == y) return false;\n        if(par[x] > par[y])\
    \ {\n            swap(x, y);\n            p = -p;\n        }\n        par[x] +=\
    \ par[y];\n        par[y] = x;\n        if(merge_value != nullptr) val[x] = merge_value(val[x],\
    \ val[y]);\n        pot[y] = p;\n        return true;\n    }\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y <\
    \ n);\n        return root(x) == root(y);\n    }\n    VVI groups() {\n       \
    \ VVI res(n);\n        REP(i, n) {\n            res[root(i)].push_back(i);\n \
    \       }\n        sort(ALL(res), [](VI& a, VI& b) {\n            return a.size()\
    \ > b.size();\n        });\n        while(!res.empty() && res.back().empty())\
    \ res.pop_back();\n        return res;\n    }\n};\n\ntemplate <typename Potential>\n\
    using WeightedUnionFind = UnionFind<nullptr_t, nullptr, Potential>;\n#line 4 \"\
    graph/graph.hpp\"\n\ntemplate <typename T=int>\nstruct Edge {\n    int from, to;\n\
    \    T cost;\n    int id;\n    Edge() = default;\n    Edge(int from, int to, T\
    \ cost=1, int id=-1) : from(from), to(to), cost(cost), id(id) {}\n    operator\
    \ int() const { return to; }\n};\n\ntemplate <typename T=int>\nstruct Graph {\n\
    \    int n;\n    int m;\n    vector<vector<Edge<T>>> g;\n    Graph(int n_=0) :\
    \ n(n_), m(0), g(n_) {\n        assert(n_ >= 0);\n    }\n    void add_edge(int\
    \ u, int v, T w=1) {\n        assert(0 <= u && u < n);\n        assert(0 <= v\
    \ && v < n);\n        g[u].push_back({u, v, w, m});\n        g[v].push_back({v,\
    \ u, w, m++});\n    }\n    void add_directed_edge(int u, int v, T w=1) {\n   \
    \     assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m++});\n    }\n    void read(int m_, int padding=-1, bool weighted=false,\
    \ bool directed=false) {\n        assert(m_ >= 0);\n        REP(i, m_) {\n   \
    \         int u, v; cin >> u >> v; u += padding, v += padding;\n            T\
    \ c(1);\n            if(weighted) cin >> c;\n            if(directed) add_directed_edge(u,\
    \ v, c);\n            else add_edge(u, v, c);\n        }\n    }\n    vector<Edge<T>>&\
    \ operator[](int u) {\n        assert(0 <= u && u < n);\n        return g[u];\n\
    \    }\n    const vector<Edge<T>>& operator[](int u) const {\n        assert(0\
    \ <= u && u < n);\n        return g[u];\n    }\n    pair<vector<T>, vector<Edge<T>>>\
    \ dijkstra(int st) const {\n        assert(0 <= st && st < n);\n        T inf\
    \ = numeric_limits<T>::max();\n        vector<T> dist(n, inf);\n        vector<Edge<T>>\
    \ pre(n);\n        GPQ<pair<T, int>> pq;\n        dist[st] = 0;\n        pq.emplace(0,\
    \ st);\n        while(!pq.empty()) {\n            auto [d, from] = pq.top(); pq.pop();\n\
    \            if(dist[from] < d) continue;\n            for(auto& e : g[from])\
    \ {\n                if(chmin(dist[e.to], d + e.cost)) {\n                   \
    \ pre[e.to] = e;\n                    pq.emplace(dist[e.to], e.to);\n        \
    \        }\n            }\n        }\n        return {dist, pre};\n    }\n   \
    \ pair<vector<T>, vector<Edge<T>>> bfs(int st) const {\n        assert(0 <= st\
    \ && st < n);\n        T inf = numeric_limits<T>::max();\n        vector<T> dist(n,\
    \ inf);\n        vector<Edge<T>> pre(n);\n        queue<int> que;\n        dist[st]\
    \ = 0;\n        que.emplace(st);\n        while(!que.empty()) {\n            int\
    \ from = que.front(); que.pop();\n            for(auto& e : g[from]) {\n     \
    \           if(chmin(dist[e.to], dist[e.from] + 1)) {\n                    pre[e.to]\
    \ = e;\n                    que.emplace(e.to);\n                }\n          \
    \  }\n        }\n        return {dist, pre};\n    }\n    vector<Edge<T>> edges()\
    \ const {\n        vector<Edge<T>> res;\n        REP(i, n) for(auto& e : g[i])\
    \ res.emplace_back(e);\n        sort(res.begin(), res.end(), [](const Edge<T>&\
    \ a, const Edge<T>& b) {\n            return a.id < b.id;\n        });\n     \
    \   res.erase(unique(ALL(res), [](const Edge<T>& a, const Edge<T>& b) {\n    \
    \        return a.id == b.id;\n        }), res.end());\n        return res;\n\
    \    }\n    vector<Edge<T>> kruskal() const {\n        vector<Edge<T>> res;\n\
    \        vector<Edge<T>> es = edges();\n        UnionFind uf(n);\n        sort(ALL(es),\
    \ [](const Edge<T>& a, const Edge<T>& b) {\n            return a.cost < b.cost;\n\
    \        });\n        for(auto& e : edges()) {\n            if(uf.merge(e.from,\
    \ e.to)) res.emplace_back(e);\n        }\n        return res;\n    }\n};\n#line\
    \ 3 \"graph/tree.hpp\"\n\ntemplate <typename T=int>\nstruct Tree : Graph<T> {\n\
    \    int root = -1;\n    vector<Edge<T>> par;\n    vector<vector<Edge<T>>> child;\n\
    \    vector<T> depth;\n    vector<int> sz;\n    vector<int> preorder, postorder,\
    \ eulertour;\n    vector<vector<int>> doubling_par;\n    Tree(int n_=0) : Graph<T>(n_)\
    \ {}\n    Tree(const Graph<T>& g) : Graph<T>(g) {}\n    Tree(const vector<int>&\
    \ par_, int padding = -1) : Graph<T>(par_.size()+1) {\n        REP(i, par_.size())\
    \ {\n            this->add_edge(i+1, par_[i] + padding);\n        }\n    }\n \
    \   void read(int padding=-1, bool weighted=false) {\n        Graph<T>::read(this->n-1,\
    \ padding, weighted, false);\n    }\n    void build(int root_) {\n        assert(0\
    \ <= root_ && root_ < this->n);\n        root = root_;\n        int n = this->n;\n\
    \        par = vector<Edge<T>>(n);\n        child = vector<vector<Edge<T>>>(n);\n\
    \        depth = vector<T>(n);\n        sz = vector<int>(n);\n        stack<int>\
    \ stk;\n        stk.push(~root);\n        stk.push(root);\n        par[root] =\
    \ {root, -1, 0, -1};\n        depth[root] = 0;\n        while(!stk.empty()) {\n\
    \            int from = stk.top(); stk.pop();\n            if(from >= 0) {\n \
    \               preorder.push_back(from);\n                eulertour.push_back(from);\n\
    \                for(auto& e : this->g[from]) {\n                    if(e.to ==\
    \ par[from]) continue;\n                    par[e.to] = {e.to, from, e.cost, e.id};\n\
    \                    child[from].push_back(e);\n                    depth[e.to]\
    \ = depth[from] + e.cost;\n                    stk.push(~e.to);\n            \
    \        stk.push(e.to);\n                }\n            } else {\n          \
    \      from = ~from;\n                postorder.push_back(from);\n           \
    \     eulertour.push_back(~from);\n                sz[from] = 1;\n           \
    \     for(auto& e : child[from]) {\n                    sz[from] += sz[e.to];\n\
    \                }\n            }\n        }\n    }\n    void lca_build() {\n\
    \        int n = this->n;\n        int height = 0;\n        while(1 << height\
    \ < n) height++;\n        doubling_par.assign(height, VI(n, -1));\n        REP(i,\
    \ n) doubling_par[0][i] = par[i];\n        REP(i, height-1) {\n            REP(j,\
    \ n) {\n                if(doubling_par[i][j] != -1) {\n                    doubling_par[i+1][j]\
    \ = doubling_par[i][doubling_par[i][j]];\n                }\n            }\n \
    \       }\n    }\n    int climb(int i, int k) {\n        assert(0 <= i && i <\
    \ this->n);\n        int height = doubling_par.size();\n        REP(j, height)\
    \ {\n            if(k >> j & 1) {\n                i = doubling_par[j][i];\n \
    \           }\n            if(i == -1) return -1;\n        }\n        return i;\n\
    \    }\n    int lca(int i, int j) {\n        assert(0 <= i && i < this->n);\n\
    \        assert(0 <= j && j < this->n);\n        if(depth[i] < depth[j]) j = climb(j,\
    \ depth[j] - depth[i]);\n        if(depth[i] > depth[j]) i = climb(i, depth[i]\
    \ - depth[j]);\n        if(i == j) return i;\n        int height = doubling_par.size();\n\
    \        for(int k = height-1; k >= 0; k--) {\n            if(depth[i] < 1 <<\
    \ k) continue;\n            if(doubling_par[k][i] != doubling_par[k][j]) {\n \
    \               i = doubling_par[k][i];\n                j = doubling_par[k][j];\n\
    \            }\n        }\n        return par[i];\n    }\n    int dist(int i,\
    \ int j) {\n        assert(0 <= i && i < this->n);\n        assert(0 <= j && j\
    \ < this->n);\n        return depth[i] + depth[j] - depth[lca(i, j)] * 2;\n  \
    \  }\n};\n"
  code: "#pragma once\n#include \"graph.hpp\"\n\ntemplate <typename T=int>\nstruct\
    \ Tree : Graph<T> {\n    int root = -1;\n    vector<Edge<T>> par;\n    vector<vector<Edge<T>>>\
    \ child;\n    vector<T> depth;\n    vector<int> sz;\n    vector<int> preorder,\
    \ postorder, eulertour;\n    vector<vector<int>> doubling_par;\n    Tree(int n_=0)\
    \ : Graph<T>(n_) {}\n    Tree(const Graph<T>& g) : Graph<T>(g) {}\n    Tree(const\
    \ vector<int>& par_, int padding = -1) : Graph<T>(par_.size()+1) {\n        REP(i,\
    \ par_.size()) {\n            this->add_edge(i+1, par_[i] + padding);\n      \
    \  }\n    }\n    void read(int padding=-1, bool weighted=false) {\n        Graph<T>::read(this->n-1,\
    \ padding, weighted, false);\n    }\n    void build(int root_) {\n        assert(0\
    \ <= root_ && root_ < this->n);\n        root = root_;\n        int n = this->n;\n\
    \        par = vector<Edge<T>>(n);\n        child = vector<vector<Edge<T>>>(n);\n\
    \        depth = vector<T>(n);\n        sz = vector<int>(n);\n        stack<int>\
    \ stk;\n        stk.push(~root);\n        stk.push(root);\n        par[root] =\
    \ {root, -1, 0, -1};\n        depth[root] = 0;\n        while(!stk.empty()) {\n\
    \            int from = stk.top(); stk.pop();\n            if(from >= 0) {\n \
    \               preorder.push_back(from);\n                eulertour.push_back(from);\n\
    \                for(auto& e : this->g[from]) {\n                    if(e.to ==\
    \ par[from]) continue;\n                    par[e.to] = {e.to, from, e.cost, e.id};\n\
    \                    child[from].push_back(e);\n                    depth[e.to]\
    \ = depth[from] + e.cost;\n                    stk.push(~e.to);\n            \
    \        stk.push(e.to);\n                }\n            } else {\n          \
    \      from = ~from;\n                postorder.push_back(from);\n           \
    \     eulertour.push_back(~from);\n                sz[from] = 1;\n           \
    \     for(auto& e : child[from]) {\n                    sz[from] += sz[e.to];\n\
    \                }\n            }\n        }\n    }\n    void lca_build() {\n\
    \        int n = this->n;\n        int height = 0;\n        while(1 << height\
    \ < n) height++;\n        doubling_par.assign(height, VI(n, -1));\n        REP(i,\
    \ n) doubling_par[0][i] = par[i];\n        REP(i, height-1) {\n            REP(j,\
    \ n) {\n                if(doubling_par[i][j] != -1) {\n                    doubling_par[i+1][j]\
    \ = doubling_par[i][doubling_par[i][j]];\n                }\n            }\n \
    \       }\n    }\n    int climb(int i, int k) {\n        assert(0 <= i && i <\
    \ this->n);\n        int height = doubling_par.size();\n        REP(j, height)\
    \ {\n            if(k >> j & 1) {\n                i = doubling_par[j][i];\n \
    \           }\n            if(i == -1) return -1;\n        }\n        return i;\n\
    \    }\n    int lca(int i, int j) {\n        assert(0 <= i && i < this->n);\n\
    \        assert(0 <= j && j < this->n);\n        if(depth[i] < depth[j]) j = climb(j,\
    \ depth[j] - depth[i]);\n        if(depth[i] > depth[j]) i = climb(i, depth[i]\
    \ - depth[j]);\n        if(i == j) return i;\n        int height = doubling_par.size();\n\
    \        for(int k = height-1; k >= 0; k--) {\n            if(depth[i] < 1 <<\
    \ k) continue;\n            if(doubling_par[k][i] != doubling_par[k][j]) {\n \
    \               i = doubling_par[k][i];\n                j = doubling_par[k][j];\n\
    \            }\n        }\n        return par[i];\n    }\n    int dist(int i,\
    \ int j) {\n        assert(0 <= i && i < this->n);\n        assert(0 <= j && j\
    \ < this->n);\n        return depth[i] + depth[j] - depth[lca(i, j)] * 2;\n  \
    \  }\n};\n"
  dependsOn:
  - graph/graph.hpp
  - base.hpp
  - stl-expansion.hpp
  - connectivity/union-find.hpp
  isVerificationFile: false
  path: graph/tree.hpp
  requiredBy: []
  timestamp: '2023-01-21 00:25:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-lowest-common-ancestor.test.cpp
documentation_of: graph/tree.hpp
layout: document
redirect_from:
- /library/graph/tree.hpp
- /library/graph/tree.hpp.html
title: graph/tree.hpp
---