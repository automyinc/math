
#ifndef MATH_INCLUDE_MATH_MATRIX2D_H_
#define MATH_INCLUDE_MATH_MATRIX2D_H_

#include "Matrix.h"


namespace math {

class Matrix2d : public Matrix<double, 2, 2> {
public:
	Matrix2d() {}
	
	Matrix2d(const Matrix<double, 2, 2>& mat) : Matrix(mat) {}
	
};


} // math


namespace vnx {

inline void read(TypeInput& in, ::math::Matrix2d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::math::Matrix2d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::math::Matrix2d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::math::Matrix2d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::math::Matrix2d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_MATRIX2D_H_ */
