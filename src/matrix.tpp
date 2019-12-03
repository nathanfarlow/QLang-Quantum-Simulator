#include "defaultprocessor.h"

#include <sstream>

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

	processor_ = std::make_shared<DefaultProcessor<T>>();
}

template <typename T>
Matrix<T>::Matrix(size_t num_rows, size_t num_cols, T init) {

	data_.resize(num_rows);
	for(auto &row : data_)
		row.resize(num_cols, init);

	num_rows_ = num_rows;
	num_cols_ = num_cols;

	processor_ = std::make_shared<DefaultProcessor<T>>();
}

template <typename T>
Matrix<T>::Matrix(const Matrix &matrix) {
	num_rows_ = matrix.num_rows_;
	num_cols_ = matrix.num_cols_;

	data_ = matrix.data_;
	processor_ = matrix.processor_;
}

template <typename T>
Matrix<T>::Matrix(Matrix &&matrix) {
	num_rows_ = matrix.num_rows_;
	num_cols_ = matrix.num_cols_;

	data_ = std::move(matrix.data_);
	processor_ = std::move(matrix.processor_);
}

template <typename T>
Matrix<T>::~Matrix() {

}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix) {
	num_rows_ = matrix.num_rows_;
	num_cols_ = matrix.num_cols_;

	data_ = matrix.data_;
	processor_ = matrix.processor_;

	return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&matrix) {
	num_rows_ = matrix.num_rows_;
	num_cols_ = matrix.num_cols_;

	data_ = std::move(matrix.data_);
	processor_ = std::move(matrix.processor_);

	return *this;
}

template <typename T>
std::vector<T> &Matrix<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
void Matrix<T>::set_processor(std::shared_ptr<MatrixProcessor<T>> processor) {
    this->processor_ = processor;
}

template <typename T>
std::string Matrix<T>::ToString() {
	std::stringstream ss;


	for(auto row : data_) {
		bool beginning = true;

		for(auto obj : row) {

			if(!beginning)
				ss << " ";

			ss << obj;
			beginning = false;
		}

		ss << std::endl;
	}

	//Trim the trailing new line
	return ss.str().substr(0, ss.str().length() - 1);
}