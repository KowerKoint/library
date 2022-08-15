#line 1 "test/aoj-ntl-1-b.test.cpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#line 2 "base.hpp"

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)
#define ALL(a) (a).begin(),(a).end()
#define END(...) { print(__VA_ARGS__); return; }

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using ull = unsigned long long;
using VUL = vector<ull>;
using VVUL = vector<VUL>;
using VVVUL = vector<VVUL>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VS = vector<string>;
using VVS = vector<VS>;
using VVVS = vector<VVS>;
using VC = vector<char>;
using VVC = vector<VC>;
using VVVC = vector<VVC>;
using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VVVP = vector<VVP>;
using LP = pair<ll, ll>;
using VLP = vector<LP>;
using VVLP = vector<VLP>;
using VVVLP = vector<VVLP>;

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr int DX[] = {1, 0, -1, 0};
constexpr int DY[] = {0, 1, 0, -1};

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

#ifdef DEBUG
void dbg() { cerr << '\n'; }
template<typename T>
void dbg(const T &t) { cerr << t << '\n'; }
template<typename Head, typename... Tail>
void dbg(const Head &head, const Tail &... tail) {
    cerr << head << ' ';
    dbg(tail...);
}
#else
template<typename... Args>
void dbg(const Args &... args) {}
#endif

template<typename T>
vector<vector<T>> split(typename vector<T>::const_iterator begin, typename vector<T>::const_iterator end, T val) {
    vector<vector<T>> res;
    vector<T> cur;
    for(auto it = begin; it != end; it++) {
        if(*it == val) {
            res.push_back(cur);
            cur.clear();
        } else cur.push_back(*it);
    }
    res.push_back(cur);
    return res;
}

vector<string> split(typename string::const_iterator begin, typename string::const_iterator end, char val) {
    vector<string> res;
    string cur = "";
    for(auto it = begin; it != end; it++) {
        if(*it == val) {
            res.push_back(cur);
            cur.clear();
        } else cur.push_back(*it);
    }
    res.push_back(cur);
    return res;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template <typename T>
pair<VI, vector<T>> compress(const vector<T> &a) {
    int n = a.size();
    vector<T> x;
    REP(i, n) x.push_back(a[i]);
    sort(ALL(x)); x.erase(unique(ALL(x)), x.end());
    VI res(n);
    REP(i, n) res[i] = lower_bound(ALL(x), a[i]) - x.begin();
    return make_pair(res, x);
}

template <typename It>
auto rle(It begin, It end) {
    vector<pair<typename It::value_type, int>> res;
    if(begin == end) return res;
    auto pre = *begin;
    int num = 1;
    for(auto it = begin + 1; it != end; it++) {
        if(pre != *it) {
            res.emplace_back(pre, num);
            pre = *it;
            num = 1;
        } else num++;
    }
    res.emplace_back(pre, num);
    return res;
}

template <typename It>
vector<pair<typename It::value_type, int>> rle_sort(It begin, It end) {
    vector<typename It::value_type> cloned(begin, end);
    sort(ALL(cloned));
    auto e = rle(ALL(cloned));
    sort(ALL(e), [](const auto& l, const auto& r) { return l.second < r.second; });
    return e;
}

template <typename T>
pair<vector<T>, vector<T>> factorial(int n) {
    vector<T> res(n+1), rev(n+1);
    res[0] = 1;
    REP(i, n) res[i+1] = res[i] * (i+1);
    rev[n] = 1 / res[n];
    for(int i = n; i > 0; i--) {
        rev[i-1] = rev[i] * i;
    }
    return make_pair(res, rev);
}
#line 3 "internal_operator.hpp"

namespace kowerkoint {
    template <typename T>
    T add(T a, T b) { return a + b; }
    template <typename T>
    T sub(T a, T b) { return a - b; }
    template <typename T>
    T zero() { return T(0); }
    template <typename T>
    T div(T a, T b) { return a / b; }
    template <typename T>
    T mult(T a, T b) { return a * b; }
    template <typename T>
    T one() { return T(1); }
    template <typename T>
    T default_xor(T a, T b) { return a ^ b; }
    template <typename T>
    T default_and(T a, T b) { return a & b; }
    template <typename T>
    T default_or(T a, T b) { return a | b; }
    ll mod3() { return 998244353LL; }
    ll mod7() { return 1000000007LL; }
    ll mod9() { return 1000000009LL; }
    template <typename T>
    T default_max(T a, T b) { return max(a, b); }
    template <typename T>
    T default_min(T a, T b) { return min(a, b); }
}

#line 2 "integer/extgcd.hpp"

ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll nx = 0, ny = 1;
    while(b) {
        ll q = a / b;
        tie(a, b) = LP(b, a % b);
        tie(x, nx) = LP(nx, x - nx*q);
        tie(y, ny) = LP(ny, y - ny*q);
    }
    return a;
}
#line 2 "integer/pow-mod.hpp"

