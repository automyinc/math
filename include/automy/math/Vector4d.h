
#ifndef INCLUDE_AUTOMY_MATH_VECTOR4D_H_
#define INCLUDE_AUTOMY_MATH_VECTOR4D_H_

#include "Matrix.h"


namespace automy {
namespace math {

class Vector4d : public Matrix<double, 4, 1> {
public:
	Vector4d() {}
	
	Vector4d(const Matrix<double, 4, 1>& mat) : Matrix(mat) {}
	
	Vector4d(double x, double y, double z, double w) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
		data[3] = w;
	}
	
	double& x() { return data[0]; }
	double& y() { return data[1]; }
	double& z() { return data[2]; }
	double& w() { return data[3]; }
	
	const double& x() const { return data[0]; }
	const double& y() const { return data[1]; }
	const double& z() const { return data[2]; }
	const double& w() const { return data[3]; }
	
};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector4d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector4d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector4d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector4d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector4d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR4D_H_ */
