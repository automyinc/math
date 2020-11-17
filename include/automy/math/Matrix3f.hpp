
#ifndef INCLUDE_AUTOMY_MATH_MATRIX3F_HPP_
#define INCLUDE_AUTOMY_MATH_MATRIX3F_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Matrix3f : public Matrix<float, 3, 3> {
public:
	Matrix3f() = default;

	template<typename S>
	Matrix3f(const Matrix<S, 3, 3>& mat) {
		*this = mat;
	}

	template<typename S>
	Matrix3f& operator=(const Matrix<S, 3, 3>& mat) {
		Matrix<float, 3, 3>::operator=(mat);
		return *this;
	}

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Matrix3f& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Matrix3f& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Matrix3f& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Matrix3f& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Matrix3f& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_MATRIX3F_HPP_ */
