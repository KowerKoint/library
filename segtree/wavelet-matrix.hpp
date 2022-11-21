#pragma once
#include "../base.hpp"
#include "../bit/bitset.hpp"

template <typename T = unsigned long long, int NUMBITS = 64>
struct WaveletMatrix {
    int n;
    int numzero[NUMBITS];
    Bitset bs[NUMBITS];
    VI sumone[NUMBITS];
    map<T, int> start_idx;

    WaveletMatrix(const vector<T>& v) {
        n = v.size();
        VI indices(n);
        iota(indices.begin(), indices.end(), 0);
        for(int i = NUMBITS-1; i >= 0; i--) {
            bs[i].resize(n);
            sumone[i].resize(n+1);
            REP(j, n) {
                sumone[i][j+1] = sumone[i][j];
                if(v[indices[j]] >> i & 1) {
                    bs[i].set(j);
                    sumone[i][j+1]++;
                }
            }
            numzero[i] = n - bs[i].count();
            VI iindices(n);
            REP(j, n) iindices[indices[j]] = j;
            stable_sort(ALL(indices), [&](int a, int b) {
                return bs[i][iindices[a]] < bs[i][iindices[b]];
            });
        }
        REP(i, n) {
            int idx = indices[i];
            if(start_idx.count(v[idx]) == 0) {
                start_idx[v[idx]] = i;
            }
        }
    }

    T access(int k) const {
        assert(0 <= k && k < n);
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

    T operator[](int k) const {
        assert(0 <= k && k < n);
        return access(k);
    }

    int rank(T x, int r) const {
        assert(0 <= r && r <= n);
        auto it = start_idx.find(x);
        if(it == start_idx.end()) return 0;
        for(int i = NUMBITS-1; i >= 0; i--) {
            if(x >> i & 1) {
                r = numzero[i] + sumone[i][r];
            } else {
                r = r - sumone[i][r];
            }
        }
        return r - it->second;
    }

    // not tested
    int select(T x, int c) const {
        assert(0 <= c && c < n);
        auto it = start_idx.find(x);
        assert(it != start_idx.end());
        int k = it->second + c + 1;
        REP(i, NUMBITS) {
            if(x >> i & 1) {
                int ok = 1, ng = n+1;
                while(ng - ok > 1) {
                    int mid = (ok + ng) / 2;
                    if(numzero[i] + sumone[i][mid] <= k) ok = mid;
                    else ng = mid;
                }
                k = ok;
            } else {
                int ok = n, ng = 0;
                while(ok - ng > 1) {
                    int mid = (ok + ng) / 2;
                    if(mid - sumone[i][mid] < k) ng = mid;
                    else ok = mid;
                }
                k = ok;
            }
        }
        return k - 1;
    }
};
