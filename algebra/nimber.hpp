#pragma once
#include "field.hpp"

namespace _nimber_precalc {
    static ull small_product[256][256];
    static ull pow64_product[8][8][256];
    static bool built = false;

    ull nim_product_rec(ull x, ull y, int numbits) {
        if(x < 256 && y < 256) return small_product[x][y];
        int nnumbits = numbits >> 1;
        ull x1 = x >> numbits, x0 = x ^ (x1 << numbits);
        ull y1 = y >> numbits, y0 = y ^ (y1 << numbits);
        ull x1y1 = nim_product_rec(x1, y1, nnumbits);
        ull x1y0 = nim_product_rec(x1, y0, nnumbits);
        ull x0y1 = nim_product_rec(x0, y1, nnumbits);
        ull x0y0 = nim_product_rec(x0, y0, nnumbits);
        return ((x1y1^x1y0^x0y1) << numbits) ^ nim_product_rec(x1y1, 1ULL<<(numbits-1), nnumbits) ^ x0y0;
    }

    void precalc() {
        built = true;
        small_product[1][1] = 1ULL;
        REP(i, 3) {
            REP(j, 1ULL<<(1<<(i+1))) {
                ull ju = j >> (1<<i);
                ull jl = j & ((1ULL<<(1<<i))-1);
                REP(k, 1ULL<<(1<<(i+1))) {
                    ull ku = k >> (1<<i);
                    ull kl = k & ((1ULL<<(1<<i))-1);
                    small_product[j][k] = ((small_product[ju][ku]^small_product[jl][ku]^small_product[ju][kl]) << (1<<i)) ^ (small_product[small_product[ju][ku]][1ULL<<((1<<i)-1)]^small_product[jl][kl]);
                }
            }
        }
        REP(i, 8) REP(j, 8) {
            ull tmp = nim_product_rec(1ULL<<(i<<3), 1ULL<<(j<<3), 1ULL<<5);
            REP(k, 256) pow64_product[i][j][k] = nim_product_rec(tmp, k, 1ULL<<5);
        }
    }

}

ull nim_product(const ull& x, const ull& y) {
    if(!_nimber_precalc::built) _nimber_precalc::precalc();
    ull ret = 0;
    REP(i, 8) REP(j, 8) {
        ret ^= _nimber_precalc::pow64_product[i][j][_nimber_precalc::small_product[(x>>(i<<3))&255][(y>>(j<<3))&255]];
    }
    return ret;
}

struct SumGroupNimber : SumGroupBase<ull> {
    constexpr static ull& addassign(ull& l, const ull& r) {
        return l ^= r;
    }
    constexpr static bool defzero = true;
    constexpr static ull zero = 0;
    inline static ull minus(const ull& r) {
        return r;
    }
};
struct ProdGroupNimber : ProdGroupBase<ull> {
    static ull& mulassign(ull& l, const ull& r) {
        l = nim_product(l, r);
        return l;
    }
    constexpr static bool defone = true;
    constexpr static ull one = 1;
};

using Nimber = Field<ull, SumGroupNimber, ProdGroupNimber>;
