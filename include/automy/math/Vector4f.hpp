
#ifndef INCLUDE_AUTOMY_MATH_VECTOR4F_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR4F_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector4f : public Matrix<float, 4, 1> {
public:
	Vector4f() = default;

	template<typename S>
	Vector4f(const Matrix<S, 4, 1>& mat) {
		*this = mat;
	}

	template<typename S>
	Vector4f& operator=(const Matrix<S, 4, 1>& mat) {
		Matrix<float, 4, 1>::operator=(mat);
		return *this;
	}

	Vector4f(float x, float y, float z, float w) {
		(*this)[0] = x;
		(*this)[1] = y;
		(*this)[2] = z;
		(*this)[3] = w;
	}

	float& x() { return (*this)[0]; }
	float& y() { return (*this)[1]; }
	float& z() { return (*this)[2]; }
	float& w() { return (*this)[3]; }

	const float& x() const { return (*this)[0]; }
	const float& y() const { return (*this)[1]; }
	const float& z() const { return (*this)[2]; }
	const float& w() const { return (*this)[3]; }

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
