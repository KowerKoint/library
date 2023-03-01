#pragma once
#include "../base.hpp"

template<typename GroupValue_, typename VertexValue_, typename VertexValueCoef_>
struct UnionFindData {
    GroupValue_ group_value;
    bool vertex_value_determined;
    VertexValue_ vertex_value;
    VertexValueCoef_ a;
    VertexValue_ b;
};
template<>
struct UnionFindData<nullptr_t, nullptr_t, nullptr_t> {
};
template<typename VertexValue_>
struct UnionFindData<nullptr_t, VertexValue_, nullptr_t> {
    bool vertex_value_determined;
    VertexValue_ vertex_value;
    VertexValue_ b;
};
template<typename VertexValue_, typename VertexValueCoef_>
struct UnionFindData<nullptr_t, VertexValue_, VertexValueCoef_> {
    bool vertex_value_determined;
    VertexValue_ vertex_value;
    VertexValueCoef_ a;
    VertexValue_ b;
};
template <typename GroupValue_>
struct UnionFindData<GroupValue_, nullptr_t, nullptr_t> {
    GroupValue_ group_value;
};
template<typename GroupValue_, typename VertexValue_>
struct UnionFindData<GroupValue_, VertexValue_, nullptr_t> {
    GroupValue_ group_value;
    bool vertex_value_determined;
    VertexValue_ vertex_value;
    VertexValue_ b;
};

