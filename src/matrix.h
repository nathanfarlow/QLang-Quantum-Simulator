#pragma once

#include "matrixprocessor.h"

#include <vector>

template<typename T>
class Matrix {
    size_t total_elements_;
    const std::vector<std::vector<T>> data_;

    MatrixProcessor<T> processor_;
public:

    Matrix(const std::vector<std::vector<T>> &data);

    Matrix(size_t num_rows, size_t num_cols);

    ~Matrix() {}

    T& operator[](size_t index);

    friend class MatrixProcessor<T>;
    void set_processor(MatrixProcessor<T> e);
};
