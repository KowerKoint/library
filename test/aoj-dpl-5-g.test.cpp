#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"
#include "../counting/counting.hpp"
#include "../algebra/modint.hpp"

int main() {
    int n, k; cin >> n >> k;
    print(Counting<MI7>().bell(n, k));
}
