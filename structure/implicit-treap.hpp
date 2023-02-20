#pragma once
#include "../base.hpp"

/**
 * @brief ImplicitTreap
 * @docs docs/implicit-treap.md
 */
template <typename Value, typename ValueMonoid = void*, typename Update = void*, typename UpdateMonoid = void*, typename Mapping = void*, bool MappingWithSize = false>
class ImplicitTreap {
    struct Node {
        Value value;
        ull pri;
        Node *l, *r, *par;
        size_t cnt;
        Value sum;
        bool rev;
        Update lazy;
        Node(const Value &value, ull pri) : value(value), pri(pri), l(nullptr), r(nullptr), par(nullptr), cnt(1), sum(value), rev(false), lazy(UpdateMonoid::id()) {}
    };

    mt19937_64 _rng;
    Node *_root;
    Mapping _mapping;

    inline void _update(Node *t) {
        t->cnt = 1;
        if (t->l) t->cnt += t->l->cnt;
        if (t->r) t->cnt += t->r->cnt;
        if constexpr (!is_same_v<ValueMonoid, void*>) {
            t->sum = t->value;
            if (t->l) t->sum = ValueMonoid::op(t->l->sum, t->sum);
            if (t->r) t->sum = ValueMonoid::op(t->sum, t->r->sum);
        }
    }
    void _push(Node *t) {
        if(t->rev) {
            swap(t->l, t->r);
            if (t->l) t->l->rev ^= true;
            if (t->r) t->r->rev ^= true;
            t->rev = false;
        }
        if constexpr (!is_same_v<Update, void*>) {
            if(t->l) {
                t->l->lazy = UpdateMonoid::op(t->lazy, t->l->lazy);
                if constexpr(MappingWithSize) {
                    t->l->sum = _mapping(t->lazy, t->l->sum, t->l->cnt);
                } else {
                    t->l->sum = _mapping(t->lazy, t->l->sum);
                }
            }
            if(t->r) {
                t->r->lazy = UpdateMonoid::op(t->lazy, t->r->lazy);
                if constexpr(MappingWithSize) {
                    t->r->sum = _mapping(t->lazy, t->r->sum, t->r->cnt);
                } else {
                    t->r->sum = _mapping(t->lazy, t->r->sum);
                }
            }
            if constexpr(MappingWithSize) {
                t->value = _mapping(t->lazy, t->value, 1);
            } else {
                t->value = _mapping(t->lazy, t->value);
            }
            t->lazy = UpdateMonoid::id();
            _update(t);
        }
    }
    void _free_subtree(Node *t) {
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
    pair<Node*, Node*> _split(Node *t, size_t k) {
        stack<pair<Node*, bool>> ret;
        while(t) {
            _push(t);
            size_t implicit_key = 1;
            if(t->l) implicit_key += t->l->cnt;
            if(k < implicit_key) {
                ret.push({t, true});
                t = t->l;
            } else {
                ret.push({t, false});
                t = t->r;
                k -= implicit_key;
            }
        }
        Node *l = nullptr, *r = nullptr;
        while(!ret.empty()) {
            auto [p, b] = ret.top(); ret.pop();
            if(b) {
                p->l = r;
                if(r) r->par = p;
                _update(p);
                r = p;
            } else {
                p->r = l;
                if(l) l->par = p;
                _update(p);
                l = p;
            }
        }
        return {l, r};
    }
    Node* _merge(Node *l, Node *r) {
        stack<pair<Node*, bool>> stk;
        while(1) {
            if(l) _push(l);
            if(r) _push(r);
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
                if(t) t->par = p;
                _update(p);
                t = p;
            } else {
                p->l = t;
                if(t) t->par = p;
                _update(p);
                t = p;
            }
        }
        return t;
    }

public:
    class ValueReference {
    private:
        ImplicitTreap &treap;
        Node *node;
    public:
        ValueReference(ImplicitTreap &treap, Node *node) : treap(treap), node(node) {}
        ValueReference& operator=(const Value& v) {
            stack<Node*> stk;
            Node *t = node;
            while(t->par) {
                stk.push(t);
                t = t->par;
            }
            while(!stk.empty()) {
                treap._push(t);
                t = stk.top(); stk.pop();
            }
            treap._push(t);
            t->value = v;
            treap._update(t);
            while(t->par) {
                t = t->par;
                treap._update(t);
            }
            return *this;
        }
        operator Value() const {
            stack<Node*> stk;
            Node *t = node;
            while(t->par) {
                stk.push(t);
                t = t->par;
            }
            while(!stk.empty()) {
                treap._push(t);
                t = stk.top(); stk.pop();
            }
            treap._push(t);
            return t->value;
        }
    };

