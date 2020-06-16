
#ifndef INCLUDE_AUTOMY_MATH_MATRIX4D_HPP_
#define INCLUDE_AUTOMY_MATH_MATRIX4D_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Matrix4d : public Matrix<double, 4, 4> {
public:
	Matrix4d() = default;

	template<typename S>
	Matrix4d(const Matrix<S, 4, 4>& mat) {
		*this = mat;
	}

	template<typename S>
	Matrix4d& operator=(const Matrix<S, 4, 4>& mat) {
		Matrix<double, 4, 4>::operator=(mat);
		return *this;
	}

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Matrix4d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Matrix4d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Matrix4d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Matrix4d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Matrix4d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_MATRIX4D_HPP_ */
