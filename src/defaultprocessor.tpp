
template <typename T>
Matrix<T> DefaultProcessor<T>::add(const Matrix<T> &m, const T &val) {
	Matrix<T> copy(m);

	for(auto &row : copy.data_) {
		for(auto &item : row) {
			item += val;
		}
	}

	return copy;
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
	return Matrix<T>(1, 1, 1);
}

template <typename T>
Matrix<T> DefaultProcessor<T>::sub(const Matrix<T> &m1, const Matrix<T> &m2) {
    return Matrix<T>(1, 1, 1);
}

template <typename T>
Matrix<T> DefaultProcessor<T>::mul(const Matrix<T> &m, const T &val) {
	return Matrix<T>(1, 1, 1);
}

template <typename T>
Matrix<T> DefaultProcessor<T>::mul(const Matrix<T> &m1, const Matrix<T> &m2) {
    return Matrix<T>(1, 1, 1);
}

template <typename T>
Matrix<T> DefaultProcessor<T>::tensor(const Matrix<T> &m1, const Matrix<T> &m2) {
    return Matrix<T>(1, 1, 1);
}
