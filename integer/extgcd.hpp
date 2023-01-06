#pragma once
#include "../base.hpp"

constexpr ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll nx = 0, ny = 1;
    while(b) {
        ll q = a / b;
        ll r = a % b;
        a = b, b = r;
        ll nnx = x - q * nx;
        ll nny = y - q * ny;
        x = nx, nx = nnx;
        y = ny, ny = nny;
    }
    return a;
}
