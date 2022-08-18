#pragma once
#include "graph.hpp"

template <typename T=int>
struct Tree : Graph<T> {
    int root = -1;
    vector<Edge<T>> par;
    vector<vector<Edge<T>>> child;
    vector<T> depth;
    vector<int> sz;
    Tree(int n_=0) : Graph<T>(n_) {}
    Tree(const Graph<T>& g) : Graph<T>(g) {}
    Tree(const vector<int>& par_, int padding = -1) {
        this->n = par_.size() + 1;
        REP(i, par_.size()) {
            this->add_edge(i+1, par_[i] + padding);
        }
    }
    void read(int padding=-1, bool weighted=false) {
        Graph<T>::read(this->n-1, padding, weighted, false);
        Graph<T>::read(this->n-1, padding, weighted, false);
    }
    void build(int root_) {
        root = root_;
        int n = this->n;
        par = vector<Edge<T>>(n);
        child = vector<vector<Edge<T>>>(n);
        depth = vector<T>(n);
        sz = vector<int>(n);
        stack<int> stk;
        stk.push(~root);
        stk.push(root);
        par[root] = {root, -1, 0, -1};
        depth[root] = 0;
        while(!stk.empty()) {
            int from = stk.top(); stk.pop();
            if(from >= 0) {
                for(auto& e : this[from]) {
                    if(e.to == par[from]) continue;
                    par[e.to] = {e.to, from, e.cost, e.id};
                    child[from].push_back(e);
                    depth[e.to] = depth[from] + e.cost;
                    stk.push(~e.to);
                    stk.push(e.to);
                }
            } else {
                from = ~from;
                sz[from] = 1;
                for(auto& e : child[from]) {
                    sz[from] += sz[e.to];
                }
            }
        }
    }
};
