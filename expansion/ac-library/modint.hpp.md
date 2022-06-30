---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-determinant-of-matrix/main.test.cpp
    title: test/yosupo-determinant-of-matrix/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"expansion/ac-library/modint.hpp\"\nostream &operator<<(ostream\
    \ &os, const modint &x) {\n    os << x.val();\n    return os;\n}\n\nostream &operator<<(ostream\
    \ &os, const modint998244353 &x) {\n    os << x.val();\n    return os;\n}\n\n\
    ostream &operator<<(ostream &os, const modint1000000007 &x) {\n    os << x.val();\n\
    \    return os;\n}\n\nistream &operator>>(istream &is, modint &x) {\n    int y;\
    \ is >> y;\n    x = y;\n    return is;\n}\n\nistream &operator>>(istream &is,\
    \ modint998244353 &x) {\n    int y; is >> y;\n    x = y;\n    return is;\n}\n\n\
    istream &operator>>(istream &is, modint1000000007 &x) {\n    int y; is >> y;\n\
    \    x = y;\n    return is;\n}\n"
  code: "ostream &operator<<(ostream &os, const modint &x) {\n    os << x.val();\n\
    \    return os;\n}\n\nostream &operator<<(ostream &os, const modint998244353 &x)\
    \ {\n    os << x.val();\n    return os;\n}\n\nostream &operator<<(ostream &os,\
    \ const modint1000000007 &x) {\n    os << x.val();\n    return os;\n}\n\nistream\
    \ &operator>>(istream &is, modint &x) {\n    int y; is >> y;\n    x = y;\n   \
    \ return is;\n}\n\nistream &operator>>(istream &is, modint998244353 &x) {\n  \
    \  int y; is >> y;\n    x = y;\n    return is;\n}\n\nistream &operator>>(istream\
    \ &is, modint1000000007 &x) {\n    int y; is >> y;\n    x = y;\n    return is;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: expansion/ac-library/modint.hpp
  requiredBy: []
  timestamp: '2022-05-29 20:46:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-determinant-of-matrix/main.test.cpp
documentation_of: expansion/ac-library/modint.hpp
layout: document
redirect_from:
- /library/expansion/ac-library/modint.hpp
- /library/expansion/ac-library/modint.hpp.html
title: expansion/ac-library/modint.hpp
---
