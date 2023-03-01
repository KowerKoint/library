---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: operator.hpp
    title: operator.hpp
  - icon: ':heavy_check_mark:'
    path: stl-expansion.hpp
    title: stl-expansion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-determinant-of-matrix.test.cpp
    title: test/yosupo-determinant-of-matrix.test.cpp
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
    }\n#line 3 \"operator.hpp\"\n\ntemplate <typename T>\nT add_op(T a, T b) { return\
    \ a + b; }\ntemplate <typename T>\nT sub_op(T a, T b) { return a - b; }\ntemplate\
    \ <typename T>\nT zero_e() { return T(0); }\ntemplate <typename T>\nT div_op(T\
    \ a, T b) { return a / b; }\ntemplate <typename T>\nT mult_op(T a, T b) { return\
    \ a * b; }\ntemplate <typename T>\nT one_e() { return T(1); }\ntemplate <typename\
    \ T>\nT xor_op(T a, T b) { return a ^ b; }\ntemplate <typename T>\nT and_op(T\
    \ a, T b) { return a & b; }\ntemplate <typename T>\nT or_op(T a, T b) { return\
    \ a | b; }\nll mod3() { return 998244353LL; }\nll mod7() { return 1000000007LL;\
    \ }\nll mod9() { return 1000000009LL; }\ntemplate <typename T>\nT max_op(T a,\
    \ T b) { return max(a, b); }\ntemplate <typename T>\nT min_op(T a, T b) { return\
    \ min(a, b); }\n\ntemplate <typename T>\nT max_e() { return numeric_limits<T>::max();\
    \ }\ntemplate <typename T>\nT min_e() { return numeric_limits<T>::min(); }\n#line\
    \ 4 \"matrix/matrix.hpp\"\n\ntemplate <\n    typename T,\n    T (*add)(const T,\
    \ const T)=add_op,\n    T (*zero)()=zero_e,\n    T (*mult)(const T, const T)=mult_op,\n\
    \    T (*one)()=one_e,\n    T (*sub)(const T, const T)=sub_op,\n    T (*div)(const\
    \ T, const T)=div_op\n>\nstruct Matrix {\n    int n, m;\n    vector<vector<T>>\
    \ A;\n\n    Matrix() : n(0), m(0), A(vector<vector<T>>(0)) {}\n    Matrix(size_t\
    \ _n, size_t _m) : n(_n), m(_m), A(_n, vector<T>(_m, zero())) {}\n    Matrix(const\
    \ vector<vector<T>>& _A) : n(_A.size()), m(_A[0].size()), A(_A) {}\n\n    vector<T>\
    \ &operator[](int i) {\n        assert(0 <= i && i < n);\n        return A.at(i);\n\
    \    }\n    const vector<T> &operator[](int i) const {\n        assert(0 <= i\
    \ && i < n);\n        return A.at(i);\n    }\n\n    static Matrix I(size_t n)\
    \ {\n        assert(n >= 0);\n        Matrix ret(n, n);\n        REP(i, n) ret[i][i]\
    \ = one();\n        return ret;\n    }\n\n    Matrix &operator+=(const Matrix\
    \ &B) {\n        assert(n == B.n && m == B.m);\n        REP(i, n) REP(j, m) A[i][j]\
    \ = add(A[i][j], B[i][j]);\n        return *this;\n    }\n    Matrix operator+(const\
    \ Matrix &B) const {\n        assert(n == B.n && m == B.m);\n        return (Matrix(*this)\
    \ += B);\n    }\n\n    Matrix &operator-=(const Matrix &B) {\n        assert(n\
    \ == B.n && m == B.m);\n        REP(i, n) REP(j, m) A[i][j] = sub(A[i][j], B[i][j]);\n\
    \        return *this;\n    }\n    Matrix operator-(const Matrix &B) const {\n\
    \        assert(n == B.n && m == B.m);\n        return (Matrix(*this) -= B);\n\
    \    }\n\n    Matrix &operator*=(const Matrix &B) {\n        assert(m == B.n);\n\
    \        vector<vector<T>> res(n, vector<T>(B.m, zero()));\n        REP(i, n)\
    \ REP(j, m) REP(k, B.m) res[i][k] = add(res[i][k], mult(A[i][j], B[j][k]));\n\
    \        A.swap(res);\n        m = B.m;\n        return (*this);\n    }\n    Matrix\
    \ operator*(const Matrix &B) const {\n        assert(m == B.n);\n        return\
    \ (Matrix(*this) *= B);\n    }\n\n    Matrix &operator|=(const Matrix &B) {\n\
    \        assert(B.n == n);\n        REP(i, n) {\n            A[i].resize(m+B.m);\n\
    \            REP(j, B.m) A[i][m+j] = B[i][j];\n        }\n        m += B.m;\n\
    \        return (*this);\n    }\n    Matrix operator|(const Matrix &B) const {\n\
    \        assert(B.n == n);\n        return (Matrix(*this) |= B);\n    }\n\n  \
    \  Matrix &operator|=(const vector<T> &B) {\n        assert(B.size() == n);\n\
    \        REP(i, n) {\n            A[i].push_back(B[i]);\n        }\n        m++;\n\
    \        return (*this);\n    }\n    Matrix operator|(const vector<T> &B) const\
    \ {\n        assert(B.size() == n);\n        return (Matrix(*this) |= B);\n  \
    \  }\n\n    Matrix &operator&=(const Matrix &B) {\n        assert(B.m == m);\n\
    \        A.resize(n+B.n);\n        REP(i, B.n) {\n            A[n+i] = B[i];\n\
    \        }\n        n += B.n;\n        return (*this);\n    }\n    Matrix operator&(const\
    \ Matrix &B) const {\n        assert(B.m == m);\n        return (Matrix(*this)\
    \ &= B);\n    }\n\n    Matrix &operator&=(const vector<T> &B) {\n        assert(B.size()\
    \ == m);\n        A.push_back(B);\n        n++;\n        return (*this);\n   \
    \ }\n    Matrix operator&(const vector<T> &B) const {\n        assert(B.size()\
    \ == m);\n        return (Matrix(*this) &= B);\n    }\n\n    friend istream &operator>>(istream\
    \ &is, Matrix &mat) {\n        REP(i, mat.n) REP(j, mat.m) is >> mat[i][j];\n\
    \        return is;\n    }\n\n    friend ostream &operator<<(ostream &os, const\
    \ Matrix &mat) {\n        REP(i, mat.n) {\n            REP(j, mat.m) os << mat[i][j]\
    \ << (j==mat.m-1? '\\n' : ' ');\n        }\n        return os;\n    }\n\n    pair<Matrix,\
    \ T> gaussian_elimination() const {\n        Matrix mat(*this);\n        T det\
    \ = one();\n        VI columns;\n        int i = 0;\n        int j = 0;\n    \
    \    while(i < n && j < m) {\n            int idx = -1;\n            FOR(k, i,\
    \ n) if(mat[k][j] != zero()) idx = k;\n            if(idx == -1) {\n         \
    \       det = zero();\n                j++;\n                continue;\n     \
    \       }\n            if(i != idx) {\n                det *= sub(zero(), one());\n\
    \                swap(mat[i], mat[idx]);\n            }\n            det *= mat[i][j];\n\
    \            T scale = mat[i][j];\n            REP(l, m) mat[i][l] = div(mat[i][l],\
    \ scale);\n            FOR(k, i+1, n) {\n                T scale = mat[k][j];\n\
    \                REP(l, m) mat[k][l] = sub(mat[k][l], mult(mat[i][l], scale));\n\
    \            }\n            columns.push_back(j);\n            i++;\n        \
    \    j++;\n        }\n        REP(i, columns.size()) {\n            int j = columns[i];\n\
    \            REP(k, i) {\n                T scale = mat[k][j];\n             \
    \   FOR(l, j, m) {\n                    mat[k][l] = sub(mat[k][l], mult(mat[i][l],\
    \ scale));\n                }\n            }\n        }\n        return {mat,\
    \ det};\n    }\n\n    void make_basis() {\n        *this = gaussian_elimination().first;\n\
    \        while(n && get_bra(n-1) == vector<T>(m, zero())) pop_bra();\n    }\n\n\
    \    Matrix inv() const {\n        Matrix and_i = (*this) | I(n);\n        auto\
    \ [i_and, det] = and_i.gaussian_elimination();\n        assert(det != zero());\n\
    \        Matrix res(n, n);\n        REP(i, n) REP(j, n) res[i][j] = i_and[i][n+j];\n\
    \        return res;\n    }\n\n    vector<T> get_bra(int i) const {\n        assert(0\
    \ <= i && i < n);\n        return A[i];\n    }\n\n    vector<T> get_ket(int i)\
    \ const {\n        assert(0 <= i && i < m);\n        vector<T> res(n);\n     \
    \   REP(i, n) res[i] = A[i][i];\n        return res;\n    }\n\n    void pop_bra()\
    \ {\n        assert(n > 0);\n        A.pop_back();\n        n--;\n    }\n\n  \
    \  void pop_ket() {\n        assert(m > 0);\n        REP(i, n) A[i].pop_back();\n\
    \        m--;\n    }\n\n    Matrix transpose() const {\n        Matrix res(m,\
    \ n);\n        REP(i, n) REP(j, m) res[j][i] = A[i][j];\n        return res;\n\
    \    }\n\n    Matrix operator^=(ll k) {\n        if(k < 0) {\n            *this\
    \ = this->inv();\n            k = -k;\n        }\n        Matrix res = Matrix::I(n);\n\
    \        while(k) {\n            if(k & 1) res *= *this;\n            *this *=\
    \ *this;\n            k >>= 1LL;\n        }\n        A.swap(res.A);\n        return\
    \ (*this);\n    }\n    Matrix operator^(const ll k) const {\n        return (Matrix(*this)\
    \ ^= k);\n    }\n};\n\nusing XorMatrix = Matrix<\n    int,\n    xor_op<int>,\n\
    \    zero_e<int>,\n    and_op<int>,\n    one_e<int>,\n    xor_op<int>,\n    and_op<int>\n\
    >;\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../operator.hpp\"\n\n\
    template <\n    typename T,\n    T (*add)(const T, const T)=add_op,\n    T (*zero)()=zero_e,\n\
    \    T (*mult)(const T, const T)=mult_op,\n    T (*one)()=one_e,\n    T (*sub)(const\
    \ T, const T)=sub_op,\n    T (*div)(const T, const T)=div_op\n>\nstruct Matrix\
    \ {\n    int n, m;\n    vector<vector<T>> A;\n\n    Matrix() : n(0), m(0), A(vector<vector<T>>(0))\
    \ {}\n    Matrix(size_t _n, size_t _m) : n(_n), m(_m), A(_n, vector<T>(_m, zero()))\
    \ {}\n    Matrix(const vector<vector<T>>& _A) : n(_A.size()), m(_A[0].size()),\
    \ A(_A) {}\n\n    vector<T> &operator[](int i) {\n        assert(0 <= i && i <\
    \ n);\n        return A.at(i);\n    }\n    const vector<T> &operator[](int i)\
    \ const {\n        assert(0 <= i && i < n);\n        return A.at(i);\n    }\n\n\
    \    static Matrix I(size_t n) {\n        assert(n >= 0);\n        Matrix ret(n,\
    \ n);\n        REP(i, n) ret[i][i] = one();\n        return ret;\n    }\n\n  \
    \  Matrix &operator+=(const Matrix &B) {\n        assert(n == B.n && m == B.m);\n\
    \        REP(i, n) REP(j, m) A[i][j] = add(A[i][j], B[i][j]);\n        return\
    \ *this;\n    }\n    Matrix operator+(const Matrix &B) const {\n        assert(n\
    \ == B.n && m == B.m);\n        return (Matrix(*this) += B);\n    }\n\n    Matrix\
    \ &operator-=(const Matrix &B) {\n        assert(n == B.n && m == B.m);\n    \
    \    REP(i, n) REP(j, m) A[i][j] = sub(A[i][j], B[i][j]);\n        return *this;\n\
    \    }\n    Matrix operator-(const Matrix &B) const {\n        assert(n == B.n\
    \ && m == B.m);\n        return (Matrix(*this) -= B);\n    }\n\n    Matrix &operator*=(const\
    \ Matrix &B) {\n        assert(m == B.n);\n        vector<vector<T>> res(n, vector<T>(B.m,\
    \ zero()));\n        REP(i, n) REP(j, m) REP(k, B.m) res[i][k] = add(res[i][k],\
    \ mult(A[i][j], B[j][k]));\n        A.swap(res);\n        m = B.m;\n        return\
    \ (*this);\n    }\n    Matrix operator*(const Matrix &B) const {\n        assert(m\
    \ == B.n);\n        return (Matrix(*this) *= B);\n    }\n\n    Matrix &operator|=(const\
    \ Matrix &B) {\n        assert(B.n == n);\n        REP(i, n) {\n            A[i].resize(m+B.m);\n\
    \            REP(j, B.m) A[i][m+j] = B[i][j];\n        }\n        m += B.m;\n\
    \        return (*this);\n    }\n    Matrix operator|(const Matrix &B) const {\n\
    \        assert(B.n == n);\n        return (Matrix(*this) |= B);\n    }\n\n  \
    \  Matrix &operator|=(const vector<T> &B) {\n        assert(B.size() == n);\n\
    \        REP(i, n) {\n            A[i].push_back(B[i]);\n        }\n        m++;\n\
    \        return (*this);\n    }\n    Matrix operator|(const vector<T> &B) const\
    \ {\n        assert(B.size() == n);\n        return (Matrix(*this) |= B);\n  \
    \  }\n\n    Matrix &operator&=(const Matrix &B) {\n        assert(B.m == m);\n\
    \        A.resize(n+B.n);\n        REP(i, B.n) {\n            A[n+i] = B[i];\n\
    \        }\n        n += B.n;\n        return (*this);\n    }\n    Matrix operator&(const\
    \ Matrix &B) const {\n        assert(B.m == m);\n        return (Matrix(*this)\
    \ &= B);\n    }\n\n    Matrix &operator&=(const vector<T> &B) {\n        assert(B.size()\
    \ == m);\n        A.push_back(B);\n        n++;\n        return (*this);\n   \
    \ }\n    Matrix operator&(const vector<T> &B) const {\n        assert(B.size()\
    \ == m);\n        return (Matrix(*this) &= B);\n    }\n\n    friend istream &operator>>(istream\
    \ &is, Matrix &mat) {\n        REP(i, mat.n) REP(j, mat.m) is >> mat[i][j];\n\
    \        return is;\n    }\n\n    friend ostream &operator<<(ostream &os, const\
    \ Matrix &mat) {\n        REP(i, mat.n) {\n            REP(j, mat.m) os << mat[i][j]\
    \ << (j==mat.m-1? '\\n' : ' ');\n        }\n        return os;\n    }\n\n    pair<Matrix,\
    \ T> gaussian_elimination() const {\n        Matrix mat(*this);\n        T det\
    \ = one();\n        VI columns;\n        int i = 0;\n        int j = 0;\n    \
    \    while(i < n && j < m) {\n            int idx = -1;\n            FOR(k, i,\
    \ n) if(mat[k][j] != zero()) idx = k;\n            if(idx == -1) {\n         \
    \       det = zero();\n                j++;\n                continue;\n     \
    \       }\n            if(i != idx) {\n                det *= sub(zero(), one());\n\
    \                swap(mat[i], mat[idx]);\n            }\n            det *= mat[i][j];\n\
    \            T scale = mat[i][j];\n            REP(l, m) mat[i][l] = div(mat[i][l],\
    \ scale);\n            FOR(k, i+1, n) {\n                T scale = mat[k][j];\n\
    \                REP(l, m) mat[k][l] = sub(mat[k][l], mult(mat[i][l], scale));\n\
    \            }\n            columns.push_back(j);\n            i++;\n        \
    \    j++;\n        }\n        REP(i, columns.size()) {\n            int j = columns[i];\n\
    \            REP(k, i) {\n                T scale = mat[k][j];\n             \
    \   FOR(l, j, m) {\n                    mat[k][l] = sub(mat[k][l], mult(mat[i][l],\
    \ scale));\n                }\n            }\n        }\n        return {mat,\
    \ det};\n    }\n\n    void make_basis() {\n        *this = gaussian_elimination().first;\n\
    \        while(n && get_bra(n-1) == vector<T>(m, zero())) pop_bra();\n    }\n\n\
    \    Matrix inv() const {\n        Matrix and_i = (*this) | I(n);\n        auto\
    \ [i_and, det] = and_i.gaussian_elimination();\n        assert(det != zero());\n\
    \        Matrix res(n, n);\n        REP(i, n) REP(j, n) res[i][j] = i_and[i][n+j];\n\
    \        return res;\n    }\n\n    vector<T> get_bra(int i) const {\n        assert(0\
    \ <= i && i < n);\n        return A[i];\n    }\n\n    vector<T> get_ket(int i)\
    \ const {\n        assert(0 <= i && i < m);\n        vector<T> res(n);\n     \
    \   REP(i, n) res[i] = A[i][i];\n        return res;\n    }\n\n    void pop_bra()\
    \ {\n        assert(n > 0);\n        A.pop_back();\n        n--;\n    }\n\n  \
    \  void pop_ket() {\n        assert(m > 0);\n        REP(i, n) A[i].pop_back();\n\
    \        m--;\n    }\n\n    Matrix transpose() const {\n        Matrix res(m,\
    \ n);\n        REP(i, n) REP(j, m) res[j][i] = A[i][j];\n        return res;\n\
    \    }\n\n    Matrix operator^=(ll k) {\n        if(k < 0) {\n            *this\
    \ = this->inv();\n            k = -k;\n        }\n        Matrix res = Matrix::I(n);\n\
    \        while(k) {\n            if(k & 1) res *= *this;\n            *this *=\
    \ *this;\n            k >>= 1LL;\n        }\n        A.swap(res.A);\n        return\
    \ (*this);\n    }\n    Matrix operator^(const ll k) const {\n        return (Matrix(*this)\
    \ ^= k);\n    }\n};\n\nusing XorMatrix = Matrix<\n    int,\n    xor_op<int>,\n\
    \    zero_e<int>,\n    and_op<int>,\n    one_e<int>,\n    xor_op<int>,\n    and_op<int>\n\
    >;\n"
  dependsOn:
  - base.hpp
  - stl-expansion.hpp
  - operator.hpp
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy: []
  timestamp: '2023-03-02 00:13:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-determinant-of-matrix.test.cpp
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: matrix/matrix.hpp
---