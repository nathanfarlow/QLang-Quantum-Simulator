#pragma once

#include "matrixprocessor.h"

#include <string>
#include <vector>

template<typename T>
class Matrix {
    size_t num_rows_, num_cols_;

    std::shared_ptr<MatrixProcessor<T>> processor_;
public:
    std::vector<std::vector<T>> data_;

    Matrix(const std::vector<std::vector<T>> &data);
    Matrix(size_t num_rows, size_t num_cols, T init);

	Matrix(const Matrix &matrix);
	Matrix(Matrix &&matrix);

    ~Matrix();

    Matrix<T> &operator=(const Matrix<T> &matrix);
    Matrix<T> &operator=(Matrix<T> &&matrix);
    
    std::vector<T> &operator[](size_t index);

    void set_processor(std::shared_ptr<MatrixProcessor<T>> processor);

    std::string ToString();

    size_t get_rows() { return num_rows_; }
    size_t get_cols() { return num_cols_; }
};

#include "matrix.tpp"
