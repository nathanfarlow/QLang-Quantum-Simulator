#pragma once

#include "matrixprocessor.h"

template <typename T>
class DefaultProcessor : public MatrixProcessor<T> {
public:
    virtual Matrix<T> add(const Matrix<T> &m, const T &val);
    virtual Matrix<T> add(const Matrix<T> &m1, const Matrix<T> &m2);

    virtual Matrix<T> sub(const Matrix<T> &m, const T &val);
    virtual Matrix<T> sub(const Matrix<T> &m1, const Matrix<T> &m2);

    virtual Matrix<T> mul(const Matrix<T> &m, const T &val);
    virtual Matrix<T> mul(const Matrix<T> &m1, const Matrix<T> &m2);

    virtual Matrix<T> tensor(const Matrix<T> &m1, const Matrix<T> &m2);
};

#include "defaultprocessor.tpp"