    class Iterator {
    private:
        ImplicitTreap &treap;
        Node *node;
    public:
        Iterator(ImplicitTreap &treap, Node *node) : treap(treap), node(node) {}
        Iterator& operator++() {
            if(node->r) {
                node = node->r;
                while(node->l) node = node->l;
            } else {
                while(node->par && node->par->r == node) node = node->par;
                node = node->par;
            }
            return *this;
        }
        Iterator& operator--() {
            if(!node) node = treap._root->rightmost();
            else if(node->l) {
                node = node->l;
                while(node->r) node = node->r;
            } else {
                while(node->par && node->par->l == node) node = node->par;
                node = node->par;
            }
            return *this;
        }
        bool operator==(const Iterator& itr) const { return node == itr.node; }
        bool operator!=(const Iterator& itr) const { return node != itr.node; }
        ValueReference operator*() { return ValueReference(treap, node); }
        ValueReference operator->() { return ValueReference(treap, node); }
    };
    friend class Iterator;

    ImplicitTreap(ull seed = random_device{}()) : _rng(seed), _root(nullptr), _mapping() {}
    template <typename It>
    ImplicitTreap(It first, It last, ull seed = random_device{}()) : ImplicitTreap(seed) {
        while(first != last) {
            push_back(*first);
            ++first;
        }
    }
    ~ImplicitTreap() { _free_subtree(_root); }
    Iterator begin() {
        if(!_root) return Iterator(*this, nullptr);
        auto [l, r] = _split(_root, 1);
        _root = _merge(l, r);
        return Iterator(*this, l);
    }
    Iterator end() { return Iterator(_root, nullptr); }
    size_t size() const { return _root ? _root->cnt : 0; }
    Iterator kth_element(size_t k) {
        auto [l, r] = _split(_root, k);
        auto [m, r2] = _split(r, 1);
        _root = _merge(_merge(l, m), r2);
        return Iterator(*this, m);
    }
    ValueReference operator[](size_t k) {
        auto [l, r] = _split(_root, k);
        auto [m, rr] = _split(r, 1);
        _root = _merge(l, rr);
        return ValueReference(*this, m);
    }
    Value query(size_t l, size_t r) {
        auto [l1, r1] = _split(_root, l);
        auto [m, r2] = _split(r1, r - l);
        Value ret = m->sum;
        _root = _merge(_merge(l1, m), r2);
        return ret;
    }
    void insert(size_t k, const Value& v) {
        auto [l, r] = _split(_root, k);
        _root = _merge(_merge(l, new Node(v, _rng())), r);
    }
    void push_back(const Value& v) { insert(size(), v); }
    void erase(size_t k) {
        auto [l, r] = _split(_root, k);
        auto [m, r2] = _split(r, 1);
        _root = _merge(l, r2);
        delete m;
    }
    void pop_back() { erase(size() - 1); }
    void reverse(size_t l, size_t r) {
        auto [l1, r1] = _split(_root, l);
        auto [m, r2] = _split(r1, r - l);
        m->rev ^= true;
        _root = _merge(_merge(l1, m), r2);
    }
    void apply(size_t l, size_t r, const Update& f) {
        auto [l1, r1] = _split(_root, l);
        auto [m, r2] = _split(r1, r - l);
        if constexpr(MappingWithSize) {
            m->sum = _mapping(f, m->sum, m->cnt);
        } else {
            m->sum = _mapping(f, m->sum);
        }
        m->lazy = UpdateMonoid::op(f, m->lazy);
        _root = _merge(_merge(l1, m), r2);
    }
};
