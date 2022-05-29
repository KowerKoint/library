#include "KowerKoint/general.hpp"

#include <atcoder/scc>
using namespace atcoder;
#include "KowerKoint/expansion/ac-library/scc.hpp"

void solve(){
    int n; ll k; cin >> n >> k;
    VL a(n); cin >> a;
    VI nxt(n);
    REP(i, n) nxt[i] = (i+a[i]) % n;
    LoopDetective loop(nxt);
    auto [prepath, looppath] = loop.path(0);
    print(loop.query<ll, ll>(0, k, a));
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