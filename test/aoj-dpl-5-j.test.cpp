#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J"
#include "../counting/counting.hpp"
#include "../integer/modint.hpp"

int main() {
    int n, k; cin >> n >> k;
    print(Counting<MI7>{}.partition_table(n, k)[n][k]);
}
