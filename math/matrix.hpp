#pragma once
#include "../template.cpp"
#include "../internal_operator.hpp"

template <
    typename T,
    T (*add)(const T, const T)=internal_operator::default_add,
    T (*zero)()=internal_operator::zero,
    T (*mult)(const T, const T)=internal_operator::default_mult,
    T (*one)()=internal_operator::one,
    T (*sub)(const T, const T)=internal_operator::default_sub,
    T (*div)(const T, const T)=internal_operator::default_div
>
struct Matrix {
    vector<vector<T>> A;

    Matrix(size_t n, size_t m) : A(n, vector<T>(m, zero())) {}

    size_t height() const { return A.size(); }
    size_t width() const { return A[0].size(); }

    vector<T> &operator[](int i) { return A.at(i); }
    const vector<T> &operator[](int i) const { return A.at(i); }

    static Matrix I(size_t n) {
        Matrix ret(n, n);
        REP(i, n) ret[i][i] = one();
        return ret;
    }

    Matrix &operator+=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        REP(i, n) REP(j, m) A[i][j] = add(A[i][j], B[i][j]);
        return *this;
    }
    Matrix operator+(const Matrix &B) const {
        return (Matrix(*this) += B);
    }

    Matrix &operator-=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        REP(i, n) REP(j, m) A[i][j] = sub(A[i][j], B[i][j]);
        return *this;
    }
    Matrix operator-(const Matrix &B) const {
        return (Matrix(*this) -= B);
    }

    Matrix &operator*=(const Matrix &B) {
        size_t n = height(), m = width(), l = B.width();
        assert(m == B.height());
        vector<vector<T>> res(n, vector<T>(l, zero()));
        REP(i, n) REP(j, m) REP(k, l) res[i][k] = add(res[i][k], mult(A[i][j], B[j][k]));
        A.swap(res);
        return (*this);
    }
    Matrix operator*(const Matrix &B) const {
        return (Matrix(*this) *= B);
    }

    friend istream &operator>>(istream &is, Matrix &mat) {
        size_t n = mat.height(), m = mat.width();
        REP(i, n) REP(j, m) is >> mat[i][j];
        return is;
    }

    friend ostream &operator<<(ostream &os, Matrix &mat) {
        size_t n = mat.height(), m = mat.width();
        REP(i, n) {
            REP(j, m) os << mat[i][j] << (j==m-1? '\n' : ' ');
        }
        return os;
    }

    pair<Matrix, T> gaussian_elimination() const {
        int n = height(), m = width();
        Matrix mat(*this);
        T det = one();
        VI columns;
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            int idx = -1;
            FOR(k, i, n) if(mat[k][j] != zero()) idx = k;
            if(idx == -1) {
                det = zero();
                j++;
                continue;
            }
            if(i != idx) {
                det *= sub(zero(), one());
                swap(mat[i], mat[idx]);
            }
            det *= mat[i][j];
            T scale = mat[i][j];
            REP(l, m) mat[i][l] = div(mat[i][l], scale);
            FOR(k, i+1, n) {
                T scale = mat[k][j];
                REP(l, m) mat[k][l] = sub(mat[k][l], mult(mat[i][l], scale));
            }
            columns.push_back(j);
            i++;
            j++;
        }
        REP(i, columns.size()) {
            int j = columns[i];
            REP(k, i) {
                T scale = mat[k][j];
                FOR(l, j, m) {
                    mat[k][l] = sub(mat[k][l], mult(mat[i][l], scale));
                }
            }
        }
        return make_pair(mat, det);
    }

    Matrix inv() const {
        int n = height();
        Matrix and_i(n, n*2);
        REP(i, n) REP(j, n) and_i[i][j] = A[i][j];
        REP(i, n) and_i[i][n+i] = one();
        auto [i_and, det] = and_i.gaussian_elimination();
        assert(det != zero());
        Matrix res(n, n);
        REP(i, n) REP(j, n) res[i][j] = i_and[i][n+i];
        return res;
    }

    Matrix operator^=(ll n) {
        if(n < 0) {
            *this = this->inv();
            n = -n;
        }
        Matrix res = Matrix::I(height());
        while(n) {
            if(n & 1) res *= *this;
            *this *= *this;
            n >>= 1LL;
        }
        A.swap(res.A);
        return (*this);
    }
    Matrix operator^(const ll n) const {
        return (Matrix(*this) ^= n);
    }
};
