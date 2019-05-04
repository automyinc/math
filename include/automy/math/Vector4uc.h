
#ifndef INCLUDE_AUTOMY_MATH_VECTOR4UC_H_
#define INCLUDE_AUTOMY_MATH_VECTOR4UC_H_

#include "Matrix.h"


namespace automy {
namespace math {

class Vector4uc : public Matrix<uint8_t, 4, 1> {
public:
	Vector4uc() {}
	
	Vector4uc(const Matrix<uint8_t, 4, 1>& mat) : Matrix(mat) {}
	
	Vector4uc(uint8_t x, uint8_t y, uint8_t z, uint8_t w) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
		data[3] = w;
	}
	
	uint8_t& x() { return data[0]; }
	uint8_t& y() { return data[1]; }
	uint8_t& z() { return data[2]; }
	uint8_t& w() { return data[3]; }
	
	const uint8_t& x() const { return data[0]; }
	const uint8_t& y() const { return data[1]; }
	const uint8_t& z() const { return data[2]; }
	const uint8_t& w() const { return data[3]; }
	
};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector4uc& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector4uc& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector4uc& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector4uc& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector4uc& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR4UC_H_ */
