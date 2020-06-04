
#ifndef MATH_INCLUDE_AUTOMY_MATH_MATRIX_HPP_
#define MATH_INCLUDE_AUTOMY_MATH_MATRIX_HPP_

#include <automy/math/Matrix.h>

#include <vnx/Visitor.h>
#include <vnx/Input.hpp>
#include <vnx/Output.hpp>


namespace automy {
namespace math {

template<typename T, size_t Rows, size_t Cols>
std::ostream& Matrix<T, Rows, Cols>::print(std::ostream& out, const std::string& name) const {
	out << name << " = [" << std::endl;
	for(size_t i = 0; i < Rows; ++i) {
		if(i > 0) {
			out << "," << std::endl;
		}
		out << "[";
		for(size_t j = 0; j < Cols; ++j) {
			if(j > 0) {
				out << ", ";
			}
			out << (*this)(i, j);
		}
		out << "]";
	}
	out << "]" << std::endl;
	return out;
}

template<typename T, size_t Rows, size_t Cols>
void Matrix<T, Rows, Cols>::read(vnx::TypeInput& in, const vnx::TypeCode* type_code, const uint16_t* code) {
	switch(code[0]) {
		case vnx::CODE_MATRIX:
		case vnx::CODE_ALT_MATRIX:
			// new format since vnx-1.2.0
			vnx::read_matrix<T, 2>(in, data.data(), {Rows, Cols}, code);
			break;
		case vnx::CODE_ARRAY:
		case vnx::CODE_ALT_ARRAY:
		case vnx::CODE_LIST:
		case vnx::CODE_ALT_LIST:
			// alternate format
			vnx::read(in, data, type_code, code);
			break;
		default:
			data = {};
			vnx::skip(in, type_code, code);
	}
}

template<typename T, size_t Rows, size_t Cols>
void Matrix<T, Rows, Cols>::write(vnx::TypeOutput& out, const vnx::TypeCode* type_code, const uint16_t* code) const {
	vnx::write_matrix<T, 2>(out, data.data(), {Rows, Cols}, code);
}

template<typename T, size_t Rows, size_t Cols>
void Matrix<T, Rows, Cols>::read(std::istream& in) {
	vnx::read_matrix<T, 2>(in, data.data(), {Rows, Cols});
}

template<typename T, size_t Rows, size_t Cols>
void Matrix<T, Rows, Cols>::write(std::ostream& out) const {
	vnx::write_matrix<T, 2>(out, data.data(), {Rows, Cols});
}

template<typename T, size_t Rows, size_t Cols>
void Matrix<T, Rows, Cols>::accept(vnx::Visitor& visitor) const {
	vnx::accept_matrix<T, 2>(visitor, data.data(), {Rows, Cols});
}

template<typename T, size_t Rows, size_t Cols>
std::ostream& operator<<(std::ostream& out, const Matrix<T, Rows, Cols>& value) {
	vnx::write(out, value.data);
	return out;
}

template<typename T, size_t Rows, size_t Cols>
std::istream& operator>>(std::istream& in, Matrix<T, Rows, Cols>& value) {
	vnx::read(in, value.data);
	return in;
}


template<typename T, size_t Rows, size_t Cols>
Matrix<T, Rows, Cols> inverse(const Matrix<T, Rows, Cols>& mat) {
	throw std::logic_error("not implemented");
}

template<typename T>
Matrix<T, 1, 1> inverse(const Matrix<T, 1, 1>& m) {
	return m * (T(1) / m[0]);
}

template<typename T>
Matrix<T, 2, 2> inverse(const Matrix<T, 2, 2>& m) {
	const T det = (m(0,0) * m(1, 1)) - (m(0, 1) * m(1, 0));
	if(det == 0) {
		throw std::runtime_error("inverse(): determinant = 0");
	}
	Matrix<T, 2, 2> tmp;
	tmp(0, 0) = m(1, 1);
	tmp(1, 0) = -m(1, 0);
	tmp(0, 1) = -m(0, 1);
	tmp(1, 1) = m(0, 0);
	return tmp * (T(1) / det);
}

template<typename T>
Matrix<T, 3, 3> inverse(const Matrix<T, 3, 3>& m) {
	const T det = m(0, 0) * (m(1, 1) * m(2, 2) - m(2, 1) * m(1, 2)) -
				  m(0, 1) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) +
				  m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0));
	if(det == 0) {
		throw std::runtime_error("inverse(): determinant = 0");
	}
	Matrix<T, 3, 3> tmp;
	tmp(0, 0) = m(1, 1) * m(2, 2) - m(2, 1) * m(1, 2);
	tmp(0, 1) = m(0, 2) * m(2, 1) - m(0, 1) * m(2, 2);
	tmp(0, 2) = m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1);
	tmp(1, 0) = m(1, 2) * m(2, 0) - m(1, 0) * m(2, 2);
	tmp(1, 1) = m(0, 0) * m(2, 2) - m(0, 2) * m(2, 0);
	tmp(1, 2) = m(1, 0) * m(0, 2) - m(0, 0) * m(1, 2);
	tmp(2, 0) = m(1, 0) * m(2, 1) - m(2, 0) * m(1, 1);
	tmp(2, 1) = m(2, 0) * m(0, 1) - m(0, 0) * m(2, 1);
	tmp(2, 2) = m(0, 0) * m(1, 1) - m(1, 0) * m(0, 1);
	return tmp * (T(1) / det);
}

template<typename T>
Matrix<T, 4, 4> inverse(const Matrix<T, 4, 4>& m) {
	Matrix<T, 4, 4> tmp;
	tmp[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15]
			+ m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];

	tmp[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15]
			- m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];

	tmp[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15]
			+ m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];

	tmp[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14]
			- m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];

	tmp[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15]
			- m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];

	tmp[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15]
			+ m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];

	tmp[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15]
			- m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];

	tmp[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14]
			+ m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];

	tmp[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15]
			+ m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];

	tmp[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15]
			- m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];

	tmp[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15]
			+ m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];

	tmp[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14]
			- m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];

	tmp[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11]
			- m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];

	tmp[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11]
			+ m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];

	tmp[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11]
			- m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];

	tmp[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10]
			+ m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

	const T det = m[0] * tmp[0] + m[1] * tmp[4] + m[2] * tmp[8] + m[3] * tmp[12];
	if(det == 0) {
		throw std::runtime_error("inverse(): determinant = 0");
	}
	return tmp * (T(1) / det);
}


} // math
} // automy

#endif /* MATH_INCLUDE_AUTOMY_MATH_MATRIX_HPP_ */
