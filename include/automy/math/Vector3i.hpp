
#ifndef INCLUDE_AUTOMY_MATH_VECTOR3I_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR3I_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector3i : public Matrix<int32_t, 3, 1> {
public:
	Vector3i() {}

	Vector3i(const Matrix<int32_t, 3, 1>& mat) : Matrix(mat) {}

	Vector3i(int32_t x, int32_t y, int32_t z) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}

	int32_t& x() { return data[0]; }
	int32_t& y() { return data[1]; }
	int32_t& z() { return data[2]; }

	const int32_t& x() const { return data[0]; }
	const int32_t& y() const { return data[1]; }
	const int32_t& z() const { return data[2]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector3i& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector3i& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector3i& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector3i& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector3i& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR3I_HPP_ */
