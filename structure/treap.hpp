#pragma once
#include "../base.hpp"

/**
 * @brief Treap
 * @docs docs/treap.md
 */
template <typename Key, typename Compare = less<Key>, bool multi = false, typename Value = void*, typename MergeValue = void*>
class Treap {
    struct Node {
        pair<const Key, Value> key_value;
        const Key &key;
        Value &value;
        size_t id;
        ull pri;
        Node *l, *r, *par;
        size_t cnt;
        Value sum;
        Node(const Key &key, const Value &value, ull pri) : key_value(key, value), key(key_value.first), value(key_value.second), pri(pri), l(nullptr), r(nullptr), par(nullptr), cnt(1), sum(value) {
            static size_t id = 0;
            this->id = id++;
        }
        Node* leftmost() {
            Node *t = this;
            while(l) t = t->l;
            return t;
        }
        const Node* leftmost() const {
            const Node *t = this;
            while(t->l) t = t->l;
            return t;
        }
        Node* erase_leftmost() {
            Node *t = this;
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
        Node* rightmost() {
            Node *t = this;
            while(t->r) t = t->r;
            return t;
        }
        const Node* rightmost() const {
            const Node *t = this;
            if(!t) return nullptr;
            while(t->r) t = t->r;
            return t;
        }
        Node* erase_rightmost() {
            Node *t = this;
            if(!t->r) {
                Node *p = t->l;
                if(p) p->par = nullptr;
                delete t;
                return p;
            }
            Node *p = t;
            while(p->r->r) p = p->r;
            Node *q = p->r;
            p->r = q->l;
            if(q->l) q->l->par = p;
            delete q;
            return t;
        }
    };

    mt19937_64 _rng;
    Node *_root;
    Compare _comp;
    MergeValue _merge_value;

    bool _comp_key_id(const Key &key1, size_t id1, const Key &key2, size_t id2) {
        return _comp(key1, key2) || (!_comp(key2, key1) && id1 < id2);
    }
    void _update(Node *t) {
        t->cnt = 1;
        if (t->l) t->cnt += t->l->cnt;
        if (t->r) t->cnt += t->r->cnt;
        if constexpr (!is_same_v<MergeValue, void*>) {
            t->sum = t->value;
            if (t->l) t->sum = _merge_value(t->l->sum, t->sum);
            if (t->r) t->sum = _merge_value(t->sum, t->r->sum);
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
    pair<Node*, Node*> _split(Node *t, const Key &key, size_t id) {
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
    Node* _merge(Node *l, Node *r) {
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
    Node* _lower_bound(Node *t, const Key& key, size_t id) {
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
    const Node* _lower_bound(const Node *t, const Key& key, size_t id) const {
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

public:
    class Iterator {
    private:
        Node *root, *p;
    public:
        Iterator(Node *root, Node *p) : root(root), p(p) {}
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
            if(!p) p = root->rightmost();
            else if(p->l) {
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
        pair<const Key, Value>& operator*() const { return p->key_value; }
        pair<const Key, Value>* operator->() const { return &p->key_value; }
    };
    class ConstIterator {
    private:
        const Node *root, *p;
    public:
        ConstIterator(const Node *root, const Node *p) : p(p) {}
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
            if(!p) p = root->rightmost();
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
        const pair<const Key, Value>& operator*() const { return p->key_value; }
        const pair<const Key, Value>* operator->() const { return &p->key_value; }
    };
    friend struct Iterator;
    friend struct ConstIterator;

    Treap(ull seed = random_device{}()) : _rng(seed), _root(nullptr), _comp()  {}
    ~Treap() { _free_subtree(_root); }
    Iterator begin() { return Iterator(_root, _root->leftmost()); }
    ConstIterator begin() const { return ConstIterator(_root, _root->leftmost()); }
    Iterator end() { return Iterator(_root, nullptr); }
    ConstIterator end() const { return ConstIterator(_root, nullptr); }
    size_t size() const { return _root ? _root->size : 0; }
    Iterator lower_bound(const Key &key) {
        return Iterator(_root, _lower_bound(_root, key, 0ULL));
    }
    ConstIterator lower_bound(const Key &key) const {
        return ConstIterator(_root, _lower_bound(_root, key, 0ULL));
    }
    Iterator upper_bound(const Key &key) {
        return Iterator(_root, _lower_bound(_root, key, numeric_limits<size_t>::max()));
    }
    ConstIterator upper_bound(const Key &key) const {
        return ConstIterator(_root, _lower_bound(_root, key, numeric_limits<size_t>::max()));
    }
    Iterator find(const Key &key) {
        Node *p = _lower_bound(_root, key, 0ULL);
        if(!p || _comp(key, p->key)) return end();
        return Iterator(_root, p);
    }
    ConstIterator find(const Key &key) const {
        const Node *p = _lower_bound(_root, key, 0ULL);
        if(!p || _comp(key, p->key)) return end();
        return ConstIterator(_root, p);
    }
    bool contains(const Key &key) const {
        Node *p = _lower_bound(_root, key, 0ULL);
        return p && !_comp(key, p->key);
    }
    pair<Iterator, bool> insert(const Key &key, const Value &value = Value()) {
        if constexpr(!multi) {
            Node *p = _lower_bound(_root, key, 0ULL);
            if(p && !_comp(key, p->key)) {
                p->value = value;
                return {Iterator(_root, p), false};
            }
        }
        Node *p = new Node(key, value, _rng());
        auto [l, r] = _split(_root, key, p->id);
        _root = _merge(_merge(l, p), r);
        return {Iterator(_root, p), true};
    }
    Value& operator[](const Key &key) {
        Node *p = _lower_bound(_root, key, 0ULL);
        if(!p || _comp(key, p->key)) {
            p = new Node(key, Value(), _rng());
            auto [l, r] = _split(_root, key, p->id);
            _root = _merge(_merge(l, p), r);
        }
        return p->value;
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
        Node *ret = r2 ? r2->leftmost() : nullptr;
        _root = _merge(l, r2);
        delete m;
        return Iterator(_root, ret);
    }
    void clear() {
        _free_subtree(_root);
        _root = nullptr;
    }
};
