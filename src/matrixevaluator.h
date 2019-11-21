
template <typename T>
class Matrix;

template <typename T>
class MatrixEvaluator {
    virtual Matrix<T> add(const Matrix<T> &m, const T &val) = 0;
    virtual Matrix<T> add(const Matrix<T> &m1, const Matrix<T> &m2) = 0;

    virtual Matrix<T> sub(const Matrix<T> &m, const T &val) = 0;
    virtual Matrix<T> sub(const Matrix<T> &m1, const Matrix<T> &m2) = 0;

    virtual Matrix<T> mul(const Matrix<T> &m, const T &val) = 0;
    virtual Matrix<T> mul(const Matrix<T> &m1, const Matrix<T> &m2) = 0;

    virtual Matrix<T> tensor(const Matrix<T> &m1, const Matrix<T> &m2) = 0;
};

template <typename T>
class NaiveEvaluator : public MatrixEvaluator<T> {
    Matrix<T> add(const Matrix<T> &m, const T &val);
    Matrix<T> add(const Matrix<T> &m1, const Matrix<T> &m2);

    Matrix<T> sub(const Matrix<T> &m, const T &val);
    Matrix<T> sub(const Matrix<T> &m1, const Matrix<T> &m2);

    Matrix<T> mul(const Matrix<T> &m, const T &val);
    Matrix<T> mul(const Matrix<T> &m1, const Matrix<T> &m2);

    Matrix<T> tensor(const Matrix<T> &m1, const Matrix<T> &m2);
};