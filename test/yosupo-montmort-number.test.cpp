#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"
#include "../counting/montmort.hpp"
#include "../integer/modint.hpp"

ll m;
ll mod() {
    return m;
}

int main() {
    ll n; cin >> n >> m;
    auto res = montmort<Modint<mod>>(n);
    print(vector<Modint<mod>>(res.begin()+1, res.end()));
}
