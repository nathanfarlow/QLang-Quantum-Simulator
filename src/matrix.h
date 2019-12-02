#pragma once

#include "matrixprocessor.h"

#include <vector>

template<typename T>
class Matrix {
    size_t total_elements_;
    const std::vector<size_t> &dimensions;

    T *data_;

    MatrixProcessor<T> processor_;
public:

    Matrix(const std::vector<size_t> &dimensions);

    Matrix(size_t rows, size_t cols)
        : Matrix({rows, cols}) {}

    ~Matrix();

    T& operator[](size_t index);

    friend class MatrixProcessor<T>;
    void set_processor(MatrixProcessor<T> e);
};
