#pragma once

#include <vector>

template <typename T>
class Matrix;

template <typename T>
class MatrixExecutor {
    virtual Matrix<T> add(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
    virtual Matrix<T> sub(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
    virtual Matrix<T> mul(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
    virtual Matrix<T> tensor(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
};

template<typename T>
class Matrix {
    size_t total_elements_;
    const std::vector<size_t> &dimensions;

    T *data_;

    MatrixExecutor<T> executor;
public:

    Matrix(const std::vector<size_t> &dimensions);

    Matrix(size_t rows, size_t cols)
        : Matrix({rows, cols}) {}

    ~Matrix();

    T& operator[](size_t index);

    void set_executor(MatrixExecutor<T> e);
};
