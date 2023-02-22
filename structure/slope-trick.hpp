#pragma once
#include "../base.hpp"

template <typename T>
class SlopeTrick {
    T _min_f;
    PQ<T> _left;
    GPQ<T> _right;
    T _l_shift, _r_shift;

public:
    SlopeTrick() : _min_f(0), _l_shift(0), _r_shift(0) {}
    T min_f() const { return _min_f; }
    void add_all(const T &a) { _min_f += a; }
    void add_a_minus_x(const T &a) {
        if(_right.empty() || a < _right.top() + _r_shift) {
            _left.push(a - _l_shift);
        } else {
            _min_f += a - _right.top() - _r_shift;
            _left.push(_right.top() + _r_shift - _l_shift);
            _right.pop();
            _right.push(a - _r_shift);
        }
    }
    void add_x_minus_a(const T &a) {
        if(_left.empty() || _left.top() + _l_shift < a) {
            _right.push(a - _r_shift);
        } else {
            _min_f += _left.top() + _l_shift - a;
            _right.push(_left.top() + _l_shift - _r_shift);
            _left.pop();
            _left.push(a - _l_shift);
        }
    }
    void add_abs(const T &a) {
        add_a_minus_x(a);
        add_x_minus_a(a);
    }
    void clear_right() {
        while(!_right.empty()) _right.pop(0);
    }
    void clear_left() {
        while(!_left.empty()) _left.pop(0);
    }
    void shift(const T &a) {
        _l_shift += a;
        _r_shift += a;
    }
    void shift(const T &a, const T &b) {
        _l_shift += a;
        _r_shift += b;
    }
};
