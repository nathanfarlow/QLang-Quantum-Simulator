#include "matrix.h"

template <typename T>
class Matrix;

template <typename T>
class MatrixExecutor {
    virtual Matrix<T> add(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
    virtual Matrix<T> sub(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
    virtual Matrix<T> mul(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
    virtual Matrix<T> tensor(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
};

template <typename T>
class NaiveExecutor : public MatrixExecutor<T> {};