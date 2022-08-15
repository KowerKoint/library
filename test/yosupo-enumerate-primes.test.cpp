#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "../integer/prime.hpp"

int main() {
    int n, a, b; cin >> n >> a >> b;
    Prime pm(n);
    auto primes = pm.prime_list(n);
    VI ans;
    for(ll i = b; i < primes.size(); i += a) ans.push_back(primes[i]);
    print(primes.size(), ans.size());
    print(ans);
}
