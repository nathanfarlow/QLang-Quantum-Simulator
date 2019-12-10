#pragma once

template <typename T>
class Matrix;

template <typename T>
class MatrixProcessor {
public:
    virtual Matrix<T> add(const Matrix<T> &m, const T &val) = 0;
    virtual Matrix<T> add(const Matrix<T> &m1, const Matrix<T> &m2) = 0;

    virtual Matrix<T> sub(const Matrix<T> &m, const T &val) = 0;
    virtual Matrix<T> sub(const Matrix<T> &m1, const Matrix<T> &m2) = 0;

    virtual Matrix<T> mul(const Matrix<T> &m, const T &val) = 0;
    virtual Matrix<T> mul(const Matrix<T> &m1, const Matrix<T> &m2) = 0;

    virtual Matrix<T> tensor(const Matrix<T> &m1, const Matrix<T> &m2) = 0;

    virtual ~MatrixProcessor() {}
};

