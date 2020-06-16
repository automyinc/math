
#ifndef AUTOMY_MATH_INCLUDE_MATRIX_H_
#define AUTOMY_MATH_INCLUDE_MATRIX_H_

#include <automy/math/package.hxx>

#include <cmath>
#include <cstdint>
#include <ostream>
#include <array>
#include <stdexcept>
#include <initializer_list>


namespace automy {
namespace math {

struct NO_INIT {};

template<typename T, size_t Rows, size_t Cols>
class Matrix;

template<typename T>
class MatrixX;

template<typename T, size_t Rows, size_t Cols>
std::ostream& operator<<(std::ostream& out, const Matrix<T, Rows, Cols>& value);

template<typename T, size_t Rows, size_t Cols>
std::istream& operator>>(std::istream& in, Matrix<T, Rows, Cols>& value);

template<typename T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols> inverse(const Matrix<T, Rows, Cols>& mat);

template<typename T>
Matrix<T, 1, 1> inverse(const Matrix<T, 1, 1>& m);

template<typename T>
Matrix<T, 2, 2> inverse(const Matrix<T, 2, 2>& m);

template<typename T>
Matrix<T, 3, 3> inverse(const Matrix<T, 3, 3>& m);

template<typename T>
Matrix<T, 4, 4> inverse(const Matrix<T, 4, 4>& m);


template<typename T, size_t Rows, size_t Cols>
class Matrix {
public:
	typedef T Scalar;
	
	/*
	 * Default constructor initializes with all zeros.
	 */
	Matrix() : data({}) {}
	
	/*
	 * Special constructor, does not initialize data.
	 */
	Matrix(NO_INIT) {}
	
	/*
	 * Generic copy constructor.
	 */
	template<typename S>
	Matrix(const Matrix<S, Rows, Cols>& mat) {
		*this = mat;
	}

	/*
	 * Generic copy constructor for a MatrixX.
	 */
	template<typename S>
	Matrix(const MatrixX<S>& mat);

	/*
	 * Initialize with column major list (ie. human readable form).
	 */
	Matrix(const std::initializer_list<T>& list) {
		if(list.size() != Rows * Cols) {
			throw std::logic_error("list.size() != Rows * Cols");
		}
		size_t i = 0;
		for(const T& v : list) {
			(*this)(i / Cols, i % Cols) = v;
			i++;
		}
	}
	
	/*
	 * Returns identity matrix.
	 */
	static Matrix Identity() {
		if(Rows != Cols) {
			throw std::logic_error("Rows != Cols");
		}
		Matrix res;
		for(size_t i = 0; i < Rows; ++i) {
			res(i, i) = 1;
		}
		return res;
	}
	
	T* get_data() {
		return &data[0];
	}
	
	const T* get_data() const {
		return &data[0];
	}
	
	T& operator()(size_t i, size_t j) {
		return data[j * Rows + i];
	}
	
	const T& operator()(size_t i, size_t j) const {
		return data[j * Rows + i];
	}
	
	T& operator[](size_t i) {
		return data[i];
	}
	
	const T& operator[](size_t i) const {
		return data[i];
	}
	
	Matrix& operator=(const Matrix&) = default;

	template<typename S>
	Matrix& operator=(const Matrix<S, Rows, Cols>& mat) {
		for(size_t i = 0; i < size(); ++i) {
			data[i] = mat[i];
		}
		return *this;
	}

	Matrix<T, Cols, Rows> transpose() const {
		Matrix<T, Cols, Rows> res;
		for(size_t j = 0; j < Cols; ++j) {
			for(size_t i = 0; i < Rows; ++i) {
				res(j, i) = (*this)(i, j);
			}
		}
		return res;
	}
	
	T squared_norm() const {
		T sum = 0;
		for(T v : data) {
			sum += v*v;
		}
		return sum;
	}
	
	T norm() const {
		return std::sqrt(squared_norm());
	}

	void normalize() {
		(*this) *= (T(1) / norm());
	}

	Matrix normalized() const {
		return (*this) * (T(1) / norm());
	}

	size_t rows() const {
		return Rows;
	}

