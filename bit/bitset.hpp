#include "../base.hpp"

struct Bitset {
    private:
    void correct() {
        for(int i = n - (bnum-1)*64; i < 64; i++) {
            v[bnum-1] &= ~(1 << i);
        }
    }
    public:
    vector<ull> v;
    int n, bnum;
    Bitset(int n_ = 0) : n(n_) {
        bnum = (n+63) / 64;
        v.resize(bnum);
    }
    int operator[](int i) {
        return (v[i/64] >> (i%64)) & 1;
    }
    int count() {
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
    bool all() {
        return count() == n;
    }
    bool any() {
        return count() > 0;
    }
    bool none() {
        return count() == 0;
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
        correct();
    }
    void all_set() {
        fill(v.begin(), v.end(),  ~0ULL);
        correct();
    }
    void all_reset() {
        fill(v.begin(), v.end(), 0);
    }
    void all_flip() {
        for (int i = 0; i < v.size(); i++) {
            v[i] = ~v[i];
        }
        correct();
    }
    Bitset& operator&=(const Bitset& b) {
        for(int i = 0; i < min(bnum, b.bnum); i++) {
            v[i] &= b.v[i];
        }
        return *this;
    }
    Bitset operator&(const Bitset& b) const {
        return Bitset(*this) &= b;
    }
    Bitset& operator|=(const Bitset& b) {
        for(int i = 0; i < min(bnum, b.bnum); i++) {
            v[i] |= b.v[i];
        }
        correct();
        return *this;
    }
    Bitset operator|(const Bitset& b) const {
        return Bitset(*this) |= b;
    }
    Bitset& operator^=(const Bitset& b) {
        for(int i = 0; i < min(bnum, b.bnum); i++) {
            v[i] ^= b.v[i];
        }
        correct();
        return *this;
    }
    Bitset operator^(const Bitset& b) const {
        return Bitset(*this) ^= b;
    }
    Bitset operator~() const {
        Bitset b(*this);
        b.all_flip();
        return b;
    }
    bool operator==(const Bitset& b) const {
        return v == b.v;
    }
    bool operator!=(const Bitset& b) const {
        return v != b.v;
    }
    Bitset& operator<<=(int sz) {
        for(int i = bnum-1; i >= 0; i--) {
            if(i-sz/64 >= 0) v[i] = v[i-sz/64] << (sz%64);
            if(i-sz/64-1 >= 0) v[i] |= v[i-sz/64-1] >> (64-sz%64);
        }
        correct();
        return *this;
    }
    Bitset operator<<(int sz) const {
        return Bitset(*this) <<= sz;
    }
    Bitset& operator>>=(int sz) {
        for(int i = 0; i < bnum; i++) {
            if(i+sz/64 < bnum) v[i] = v[i+sz/64] >> (sz%64);
            if(i+sz/64+1 < bnum) v[i] |= v[i+sz/64+1] << (64-sz%64);
        }
        return *this;
    }
    Bitset operator>>(int sz) const {
        return Bitset(*this) >>= sz;
    }
};
