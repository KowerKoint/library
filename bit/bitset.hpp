#include "../base.hpp"

struct Bitset {
    private:
    constexpr static ull mask[] = {
        0x0000000000000000ull, 0x0000000000000001ull, 0x0000000000000003ull, 0x0000000000000007ull,
        0x000000000000000Full, 0x000000000000001Full, 0x000000000000003Full, 0x000000000000007Full,
        0x00000000000000FFull, 0x00000000000001FFull, 0x00000000000003FFull, 0x00000000000007FFull,
        0x0000000000000FFFull, 0x0000000000001FFFull, 0x0000000000003FFFull, 0x0000000000007FFFull,
        0x000000000000FFFFull, 0x000000000001FFFFull, 0x000000000003FFFFull, 0x000000000007FFFFull,
        0x00000000000FFFFFull, 0x00000000001FFFFFull, 0x00000000003FFFFFull, 0x00000000007FFFFFull,
        0x0000000000FFFFFFull, 0x0000000001FFFFFFull, 0x0000000003FFFFFFull, 0x0000000007FFFFFFull,
        0x000000000FFFFFFFull, 0x000000001FFFFFFFull, 0x000000003FFFFFFFull, 0x000000007FFFFFFFull,
        0x00000000FFFFFFFFull, 0x00000001FFFFFFFFull, 0x00000003FFFFFFFFull, 0x00000007FFFFFFFFull,
        0x0000000FFFFFFFFFull, 0x0000001FFFFFFFFFull, 0x0000003FFFFFFFFFull, 0x0000007FFFFFFFFFull,
        0x000000FFFFFFFFFFull, 0x000001FFFFFFFFFFull, 0x000003FFFFFFFFFFull, 0x000007FFFFFFFFFFull,
        0x00000FFFFFFFFFFFull, 0x00001FFFFFFFFFFFull, 0x00003FFFFFFFFFFFull, 0x00007FFFFFFFFFFFull,
        0x0000FFFFFFFFFFFFull, 0x0001FFFFFFFFFFFFull, 0x0003FFFFFFFFFFFFull, 0x0007FFFFFFFFFFFFull,
        0x000FFFFFFFFFFFFFull, 0x001FFFFFFFFFFFFFull, 0x003FFFFFFFFFFFFFull, 0x007FFFFFFFFFFFFFull,
        0x00FFFFFFFFFFFFFFull, 0x01FFFFFFFFFFFFFFull, 0x03FFFFFFFFFFFFFFull, 0x07FFFFFFFFFFFFFFull,
        0x0FFFFFFFFFFFFFFFull, 0x1FFFFFFFFFFFFFFFull, 0x3FFFFFFFFFFFFFFFull, 0x7FFFFFFFFFFFFFFFull,
        0xFFFFFFFFFFFFFFFFull
    };
    void correct() {
        if(n % 64) v[bnum-1] &= mask[n % 64];
    }
    public:
    vector<ull> v;
    int n, bnum;
    Bitset(int n_ = 0) : n(n_) {
        assert(n_ >= 0);
        bnum = (n+63) / 64;
        v.resize(bnum);
    }
    int operator[](int i) const {
        assert(0 <= i && i < n);
        return (v[i/64] >> (i%64)) & 1;
    }
    int count() const {
        int c = 0;
        for (int i = 0; i < v.size(); i++) {
            c += __builtin_popcountll(v[i]);
        }
        return c;
    }
    // not tested
    int count_range(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        int c = 0;
        int l2 = l / 64;
        int r2 = r / 64;
        for(int i = l2; i < r2; i++) {
            c += __builtin_popcountll(v[i]);
        }
        if(l % 64) {
            c -= __builtin_popcountll(v[l2] & mask[l % 64]);
        }
        if(r % 64) {
            c += __builtin_popcountll(v[r2] & mask[r % 64]);
        }
        return c;
    }
    bool all() const {
        return count() == n;
    }
    bool any() const {
        return count() > 0;
    }
    bool none() const {
        return count() == 0;
    }
    void set(int i) {
        assert(0 <= i && i < n);
        v[i / 64] |= 1ull << (i % 64);
    }
    void reset(int i) {
        assert(0 <= i && i < n);
        v[i / 64] &= ~(1ull << (i % 64));
    }
    void flip(int i) {
        assert(0 <= i && i < n);
        v[i / 64] ^= 1ull << (i % 64);
    }
    void resize(int n_) {
        assert(n_ >= 0);
        n = n_;
        bnum = (n+63) / 64;
        v.resize(bnum);
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
        assert(n == b.n);
        for(int i = 0; i < min(bnum, b.bnum); i++) {
            v[i] &= b.v[i];
        }
        return *this;
    }
    Bitset operator&(const Bitset& b) const {
        assert(n == b.n);
        return Bitset(*this) &= b;
    }
    Bitset& operator|=(const Bitset& b) {
        assert(n == b.n);
        for(int i = 0; i < min(bnum, b.bnum); i++) {
            v[i] |= b.v[i];
        }
        correct();
        return *this;
    }
    Bitset operator|(const Bitset& b) const {
        assert(n == b.n);
        return Bitset(*this) |= b;
    }
    Bitset& operator^=(const Bitset& b) {
        assert(n == b.n);
        for(int i = 0; i < min(bnum, b.bnum); i++) {
            v[i] ^= b.v[i];
        }
        correct();
        return *this;
    }
    Bitset operator^(const Bitset& b) const {
        assert(n == b.n);
        return Bitset(*this) ^= b;
    }
    Bitset operator~() const {
        Bitset b(*this);
        b.all_flip();
        return b;
    }
    bool operator==(const Bitset& b) const {
        assert(n == b.n);
        return v == b.v;
    }
    bool operator!=(const Bitset& b) const {
        assert(n == b.n);
        return v != b.v;
    }
    Bitset& operator<<=(int sz) {
        assert(sz >= 0);
        for(int i = bnum-1; i >= 0; i--) {
            if(i-sz/64 < 0) v[i] = 0;
            else if(i-sz/64-1 < 0 || sz%64 == 0) v[i] = v[i-sz/64] << (sz%64);
            else v[i] = (v[i-sz/64] << (sz%64)) | (v[i-sz/64-1] >> (64-sz%64));
        }
        correct();
        return *this;
    }
    Bitset operator<<(int sz) const {
        assert(sz >= 0);
        return Bitset(*this) <<= sz;
    }
    Bitset& operator>>=(int sz) {
        assert(sz >= 0);
        for(int i = 0; i < bnum; i++) {
            if(i+sz/64 < bnum) v[i] = v[i+sz/64] >> (sz%64);
            if(i+sz/64+1 < bnum) v[i] |= v[i+sz/64+1] << (64-sz%64);
        }
        return *this;
    }
    Bitset operator>>(int sz) const {
        assert(sz >= 0);
        return Bitset(*this) >>= sz;
    }
};
