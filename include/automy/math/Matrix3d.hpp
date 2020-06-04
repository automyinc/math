
#ifndef INCLUDE_AUTOMY_MATH_MATRIX3D_HPP_
#define INCLUDE_AUTOMY_MATH_MATRIX3D_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Matrix3d : public Matrix<double, 3, 3> {
public:
	Matrix3d() {}

	Matrix3d(const Matrix<double, 3, 3>& mat) : Matrix(mat) {}

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Matrix3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Matrix3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Matrix3d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Matrix3d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Matrix3d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_MATRIX3D_HPP_ */