	size_t cols() const {
		return Cols;
	}

	size_t size() const {
		return Rows * Cols;
	}
	
	Matrix inverse() const {
		if(Rows != Cols) {
			throw std::logic_error("Rows != Cols");
		}
		return math::inverse<T>(*this);
	}
	
	template<size_t N, size_t M = 1>
	Matrix<T, N, M> get(size_t i_0 = 0, size_t j_0 = 0) const {
		Matrix<T, N, M> res;
		for(size_t j = 0; j < M; ++j) {
			for(size_t i = 0; i < N; ++i) {
				res(i, j) = (*this)(i + i_0, j + j_0);
			}
		}
		return res;
	}
	
	Matrix<T, Rows+1, 1> extend() const {
		if(Cols != 1) {
			throw std::logic_error("Cols != 1");
		}
		Matrix<T, Rows+1, 1> res;
		for(size_t i = 0; i < Rows; ++i) {
			res[i] = data[i];
		}
		res[Rows] = 1;
		return res;
	}
	
	Matrix<T, Rows-1, 1> project() const {
		if(Cols != 1) {
			throw std::logic_error("Cols != 1");
		}
		return get<Rows-1>() * (T(1) / data[Rows-1]);
	}
	
	T dot(const Matrix& B) const {
		T res = 0;
		for(size_t i = 0; i < size(); ++i) {
			res += data[i] * B[i];
		}
		return res;
	}
	
	template<size_t N>
	Matrix<T, Rows, N> operator*(const Matrix<T, Cols, N>& B) const {
		Matrix<T, Rows, N> C;
		for(size_t i = 0; i < Rows; ++i) {
			for(size_t j = 0; j < N; ++j) {
				for(size_t k = 0; k < Cols; ++k) {
					C(i, j) += (*this)(i, k) * B(k, j);
				}
			}
		}
		return C;
	}
	
	template<size_t N>
	Matrix& operator*=(const Matrix<T, Cols, N>& B) {
		*this = *this * B;
		return *this;
	}
	
	Matrix& operator*=(const T& value) {
		for(size_t i = 0; i < Rows * Cols; ++i) {
			(*this)[i] *= value;
		}
		return *this;
	}
	
	Matrix operator*(const T& value) const {
		Matrix C = *this;
		C *= value;
		return C;
	}
	
	Matrix& operator/=(const T& value) {
		for(size_t i = 0; i < Rows * Cols; ++i) {
			(*this)[i] /= value;
		}
		return *this;
	}
	
	Matrix operator/(const T& value) const {
		Matrix C = *this;
		C /= value;
		return C;
	}
	
	Matrix& operator+=(const Matrix& B) {
		for(size_t i = 0; i < Rows * Cols; ++i) {
			(*this)[i] += B[i];
		}
		return *this;
	}
	
	Matrix operator+(const Matrix& B) const {
		Matrix C = *this;
		C += B;
		return C;
	}
	
	Matrix& operator-=(const Matrix& B) {
		for(size_t i = 0; i < Rows * Cols; ++i) {
			(*this)[i] -= B[i];
		}
		return *this;
	}
	
	Matrix operator-(const Matrix& B) const {
		Matrix C = *this;
		C -= B;
		return C;
	}
	
	bool operator==(const Matrix& B) const {
		return data == B.data;
	}
	
	bool operator!=(const Matrix& B) const {
		return data != B.data;
	}

	friend Matrix operator*(const T& value, const Matrix& A) {
		return A * value;
	}

	std::ostream& print(std::ostream& out, const std::string& name) const;
	
	void read(vnx::TypeInput& in, const vnx::TypeCode* type_code, const uint16_t* code);
	
	void write(vnx::TypeOutput& out, const vnx::TypeCode* type_code, const uint16_t* code) const;
	
	void read(std::istream& in);
	
	void write(std::ostream& out) const;
	
	void accept(vnx::Visitor& visitor) const;
	
private:
	std::array<T, Rows * Cols> data;
	
};


} // math
} // automy

#endif /* MATH_INCLUDE_MATRIX_H_ */
