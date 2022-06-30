---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"expansion/ac-library/segtree.hpp\"\ntemplate<typename S>\n\
    struct value_size { S value; int size; };\n\ntemplate<typename S>\nS min_op(S\
    \ l, S r) { return min(l, r); };\ntemplate<typename S>\nS max_op(S l, S r) { return\
    \ max(l, r); };\ntemplate<typename S>\nS sum_op(S l, S r) { return l + r; };\n\
    template<typename S>\nvalue_size<S> sum_op_size(value_size<S> l, value_size<S>\
    \ r) {\n    return {l.value + r.value, l.size + r.size};\n};\n\ntemplate<typename\
    \ S>\nS min_e() { return  numeric_limits<S>::max(); };\ntemplate<typename S>\n\
    S max_e() { return numeric_limits<S>::min(); };\ntemplate<typename S>\nS sum_e()\
    \ { return 0; }\ntemplate<typename S>\nvalue_size<S> sum_e_size() { return {0,\
    \ 0}; }\ntemplate<typename S>\nvalue_size<S> min_e_size() { return {numeric_limits<S>::max(),\
    \ 0}; }\ntemplate<typename S>\nvalue_size<S> max_e_size() { return {numeric_limits<S>::min(),\
    \ 0}; }\n\ntemplate<typename S, typename F>\nS chmin_mapping(F f, S x) { return\
    \ min(x, f); }\ntemplate<typename S, typename F>\nS chmax_mapping(F f, S x) {\
    \ return max(x, f); }\ntemplate<typename S, typename F>\nS add_mapping(F f, S\
    \ x) { return x + f; }\ntemplate<typename S, typename F>\nvalue_size<S> add_mapping_size(F\
    \ f, value_size<S> x) {\n    return {x.value + x.size * f, x.size};\n}\ntemplate\
    \ <typename S,typename F, F ID>\nS change_mapping(F f, S x) { return (f == ID?\
    \ x : f); }\ntemplate <typename S,typename F, F ID>\nvalue_size<S> change_mapping_size(F\
    \ f, value_size<S> x) { \n    value_size<S> ret = {f * x.size, x.size};\n    return\
    \ (f == ID? x : ret); \n}\ntemplate <typename S, typename F1, typename F2>\nS\
    \ linear_mapping(pair<F1, F2> f, S x) { return x * f.first + f.second; }\ntemplate\
    \ <typename S, typename F1, typename F2>\nvalue_size<S> linear_mapping_size(pair<F1,\
    \ F2> f, value_size<S> x) { return {x.value * f.first + x.size * f.second, x.size};\
    \ }\n\ntemplate<typename F>\nF chmin_composition(F f, F g) { return min(f, g);\
    \ }\ntemplate<typename F>\nF chmax_composition(F f, F g) { return max(f, g); }\n\
    template<typename F>\nF add_composition(F f, F g) { return f + g; }\ntemplate\
    \ <typename F, F ID>\nF change_composition(F f, F g) { return (f == ID? g : f);\
    \ }\ntemplate<typename F1, typename F2>\npair<F1, F2> linear_composition(pair<F1,\
    \ F2> f, pair<F1, F2> g) { return {f.first * g.first, f.first * g.second + f.second};\
    \ }\n\ntemplate<typename F>\nF chmin_id() { return numeric_limits<F>::max(); }\n\
    template<typename F>\nF chmax_id() { return numeric_limits<F>::min(); }\ntemplate<typename\
    \ F>\nF add_id() { return 0; }\ntemplate<typename F, F ID>\nF change_id() { return\
    \ ID; }\ntemplate<typename F1, typename F2>\npair<F1, F2> linear_id() { return\
    \ {1, 0}; }\n\ntemplate<typename S>\nusing RSumQ = segtree<S, sum_op<S>, sum_e<S>>;\n\
    template<typename S>\nusing RMaxQ = segtree<S, max_op<S>, max_e<S>>;\ntemplate<typename\
    \ S>\nusing RMinQ = segtree<S, min_op<S>, min_e<S>>;\n\ntemplate<typename S, typename\
    \ F>\nusing RAddSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,\n\
    \    F, add_mapping_size<S, F>, add_composition<F>, add_id<F>>;\ntemplate<typename\
    \ S, typename F>\nusing RAddMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    F,\
    \ add_mapping<S, F>, add_composition<F>, add_id<F>>;\ntemplate<typename S, typename\
    \ F>\nusing RAddMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,\n    F, add_mapping<S,\
    \ F>, add_composition<F>, add_id<F>>;\ntemplate<typename S, typename F>\nusing\
    \ RMinMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    F, chmin_mapping<S, F>,\
    \ chmin_composition<F>, chmin_id<F>>;\ntemplate<typename S, typename F>\nusing\
    \ RMaxMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,\n    F, chmax_mapping<S, F>,\
    \ chmax_composition<F>, chmax_id<F>>;\ntemplate<typename S, typename F, F ID>\n\
    using RChangeMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    F, change_mapping<S,\
    \ F, ID>,\n    change_composition<F, ID>,\n    change_id<F, ID>>;\ntemplate<typename\
    \ S, typename F, F ID>\nusing RChangeMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,\n\
    \    F, change_mapping<S, F, ID>,\n    change_composition<F, ID>,\n    change_id<F,\
    \ ID>>;\ntemplate<typename S, typename F, F ID>\nusing RChangeSumQ = lazy_segtree<value_size<S>,\
    \ sum_op_size<S>, sum_e_size<S>,\n    F, change_mapping_size<S, F, ID>,\n    change_composition<F,\
    \ ID>,\n    change_id<F, ID>>;\ntemplate<typename S, typename F1, typename F2>\n\
    using RLinearMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    pair<F1, F2>, linear_mapping<S,\
    \ F1, F2>,\n    linear_composition<F1, F2>,\n    linear_id<F1, F2>>;\ntemplate<typename\
    \ S, typename F1, typename F2>\nusing RLinearMaxQ = lazy_segtree<S, max_op<S>,\
    \ max_e<S>,\n    pair<F1, F2>, linear_mapping<S, F1, F2>,\n    linear_composition<F1,\
    \ F2>,\n    linear_id<F1, F2>>;\ntemplate<typename S, typename F1, typename F2>\n\
    using RLinearSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,\n\
    \    pair<F1, F2>, linear_mapping_size<S, F1, F2>,\n    linear_composition<F1,\
    \ F2>,\n    linear_id<F1, F2>>;\n"
  code: "template<typename S>\nstruct value_size { S value; int size; };\n\ntemplate<typename\
    \ S>\nS min_op(S l, S r) { return min(l, r); };\ntemplate<typename S>\nS max_op(S\
    \ l, S r) { return max(l, r); };\ntemplate<typename S>\nS sum_op(S l, S r) { return\
    \ l + r; };\ntemplate<typename S>\nvalue_size<S> sum_op_size(value_size<S> l,\
    \ value_size<S> r) {\n    return {l.value + r.value, l.size + r.size};\n};\n\n\
    template<typename S>\nS min_e() { return  numeric_limits<S>::max(); };\ntemplate<typename\
    \ S>\nS max_e() { return numeric_limits<S>::min(); };\ntemplate<typename S>\n\
    S sum_e() { return 0; }\ntemplate<typename S>\nvalue_size<S> sum_e_size() { return\
    \ {0, 0}; }\ntemplate<typename S>\nvalue_size<S> min_e_size() { return {numeric_limits<S>::max(),\
    \ 0}; }\ntemplate<typename S>\nvalue_size<S> max_e_size() { return {numeric_limits<S>::min(),\
    \ 0}; }\n\ntemplate<typename S, typename F>\nS chmin_mapping(F f, S x) { return\
    \ min(x, f); }\ntemplate<typename S, typename F>\nS chmax_mapping(F f, S x) {\
    \ return max(x, f); }\ntemplate<typename S, typename F>\nS add_mapping(F f, S\
    \ x) { return x + f; }\ntemplate<typename S, typename F>\nvalue_size<S> add_mapping_size(F\
    \ f, value_size<S> x) {\n    return {x.value + x.size * f, x.size};\n}\ntemplate\
    \ <typename S,typename F, F ID>\nS change_mapping(F f, S x) { return (f == ID?\
    \ x : f); }\ntemplate <typename S,typename F, F ID>\nvalue_size<S> change_mapping_size(F\
    \ f, value_size<S> x) { \n    value_size<S> ret = {f * x.size, x.size};\n    return\
    \ (f == ID? x : ret); \n}\ntemplate <typename S, typename F1, typename F2>\nS\
    \ linear_mapping(pair<F1, F2> f, S x) { return x * f.first + f.second; }\ntemplate\
    \ <typename S, typename F1, typename F2>\nvalue_size<S> linear_mapping_size(pair<F1,\
    \ F2> f, value_size<S> x) { return {x.value * f.first + x.size * f.second, x.size};\
    \ }\n\ntemplate<typename F>\nF chmin_composition(F f, F g) { return min(f, g);\
    \ }\ntemplate<typename F>\nF chmax_composition(F f, F g) { return max(f, g); }\n\
    template<typename F>\nF add_composition(F f, F g) { return f + g; }\ntemplate\
    \ <typename F, F ID>\nF change_composition(F f, F g) { return (f == ID? g : f);\
    \ }\ntemplate<typename F1, typename F2>\npair<F1, F2> linear_composition(pair<F1,\
    \ F2> f, pair<F1, F2> g) { return {f.first * g.first, f.first * g.second + f.second};\
    \ }\n\ntemplate<typename F>\nF chmin_id() { return numeric_limits<F>::max(); }\n\
    template<typename F>\nF chmax_id() { return numeric_limits<F>::min(); }\ntemplate<typename\
    \ F>\nF add_id() { return 0; }\ntemplate<typename F, F ID>\nF change_id() { return\
    \ ID; }\ntemplate<typename F1, typename F2>\npair<F1, F2> linear_id() { return\
    \ {1, 0}; }\n\ntemplate<typename S>\nusing RSumQ = segtree<S, sum_op<S>, sum_e<S>>;\n\
    template<typename S>\nusing RMaxQ = segtree<S, max_op<S>, max_e<S>>;\ntemplate<typename\
    \ S>\nusing RMinQ = segtree<S, min_op<S>, min_e<S>>;\n\ntemplate<typename S, typename\
    \ F>\nusing RAddSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,\n\
    \    F, add_mapping_size<S, F>, add_composition<F>, add_id<F>>;\ntemplate<typename\
    \ S, typename F>\nusing RAddMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    F,\
    \ add_mapping<S, F>, add_composition<F>, add_id<F>>;\ntemplate<typename S, typename\
    \ F>\nusing RAddMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,\n    F, add_mapping<S,\
    \ F>, add_composition<F>, add_id<F>>;\ntemplate<typename S, typename F>\nusing\
    \ RMinMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    F, chmin_mapping<S, F>,\
    \ chmin_composition<F>, chmin_id<F>>;\ntemplate<typename S, typename F>\nusing\
    \ RMaxMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,\n    F, chmax_mapping<S, F>,\
    \ chmax_composition<F>, chmax_id<F>>;\ntemplate<typename S, typename F, F ID>\n\
    using RChangeMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    F, change_mapping<S,\
    \ F, ID>,\n    change_composition<F, ID>,\n    change_id<F, ID>>;\ntemplate<typename\
    \ S, typename F, F ID>\nusing RChangeMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,\n\
    \    F, change_mapping<S, F, ID>,\n    change_composition<F, ID>,\n    change_id<F,\
    \ ID>>;\ntemplate<typename S, typename F, F ID>\nusing RChangeSumQ = lazy_segtree<value_size<S>,\
    \ sum_op_size<S>, sum_e_size<S>,\n    F, change_mapping_size<S, F, ID>,\n    change_composition<F,\
    \ ID>,\n    change_id<F, ID>>;\ntemplate<typename S, typename F1, typename F2>\n\
    using RLinearMinQ = lazy_segtree<S, min_op<S>, min_e<S>,\n    pair<F1, F2>, linear_mapping<S,\
    \ F1, F2>,\n    linear_composition<F1, F2>,\n    linear_id<F1, F2>>;\ntemplate<typename\
    \ S, typename F1, typename F2>\nusing RLinearMaxQ = lazy_segtree<S, max_op<S>,\
    \ max_e<S>,\n    pair<F1, F2>, linear_mapping<S, F1, F2>,\n    linear_composition<F1,\
    \ F2>,\n    linear_id<F1, F2>>;\ntemplate<typename S, typename F1, typename F2>\n\
    using RLinearSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,\n\
    \    pair<F1, F2>, linear_mapping_size<S, F1, F2>,\n    linear_composition<F1,\
    \ F2>,\n    linear_id<F1, F2>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: expansion/ac-library/segtree.hpp
  requiredBy: []
  timestamp: '2022-03-14 17:38:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: expansion/ac-library/segtree.hpp
layout: document
redirect_from:
- /library/expansion/ac-library/segtree.hpp
- /library/expansion/ac-library/segtree.hpp.html
title: expansion/ac-library/segtree.hpp
---
