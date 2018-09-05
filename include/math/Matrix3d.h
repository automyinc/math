
#ifndef MATH_INCLUDE_MATH_MATRIX3D_H_
#define MATH_INCLUDE_MATH_MATRIX3D_H_

#include "Matrix.h"


namespace math {

class Matrix3d : public Matrix<double, 3, 3> {
public:
	Matrix3d() {}
	
	Matrix3d(const Matrix<double, 3, 3>& mat) : Matrix(mat) {}
	
};


} // math


namespace vnx {

inline void read(TypeInput& in, ::math::Matrix3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::math::Matrix3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::math::Matrix3d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::math::Matrix3d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::math::Matrix3d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_MATRIX3D_H_ */
