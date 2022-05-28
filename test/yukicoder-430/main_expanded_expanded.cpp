#line 1 "library/KowerKoint/test/yukicoder-430/main_expanded.cpp"

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

vector<pair<char, int>> rle(string s) {
    return rle(ALL(s));
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

/* #include <atcoder/all> */
/* using namespace atcoder; */
/* #include "KowerKoint/expansion/ac-library/all.hpp" */


namespace internal_operator {
    template <typename T>
    T default_add(T a, T b) { return a + b; }
    template <typename T>
    T default_sub(T a, T b) { return a - b; }
    template <typename T>
    T zero() { return T(0); }
    template <typename T>
    T default_div(T a, T b) { return a / b; }
    template <typename T>
    T default_mult(T a, T b) { return a * b; }
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


ll kth_root(ll x, ll k) {
    if(k == 1) return x;
    ll res = 0;
    for(int i = 31; i >= 0; i--) {
        bool over = false;
        ll tmp = 1;
        ll nxt = res | 1LL << i;
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

ll sqrt(ll x) {
    return kth_root(x, 2);
}

struct Prime {
    VI sieved;
    VL primes;

    Prime() {}
    Prime(ll n) {
        expand(n);
    }

    void expand(ll n) {
        ll sz = (ll)sieved.size() - 1;
        if(n <= sz) return;
        sieved.resize(n+1);
        sieved[0] = sieved[1] = 1;
        primes.clear();
        primes.push_back(2);
        for(ll d = 4; d <= n; d += 2) sieved[d] = 1;
        FOR(d, 3, n+1) {
            if(!sieved[d]) {
                primes.push_back(d);
                for(ll i = d*d; i <= n; i += d*2) sieved[i] = 1;
            }
        }
    }

    bool is_prime(ll n) {
        assert(n > 0);
        if(n <= (ll)sieved.size() - 1) return !sieved[n];
        for(ll d = 2; d*d <= n; d++) {
            if(n % d == 0) return false;
        }
        return true;
    }

    VL least_prime_factors(ll n) {
        assert(n > 0);
        VL lpfs(n+1, -1), primes;
        FOR(d, 2, n+1) {
            if(lpfs[d] == -1) {
                lpfs[d] = d;
                primes.push_back(d);
            }
            for(ll p : primes) {
                if(p * d > n || p > lpfs[d]) break;
                lpfs[p*d] = p;
            }
        }
        return lpfs;
    }

    VL prime_list(ll n) {
        assert(n > 0);
        expand(n);
        return VL(primes.begin(), upper_bound(ALL(primes), n));
    }

    vector<pair<ll, int>> prime_factor(ll n) {
        assert(n > 0);
        vector<pair<ll, int>> factor;
        expand(sqrt(n));
        for(ll prime : primes) {
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


    VL divisor(ll n) {
        assert(n > 0);
        auto factor = prime_factor(n);
        VL res = {1};
        for(auto [prime, cnt] : factor) {
            int sz = res.size();
            res.resize(sz * (cnt+1));
            REP(i, sz*cnt) res[sz+i] = res[i] * prime;
            REP(i, cnt) inplace_merge(res.begin(), res.begin() + sz*(i+1), res.begin() + sz*(i+2));
        }
        return res;
    }
};

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

using MI3 = Modint<internal_operator::mod3>;
using V3 = vector<MI3>;
using VV3 = vector<V3>;
using VVV3 = vector<VV3>;
using MI7 = Modint<internal_operator::mod7>;
using V7 = vector<MI7>;
using VV7 = vector<V7>;
using VVV7 = vector<VV7>;
using MI9 = Modint<internal_operator::mod9>;
using V9 = vector<MI9>;
using VV9 = vector<V9>;
using VVV9 = vector<VV9>;

template <typename It>
vector<int> kmp_table(It begin, It end) {
    int m = end - begin;
    vector<int> table(m);
    int j = 0;
    FOR(i, 1, m) {
        while(j > 0 && *(begin+i) != *(begin+j)) j = table[j-1];
        if(*(begin+i) == *(begin+j)) table[i] = ++j;
    }
    return table;
}

vector<int> kmp_table(string& t) {
    return kmp_table(ALL(t));
}

template <typename It>
vector<int> kmp_find(It s_begin, It s_end, It t_begin, It t_end, vector<int>& table) {
    int n = s_end - s_begin;
    int m = t_end - t_begin;
    vector<int> res;
    int j = 0;
    REP(i, n) {
        while(j > 0 && *(s_begin+i) != *(t_begin+j)) j = table[j-1];
        if(*(s_begin+i) == *(t_begin+j)) {
            if(++j == m) {
                res.push_back(i - (m-1));
                j = table[m-1];
            }
        }
    }
    return res;
}

vector<int> kmp_find(string& s, string& t, vector<int>& table) {
    return kmp_find(ALL(s), ALL(t), table);
}

template <typename T=char, T begin_char='a', int char_sz=26>
struct Trie {
    struct Node {
        T c;
        int sz = 0;
        int depth;
        vector<Node*> nxt;
        Node* failure;
        vector<int> fullmatch_keyword_id;
        vector<int> suffixmatch_keyword_id;

        Node(T _c, int _d): c(_c), depth(_d) {
            nxt.resize(char_sz);
            fill(ALL(nxt), nullptr);
        }
    };

    Node* root;
    int keyword_id = 0;

    Trie() {
        root = new Node(begin_char-1, 0);
    }

    template <typename It>
    void add(It begin, It end, int keyword_id_=-1) {
        if(keyword_id_ == -1) keyword_id_ = keyword_id++;
        Node* cursor = root;
        cursor->sz++;
        for(It it = begin; it != end; it++) {
            if(!cursor->nxt[*it-begin_char]) cursor->nxt[*it-begin_char] = new Node(*it, cursor->depth+1);
            cursor = cursor->nxt[*it-begin_char];
            cursor->sz++;
        }
        cursor->fullmatch_keyword_id.push_back(keyword_id_);
    }

    void add(const string& str, int keyword_id_=-1) {
        add(ALL(str), keyword_id_ == -1? keyword_id++ : keyword_id_);
    }

    void build_failure() {
        queue<Node*> que;
        REP(i, char_sz) {
            Node* to = root->nxt[i];
            to->failure = root;
            for(int x : to->fullmatch_keyword_id) {
                to->suffixmatch_keyword_id.push_back(x);
            }
            que.push(to);
        }
        while(!que.empty()) {
            Node* from = que.front(); que.pop();
            REP(i, char_sz) {
                Node* to = from->nxt[i];
                Node* cursor = from->failure;
                while(cursor != root && !cursor->nxt[i]) cursor = cursor->failure;
                if(cursor->nxt[i]) to->failure = cursor->nxt[i];
                else to->failure = root;
                for(int x : to->fullmatch_keyword_id) {
                    to->suffixmatch_keyword_id.push_back(x);
                }
                for(int x : to->failure->suffixmatch_keyword_id) {
                    to->suffixmatch_keyword_id.push_back(x);
                }
                que.push(to);
            }
        }
    }

    template <typename It>
    void aho_corasick(It begin, It end, function<void(vector<int>&)>& f) {
        Node* cursor = root;
        for(It it = begin; it != end; it++) {
            while(cursor != root && !cursor->nxt[*it-begin_char]) cursor = cursor->failure;
            if(cursor->nxt[*it-begin_char]) {
                cursor = cursor->nxt[*it-begin_char];
                f(cursor->suffixmatch_keyword_id);
            }
        }
    }

    template <typename It>
    ll aho_corasick(It begin, It end) {
        ll res = 0;
        function<void(vector<int>&)> f = [&](vector<int>& v) {
            res += v.size();
        };
        aho_corasick(begin, end, f);
        return res;
    }

    void aho_corasick(string &s, function<void(vector<int>&)>& f) {
        aho_corasick(ALL(s), f);
    }

    ll aho_corasick(string &s) {
        return aho_corasick(ALL(s));
    }
};

template <typename T>
struct RollingHash {
    int num;
    vector<T> base;
    vector<vector<T>> power;

    RollingHash(vector<T> base_) : num(base_.size()), base(base_) {
        power = vector<vector<T>>(num, vector<T>(1, 1));
    }

    RollingHash(int num_=3) : num(num_) {
        assert(num_ > 0);
        power = vector<vector<T>>(num, vector<T>(1, 1));
        mt19937 engine((random_device){}());
        REP(i, num) base.push_back(engine());
    }

    void expand(int n) {
        int m = power[0].size();
        if(m > n) return;
        REP(i, num) {
            power[i].resize(n+1);
            FOR(j, m, n+1) power[i][j] = power[i][j-1] * base[i];
        }
    }

    template<typename It>
    vector<vector<T>> build(It begin, It end) {
        int n = end - begin;
        vector<vector<T>> res(num, vector<T>(n+1));
        REP(i, num) REP(j, n) {
            res[i][j+1] = res[i][j] * base[i] + *(begin+j);
        }
        return res;
    }

    vector<vector<T>> build(const string& s) {
        return build(ALL(s));
    }

    vector<T> query(const vector<vector<T>>& hash, int l, int r) {
        assert(hash.size() == num);
        assert(0 <= l && l <= r && r < hash[0].size());
        expand(r - l);
        vector<T> res(num);
        REP(i, num) res[i] = hash[i][r] - hash[i][l] * power[i][r-l];
        return res;
    }
};

void solve(){
    string s; cin >> s;
    int m; cin >> m;
    ll ans = 0;
    Trie<char, 'A'> trie;
    REP(i, m) {
        string c; cin >> c;
        trie.add(c);
    }
    trie.build_failure();
    print(trie.aho_corasick(s));
}

// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)
int main() {
    // Fasterize input/output script
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    // scanf/printf user should delete this fasterize input/output script

    int t = 1;
    //cin >> t; // comment out if solving multi testcase
    for(int testCase = 1;testCase <= t;++testCase){
        solve();
    }
    return 0;
}
