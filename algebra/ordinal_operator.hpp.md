---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algebra/nimber.hpp
    title: algebra/nimber.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-nim-product.test.cpp
    title: test/yosupo-nim-product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/ordinal_operator.hpp\"\n\ntemplate <typename T>\n\
    T ordinal_identity(T x) {\n    return x;\n}\ntemplate <typename T>\nT ordinal_plus(const\
    \ T a, const T b) {\n    return a + b;\n}\ntemplate <typename T>\nT ordinal_zero()\
    \ {\n    return T(0);\n}\ntemplate <typename T>\nT ordinal_mult(const T a, const\
    \ T b) {\n    return a * b;\n}\ntemplate <typename T>\nT ordinal_one() {\n   \
    \ return T(1);\n}\ntemplate <typename T>\nT ordinal_plusinv(const T a) {\n   \
    \ return -a;\n}\ntemplate <typename T>\nT ordinal_multinv(const T a) {\n    return\
    \ T(1) / a;\n}\ntemplate <typename T>\nT ordinal_xor(const T a, const T b) {\n\
    \    return a ^ b;\n}\ntemplate <typename T>\nT ordinal_and(const T a, const T\
    \ b) {\n    return a & b;\n}\ntemplate <typename T>\nT ordinal_or(const T a, const\
    \ T b) {\n    return a | b;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nT ordinal_identity(T x) {\n    return\
    \ x;\n}\ntemplate <typename T>\nT ordinal_plus(const T a, const T b) {\n    return\
    \ a + b;\n}\ntemplate <typename T>\nT ordinal_zero() {\n    return T(0);\n}\n\
    template <typename T>\nT ordinal_mult(const T a, const T b) {\n    return a *\
    \ b;\n}\ntemplate <typename T>\nT ordinal_one() {\n    return T(1);\n}\ntemplate\
    \ <typename T>\nT ordinal_plusinv(const T a) {\n    return -a;\n}\ntemplate <typename\
    \ T>\nT ordinal_multinv(const T a) {\n    return T(1) / a;\n}\ntemplate <typename\
    \ T>\nT ordinal_xor(const T a, const T b) {\n    return a ^ b;\n}\ntemplate <typename\
    \ T>\nT ordinal_and(const T a, const T b) {\n    return a & b;\n}\ntemplate <typename\
    \ T>\nT ordinal_or(const T a, const T b) {\n    return a | b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/ordinal_operator.hpp
  requiredBy:
  - algebra/nimber.hpp
  timestamp: '2022-11-01 23:37:53+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-nim-product.test.cpp
documentation_of: algebra/ordinal_operator.hpp
layout: document
redirect_from:
- /library/algebra/ordinal_operator.hpp
- /library/algebra/ordinal_operator.hpp.html
title: algebra/ordinal_operator.hpp
---
