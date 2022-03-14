template<typename S>
struct value_size { S value; int size; };

template<typename S>
S min_op(S l, S r) { return min(l, r); };
template<typename S>
S max_op(S l, S r) { return max(l, r); };
template<typename S>
S sum_op(S l, S r) { return l + r; };
template<typename S>
value_size<S> sum_op_size(value_size<S> l, value_size<S> r) {
    return {l.value + r.value, l.size + r.size};
};

template<typename S>
S min_e() { return  numeric_limits<S>::max(); };
template<typename S>
S max_e() { return numeric_limits<S>::min(); };
template<typename S>
S sum_e() { return 0; }
template<typename S>
value_size<S> sum_e_size() { return {0, 0}; }
template<typename S>
value_size<S> min_e_size() { return {numeric_limits<S>::max(), 0}; }
template<typename S>
value_size<S> max_e_size() { return {numeric_limits<S>::min(), 0}; }

template<typename S, typename F>
S chmin_mapping(F f, S x) { return min(x, f); }
template<typename S, typename F>
S chmax_mapping(F f, S x) { return max(x, f); }
template<typename S, typename F>
S add_mapping(F f, S x) { return x + f; }
template<typename S, typename F>
value_size<S> add_mapping_size(F f, value_size<S> x) {
    return {x.value + x.size * f, x.size};
}
template <typename S,typename F, F ID>
S change_mapping(F f, S x) { return (f == ID? x : f); }
template <typename S,typename F, F ID>
value_size<S> change_mapping_size(F f, value_size<S> x) { 
    value_size<S> ret = {f * x.size, x.size};
    return (f == ID? x : ret); 
}
template <typename S, typename F1, typename F2>
S linear_mapping(pair<F1, F2> f, S x) { return x * f.first + f.second; }
template <typename S, typename F1, typename F2>
value_size<S> linear_mapping_size(pair<F1, F2> f, value_size<S> x) { return {x.value * f.first + x.size * f.second, x.size}; }

template<typename F>
F chmin_composition(F f, F g) { return min(f, g); }
template<typename F>
F chmax_composition(F f, F g) { return max(f, g); }
template<typename F>
F add_composition(F f, F g) { return f + g; }
template <typename F, F ID>
F change_composition(F f, F g) { return (f == ID? g : f); }
template<typename F1, typename F2>
pair<F1, F2> linear_composition(pair<F1, F2> f, pair<F1, F2> g) { return {f.first * g.first, f.first * g.second + f.second}; }

template<typename F>
F chmin_id() { return numeric_limits<F>::max(); }
template<typename F>
F chmax_id() { return numeric_limits<F>::min(); }
template<typename F>
F add_id() { return 0; }
template<typename F, F ID>
F change_id() { return ID; }
template<typename F1, typename F2>
pair<F1, F2> linear_id() { return {1, 0}; }

template<typename S>
using RSumQ = segtree<S, sum_op<S>, sum_e<S>>;
template<typename S>
using RMaxQ = segtree<S, max_op<S>, max_e<S>>;
template<typename S>
using RMinQ = segtree<S, min_op<S>, min_e<S>>;

template<typename S, typename F>
using RAddSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,
    F, add_mapping_size<S, F>, add_composition<F>, add_id<F>>;
template<typename S, typename F>
using RAddMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    F, add_mapping<S, F>, add_composition<F>, add_id<F>>;
template<typename S, typename F>
using RAddMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    F, add_mapping<S, F>, add_composition<F>, add_id<F>>;
template<typename S, typename F>
using RMinMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    F, chmin_mapping<S, F>, chmin_composition<F>, chmin_id<F>>;
template<typename S, typename F>
using RMaxMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    F, chmax_mapping<S, F>, chmax_composition<F>, chmax_id<F>>;
template<typename S, typename F, F ID>
using RChangeMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    F, change_mapping<S, F, ID>,
    change_composition<F, ID>,
    change_id<F, ID>>;
template<typename S, typename F, F ID>
using RChangeMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    F, change_mapping<S, F, ID>,
    change_composition<F, ID>,
    change_id<F, ID>>;
template<typename S, typename F, F ID>
using RChangeSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,
    F, change_mapping_size<S, F, ID>,
    change_composition<F, ID>,
    change_id<F, ID>>;
template<typename S, typename F1, typename F2>
using RLinearMinQ = lazy_segtree<S, min_op<S>, min_e<S>,
    pair<F1, F2>, linear_mapping<S, F1, F2>,
    linear_composition<F1, F2>,
    linear_id<F1, F2>>;
template<typename S, typename F1, typename F2>
using RLinearMaxQ = lazy_segtree<S, max_op<S>, max_e<S>,
    pair<F1, F2>, linear_mapping<S, F1, F2>,
    linear_composition<F1, F2>,
    linear_id<F1, F2>>;
template<typename S, typename F1, typename F2>
using RLinearSumQ = lazy_segtree<value_size<S>, sum_op_size<S>, sum_e_size<S>,
    pair<F1, F2>, linear_mapping_size<S, F1, F2>,
    linear_composition<F1, F2>,
    linear_id<F1, F2>>;
