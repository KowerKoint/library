#pragma once

#include "integer/modint.hpp"

template <typename It>
Vector<int> kmp_table(It begin, It end) {
    int m = end - begin;
    Vector<int> table(m);
    int j = 0;
    FOR(i, 1, m) {
        while(j > 0 && *(begin+i) != *(begin+j)) j = table[j-1];
        if(*(begin+i) == *(begin+j)) table[i] = ++j;
    }
    return table;
}

Vector<int> kmp_table(string& t) {
    return kmp_table(ALL(t));
}

template <typename It>
Vector<int> kmp_find(It s_begin, It s_end, It t_begin, It t_end, Vector<int>& table) {
    int n = s_end - s_begin;
    int m = t_end - t_begin;
    Vector<int> res;
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

Vector<int> kmp_find(string& s, string& t, Vector<int>& table) {
    return kmp_find(ALL(s), ALL(t), table);
}

template <typename T=char, T begin_char='a', int char_sz=26>
struct Trie {
    struct Node {
        T c;
        int sz = 0;
        int depth;
        Vector<Node*> nxt;
        Node* failure;
        Vector<int> fullmatch_keyword_id;
        Vector<int> suffixmatch_keyword_id;

        Node(T _c, int _d): c(_c), depth(_d) {
            nxt.resize(char_sz);
            fill(ALL(nxt), nullptr);
        }
        ~Node() {
            for(auto& p: nxt) if(p) delete p;
        }
    };

    Node* root;
    int keyword_id = 0;

    Trie() {
        root = new Node(begin_char-1, 0);
    }
    ~Trie() {
        delete root;
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
            if(!to) continue;
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
                if(!to) continue;
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
    void aho_corasick(It begin, It end, function<void(Vector<int>&)>& f) {
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
        function<void(Vector<int>&)> f = [&](Vector<int>& v) {
            res += v.size();
        };
        aho_corasick(begin, end, f);
        return res;
    }

    void aho_corasick(string &s, function<void(Vector<int>&)>& f) {
        aho_corasick(ALL(s), f);
    }

    ll aho_corasick(string &s) {
        return aho_corasick(ALL(s));
    }
};

template <typename T>
struct RollingHash {
    int num;
    Vector<T> base;
    Vector<Vector<T>> power;

    RollingHash(const vector<T>& base_) : num(base_.size()), base(base_) {
        power = Vector<Vector<T>>(num, Vector<T>(1, 1));
    }

    RollingHash(int num_=3) : num(num_) {
        assert(num_ > 0);
        power = Vector<Vector<T>>(num, Vector<T>(1, 1));
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
    Vector<Vector<T>> build(It begin, It end) {
        int n = end - begin;
        Vector<Vector<T>> res(num, Vector<T>(n+1));
        REP(i, num) REP(j, n) {
            res[i][j+1] = res[i][j] * base[i] + *(begin+j);
        }
        return res;
    }

    Vector<Vector<T>> build(const string& s) {
        return build(ALL(s));
    }

    Vector<T> query(const Vector<Vector<T>>& hash, int l, int r) {
        assert(hash.size() == num);
        assert(0 <= l && l <= r && r < hash[0].size());
        expand(r - l);
        Vector<T> res(num);
        REP(i, num) res[i] = hash[i][r] - hash[i][l] * power[i][r-l];
        return res;
    }
};
