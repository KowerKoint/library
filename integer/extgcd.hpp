#pragma once
#include "../base.hpp"

ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll nx = 0, ny = 1;
    while(b) {
        ll q = a / b;
        tie(a, b) = LP(b, a % b);
        tie(x, nx) = LP(nx, x - nx*q);
        tie(y, ny) = LP(ny, y - ny*q);
    }
    return a;
}