ll inv_mod(ll n, ll m) {
    ll x, y;
    assert(extgcd(n, m, x, y) == 1);
    x %= m;
    if(x < 0) x += m;
    return x;
}

ll pow_mod(ll a, ll n, ll m) {
    if(n == 0) return 1LL;
    if(n < 0) return inv_mod(pow_mod(a, -n, m), m);
    ll res = 1;
    while(n) {
        if(n & 1) {
            res *= a;
            res %= m;
        }
        n >>= 1;
        a *= a;
        a %= m;
    }
    return res;
}
#line 4 "integer/modint.hpp"

template <ll (*mod)()>
struct Modint {
    ll val;
    
    Modint(): val(0) {}

    Modint(ll x): val(x) {
        val %= mod();
        if(val < 0) val += mod();
    }

    Modint& operator+=(const Modint& r) {
        val += r.val;
        if(val >= mod()) val -= mod();
        return *this;
    }
    friend Modint operator+(const Modint& l, const Modint& r) {
        return Modint(l) += r;
    }

    Modint& operator-=(const Modint& r) {
        val -= r.val;
        if(val < 0) val += mod();
        return *this;
    }
    friend Modint operator-(const Modint& l, const Modint& r) {
        return Modint(l) -= r;
    }

    Modint& operator*=(const Modint& r) {
        val *= r.val;
        val %= mod();
        return *this;
    }
    Modint operator*(const Modint& r) {
        return (Modint(*this) *= r);
    }
    friend Modint operator*(const Modint& l, const Modint& r) {
        return Modint(l) *= r;
    }

    Modint pow(ll n) const {
        return Modint(pow_mod(val, n, mod()));
    }

    Modint inv() const {
        return Modint(inv_mod(val, mod()));
    }

    Modint& operator/=(const Modint& r) {
        return (*this *= r.inv());
    }
    friend Modint operator/(const Modint& l, const Modint& r) {
        return Modint(l) /= r;
    }

    Modint& operator^=(const ll n) {
        val = pow_mod(val, n, mod());
        return *this;
    }
    Modint operator^(const ll n) {
        return this->pow(n);
    }

    Modint operator+() const { return *this; }
    Modint operator-() const { return Modint() - *this; }

    Modint& operator++() {
        val++;
        if(val == mod()) val = 0LL;
        return *this;
    }
    Modint& operator++(int) {
        Modint res(*this);
        ++*this;
        return res;
    }

    Modint& operator--() {
        if(val == 0LL) val = mod();
        val--;
        return *this;
    }
    Modint& operator--(int) {
        Modint res(*this);
        --*this;
        return res;
    }

    friend bool operator==(const Modint& l, const Modint& r) {
        return l.val == r.val;
    }
    friend bool operator!=(const Modint& l, const Modint& r) {
        return l.val != r.val;
    }

    static pair<vector<Modint>, vector<Modint>> factorial(int n) {
        vector<Modint> fact(n+1), rfact(n+1);
        fact[0] = 1;
        REP(i, n) fact[i+1] = fact[i] * (i+1);
        rfact[n] = 1 / fact[n];
        for(int i = n-1; i >= 0; i--) rfact[i] = rfact[i+1] * (i+1);
        return {fact, rfact};
    }

    friend istream& operator>>(istream& is, Modint& mi) {
        is >> mi.val;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Modint& mi) {
        os << mi.val;
        return os;
    }
};

using MI3 = Modint<kowerkoint::mod3>;
using V3 = vector<MI3>;
using VV3 = vector<V3>;
using VVV3 = vector<VV3>;
using MI7 = Modint<kowerkoint::mod7>;
using V7 = vector<MI7>;
using VV7 = vector<V7>;
using VVV7 = vector<VV7>;
using MI9 = Modint<kowerkoint::mod9>;
using V9 = vector<MI9>;
using VV9 = vector<V9>;
using VVV9 = vector<VV9>;
#line 3 "test/aoj-ntl-1-b.test.cpp"

int main() {
    int m, n; cin >> m >> n;
    print(MI7(m).pow(n));
}
