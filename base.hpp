#pragma once

#ifndef ONLINE_JUDGE
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

#ifdef ONLINE_JUDGE
template<typename... Args>
void dbg(const Args &... args) {}
#else
void dbg() { cerr << '\n'; }
template<typename T>
void dbg(const T &t) { cerr << t << '\n'; }
template<typename Head, typename... Tail>
void dbg(const Head &head, const Tail &... tail) {
    cerr << head << ' ';
    dbg(tail...);
}
#endif

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

template<typename T>
vector<vector<T>> split(typename vector<T>::const_iterator begin, typename vector<T>::const_iterator end, T val) {
    vector<vector<T>> res;
    vector<T> cur;
    for(auto it = begin; it != end; it++) {
        if(*it == val) {
            res.push_back(cur);
            cur.clear();
        } else cur.push_back(val);
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
        } else cur.push_back(val);
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