
#ifndef MATH_INCLUDE_AUTOMY_MATH_MATRIXX_HPP_
#define MATH_INCLUDE_AUTOMY_MATH_MATRIXX_HPP_

#include <automy/math/MatrixX.h>

#include <vnx/Visitor.h>
#include <vnx/Input.hpp>
#include <vnx/Output.hpp>
#include <vnx/Object.hpp>
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
	switch(code[0]) {
		case vnx::CODE_IMAGE:
		case vnx::CODE_ALT_IMAGE: {
			std::array<size_t, 2> size_;
			vnx::read_image_size<2>(in, size_, code);
			resize(size_[0], size_[1]);
			vnx::read_image_data<T, 2>(in, data_, size_, code);
			break;
		}
		case vnx::CODE_OBJECT:
		case vnx::CODE_ALT_OBJECT: {
			// JSON format
			vnx::Object object;
			vnx::read(in, object, type_code, code);
			std::array<size_t, 2> size_;
			object["size"].to(size_);
			resize(size_[0], size_[1]);
			std::vector<T> data;
			object["data"].to(data);
			if(data.size() == size()) {
				for(size_t i = 0; i < data.size(); ++i) {
					data_[i] = data[i];
				}
			} else {
				clear();
			}
			break;
		}
		case vnx::CODE_DYNAMIC:
		case vnx::CODE_ALT_DYNAMIC: {
			uint16_t dyn_code[VNX_MAX_BYTE_CODE_SIZE];
			vnx::read_byte_code(in, dyn_code);
			MatrixX<T>::read(in, type_code, dyn_code);
			break;
		}
		default:
			clear();
			vnx::skip(in, type_code, code);
	}
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
