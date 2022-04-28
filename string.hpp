#pragma once

#include "KowerKoint/base.hpp"

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

template <typename T=char, T root_char='_', int hash_size=30>
struct Trie {
    struct Node {
        T c;
        unordered_map<char, Node*> nxt;
        Node* failure;
        vector<int> fullmatch_keyword_id;
        vector<int> suffixmatch_keyword_id;

        Node(T _c): c(_c) {
            nxt.reserve(30);
        }
    };

    Node* root;
    int keyword_id = 0;

    Trie() {
        root = new Node(root_char);
    }

    template <typename It>
    void add(It begin, It end, int keyword_id_) {
        Node* cursor = root;
        for(It it = begin; it != end; it++) {
            if(!cursor->nxt.count(*it)) cursor->nxt[*it] = new Node(*it);
            cursor = cursor->nxt[*it];
        }
        cursor->fullmatch_keyword_id.push_back(keyword_id_);
    }

    void add(const string& str, int keyword_id_=-1) {
        add(ALL(str), keyword_id_ == -1? keyword_id++ : keyword_id_);
    }

    void build_failure() {
        queue<Node*> que;
        for(auto [c, to] : root->nxt) {
            to->failure = root;
            for(int x : to->fullmatch_keyword_id) {
                to->suffixmatch_keyword_id.push_back(x);
            }
            que.push(to);
        }
        while(!que.empty()) {
            Node* from = que.front(); que.pop();
            for(auto [c, to] : from->nxt) {
                Node* cursor = from->failure;
                while(cursor != root && !cursor->nxt.count(c)) cursor = cursor->failure;
                if(cursor->nxt.count(c)) to->failure = cursor->nxt[c];
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
            while(cursor != root && !cursor->nxt.count(*it)) cursor = cursor->failure;
            if(cursor->nxt.count(*it)) {
                cursor = cursor->nxt[*it];
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
