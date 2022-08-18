#include "../base.hpp"

struct Bitset {
    vector<ull> v;
    int n;
    Bitset(int n_ = 0) : n(n_) {
        v.resize((n+63) / 64);
    }
    int operator[](int i) {
        return (v[i/64] >> (i%64)) & 1;
    }
    void set(int i) {
        v[i / 64] |= 1ull << (i % 64);
    }
    void reset(int i) {
        v[i / 64] &= ~(1ull << (i % 64));
    }
    void flip(int i) {
        v[i / 64] ^= 1ull << (i % 64);
    }
    void resize(int n_) {
        n = n_;
        v.resize((n+63) / 64);
    }
    void all_set() {
        fill(v.begin(), v.end(),  ~0ULL);
    }
    void all_reset() {
        fill(v.begin(), v.end(), 0);
    }
    void all_flip() {
        for (int i = 0; i < v.size(); i++) {
            v[i] = ~v[i];
        }
    }
    int count_all() {
        int c = 0;
        for (int i = 0; i < v.size(); i++) {
            c += __builtin_popcountll(v[i]);
        }
        return c;
    }
    int count_range(int l, int r) {
        int c = 0;
        int l2 = (l+63) / 64;
        int r2 = r / 64;
        for(int i = l2; i < r2; i++) {
            c += __builtin_popcountll(v[i]);
        }
        if(l < l2 * 64) {
            for(int i = l % 64; i < 64; i++) c += (v[l2-1] >> i) & 1;
        }
        if(r2 * 64 < r) {
            for(int i = 0; i < r % 64; i++) c += (v[r2] >> i) & 1;
        }
        return c;
    }
};
