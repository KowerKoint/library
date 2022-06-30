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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: KowerKoint/base.hpp:\
    \ line -1: no such header\n"
  code: "#include \"KowerKoint/base.hpp\"\n#include <atcoder/all>\nusing namespace\
    \ atcoder;\n#include \"KowerKoint/expansion/ac-library/modint.hpp\"\n#include\
    \ \"KowerKoint/matrix.hpp\"\n\nint main(void) {\n    int n; cin >> n;\n    Matrix<MI3>\
    \ a(n, n); cin >> a;\n    print(a.gaussian_elimination().second);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: test/yosupo-determinant-of-matrix/main.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo-determinant-of-matrix/main.cpp
layout: document
redirect_from:
- /library/test/yosupo-determinant-of-matrix/main.cpp
- /library/test/yosupo-determinant-of-matrix/main.cpp.html
title: test/yosupo-determinant-of-matrix/main.cpp
---
