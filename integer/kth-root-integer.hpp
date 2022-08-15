#pragma once
#include "../base.hpp"

ull kth_root_integer(ull x, ull k) {
    if(k == 1) return x;
    ll res = 0;
    for(int i = 31; i >= 0; i--) {
        bool over = false;
        ull tmp = 1;
        ull nxt = res | 1ULL << i;
        REP(i, k) {
            if(tmp > x / nxt) {
                over = true;
                break;
            }
            tmp *= nxt;
        }
        if(!over) res = nxt;
    }
    return res;
}

