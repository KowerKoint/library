---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: KowerKoint/matrix.hpp:\
    \ line -1: no such header\n"
  code: "#include \"KowerKoint/matrix.hpp\"\n\nint main(void) {\n    int n; cin >>\
    \ n;\n    VL a(n); cin >> a;\n    XorMatrix mat(61, n);\n    REP(i, 61) REP(j,\
    \ n) mat[i][j] = a[j] >> i & 1LL;\n    auto basis = mat.gaussian_elimination().first;\n\
    \    ll ans = 1;\n    REP(i, 61) {\n        REP(j, n) if(basis[i][j]) {\n    \
    \        ans <<= 1LL;\n            break;\n        }\n    }\n    print(ans);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: test/yukicoder-184/main.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yukicoder-184/main.cpp
layout: document
redirect_from:
- /library/test/yukicoder-184/main.cpp
- /library/test/yukicoder-184/main.cpp.html
title: test/yukicoder-184/main.cpp
---