template <typename GroupValue=nullptr_t, typename MergeGroupValue=nullptr_t, typename VertexValue=nullptr_t, typename VertexValueCoef = nullptr_t>
class UnionFind {
    int _n;
    VI _par; //size if value is negative
    vector<UnionFindData<GroupValue, VertexValue, VertexValueCoef>> _data;
    MergeGroupValue _merge_group_value;

public:
    UnionFind(int n=0) : _n(n), _par(n, -1), _data(n) {
        for(auto &d : _data) {
            if constexpr(!is_same_v<VertexValue, nullptr_t>) {
                d.vertex_value_determined = false;
                d.b = 0;
                if constexpr(!is_same_v<VertexValueCoef, nullptr_t>) {
                    d.a = 1;
                }
            }
        }
    }
    int root(int x) {
        if (_par[x] < 0) return x;
        int r = root(_par[x]);
        if constexpr (!is_same_v<VertexValue, nullptr_t>) {
            if constexpr (is_same_v<VertexValueCoef, nullptr_t>) {
                _data[x].b += _data[_par[x]].b;
            } else {
                _data[x].b =_data[x].a * _data[_par[x]].b + _data[x].b;
                _data[x].a *= _data[_par[x]].a;
            }
        }
        return _par[x] = r;
    }
    GroupValue get_group_value(int x) {
        return _data[root(x)].group_value;
    }
    void set_group_value(int x, GroupValue v) {
        _data[root(x)].group_value = v;
    }
    pair<bool, VertexValue> get_vertex_value(int x) {
        int r = root(x);
        if(!_data[r].vertex_value_determined) return {false, {}};
        if constexpr (is_same_v<VertexValueCoef, nullptr_t>) {
            return {true, _data[r].vertex_value + _data[x].b};
        } else {
            return {true, _data[x].a * _data[r].vertex_value + _data[x].b};
        }
    }
    bool set_vertex_value(int x, VertexValue v) {
        auto [determined, old] = get_vertex_value(x);
        if(determined) return old == v;
        int r = root(x);
        _data[r].vertex_value_determined = true;
        _data[r].vertex_value = (v - _data[x].b) / _data[x].a;
        return true;
    }
    int size(int x) {
        return -_par[root(x)];
    }
    bool merge(int x, int y) {
        static_assert(is_same_v<VertexValue, nullptr_t>);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (_par[x] > _par[y]) swap(x, y);
        _par[x] += _par[y];
        _par[y] = x;
        if constexpr (!is_same_v<GroupValue, nullptr_t>) {
            _data[x].group_value = _merge_group_value(_data[x].group_value, _data[y].group_value);
        }
        return true;
    }
    pair<bool, bool> merge(int x, int y, VertexValue b) {
        static_assert(!is_same_v<VertexValue, nullptr_t>);
        static_assert(is_same_v<VertexValueCoef, nullptr_t>);
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) {
            if(_data[x].b + b != _data[y].b) return {false, false};
            return {true, false};
        }
        b += _data[x].b;
        b -= _data[y].b;
        x = rx, y = ry;
        if (_par[x] > _par[y]) {
            swap(x, y);
            b = -b;
        }
        if(_data[y].vertex_value_determined) {
            if(_data[x].vertex_value_determined) {
                if(_data[x].vertex_value + b != _data[y].vertex_value) return {false, false};
            } else {
                _data[x].vertex_value_determined = true;
                _data[x].vertex_value = _data[y].vertex_value - b;
            }
        }
        _par[x] += _par[y];
        _par[y] = x;
        if constexpr (!is_same_v<GroupValue, nullptr_t>) {
            _data[x].group_value = _merge_group_value(_data[x].group_value, _data[y].group_value);
        }
        _data[y].b = b;
        return {true, true};
    }
    pair<bool, bool> merge(int x, int y, VertexValueCoef a, VertexValue b) {
        static_assert(!is_same_v<VertexValue, nullptr_t>);
        static_assert(!is_same_v<VertexValueCoef, nullptr_t>);
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) {
            VertexValueCoef a1 = a * _data[x].a - _data[y].a;
            VertexValue b1 = a * _data[x].b + b - _data[y].b;
            if(a1 == 0) {
                if(b1 != 0) return {false, false};
            } else if(_data[rx].vertex_value_determined) {
                if(a1 * _data[rx].vertex_value + b1 != 0) return {false, false};
            } else {
                _data[rx].vertex_value_determined = true;
                _data[rx].vertex_value = -b1 / a1;
            }
            return {true, false};
        }
        b = a * _data[x].b + b;
        a *= _data[x].a;
        b = (b - _data[y].b) / _data[y].a;
        a /= _data[y].a;
        x = rx, y = ry;
        if (_par[x] > _par[y]) {
            swap(x, y);
            a = 1 / a;
            b *= -a;
        }
        if(_data[y].vertex_value_determined) {
            if(_data[x].vertex_value_determined) {
                if(a * _data[x].vertex_value + b != _data[y].vertex_value) return {false, false};
            } else {
                _data[x].vertex_value_determined = true;
                _data[x].vertex_value = (_data[y].vertex_value - b) / a;
            }
        }
        _par[x] += _par[y];
        _par[y] = x;
        if constexpr (!is_same_v<GroupValue, nullptr_t>) {
            _data[x].group_value = _merge_group_value(_data[x].group_value, _data[y].group_value);
        }
        _data[y].a = a;
        _data[y].b = b;
        return {true, true};
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    VertexValue diff(int x, int y) {
        static_assert(!is_same_v<VertexValue, nullptr_t>);
        static_assert(is_same_v<VertexValueCoef, nullptr_t>);
        assert(root(x) == root(y));
        return _data[y].b - _data[x].b;
    }
    pair<VertexValueCoef, VertexValue> relation(int x, int y) {
        static_assert(!is_same_v<VertexValue, nullptr_t>);
        static_assert(!is_same_v<VertexValueCoef, nullptr_t>);
        assert(root(x) == root(y));
        VertexValueCoef a = _data[y].a / _data[x].a;
        VertexValue b = _data[y].b - a * _data[x].b;
        return {a, b};
    }
    VVI groups() {
        VVI res(_n);
        REP(i, _n) {
            res[root(i)].push_back(i);
        }
        sort(ALL(res), [](const VI &a, const VI &b) { return a.size() > b.size(); });
        while (res.size() && res.back().empty()) res.pop_back();
        return res;
    }
};

template <typename Potential>
using PotentialUnionFind = UnionFind<nullptr_t, nullptr_t, Potential>;
template <typename Coef, typename Potential>
using RelationUnionFind = UnionFind<nullptr_t, nullptr_t, Potential, Coef>;
