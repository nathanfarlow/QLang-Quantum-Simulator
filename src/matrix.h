#pragma once

#include "matrixprocessor.h"

#include <string>
#include <vector>

template<typename T>
class Matrix {
    size_t num_rows_, num_cols_;
    std::vector<std::vector<T>> data_;

    MatrixProcessor<T> *processor_;
public:

    Matrix(const std::vector<std::vector<T>> &data);

    Matrix(size_t num_rows, size_t num_cols);

    ~Matrix();

    std::vector<T> &operator[](size_t index);

    friend class MatrixProcessor<T>;
    void set_processor(MatrixProcessor<T> *e);

    std::string ToString();

    size_t get_rows() { return num_rows_; }
    size_t get_cols() { return num_cols_; }
};

#include "matrix.tpp"
