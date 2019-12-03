
template <typename T>
Matrix<T> DefaultProcessor<T>::add(const Matrix<T> &m, const T &val) {
	Matrix<T> ret(m);

	for(auto &row : ret.data_) {
		for(auto &item : row) {
			item = item + val;
		}
	}

	return ret;
}

template <typename T>
Matrix<T> DefaultProcessor<T>::add(const Matrix<T> &m1, const Matrix<T> &m2) {
	if(m1.get_rows() != m2.get_rows()
		|| m1.get_cols() != m2.get_cols())
		throw "Dimension mismatch";

	const size_t rows = m1.get_rows();
	const size_t cols = m1.get_cols();

	const Matrix<T> ret(rows, cols);

	for(size_t i = 0; i < rows; i++) {
		for(size_t j = 0; j < cols; j++) {
			//Force C++ compiler to choose non const operator
			T &item = ((std::vector<T>&)ret[i])[j];
			item = m1[i][j] + m2[i][j];
		}
	}

	return ret;
}

template <typename T>
Matrix<T> DefaultProcessor<T>::sub(const Matrix<T> &m, const T &val) {
	Matrix<T> ret(m);

	for(auto &row : ret.data_) {
		for(auto &item : row) {
			item = item - val;
		}
	}

	return ret;
}

template <typename T>
Matrix<T> DefaultProcessor<T>::sub(const Matrix<T> &m1, const Matrix<T> &m2) {
    if(m1.get_rows() != m2.get_rows()
		|| m1.get_cols() != m2.get_cols())
		throw "Dimension mismatch";

	const size_t rows = m1.get_rows();
	const size_t cols = m1.get_cols();

	const Matrix<T> ret(rows, cols);

	for(size_t i = 0; i < rows; i++) {
		for(size_t j = 0; j < cols; j++) {
			//Force C++ compiler to choose non const operator
			T &item = ((std::vector<T>&)ret[i])[j];
			item = m1[i][j] - m2[i][j];
		}
	}

	return ret;
}

template <typename T>
Matrix<T> DefaultProcessor<T>::mul(const Matrix<T> &m, const T &val) {
	Matrix<T> ret(m);

	for(auto &row : ret.data_) {
		for(auto &item : row) {
			item = item * val;
		}
	}

	return ret;
}

template <typename T>
Matrix<T> DefaultProcessor<T>::mul(const Matrix<T> &m1, const Matrix<T> &m2) {
    
	if(m1.get_cols() != m2.get_rows())
		throw "Dimension mismatch";

	Matrix<T> ret(m1.get_rows(), m2.get_cols());

	for(size_t row = 0; row < m1.get_rows(); row++) {
		for(size_t col = 0; col < m2.get_cols(); col++) {

			//Compute the dot product on the row and column
			const size_t num_elements = m1[row].size();
			T sum{};

			for(size_t i = 0; i < num_elements; i++) {
				sum += m1[row][i] * m2[i][col];
			}

			ret[row][col] = sum;
		}
	}

	return ret;
}

template <typename T>
Matrix<T> DefaultProcessor<T>::tensor(const Matrix<T> &m1, const Matrix<T> &m2) {
    return Matrix<T>(1, 1, 1);
}
