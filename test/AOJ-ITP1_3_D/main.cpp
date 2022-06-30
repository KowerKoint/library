#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"
#include "KowerKoint/base.hpp"

/* #include <atcoder/all> */
/* using namespace atcoder; */
/* #include "KowerKoint/expansion/ac-library/all.hpp" */
#include "KowerKoint/integer.hpp"

void solve(){
    ll a, b, c; cin >> a >> b >> c;
    VL div = Prime{}.divisor(c);
    print(upper_bound(ALL(div), b) - lower_bound(ALL(div), a));
}

// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)
int main() {
    // Fasterize input/output script
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    // scanf/printf user should delete this fasterize input/output script

    int t = 1;
    //cin >> t; // comment out if solving multi testcase
    for(int testCase = 1;testCase <= t;++testCase){
        solve();
    }
    return 0;
}
