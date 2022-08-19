#pragma once
#include "../base.hpp"

template <typename Value=nullptr_t, Value (*merge_value)(Value, Value)=nullptr, typename Potential=int>
struct UnionFind {
    int n;
    VI par; // size if value is negative
    vector<Value> val;
    vector<Potential> pot;
    UnionFind(int n=0) : n(n), par(n, -1), val(n), pot(n) {}
    int root(int x) {
        if(par[x] < 0) return x;
        int rt = root(par[x]);
        pot[x] += pot[par[x]];
        return par[x] = rt;
    }
    Value get_value(int x) {
        return val[root(x)];
    }
    void set_value(int x, Value v) {
        val[root(x)] = v;
    }
    Potential potential(int x) {
        root(x);
        return pot[x];
    }
    Potential diff(int x, int y) {
        return potential(y) - potential(x);
    }
    int size(int x) {
        return -par[root(x)];
    }
    bool merge(int x, int y, Potential p=0) {
        p += potential(x);
        p -= potential(y);
        x = root(x), y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) {
            swap(x, y);
            p = -p;
        }
        par[x] += par[y];
        par[y] = x;
        if(merge_value != nullptr) val[x] = merge_value(val[x], val[y]);
        pot[y] = p;
        return true;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    VVI groups() {
        VVI res(n);
        REP(i, n) {
            res[root(i)].push_back(i);
        }
        sort(ALL(res), [](VI& a, VI& b) {
            return a.size() > b.size();
        });
        while(!res.empty() && res.back().empty()) res.pop_back();
        return res;
    }
};

template <typename Potential>
using WeightedUnionFind = UnionFind<nullptr_t, nullptr, Potential>;
