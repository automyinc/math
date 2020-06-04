
#ifndef INCLUDE_AUTOMY_MATH_VECTOR3F_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR3F_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector3f : public Matrix<float, 3, 1> {
public:
	Vector3f() {}

	Vector3f(const Matrix<float, 3, 1>& mat) : Matrix(mat) {}

	Vector3f(float x, float y, float z) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}

	float& x() { return data[0]; }
	float& y() { return data[1]; }
	float& z() { return data[2]; }

	const float& x() const { return data[0]; }
	const float& y() const { return data[1]; }
	const float& z() const { return data[2]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector3f& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector3f& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector3f& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector3f& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector3f& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR3F_HPP_ */
