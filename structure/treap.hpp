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
        size_t id;
        ull pri;
        Node *l, *r, *par;
        size_t cnt;
        Node(const Key &key, ull pri) : key(key), pri(pri), l(nullptr), r(nullptr), par(nullptr), cnt(1) {
            static size_t id = 0;
            this->id = id++;
        }
    };

    mt19937_64 _rng;
    Node *_root;
    Compare _comp;

    bool _comp_key_id(const Key &key1, size_t id1, const Key &key2, size_t id2) {
        return _comp(key1, key2) || (!_comp(key2, key1) && id1 < id2);
    }

    void _update(Node *t) {
        t->cnt = 1;
        if (t->l) t->cnt += t->l->cnt;
        if (t->r) t->cnt += t->r->cnt;
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

    pair<Node *, Node *> _split(Node *t, const Key &key, size_t id) {
        stack<pair<Node *, bool>> ret;
        while(t) {
            if(_comp_key_id(t->key, t->id, key, id)) {
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
                if(l) l->par = p;
                _update(p);
                l = p;
            } else {
                p->l = r;
                if(r) r->par = p;
                _update(p);
                r = p;
            }
        }
        return {l, r};
    }

    Node *_merge(Node *l, Node *r) {
        stack<pair<Node *, bool>> stk;
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

    Node *_lower_bound(Node *t, const Key& key, size_t id) {
        Node *ret = nullptr;
        while(t) {
            if(_comp_key_id(t->key, t->id, key, id)) {
                t = t->r;
            } else {
                ret = t;
                t = t->l;
            }
        }
        return ret;
    }
    const Node *_lower_bound(const Node *t, const Key& key, size_t id) const {
        const Node *ret = nullptr;
        while(t) {
            if(_comp_key_id(t->key, t->id, key, id)) {
                t = t->r;
            } else {
                ret = t;
                t = t->l;
            }
        }
        return ret;
    }

    Node *_leftmost(Node *t) {
        if(!t) return nullptr;
        while(t->l) t = t->l;
        return t;
    }
    const Node *_leftmost(const Node *t) const {
        if(!t) return nullptr;
        while(t->l) t = t->l;
        return t;
    }

    Node *_erase_leftmost(Node *t) {
        if(!t->l) {
            Node *p = t->r;
            if(p) p->par = nullptr;
            delete t;
            return p;
        }
        Node *p = t;
        while(p->l->l) p = p->l;
        Node *q = p->l;
        p->l = q->r;
        if(q->r) q->r->par = p;
        delete q;
        return t;
    }

public:
    class Iterator {
    private:
        Node *p;
    public:
        Iterator(Node *p) : p(p) {}
        Iterator& operator++() {
            if(p->r) {
                p = p->r;
                while(p->l) p = p->l;
            } else {
                while(p->par && p->par->r == p) p = p->par;
                p = p->par;
            }
            return *this;
        }
        Iterator& operator--() {
            if(p->l) {
                p = p->l;
                while(p->r) p = p->r;
            } else {
                while(p->par && p->par->l == p) p = p->par;
                p = p->par;
            }
            return *this;
        }
        bool operator==(const Iterator &rhs) const { return p == rhs.p; }
        bool operator!=(const Iterator &rhs) const { return p != rhs.p; }
        Key& operator*() const { return p->key; }
        Key* operator->() const { return &p->key; }
    };
    class ConstIterator {
    private:
        const Node *p;
    public:
        ConstIterator(const Node *p) : p(p) {}
        ConstIterator& operator++() {
            if(p->r) {
                p = p->r;
                while(p->l) p = p->l;
            } else {
                while(p->par && p->par->r == p) p = p->par;
                p = p->par;
            }
            return *this;
        }
        ConstIterator& operator--() {
            if(p->l) {
                p = p->l;
                while(p->r) p = p->r;
            } else {
                while(p->par && p->par->l == p) p = p->par;
                p = p->par;
            }
            return *this;
        }
        bool operator==(const ConstIterator &rhs) const { return p == rhs.p; }
        bool operator!=(const ConstIterator &rhs) const { return p != rhs.p; }
        const Key& operator*() const { return p->key; }
        const Key* operator->() const { return &p->key; }
    };
    friend struct Iterator;
    friend struct ConstIterator;

    Treap(ull seed = random_device{}()) : _rng(seed), _root(nullptr), _comp()  {}
    ~Treap() { _free_subtree(_root); }
    Iterator begin() { return Iterator(_leftmost(_root)); }
    ConstIterator begin() const { return ConstIterator(_leftmost(_root)); }
    Iterator end() { return Iterator(nullptr); }
    ConstIterator end() const { return ConstIterator(nullptr); }
    size_t size() const { return _root ? _root->size : 0; }
    Iterator lower_bound(Key key) {
        return Iterator(_lower_bound(_root, key, 0ULL));
    }
    ConstIterator lower_bound(Key key) const {
        return ConstIterator(_lower_bound(_root, key, 0ULL));
    }
    Iterator upper_bound(Key key) {
        return Iterator(_lower_bound(_root, key, numeric_limits<size_t>::max()));
    }
    ConstIterator upper_bound(Key key) const {
        return ConstIterator(_lower_bound(_root, key, numeric_limits<size_t>::max()));
    }
    Iterator find(const Key &key) {
        Node *p = _lower_bound(_root, key, 0ULL);
        if(!p || _comp(key, p->key)) return end();
        return Iterator(p);
    }
    ConstIterator find(const Key &key) const {
        const Node *p = _lower_bound(_root, key, 0ULL);
        if(!p || _comp(key, p->key)) return end();
        return ConstIterator(p);
    }
    bool contains(Key key) const {
        Node *p = _lower_bound(_root, key, 0ULL);
        return p && !_comp(key, p->key);
    }
    pair<Iterator, bool> insert(const Key &key) {
        if constexpr(!multi) {
            Node *p = _lower_bound(_root, key, 0ULL);
            if(p && !_comp(key, p->key)) {
                p->key = key;
                return {Iterator(p), false};
            }
        }
        Node *p = new Node(key, _rng());
        auto [l, r] = _split(_root, key, p->id);
        _root = _merge(_merge(l, p), r);
        return {Iterator(p), true};
    }
    size_t erase(const Key &key) {
        auto [l, r] = _split(_root, key, 0ULL);
        auto [m, r2] = _split(r, key, numeric_limits<size_t>::max());
        _root = _merge(l, r2);
        size_t ret = m ? m->cnt : 0;
        _free_subtree(m);
        return ret;
    }
    Iterator erase(Iterator it) {
        Node *p = it.p;
        auto [l, r] = _split(_root, p->key, p->id);
        auto [m, r2] = _split(r, p->key, p->id + 1);
        Node *ret = r2 ? _leftmost(r2) : nullptr;
        _root = _merge(l, r2);
        delete m;
        return Iterator(ret);
    }
    void clear() {
        _free_subtree(_root);
        _root = nullptr;
    }
};
