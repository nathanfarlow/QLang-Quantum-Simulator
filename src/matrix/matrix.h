#pragma once

#include <string>
#include <vector>
#include <memory>

#include "matrixprocessor.h"

template<typename T>
class Matrix {
private:
    size_t num_rows_, num_cols_;

    T *data_;

    //The processor used to compute matrix operations
    std::shared_ptr<MatrixProcessor<T>> processor_;
public:

    Matrix() = delete;

    Matrix(const std::vector<std::vector<T>> &data);
    Matrix(size_t num_rows, size_t num_cols);
    Matrix(size_t num_rows, size_t num_cols, T init);

    Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix);

    ~Matrix();

    Matrix<T> &operator=(const Matrix<T> &matrix);
    Matrix<T> &operator=(Matrix<T> &&matrix);
    
    T *operator[](size_t index);
    const T *operator[](size_t index) const;

    Matrix<T> add(const T &val)                     const {return processor_->add(*this, val);}
    Matrix<T> add(const Matrix<T> &val)             const {return processor_->add(*this, val);}

    Matrix<T> sub(const T &val)                     const {return processor_->sub(*this, val);}
    Matrix<T> sub(const Matrix<T> &val)             const {return processor_->sub(*this, val);}

    Matrix<T> mul(const T &val)                     const {return processor_->mul(*this, val);}
    Matrix<T> mul(const Matrix<T> &val)             const {return processor_->mul(*this, val);}

    //Compute the tensor product
    Matrix<T> tensor(const Matrix<T> &val)          const {return processor_->tensor(*this, val);}    

    Matrix<T> operator+(const T &val)               const {return add(val);}
    Matrix<T> operator+(const Matrix<T> &val)       const {return add(val);}
    void operator+=(const T &val)                         {*this = add(val);}
    void operator+=(const Matrix<T> &val)                 {*this = add(val);}

    Matrix<T> operator-(const T &val)               const {return sub(val);}
    Matrix<T> operator-(const Matrix<T> &val)       const {return sub(val);}
    void operator-=(const T &val)                         {*this = sub(val);}
    void operator-=(const Matrix<T> &val)                 {*this = sub(val);}

    Matrix<T> operator*(const T &val)               const {return mul(val);}
    Matrix<T> operator*(const Matrix<T> &val)       const {return mul(val);}
    void operator*=(const T &val)                         {*this = mul(val);}
    void operator*=(const Matrix<T> &val)                 {*this = mul(val);}

    bool operator==(const Matrix<T> &matrix) const;
    bool operator!=(const Matrix<T> &matrix) const;

    void set_processor(std::shared_ptr<MatrixProcessor<T>> processor);

    std::string ToString() const;

    size_t get_rows() const { return num_rows_; }
    size_t get_cols() const { return num_cols_; }
};

#include "matrix.tpp"
