#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E"
#include "../counting/counting.hpp"
#include "../algebra/modint.hpp"

int main() {
    int n, k; cin >> n >> k;
    if(k < n) print(0);
    else print(Counting<MI7>{}.c(k, n));
}
