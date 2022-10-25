#pragma once
#include "graph.hpp"

template <typename T=int>
struct Tree : Graph<T> {
    int root = -1;
    Vector<Edge<T>> par;
    Vector<Vector<Edge<T>>> child;
    Vector<T> depth;
    Vector<int> sz;
    Vector<int> preorder, postorder, eulertour;
    Vector<Vector<int>> doubling_par;
    Tree(int n_=0) : Graph<T>(n_) {}
    Tree(const Graph<T>& g) : Graph<T>(g) {}
    Tree(const vector<int>& par_, int padding = -1) : Graph<T>(par_.size()+1) {
        REP(i, par_.size()) {
            this->add_edge(i+1, par_[i] + padding);
        }
    }
    void read(int padding=-1, bool weighted=false) {
        Graph<T>::read(this->n-1, padding, weighted, false);
    }
    void build(int root_) {
        assert(0 <= root_ && root_ < this->n);
        root = root_;
        int n = this->n;
        par = Vector<Edge<T>>(n);
        child = Vector<Vector<Edge<T>>>(n);
        depth = Vector<T>(n);
        sz = Vector<int>(n);
        stack<int> stk;
        stk.push(~root);
        stk.push(root);
        par[root] = {root, -1, 0, -1};
        depth[root] = 0;
        while(!stk.empty()) {
            int from = stk.top(); stk.pop();
            if(from >= 0) {
                preorder.push_back(from);
                eulertour.push_back(from);
                for(auto& e : this->g[from]) {
                    if(e.to == par[from]) continue;
                    par[e.to] = {e.to, from, e.cost, e.id};
                    child[from].push_back(e);
                    depth[e.to] = depth[from] + e.cost;
                    stk.push(~e.to);
                    stk.push(e.to);
                }
            } else {
                from = ~from;
                postorder.push_back(from);
                eulertour.push_back(~from);
                sz[from] = 1;
                for(auto& e : child[from]) {
                    sz[from] += sz[e.to];
                }
            }
        }
    }
    void lca_build() {
        int n = this->n;
        int height = 0;
        while(1 << height < n) height++;
        doubling_par.assign(height, VI(n, -1));
        REP(i, n) doubling_par[0][i] = par[i];
        REP(i, height-1) {
            REP(j, n) {
                if(doubling_par[i][j] != -1) {
                    doubling_par[i+1][j] = doubling_par[i][doubling_par[i][j]];
                }
            }
        }
    }
    int climb(int i, int k) {
        assert(0 <= i && i < this->n);
        int height = doubling_par.size();
        REP(j, height) {
            if(k >> j & 1) {
                i = doubling_par[j][i];
            }
            if(i == -1) return -1;
        }
        return i;
    }
    int lca(int i, int j) {
        assert(0 <= i && i < this->n);
        assert(0 <= j && j < this->n);
        if(depth[i] < depth[j]) j = climb(j, depth[j] - depth[i]);
        if(depth[i] > depth[j]) i = climb(i, depth[i] - depth[j]);
        if(i == j) return i;
        int height = doubling_par.size();
        for(int k = height-1; k >= 0; k--) {
            if(depth[i] < 1 << k) continue;
            if(doubling_par[k][i] != doubling_par[k][j]) {
                i = doubling_par[k][i];
                j = doubling_par[k][j];
            }
        }
        return par[i];
    }
    int dist(int i, int j) {
        assert(0 <= i && i < this->n);
        assert(0 <= j && j < this->n);
        return depth[i] + depth[j] - depth[lca(i, j)] * 2;
    }
};
