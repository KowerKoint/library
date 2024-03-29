#pragma once
#include "stl-expansion.hpp"
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
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
