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

    Matrix<T> add(const T &val)                 {return processor_->add(*this, val);}
    Matrix<T> add(const Matrix<T> &val)         {return processor_->add(*this, val);}

    Matrix<T> sub(const T &val)                 {return processor_->sub(*this, val);}
    Matrix<T> sub(const Matrix<T> &val)         {return processor_->sub(*this, val);}

    Matrix<T> mul(const T &val)                 {return processor_->mul(*this, val);}
    Matrix<T> mul(const Matrix<T> &val)         {return processor_->mul(*this, val);}

    Matrix<T> tensor(const Matrix<T> &val)      {return processor_->tensor(*this, val);}    

    Matrix<T> operator+(const T &val)           {return add(val);}
    Matrix<T> operator+(const Matrix<T> &val)   {return add(val);}
    void operator+=(const T &val)               {*this = add(val);}
    void operator+=(const Matrix<T> &val)       {*this = add(val);}

    Matrix<T> operator-(const T &val)           {return sub(val);}
    Matrix<T> operator-(const Matrix<T> &val)   {return sub(val);}
    void operator-=(const T &val)               {*this = sub(val);}
    void operator-=(const Matrix<T> &val)       {*this = sub(val);}

    Matrix<T> operator*(const T &val)           {return mul(val);}
    Matrix<T> operator*(const Matrix<T> &val)   {return mul(val);}
    void operator*=(const T &val)               {*this = mul(val);}
    void operator*=(const Matrix<T> &val)       {*this = mul(val);}

    void set_processor(std::shared_ptr<MatrixProcessor<T>> processor);

    std::string ToString();

    size_t get_rows() { return num_rows_; }
    size_t get_cols() { return num_cols_; }
};

#include "matrix.tpp"
