#pragma once
#include "../internal_operator.hpp"
#include "pow-mod.hpp"

template <ll (*mod)()>
struct Modint {
    ll val;
    
    Modint(): val(0) {}

    Modint(ll x): val(x) {
        val %= mod();
        if(val < 0) val += mod();
    }

    Modint& operator+=(const Modint& r) {
        val += r.val;
        if(val >= mod()) val -= mod();
        return *this;
    }
    friend Modint operator+(const Modint& l, const Modint& r) {
        return Modint(l) += r;
    }

    Modint& operator-=(const Modint& r) {
        val -= r.val;
        if(val < 0) val += mod();
        return *this;
    }
    friend Modint operator-(const Modint& l, const Modint& r) {
        return Modint(l) -= r;
    }

    Modint& operator*=(const Modint& r) {
        val *= r.val;
        val %= mod();
        return *this;
    }
    Modint operator*(const Modint& r) {
        return (Modint(*this) *= r);
    }
    friend Modint operator*(const Modint& l, const Modint& r) {
        return Modint(l) *= r;
    }

    Modint pow(ll n) const {
        return Modint(pow_mod(val, n, mod()));
    }

    Modint inv() const {
        return Modint(inv_mod(val, mod()));
    }

    Modint& operator/=(const Modint& r) {
        return (*this *= r.inv());
    }
    friend Modint operator/(const Modint& l, const Modint& r) {
        return Modint(l) /= r;
    }

    Modint& operator^=(const ll n) {
        val = pow_mod(val, n, mod());
        return *this;
    }
    Modint operator^(const ll n) {
        return this->pow(n);
    }

    Modint operator+() const { return *this; }
    Modint operator-() const { return Modint() - *this; }

    Modint& operator++() {
        val++;
        if(val == mod()) val = 0LL;
        return *this;
    }
    Modint& operator++(int) {
        Modint res(*this);
        ++*this;
        return res;
    }

    Modint& operator--() {
        if(val == 0LL) val = mod();
        val--;
        return *this;
    }
    Modint& operator--(int) {
        Modint res(*this);
        --*this;
        return res;
    }

    friend bool operator==(const Modint& l, const Modint& r) {
        return l.val == r.val;
    }
    friend bool operator!=(const Modint& l, const Modint& r) {
        return l.val != r.val;
    }

    static pair<vector<Modint>, vector<Modint>> factorial(int n) {
        vector<Modint> fact(n+1), rfact(n+1);
        fact[0] = 1;
        REP(i, n) fact[i+1] = fact[i] * (i+1);
        rfact[n] = 1 / fact[n];
        for(int i = n-1; i >= 0; i--) rfact[i] = rfact[i+1] * (i+1);
        return {fact, rfact};
    }

    friend istream& operator>>(istream& is, Modint& mi) {
        is >> mi.val;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Modint& mi) {
        os << mi.val;
        return os;
    }
};

using MI3 = Modint<kowerkoint::mod3>;
using V3 = vector<MI3>;
using VV3 = vector<V3>;
using VVV3 = vector<VV3>;
using MI7 = Modint<kowerkoint::mod7>;
using V7 = vector<MI7>;
using VV7 = vector<V7>;
using VVV7 = vector<VV7>;
using MI9 = Modint<kowerkoint::mod9>;
using V9 = vector<MI9>;
using VV9 = vector<V9>;
using VVV9 = vector<VV9>;
