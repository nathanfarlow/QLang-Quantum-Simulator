#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(size_t num_rows, size_t num_cols) {
	data_(num_rows);
	for(auto row : data_)
		row(num_cols);
}

template <typename T>
T& Matrix<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
void Matrix<T>::set_processor(MatrixProcessor<T> e) {
    this->evalulator_ = e;
}