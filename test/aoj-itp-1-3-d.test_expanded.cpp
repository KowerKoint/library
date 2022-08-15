#line 1 "test/aoj-itp-1-3-d.test.cpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
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
#line 3 "integer/kth-root-integer.hpp"

ull kth_root_integer(ull x, ull k) {
    if(k == 1) return x;
    ll res = 0;
    for(int i = 31; i >= 0; i--) {
        bool over = false;
        ull tmp = 1;
        ull nxt = res | 1ULL << i;
        REP(i, k) {
            if(tmp > x / nxt) {
                over = true;
                break;
            }
            tmp *= nxt;
        }
        if(!over) res = nxt;
    }
    return res;
}

#line 3 "integer/prime.hpp"

struct Prime {
    vector<bool> sieved;
    VI primes;

    Prime() {}
    Prime(int n) {
        expand(n);
    }

    void expand(int n) {
        int sz = (int)sieved.size() - 1;
        if(n <= sz) return;
        sieved.resize(n+1);
        sieved[0] = sieved[1] = 1;
        primes.clear();
        primes.push_back(2);
        for(int d = 4; d <= n; d += 2) sieved[d] = 1;
        FOR(d, 3, n+1) {
            if(!sieved[d]) {
                primes.push_back(d);
                for(ll i = (ll)d*d; i <= n; i += d*2) sieved[i] = 1;
            }
        }
    }

    bool is_prime(ull n) {
        assert(n > 0);
        if(n <= (int)sieved.size() - 1) return !sieved[n];
        for(ull d = 2; d*d <= n; d++) {
            if(n % d == 0) return false;
        }
        return true;
    }

    VI prime_list(int n) {
        assert(n > 0);
        expand(n);
        return VI(primes.begin(), upper_bound(ALL(primes), n));
    }

    vector<pair<ull, int>> prime_factor(ull n) {
        assert(n > 0);
        vector<pair<ull, int>> factor;
        expand(kth_root_integer(n, 2));
        for(ull prime : primes) {
            if(prime * prime > n) break;
            int cnt = 0;
            while(n % prime == 0) {
                n /= prime;
                cnt++;
            }
            if(cnt) factor.emplace_back(prime, cnt);
        }
        if(n > 1) factor.emplace_back(n, 1);
        return factor;
    }


    VUL divisor(ull n) {
        assert(n > 0);
        auto factor = prime_factor(n);
        VUL res = {1};
        for(auto [prime, cnt] : factor) {
            int sz = res.size();
            res.resize(sz * (cnt+1));
            REP(i, sz*cnt) res[sz+i] = res[i] * prime;
            REP(i, cnt) inplace_merge(res.begin(), res.begin() + sz*(i+1), res.begin() + sz*(i+2));
        }
        return res;
    }
};
#line 3 "test/aoj-itp-1-3-d.test.cpp"

int main() {
    int a, b, c; cin >> a >> b >> c;
    Prime pm;
    auto divisors = pm.divisor(c);
    print(upper_bound(ALL(divisors), b) - lower_bound(ALL(divisors), a));
}
