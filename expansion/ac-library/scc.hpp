#pragma once
#include "../../internal_operator.hpp"

struct LoopDetective {
    VI nxt;
    VVI scc;
    VI group;

    LoopDetective(VI nxt_): nxt(nxt_) {
        int n = nxt.size();
        scc_graph sccg(n);
        REP(i, n) sccg.add_edge(i, nxt[i]);
        scc = sccg.scc();
        group.resize(n);
        REP(i, scc.size()) for(int x : scc[i]) group[x] = i;
    }

    pair<VI, VI> path(int s) {
        VI prepath, looppath;
        while(group[s] != group[nxt[s]]) {
            prepath.push_back(s);
            s = nxt[s];
        }
        int t = s;
        do {
            looppath.push_back(t);
            t = nxt[t];
        } while(t != s);
        return {prepath, looppath};
    }

    template<typename T, typename U>
    T query(int s, ll k, vector<U>& v, T init=0LL,
            function<T(T, U)> add=internal_operator::default_add<T>,
            function<U(U, ll)> k_times=internal_operator::default_mult<U>) {
        T res = init;
        auto [prepath, looppath] = path(s);
        REP(i, min(k, (ll)prepath.size())) {
            res = add(res, v[prepath[i]]);
        }
        if(k <= prepath.size()) return res;
        k -= prepath.size();
        T loop_val = init;
        for(int x : looppath) loop_val = add(loop_val, v[x]);
        res = add(res, k_times(loop_val, k / looppath.size()));
        REP(i, k % looppath.size()) {
            res = add(res, v[looppath[i]]);
        }
        return res;
    };
};
