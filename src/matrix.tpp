#include "matrix.h"

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> &data) {

	const size_t num_rows = data.size();

	if(num_rows == 0)
		throw "Matrix with 0 rows";

	const size_t num_cols = data[0].size();

	for(auto row : data) {
		if(row.size() != num_cols)
			throw "Matrix is not rectangular";
	}

	num_rows_ = num_rows;
	num_cols_ = num_cols;

	data_ = data;
}

template <typename T>
Matrix<T>::Matrix(size_t num_rows, size_t num_cols) {
	
	data_.resize(num_rows);
	for(auto row : data_)
		row.resize(num_cols);

	num_rows_ = num_rows;
	num_cols_ = num_cols;
}

template <typename T>
Matrix<T>::~Matrix() {
	delete processor_;
}

template <typename T>
T& Matrix<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
void Matrix<T>::set_processor(MatrixProcessor<T> *e) {
    this->processor_ = e;
}
