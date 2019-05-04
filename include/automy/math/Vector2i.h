
#ifndef INCLUDE_AUTOMY_MATH_VECTOR2I_H_
#define INCLUDE_AUTOMY_MATH_VECTOR2I_H_

#include "Matrix.h"


namespace automy {
namespace math {

class Vector2i : public Matrix<int32_t, 2, 1> {
public:
	Vector2i() {}
	
	Vector2i(const Matrix<int32_t, 2, 1>& mat) : Matrix(mat) {}
	
	Vector2i(int32_t x, int32_t y) {
		data[0] = x;
		data[1] = y;
	}
	
	int32_t& x() { return data[0]; }
	int32_t& y() { return data[1]; }
	
	const int32_t& x() const { return data[0]; }
	const int32_t& y() const { return data[1]; }
	
};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector2i& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector2i& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector2i& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector2i& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector2i& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR2I_H_ */
