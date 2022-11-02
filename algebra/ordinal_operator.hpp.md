---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: algebra/field.hpp
    title: algebra/field.hpp
  - icon: ':question:'
    path: algebra/modint.hpp
    title: algebra/modint.hpp
  - icon: ':warning:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
  - icon: ':x:'
    path: algebra/nimber.hpp
    title: algebra/nimber.hpp
  - icon: ':x:'
    path: algebra/ring.hpp
    title: algebra/ring.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
  - icon: ':warning:'
    path: general.hpp
    title: general.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-b.test.cpp
    title: test/aoj-dpl-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-d.test.cpp
    title: test/aoj-dpl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-e.test.cpp
    title: test/aoj-dpl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-g.test.cpp
    title: test/aoj-dpl-5-g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-5-i.test.cpp
    title: test/aoj-dpl-5-i.test.cpp
  - icon: ':x:'
    path: test/aoj-dpl-5-j.test.cpp
    title: test/aoj-dpl-5-j.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-ntl-1-b.test.cpp
    title: test/aoj-ntl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-convolution.test.cpp
    title: test/yosupo-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-determinant-of-matrix.test.cpp
    title: test/yosupo-determinant-of-matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo-montmort-number.test.cpp
    title: test/yosupo-montmort-number.test.cpp
  - icon: ':x:'
    path: test/yosupo-nim-product.test.cpp
    title: test/yosupo-nim-product.test.cpp
  - icon: ':x:'
    path: test/yosupo-range-affine-range-sum.test.cpp
    title: test/yosupo-range-affine-range-sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/ordinal_operator.hpp\"\n\ntemplate <typename T>\n\
    T ordinal_identity(const T& x) {\n    return x;\n}\ntemplate <typename T>\nT ordinal_plus(const\
    \ T& a, const T& b) {\n    return a + b;\n}\ntemplate <typename T>\nT ordinal_zero()\
    \ {\n    return T(0);\n}\ntemplate <typename T>\nT ordinal_mult(const T& a, const\
    \ T& b) {\n    return a * b;\n}\ntemplate <typename T>\nT ordinal_one() {\n  \
    \  return T(1);\n}\ntemplate <typename T>\nT ordinal_plusinv(const T& a) {\n \
    \   return -a;\n}\ntemplate <typename T>\nT ordinal_multinv(const T& a) {\n  \
    \  return T(1) / a;\n}\ntemplate <typename T>\nT ordinal_xor(const T& a, const\
    \ T& b) {\n    return a ^ b;\n}\ntemplate <typename T>\nT ordinal_and(const T&\
    \ a, const T& b) {\n    return a & b;\n}\ntemplate <typename T>\nT ordinal_or(const\
    \ T& a, const T& b) {\n    return a | b;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nT ordinal_identity(const T& x) {\n\
    \    return x;\n}\ntemplate <typename T>\nT ordinal_plus(const T& a, const T&\
    \ b) {\n    return a + b;\n}\ntemplate <typename T>\nT ordinal_zero() {\n    return\
    \ T(0);\n}\ntemplate <typename T>\nT ordinal_mult(const T& a, const T& b) {\n\
    \    return a * b;\n}\ntemplate <typename T>\nT ordinal_one() {\n    return T(1);\n\
    }\ntemplate <typename T>\nT ordinal_plusinv(const T& a) {\n    return -a;\n}\n\
    template <typename T>\nT ordinal_multinv(const T& a) {\n    return T(1) / a;\n\
    }\ntemplate <typename T>\nT ordinal_xor(const T& a, const T& b) {\n    return\
    \ a ^ b;\n}\ntemplate <typename T>\nT ordinal_and(const T& a, const T& b) {\n\
    \    return a & b;\n}\ntemplate <typename T>\nT ordinal_or(const T& a, const T&\
    \ b) {\n    return a | b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/ordinal_operator.hpp
  requiredBy:
  - convolution/ntt.hpp
  - general.hpp
  - algebra/field.hpp
  - algebra/monoid.hpp
  - algebra/ring.hpp
  - algebra/modint.hpp
  - algebra/nimber.hpp
  timestamp: '2022-11-03 00:55:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj-dpl-5-j.test.cpp
  - test/aoj-dpl-5-e.test.cpp
  - test/yosupo-nim-product.test.cpp
  - test/yosupo-range-affine-range-sum.test.cpp
  - test/aoj-ntl-1-b.test.cpp
  - test/yosupo-convolution.test.cpp
  - test/aoj-dpl-5-d.test.cpp
  - test/aoj-dpl-5-i.test.cpp
  - test/yosupo-montmort-number.test.cpp
  - test/yosupo-determinant-of-matrix.test.cpp
  - test/aoj-dpl-5-b.test.cpp
  - test/aoj-dpl-5-g.test.cpp
documentation_of: algebra/ordinal_operator.hpp
layout: document
redirect_from:
- /library/algebra/ordinal_operator.hpp
- /library/algebra/ordinal_operator.hpp.html
title: algebra/ordinal_operator.hpp
---
