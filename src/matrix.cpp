#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> &data) {

	const size_t num_rows = data.size();

	if(num_rows == 0)
		throw "Matrix with 0 rows";

	for(auto row : data) {
		if(row.size() != num_rows)
			throw "Matrix is not square";
	}

	data_(data);
}

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