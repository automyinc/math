
#ifndef INCLUDE_AUTOMY_MATH_VECTOR2F_H_
#define INCLUDE_AUTOMY_MATH_VECTOR2F_H_

#include "Matrix.h"


namespace automy {
namespace math {

class Vector2f : public Matrix<float, 2, 1> {
public:
	Vector2f() {}
	
	Vector2f(const Matrix<float, 2, 1>& mat) : Matrix(mat) {}
	
	Vector2f(float x, float y) {
		data[0] = x;
		data[1] = y;
	}
	
	float& x() { return data[0]; }
	float& y() { return data[1]; }
	
	const float& x() const { return data[0]; }
	const float& y() const { return data[1]; }
	
};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector2f& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector2f& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector2f& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector2f& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector2f& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR2F_H_ */
