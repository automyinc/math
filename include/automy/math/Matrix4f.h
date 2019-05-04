
#ifndef INCLUDE_AUTOMY_MATH_MATRIX4F_H_
#define INCLUDE_AUTOMY_MATH_MATRIX4F_H_

#include "Matrix.h"


namespace automy {
namespace math {

class Matrix4f : public Matrix<float, 4, 4> {
public:
	Matrix4f() {}
	
	Matrix4f(const Matrix<float, 4, 4>& mat) : Matrix(mat) {}
	
};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Matrix4f& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Matrix4f& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Matrix4f& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Matrix4f& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Matrix4f& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_MATRIX4F_H_ */
