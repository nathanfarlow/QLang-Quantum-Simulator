
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

}

template <typename T>
std::vector<T> &Matrix<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
void Matrix<T>::set_processor(std::unique_ptr<MatrixProcessor<T>> processor) {
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
	ss.clear();
	return ss.str();
}