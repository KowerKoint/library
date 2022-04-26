#pragma once

#include "KowerKoint/base.hpp"

template <typename It>
vector<int> kmp_table(It begin, It end) {
    int m = end - begin;
    vector<int> table(m);
    int j = 0;
    FOR(i, 1, m) {
        while(j > 0 && *(begin+i) != *(begin+j)) j = table[j-1];
        if(*(begin+i) == *(begin+j)) table[i] = ++j;
    }
    return table;
}

template <typename It>
vector<int> kmp_find(It s_begin, It s_end, It t_begin, It t_end, vector<int>& table) {
    typename iterator_traits<It>::value_type T;
    int n = s_end - s_begin;
    int m = t_end - t_begin;
    vector<int> res;
    int j = 0;
    REP(i, n) {
        while(j > 0 && *(s_begin+i) != *(t_begin+j)) j = table[j-1];
        if(*(s_begin+i) == *(t_begin+j)) {
            if(++j == m) {
                res.push_back(i - (m-1));
                j = table[m-1];
            }
        }
    }
    return res;
}
