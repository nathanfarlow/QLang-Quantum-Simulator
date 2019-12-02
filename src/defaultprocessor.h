#pragma once

#include "matrixprocessor.h"

template <typename T>
class DefaultProcessor : public MatrixProcessor<T> {
    Matrix<T> add(const Matrix<T> &m, const T &val);
    Matrix<T> add(const Matrix<T> &m1, const Matrix<T> &m2);

    Matrix<T> sub(const Matrix<T> &m, const T &val);
    Matrix<T> sub(const Matrix<T> &m1, const Matrix<T> &m2);

    Matrix<T> mul(const Matrix<T> &m, const T &val);
    Matrix<T> mul(const Matrix<T> &m1, const Matrix<T> &m2);

    Matrix<T> tensor(const Matrix<T> &m1, const Matrix<T> &m2);
};
