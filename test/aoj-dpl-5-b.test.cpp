#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B"
#include "../counting/counting.hpp"
#include "../integer/modint.hpp"

int main() {
    int n, k; cin >> n >> k;
    if(n > k) print(0);
    else print(Counting<MI7>{}.p(k, n));
}
