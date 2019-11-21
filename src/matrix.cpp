#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(const std::vector<size_t> &dimensions) {
    total_elements_ = 1;
    for(size_t dimension : dimensions)
        total_elements_ *= dimension;
    data_ = new T[total_elements_];
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] data_;
}

template <typename T>
T& Matrix<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
void Matrix<T>::set_executor(MatrixExecutor<T> e) {
    this->executor = e;
}