#pragma once
#include "../base.hpp"

/**
 * @brief Treap
 * @docs docs/treap.md
 */
template <typename Key, typename Compare = less<Key>, bool multi = false>
class Treap {
    struct Node {
        Key key;
        ull pri;
        Node *l, *r;
    };

    mt19937_64 rng;
    Node *root;
    Compare comp;

    void free(Node *t) {
        if(!t) return;
        stack<Node *> stk;
        stk.push(t);
        while(!stk.empty()) {
            Node *p = stk.top(); stk.pop();
            if(p->l) stk.push(p->l);
            if(p->r) stk.push(p->r);
            delete p;
        }
    }

    pair<Node*, Node*> split(Node *t, Key key, bool upper = false) {
        stack<pair<Node*, bool>> ret;
        while(t) {
            if((!upper && comp(t->key, key)) || (upper && comp(key, t->key))) {
                ret.push({t, true});
                t = t->r;
            } else {
                ret.push({t, false});
                t = t->l;
            }
        }
        Node *l = nullptr, *r = nullptr;
        while(!ret.empty()) {
            auto [p, b] = ret.top(); ret.pop();
            if(b) {
                p->r = l;
                l = p;
            } else {
                p->l = r;
                r = p;
            }
        }
        return {l, r};
    }

    Node* merge(Node *l, Node *r) {
        stack<pair<Node*, bool>> stk;
        while(1) {
            if(!l || !r) break;
            if(l->pri > r->pri) {
                stk.push({l, true});
                l = l->r;
            } else {
                stk.push({r, false});
                r = r->l;
            }
        }
        Node *t = l ? l : r;
        while(!stk.empty()) {
            auto [p, b] = stk.top(); stk.pop();
            if(b) {
                p->r = t;
                t = p;
            } else {
                p->l = t;
                t = p;
            }
        }
        return t;
    }

    Node* lower_bound(Node *t, Key key) {
        Node *ret = nullptr;
        while(t) {
            if(comp(t->key, key)) {
                t = t->r;
            } else {
                ret = t;
                t = t->l;
            }
        }
        return ret;
    }

    Node* upper_bound(Node *t, Key key) {
        Node *ret = nullptr;
        while(t) {
            if(comp(key, t->key)) {
                ret = t;
                t = t->l;
            } else {
                t = t->r;
            }
        }
        return ret;
    }

    Node* insert(Node *t, Key key) {
        if constexpr(!multi) {
            Node *p = lower_bound(t, key);
            if(p && !comp(p->key, key) && !comp(key, p->key)) {
                p->key = key;
                return t;
            }
        }
        auto [l, r] = split(t, key);
        Node *p = new Node{key, rng(), nullptr, nullptr};
        return merge(merge(l, p), r);
    }

    Node *erase_smallest(Node *t) {
        if(!t->l) {
            Node *r = t->r;
            delete t;
            return r;
        }
        Node *p = t;
        while(p->l->l) p = p->l;
        delete p->l;
        p->l = nullptr;
        return t;
    }

    Node* erase_one(Node *t, Key key) {
        Node *p = lower_bound(t, key);
        if(!p || comp(key, p->key)) return t;
        auto [l, r] = split(t, key);
        r = erase_smallest(r);
        return merge(l, r);
    }

    Node* erase_all(Node *t, Key key) {
        auto [l, r] = split(t, key);
        auto [m, r2] = split(r, key, true);
        free(m);
        return merge(l, r2);
    }

public:
    Treap(ull seed = random_device{}()) : rng(seed), root(nullptr), comp()  {}
    ~Treap() { free(root); }
    Node *lower_bound(Key key) {
        return lower_bound(root, key);
    }
    Node *upper_bound(Key key) {
        return upper_bound(root, key);
    }
    Node *find(Key key) {
        Node *p = lower_bound(root, key);
        if(!p || comp(key, p->key)) return nullptr;
        return p;
    }
    bool contains(Key key) {
        Node *p = lower_bound(root, key);
        return p && !comp(key, p->key);
    }
    void insert(Key key) {
        root = insert(root, key);
    }
    void erase(Key key) {
        if constexpr(!multi) {
            root = erase_one(root, key);
        } else {
            root = erase_all(root, key);
        }
    }
    void erase_one(Key key) {
        root = erase_one(root, key);
    }
    void erase_all(Key key) {
        root = erase_all(root, key);
    }
};
