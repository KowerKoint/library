#pragma once
#include "../base.hpp"
#include "../operator.hpp"

template <
    typename T,
    T (*add)(const T, const T)=add_op,
    T (*zero)()=zero_e,
    T (*mult)(const T, const T)=mult_op,
    T (*one)()=one_e,
    T (*sub)(const T, const T)=sub_op,
    T (*div)(const T, const T)=div_op
>
struct Matrix {
    int n, m;
    Vector<Vector<T>> A;

    Matrix() : n(0), m(0), A(Vector<Vector<T>>(0)) {}
    Matrix(size_t _n, size_t _m) : n(_n), m(_m), A(_n, Vector<T>(_m, zero())) {}
    Matrix(const vector<vector<T>>& _A) : n(_A.size()), m(_A[0].size()), A(_A) {}

    Vector<T> &operator[](int i) {
        assert(0 <= i && i < n);
        return A.at(i);
    }
    const Vector<T> &operator[](int i) const {
        assert(0 <= i && i < n);
        return A.at(i);
    }

    static Matrix I(size_t n) {
        assert(n >= 0);
        Matrix ret(n, n);
        REP(i, n) ret[i][i] = one();
        return ret;
    }

    Matrix &operator+=(const Matrix &B) {
        assert(n == B.n && m == B.m);
        REP(i, n) REP(j, m) A[i][j] = add(A[i][j], B[i][j]);
        return *this;
    }
    Matrix operator+(const Matrix &B) const {
        assert(n == B.n && m == B.m);
        return (Matrix(*this) += B);
    }

    Matrix &operator-=(const Matrix &B) {
        assert(n == B.n && m == B.m);
        REP(i, n) REP(j, m) A[i][j] = sub(A[i][j], B[i][j]);
        return *this;
    }
    Matrix operator-(const Matrix &B) const {
        assert(n == B.n && m == B.m);
        return (Matrix(*this) -= B);
    }

    Matrix &operator*=(const Matrix &B) {
        assert(m == B.n);
        Vector<Vector<T>> res(n, Vector<T>(B.m, zero()));
        REP(i, n) REP(j, m) REP(k, B.m) res[i][k] = add(res[i][k], mult(A[i][j], B[j][k]));
        A.swap(res);
        m = B.m;
        return (*this);
    }
    Matrix operator*(const Matrix &B) const {
        assert(m == B.n);
        return (Matrix(*this) *= B);
    }

    Matrix &operator|=(const Matrix &B) {
        assert(B.n == n);
        REP(i, n) {
            A[i].resize(m+B.m);
            REP(j, B.m) A[i][m+j] = B[i][j];
        }
        m += B.m;
        return (*this);
    }
    Matrix operator|(const Matrix &B) const {
        assert(B.n == n);
        return (Matrix(*this) |= B);
    }

    Matrix &operator|=(const vector<T> &B) {
        assert(B.size() == n);
        REP(i, n) {
            A[i].push_back(B[i]);
        }
        m++;
        return (*this);
    }
    Matrix operator|(const vector<T> &B) const {
        assert(B.size() == n);
        return (Matrix(*this) |= B);
    }

    Matrix &operator&=(const Matrix &B) {
        assert(B.m == m);
        A.resize(n+B.n);
        REP(i, B.n) {
            A[n+i] = B[i];
        }
        n += B.n;
        return (*this);
    }
    Matrix operator&(const Matrix &B) const {
        assert(B.m == m);
        return (Matrix(*this) &= B);
    }

    Matrix &operator&=(const vector<T> &B) {
        assert(B.size() == m);
        A.push_back(B);
        n++;
        return (*this);
    }
    Matrix operator&(const vector<T> &B) const {
        assert(B.size() == m);
        return (Matrix(*this) &= B);
    }

    friend istream &operator>>(istream &is, Matrix &mat) {
        REP(i, mat.n) REP(j, mat.m) is >> mat[i][j];
        return is;
    }

    friend ostream &operator<<(ostream &os, const Matrix &mat) {
        REP(i, mat.n) {
            REP(j, mat.m) os << mat[i][j] << (j==mat.m-1? '\n' : ' ');
        }
        return os;
    }

    Pair<Matrix, T> gaussian_elimination() const {
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
        return {mat, det};
    }

    void make_basis() {
        *this = gaussian_elimination().first;
        while(n && get_bra(n-1) == Vector<T>(m, zero())) pop_bra();
    }

    Matrix inv() const {
        Matrix and_i = (*this) | I(n);
        auto [i_and, det] = and_i.gaussian_elimination();
        assert(det != zero());
        Matrix res(n, n);
        REP(i, n) REP(j, n) res[i][j] = i_and[i][n+j];
        return res;
    }

    Vector<T> get_bra(int i) const {
        assert(0 <= i && i < n);
        return A[i];
    }

    Vector<T> get_ket(int i) const {
        assert(0 <= i && i < m);
        Vector<T> res(n);
        REP(i, n) res[i] = A[i][i];
        return res;
    }

    void pop_bra() {
        assert(n > 0);
        A.pop_back();
        n--;
    }

    void pop_ket() {
        assert(m > 0);
        REP(i, n) A[i].pop_back();
        m--;
    }

    Matrix transpose() const {
        Matrix res(m, n);
        REP(i, n) REP(j, m) res[j][i] = A[i][j];
        return res;
    }

    Matrix operator^=(ll k) {
        if(k < 0) {
            *this = this->inv();
            k = -k;
        }
        Matrix res = Matrix::I(n);
        while(k) {
            if(k & 1) res *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(res.A);
        return (*this);
    }
    Matrix operator^(const ll k) const {
        return (Matrix(*this) ^= k);
    }
};

using XorMatrix = Matrix<
    int,
    xor_op<int>,
    zero_e<int>,
    and_op<int>,
    one_e<int>,
    xor_op<int>,
    and_op<int>
>;
