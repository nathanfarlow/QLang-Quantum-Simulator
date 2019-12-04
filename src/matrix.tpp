#include "defaultprocessor.h"

#include <sstream>
#include <cstring>

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> &data) {

    num_rows_ = data.size();

    if(num_rows_ == 0)
        throw "Matrix with 0 rows";

    num_cols_ = data[0].size();

    data_ = new T[num_rows_ * num_cols_];

    for(size_t row = 0; row < num_rows_; row++) {
        if(data[row].size() != num_cols_) {
            delete[] data_;
            data_ = nullptr;
            throw "Matrix is not rectangular";
        }

        for(size_t col = 0; col < num_cols_; col++)
            (*this)[row][col] = data[row][col];
    }

    processor_ = std::make_shared<DefaultProcessor<T>>();
}

template <typename T>
Matrix<T>::Matrix(size_t num_rows, size_t num_cols) {
    num_rows_ = num_rows;
    num_cols_ = num_cols;

    data_ = new T[num_rows_ * num_cols_];

    processor_ = std::make_shared<DefaultProcessor<T>>();
}

template <typename T>
Matrix<T>::Matrix(size_t num_rows, size_t num_cols, T init) {
    num_rows_ = num_rows;
    num_cols_ = num_cols;

    data_ = new T[num_rows_ * num_cols_];

    for(size_t row = 0; row < num_rows_; row++) {
        for(size_t col = 0; col < num_cols_; col++)
            (*this)[row][col] = init;
    }

    processor_ = std::make_shared<DefaultProcessor<T>>();
}

template <typename T>
Matrix<T>::Matrix(const Matrix &matrix) {
    num_rows_ = matrix.num_rows_;
    num_cols_ = matrix.num_cols_;

    delete[] data_;
    data_ = new T[num_rows_ * num_cols_];
    std::memcpy(data_, matrix.data_, num_rows_ * num_cols_ * sizeof(T));

    processor_ = matrix.processor_;
}

template <typename T>
Matrix<T>::Matrix(Matrix &&matrix) {
    num_rows_ = matrix.num_rows_;
    num_cols_ = matrix.num_cols_;

    data_ = matrix.data_;
    matrix.data_ = nullptr;

    processor_ = std::move(matrix.processor_);
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] data_;
    data_ = nullptr;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix) {
    num_rows_ = matrix.num_rows_;
    num_cols_ = matrix.num_cols_;

    delete[] data_;
    data_ = new T[num_rows_ * num_cols_];
    std::memcpy(data_, matrix.data_, num_rows_ * num_cols_ * sizeof(T));
    
    processor_ = matrix.processor_;

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&matrix) {
    num_rows_ = matrix.num_rows_;
    num_cols_ = matrix.num_cols_;

    std::swap(data_, matrix.data_);
    processor_ = std::move(matrix.processor_);

    return *this;
}

template <typename T>
T *Matrix<T>::operator[](size_t index) {
    if(index < 0 || index >= num_rows_)
        throw "Index out of bounds";
    return data_ + index * num_cols_;
}

template <typename T>
const T *Matrix<T>::operator[](size_t index) const {
    if(index < 0 || index >= num_rows_)
        throw "Index out of bounds";
    return data_ + index * num_cols_;
}


template <typename T>
bool Matrix<T>::operator==(const Matrix<T> &matrix) const {

    //Compare dimensions
    if(num_rows_ != matrix.num_rows_
        || num_cols_ != matrix.num_cols_)
        return false;

    //Compare each element
    for(size_t i = 0; i < num_rows_; i++) {
        for(size_t j = 0; j < num_cols_; j++) {
            if((*this)[i][j] != matrix[i][j])
                return false;
        }
    }

    return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix<T> &matrix) const {
    return !(*this == matrix);
}

template <typename T>
void Matrix<T>::set_processor(std::shared_ptr<MatrixProcessor<T>> processor) {
    this->processor_ = processor;
}

template <typename T>
std::string Matrix<T>::ToString() const {
    std::stringstream ss;

    for(size_t i = 0; i < num_rows_; i++) {
        bool beginning = true;

        for(size_t j = 0; j < num_cols_; j++) {
            if(!beginning)
                ss << " ";

            ss << (*this)[i][j];
            beginning = false;
        }

        ss << std::endl;
    }

    //Trim the trailing new line
    return ss.str().substr(0, ss.str().length() - 1);
}