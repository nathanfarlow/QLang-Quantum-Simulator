
template <typename T>
Matrix<T> DefaultProcessor<T>::add(const Matrix<T> &m, const T &val) {
	Matrix<T> copy(m);

	for(auto row : copy.data_) {
		for(auto item : row) {
			item += val;
		}
	}

	return copy;
}

template <typename T>
Matrix<T> DefaultProcessor<T>::add(const Matrix<T> &m1, const Matrix<T> &m2) {
	return Matrix<T>(1, 1, 1);
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
