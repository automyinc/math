
#ifndef INCLUDE_AUTOMY_MATH_MATRIX2D_HPP_
#define INCLUDE_AUTOMY_MATH_MATRIX2D_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Matrix2d : public Matrix<double, 2, 2> {
public:
	Matrix2d() = default;

	template<typename S>
	Matrix2d(const Matrix<S, 2, 2>& mat) {
		*this = mat;
	}

	template<typename S>
	Matrix2d& operator=(const Matrix<S, 2, 2>& mat) {
		Matrix<double, 2, 2>::operator=(mat);
		return *this;
	}

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Matrix2d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Matrix2d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Matrix2d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Matrix2d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Matrix2d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_MATRIX2D_HPP_ */
