#pragma once

#include "integer/modint.hpp"

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
