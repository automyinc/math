
#ifndef INCLUDE_AUTOMY_MATH_VECTOR4F_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR4F_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector4f : public Matrix<float, 4, 1> {
public:
	Vector4f() {}

	Vector4f(const Matrix<float, 4, 1>& mat) : Matrix(mat) {}

	Vector4f(float x, float y, float z, float w) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
		data[3] = w;
	}

	float& x() { return data[0]; }
	float& y() { return data[1]; }
	float& z() { return data[2]; }
	float& w() { return data[3]; }

	const float& x() const { return data[0]; }
	const float& y() const { return data[1]; }
	const float& z() const { return data[2]; }
	const float& w() const { return data[3]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector4f& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector4f& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector4f& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector4f& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector4f& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR4F_HPP_ */
