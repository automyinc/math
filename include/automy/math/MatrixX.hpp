
#ifndef MATH_INCLUDE_AUTOMY_MATH_MATRIXX_HPP_
#define MATH_INCLUDE_AUTOMY_MATH_MATRIXX_HPP_

#include <automy/math/MatrixX.h>

#include <vnx/Visitor.h>
#include <vnx/Input.hpp>
#include <vnx/Output.hpp>
#include <vnx/DefaultPrinter.h>


namespace automy {
namespace math {

template<typename T, size_t Rows, size_t Cols>
template<typename S>
Matrix<T, Rows, Cols>::Matrix(const MatrixX<S>& mat) {
	if(mat.rows() != Rows || mat.cols() != Cols) {
		throw std::logic_error("matrix dimension mismatch");
	}
	for(size_t i = 0; i < size(); ++i) {
		data[i] = mat[i];
	}
}

template<typename T>
std::ostream& MatrixX<T>::print(std::ostream& out, const std::string& name) const {
		out << name << " = [" << std::endl;
		for(size_t i = 0; i < rows_; ++i) {
			if(i > 0) {
				out << "," << std::endl;
			}
			out << "[";
			for(size_t j = 0; j < cols_; ++j) {
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

template<typename T>
void MatrixX<T>::read(vnx::TypeInput& in, const vnx::TypeCode* type_code, const uint16_t* code) {
	std::array<size_t, 2> size_;
	vnx::read_image_size<2>(in, size_, code);
	resize(size_[0], size_[1]);
	vnx::read_image_data<T, 2>(in, data_, size_, code);
}

template<typename T>
void MatrixX<T>::write(vnx::TypeOutput& out, const vnx::TypeCode* type_code, const uint16_t* code) const {
	vnx::write_image<T, 2>(out, data_, {rows_, cols_}, code);
}

template<typename T>
void MatrixX<T>::read(std::istream& in) {
	std::array<size_t, 2> size_;
	vnx::read_image_size<2>(in, size_);
	resize(size_[0], size_[1]);
	vnx::read_image_data<T, 2>(in, data_, size_);
}

template<typename T>
void MatrixX<T>::write(std::ostream& out) const {
	vnx::write_image<T, 2>(out, data_, {rows_, cols_});
}

template<typename T>
void MatrixX<T>::accept(vnx::Visitor& visitor) const {
	vnx::accept_image<T, 2>(visitor, data_, {rows_, cols_});
}


} // math
} // automy

#endif /* MATH_INCLUDE_AUTOMY_MATH_MATRIXX_HPP_ */
