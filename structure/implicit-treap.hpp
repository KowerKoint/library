#pragma once
#include "../base.hpp"

/**
 * @brief ImplicitTreap
 *
 * @tparam Value 値の型
 * @tparam ValueMonoid 値の総和を計算するモノイド void*の場合は計算しない
 * @tparam Update 更新値 void*の場合は更新しない
 * @tparam UpdateMonoid 更新値の合成関数を示すモノイド
 * @tparam Mapping 更新値を値や総和に作用させる関数(Update, Value)または(Update, Value, size_t)
 * @tparam MappingWithSize Mappingが3引数かどうか 3番目の引数は総和に含まれる値の個数
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

    void _update(Node *t) {
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
        ValueReference(ImplicitTreap &treap, Node *node) : treap(treap), node(node) {}
    public:
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
        operator Value() {
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
        Iterator(ImplicitTreap &treap, Node *node) : treap(treap), node(node) {}
    public:
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

    /**
     * @brief コンストラクタ
     * @param seed 乱数生成器のシード
     *
     * O(1)
     */
    ImplicitTreap(ull seed = random_device{}()) : _rng(seed), _root(nullptr), _mapping() {}
    /**
     * @brief コンストラクタ(初期化付き)
     * @param first 初期化に用いるイテレータの先頭
     * @param last 初期化に用いるイテレータの末尾
     * @param seed 乱数生成器のシード
     *
     * O(N)
     */
    template <typename It>
    ImplicitTreap(It first, It last, ull seed = random_device{}()) : ImplicitTreap(seed) {
        while(first != last) {
            push_back(*first);
            ++first;
        }
    }
    /**
     * @brief デストラクタ
     *
     * O(N)
     */
    ~ImplicitTreap() { _free_subtree(_root); }
    /**
     * @brief beginイテレータ
     * @return beginイテレータ
     *
     * O(log N)
     * イテレータ関連の操作はO(log N)
     */
    Iterator begin() {
        if(!_root) return Iterator(*this, nullptr);
        auto [l, r] = _split(_root, 1);
        _root = _merge(l, r);
        return Iterator(*this, l);
    }
    /**
     * @brief endイテレータ
     * @return endイテレータ
     *
     * O(1)
     * イテレータ関連の操作はO(log N)
     */
    Iterator end() { return Iterator(_root, nullptr); }
    /**
     * @brief 要素数
     * @return 要素数
     *
     * O(1)
     */
    size_t size() const { return _root ? _root->cnt : 0; }
    /**
     * @brief 空かどうか
     * @return 空ならtrue
     *
     * O(1)
     */
    bool empty() const { return !_root; }
    /**
     * @brief k番目の要素への参照
     * @param k 要素の添字
     * @return k番目の要素のイテレータ
     *
     * O(log N)
     */
    Iterator kth_element(size_t k) {
        auto [l, r] = _split(_root, k);
        auto [m, r2] = _split(r, 1);
        _root = _merge(_merge(l, m), r2);
        return Iterator(*this, m);
    }
    /**
     * @brief k番目の要素への参照
     * @param k 要素の添字
     * @return k番目の要素への参照
     *
     * O(log N)
     * 代入可能
     * 参照の扱いもO(log N)かかる
     */
    ValueReference operator[](size_t k) {
        auto [l, r] = _split(_root, k);
        auto [m, rr] = _split(r, 1);
        _root = _merge(l, rr);
        return ValueReference(*this, m);
    }
    /**
     * @brief 総和
     * @param l 範囲の先頭
     * @param r 範囲の末尾
     * @return [l,r)の総和
     */
    Value query(size_t l, size_t r) {
        auto [l1, r1] = _split(_root, l);
        auto [m, r2] = _split(r1, r - l);
        Value ret = m->sum;
        _root = _merge(_merge(l1, m), r2);
        return ret;
    }
    /**
     * @brief 挿入
     * @param k 挿入する要素の添字
     *
     * O(log N)
     */
    void insert(size_t k, const Value& v) {
        auto [l, r] = _split(_root, k);
        _root = _merge(_merge(l, new Node(v, _rng())), r);
    }
    /**
     * @brief 末尾への挿入
     *
     * O(log N)
     */
    void push_back(const Value& v) { insert(size(), v); }
    /**
     * @brief 削除
     * @param k 削除する要素の添字
     *
     * O(log N)
     */
    void erase(size_t k) {
        auto [l, r] = _split(_root, k);
        auto [m, r2] = _split(r, 1);
        _root = _merge(l, r2);
        delete m;
    }
    /**
     * @brief 末尾の削除
     *
     * O(log N)
     */
    void pop_back() { erase(size() - 1); }
    /**
     * @brief [l,r)の反転
     * @param l 範囲の先頭
     * @param r 範囲の末尾
     *
     * O(log N)
     * ValueMonoidを指定する場合は可換でなければならない
     */
    void reverse(size_t l, size_t r) {
        auto [l1, r1] = _split(_root, l);
        auto [m, r2] = _split(r1, r - l);
        m->rev ^= true;
        _root = _merge(_merge(l1, m), r2);
    }
    /**
     * @brief [l,r)の更新
     * @param l 範囲の先頭
     * @param r 範囲の末尾
     * @param v 更新する値
     *
     * O(log N)
     */
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
