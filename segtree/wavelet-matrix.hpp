#pragma once
#include "../base.hpp"
#include "../bit/bitset.hpp"

template <typename T = ll, int NUMBITS = 63>
struct WaveletMatrix {
    int n;
    int numzero[NUMBITS];
    vector<Bitset> bs[NUMBITS];
    VI sumone[NUMBITS];
    map<T, int> start_idx;

    WaveletMatrix(const vector<T>& v) {
        n = v.size();
        VI indices(n);
        iota(indices.begin(), indices.end(), 0);
        for(int i = NUMBITS-1; i >= 0; i--) {
            if(i < NUMBITS-1) {
                stable_sort(ALL(indices), [&](T a, T b) {
                    return bs[i+1][a] < bs[i+1][b];
                });
            }
            bs[i].resize(n);
            REP(j, n) {
                sumone[i][j+1] = sumone[i][j];
                if(v[indices[j]] >> i & 1) {
                    bs[i].set(j);
                    sumone[i][j+1]++;
                }
            }
            numzero[i] = n - bs[i].count();
        }
        REP(i, n) {
            int idx = indices[i];
            if(start_idx.count(v[idx]) == 0) {
                start_idx[v[idx]] = i;
            }
        }
    }

    T access(int k) {
        T ret = 0;
        for(int i = NUMBITS-1; i >= 0; i--) {
            ret <<= 1;
            if(bs[i][k]) {
                ret |= 1;
                k = numzero[i] + sumone[i][k];
            } else {
                k = k - sumone[i][k];
            }
        }
        return ret;
    }

    int rank(T x, int k) {
        for(int i = NUMBITS-1; i >= 0; i--) {
            if(x >> i & 1) {
                k = numzero[i] + sumone[i][k];
            } else {
                k = k - sumone[i][k];
            }
        }
        return k - start_idx[x];
    }
};
